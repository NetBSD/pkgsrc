/*	$NetBSD: strerror.c,v 1.5 2023/05/07 19:13:28 wiz Exp $	*/

#include "tnftp.h"

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
