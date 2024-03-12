/*	$NetBSD: misc.c,v 1.4 2024/03/12 16:45:07 christos Exp $	*/

/*-
 * Copyright (c) 1992 Diomidis Spinellis.
 * Copyright (c) 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Diomidis Spinellis of Imperial College, University of London.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif
#if HAVE_NBTOOL_CONFIG_H
#include "nbtool_config.h"
#endif

#include <nbcompat.h>
#if HAVE_SYS_CDEFS_H
#include <sys/cdefs.h>
#endif
__RCSID("$NetBSD: misc.c,v 1.4 2024/03/12 16:45:07 christos Exp $");
#ifdef __FBSDID
__FBSDID("$FreeBSD: head/usr.bin/sed/misc.c 200462 2009-12-13 03:14:06Z delphij $");
#endif

#if 0
static const char sccsid[] = "@(#)misc.c	8.1 (Berkeley) 6/6/93";
#endif

#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#if HAVE_ERR_H
#include <err.h>
#endif
#if HAVE_LIMITS_H
#include <limits.h>
#endif
#if HAVE_REGEX_H
#include <regex.h>
#endif
#if HAVE_STDIO_H
#include <stdio.h>
#endif
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_STRING_H
#include <string.h>
#endif

#include "defs.h"
#include "extern.h"

/*
 * malloc with result test
 */
void *
xmalloc(size_t size)
{
	void *p;

	if ((p = malloc(size)) == NULL)
		err(1, "malloc(%zu)", size);
	return p;
}

/*
 * realloc with result test
 */
void *
xrealloc(void *p, size_t size)
{
	if (p == NULL)			/* Compatibility hack. */
		return (xmalloc(size));

	if ((p = realloc(p, size)) == NULL)
		err(1, "realloc(%zu)", size);
	return p;
}

/*
 * realloc with result test
 */
void *
xcalloc(size_t c, size_t n)
{
	void *p;

	if ((p = calloc(c, n)) == NULL)
		err(1, "calloc(%zu, %zu)", c, n);
	return p;
}
/*
 * Return a string for a regular expression error passed.  This is overkill,
 * because of the silly semantics of regerror (we can never know the size of
 * the buffer).
 */
char *
strregerror(int errcode, regex_t *preg)
{
	char buf[1];
	static char *oe;
	size_t s;

	if (oe != NULL)
		free(oe);
	s = regerror(errcode, preg, buf, 0);
	oe = xmalloc(s);
	(void)regerror(errcode, preg, oe, s);
	return (oe);
}
