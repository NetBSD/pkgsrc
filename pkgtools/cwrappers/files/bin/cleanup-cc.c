/* $NetBSD: cleanup-cc.c,v 1.2 2015/04/19 14:30:07 jperkin Exp $ */

/*-
 * Copyright (c) 2009 Joerg Sonnenberger <joerg@NetBSD.org>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


#include <nbcompat.h>
#include <nbcompat/err.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define CLEANUP_HASH	256

void
cleanup_cc(struct arglist *args)
{
	struct argument *arg, *arg2, *arg3;
	struct arglist hashtab[CLEANUP_HASH];
	size_t i;

	for (i = 0; i < CLEANUP_HASH; ++i)
		TAILQ_INIT(hashtab + i);

	TAILQ_FOREACH_SAFE(arg, args, link, arg2) {
		if (arg->val[0] != '-')
			continue;
		if (strncmp(arg->val, "-Wl,-rpath,", 11) == 0) {
			if (arg->val[11] == '/')
				continue;
			argument_unlink(args, &arg);
			continue;
		}
		if (arg2 != NULL && strncmp(arg->val, "-l", 2) == 0 &&
		    strcmp(arg->val, arg2->val) == 0) {
			argument_unlink(args, &arg);
			continue;
		}
		if (strncmp(arg->val, "-I", 2) == 0 ||
		    strncmp(arg->val, "-L", 2) == 0 ||
		    strncmp(arg->val, "-Wl,-rpath,", 11) == 0 ||
		    strncmp(arg->val, "-Wl,-rpath-link,", 15) == 0) {
			i = wrapper_hash(arg->val) & (CLEANUP_HASH - 1);
			TAILQ_FOREACH(arg3, hashtab + i, tmp_link) {
				if (strcmp(arg->val, arg3->val) == 0) {
					argument_unlink(args, &arg);
					break;
				}
			}
			if (arg3 == NULL)
				TAILQ_INSERT_TAIL(hashtab + i, arg, tmp_link);
			continue;
		}
	}
}
