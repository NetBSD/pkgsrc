/* $NetBSD: digest.c,v 1.1.1.1 2002/12/20 18:13:59 schmonz Exp $ */

/*
 * Copyright (c) 2002 Alistair G. Crooks.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Alistair G. Crooks.
 * 4. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#if 0
#include <sys/cdefs.h>

#ifndef lint
__COPYRIGHT("@(#) Copyright (c) 2002 \
	        The NetBSD Foundation, Inc.  All rights reserved.");
__RCSID("$NetBSD: digest.c,v 1.1.1.1 2002/12/20 18:13:59 schmonz Exp $");
#endif
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef HAVE_ERR_H
#include <err.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#include <unistd.h>

#include "lib.h"

#ifndef HAVE_MD5FILE

#define _MD5_ASCII_BUF_SIZE	33

char *
MD5File(char *filename, char *buf)
{
	char	cmd[1024];
	char	in[1024];
	FILE	*pp;
	char	*cp;

	(void) snprintf(cmd, sizeof(cmd), "%s md5 %s", DIGEST, filename);
	if ((pp = popen(cmd, "r")) == NULL) {
		warn("MD5File: can't popen `%s'", cmd);
		return NULL;
	}
	if (fgets(in, sizeof(in), pp) == NULL) {
		warn("MD5File: can't read from `%s'", cmd);
		(void) pclose(pp);
		return NULL;
	}
	(void) pclose(pp);
	cp = strrchr(in, ' ');
	(void) strcpy(buf, cp + 1);
	buf[_MD5_ASCII_BUF_SIZE	- 1] = 0;
	return buf;
}
#endif
