/* $NetBSD: checklen.c,v 1.2 2007/03/08 14:31:06 rillig Exp $ */

#include <assert.h>
#include <string.h>

int
main(void)
{
	const char *s = SPACES;

	assert(strlen(s) == LEN);
	return 0;
}
