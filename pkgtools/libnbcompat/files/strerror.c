/*	$NetBSD: strerror.c,v 1.1.1.1 2003/03/31 05:02:57 grant Exp $ */

#include "nbcompat.h"

char *
strerror(int n)
{
	static char msg[] = "Unknown error (1234567890)";

	extern int sys_nerr;
	extern char *sys_errlist[];

	if (n >= sys_nerr) {
		snprintf(msg, sizeof(msg), "Unknown error (%d)", n);
		return(msg);
	} else {
		return(sys_errlist[n]);
	}
}
