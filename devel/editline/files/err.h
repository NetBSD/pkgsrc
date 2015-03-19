/* $NetBSD: err.h,v 1.1 2015/03/19 19:58:28 tron Exp $ */

#ifndef PKGSRC_ERR_H
#define PKGSRC_ERR_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#if !defined(__sun__)
static const char *
getexecname(void)
{
	return "???";
}
#endif

static void
err(int status, char *fmt, ...)
{
	(void)fprintf(stderr, "%s: ", getexecname());
	if (fmt != NULL) {;
		va_list ap;

		va_start(ap, fmt);
		(void)vfprintf(stderr, fmt, ap);
		va_end(ap);

	}
	(void)fputc('\n', stderr);
	(void)fflush(stderr);

	exit(status);
}


#endif
