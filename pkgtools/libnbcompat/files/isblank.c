/*	$NetBSD: isblank.c,v 1.4 2003/09/06 23:03:03 grant Exp $	*/

#include "nbcompat.h"

int
isblank(c)
	int c;
{
	return(c == ' ' || c == '\t');
}
