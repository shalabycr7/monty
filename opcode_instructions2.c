#include "monty.h"

/**
 * _queue - sets the format to queue(FIFO).
 * @doubly: linked list head.
 * @cline: index of the line.
 * Return: no value.
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
	vglo.lifo = 0;
}

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 * @doubly: linked list head.
 * @cline: index of the line.
 * Return: no return
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
	vglo.lifo = 1;
}

/**
 * _add - adds the top two elements of the stack.
 * @doubly: linked list head.
 * @cline: index of the line.
 * Return: no value.
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - do nothing.
 * @doubly: linked list head.
 * @cline: index of the line.
 * Return: no value.
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * _sub - subtracts the top element to the second top element of the stack.
 * @doubly: linked list head.
 * @cline: index of the line.
 * Return: no value.
 */
void _sub(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, cline);
}
