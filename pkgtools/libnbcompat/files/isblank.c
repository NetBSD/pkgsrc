/* $NetBSD: isblank.c,v 1.3 2003/06/30 15:13:17 grant Exp $ */

#include "nbcompat.h"

int
isblank(c)
	int c;
{
	return(c == ' ' || c == '\t');
}
