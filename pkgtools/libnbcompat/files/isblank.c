/* $NetBSD */

#include "nbcompat.h"

int
isblank(c)
	int c;
{
	return(c == ' ' || c == '\t');
}
