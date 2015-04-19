/* $NetBSD: normalise-cc.c,v 1.2 2015/04/19 14:30:07 jperkin Exp $ */

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

static void
normalise_path_list(struct arglist *args, struct argument *arg,
    const char *prefix, const char *val, int strip_relative)
{
	const char *sep;
	struct argument *arg2;

	while ((sep = strchr(val, ':')) != NULL) {
		if (sep == val || (strip_relative && val[0] != '/')) {
			val = sep + 1;
			continue;
		}
		arg2 = argument_new(concat2(prefix, val, sep - val));
		TAILQ_INSERT_AFTER(args, arg, arg2, link);
		arg = arg2;
		val = sep + 1;
	}
	if (val[0] == '\0' || (strip_relative && val[0] != '/'))
		return;
	arg2 = argument_new(concat(prefix, val));
	TAILQ_INSERT_AFTER(args, arg, arg2, link);
	arg = arg2;
}

void
normalise_cc(struct arglist *args)
{
	struct argument *arg, *arg2, *arg3;
	const char *next, *last;
	size_t len;

	TAILQ_FOREACH_SAFE(arg, args, link, arg2) {
		if (arg->val[0] != '-')
			continue;
		if (strcmp(arg->val, "-Xlinker") == 0) {
			if (arg2 == NULL)
				errx(255, "Missing argument for %s", arg->val);
			if (strncmp(arg2->val, "-Wl,", 4) == 0) {
				argument_unlink(args, &arg);
				continue;
			}
			argument_update(arg2, concat("-Wl,", arg2->val));
			argument_unlink(args, &arg);
			continue;						
		}
		if (strncmp(arg->val, "-Wl,", 4) == 0 &&
		    (next = strchr(arg->val + 4, ',')) != NULL) {
			last = arg->val + 4;
			do {
				arg3 = argument_new(concat2("-Wl,", last,
				    next - last));
				if (arg2 != NULL)
					TAILQ_INSERT_BEFORE(arg2, arg3, link);
				else
					TAILQ_INSERT_TAIL(args, arg3, link);
				last = next + 1;
			} while ((next = strchr(last, ',')) != NULL);
			arg3 = argument_new(concat("-Wl,", last));
			if (arg2 != NULL)
				TAILQ_INSERT_BEFORE(arg2, arg3, link);
			else
				TAILQ_INSERT_TAIL(args, arg3, link);
			argument_unlink(args, &arg);
			continue;
		}
	}

	TAILQ_FOREACH_SAFE(arg, args, link, arg2) {
		if (strcmp(arg->val, "-o") == 0 ||
		    strcmp(arg->val, "--dynamic-linker") == 0) {
			if (arg2 == NULL || arg2->val[0] == '-')
				errx(255, "Missing argument for %s", arg->val);
			arg2 = TAILQ_NEXT(arg2, link);
			continue;
		}
		if (arg->val[0] == '/') {
			next = strrchr(arg->val, '/');
			++next;
			if (strncmp(next, "lib", 3))
				continue;
			next += 3;
			len = strspn(next, library_name_chars);
			if (len == 0)
				continue;
			last = next + len;
			if (strncmp(last, ".so", 3) &&
			    strncmp(last, ".sl", 3))
				continue;
			if (last[3] &&
			    (last[3] != '.' || last[4] < '0' || last[4] > '9'))
				continue;
			arg3 = argument_new(xasprintf("-l%*.*s", (int)len,
			    (int)len, next));
			next = strrchr(arg->val, '/');
			len = next - arg->val;
			argument_update(arg, xasprintf("-L%*.*s", (int)len,
			    (int)len, arg->val));
			TAILQ_INSERT_AFTER(args, arg, arg3, link);
			continue;
		}
		if (arg->val[0] != '-')
			continue;
		if (strcmp(arg->val, "-I") == 0 ||
		    strcmp(arg->val, "-D") == 0 ||
		    strcmp(arg->val, "-L") == 0) {
			if (arg2 == NULL || arg2->val[0] == '-')
				errx(255, "Missing argument for %s", arg->val);
			argument_update(arg, concat(arg->val, arg2->val));
			argument_unlink(args, &arg2);
			continue;
		}
		if (strcmp(arg->val, "-Wl,-L") == 0) {
			if (arg2 == NULL || strncmp(arg2->val, "-Wl,", 4))
				errx(255, "Missing argument for %s", arg->val);
			argument_update(arg, concat("-L", arg2->val + 4));
			argument_unlink(args, &arg2);
			continue;
		}
		if (strcmp(arg->val, "-Wl,-rpath-link") == 0) {
			if (arg2 == NULL || strncmp(arg2->val, "-Wl,", 4))
				errx(255, "Missing argument for %s", arg->val);
			normalise_path_list(args, arg, "-Wl,-rpath-link,",
			    arg2->val + 4, 0);
			argument_unlink(args, &arg);
			argument_unlink(args, &arg2);
			continue;
		}
		if (strcmp(arg->val, "-R") == 0) {
			if (arg2 == NULL || arg2->val[0] == '-')
				errx(255, "Missing argument for %s", arg->val);
			normalise_path_list(args, arg, "-Wl,-rpath,",
			    arg2->val, 1);
			argument_unlink(args, &arg);
			argument_unlink(args, &arg2);
			continue;
		}
		if (strcmp(arg->val, "-Wl,-R") == 0 ||
		    strcmp(arg->val, "-Wl,-rpath") == 0 ||
		    strcmp(arg->val, "-Wl,--rpath") == 0) {
			if (arg2 == NULL || strncmp(arg2->val, "-Wl,", 4))
				errx(255, "Missing argument for %s", arg->val);
			normalise_path_list(args, arg, "-Wl,-rpath,",
			    arg2->val + 4, 1);
			argument_unlink(args, &arg);
			argument_unlink(args, &arg2);
			continue;
		}
		if (strncmp(arg->val, "-Wl,-R", 6) == 0) {
			normalise_path_list(args, arg, "-Wl,-rpath,",
			    arg->val + 6, 1);
			argument_unlink(args, &arg);
			continue;
		}
		if (strncmp(arg->val, "-R", 2) == 0) {
			normalise_path_list(args, arg, "-Wl,-rpath,",
			    arg->val + 2, 1);
			argument_unlink(args, &arg);
			continue;
		}
		if (strncmp(arg->val, "-Wl,-rpath,", 10) == 0) {
			normalise_path_list(args, arg, "-Wl,-rpath,",
			    arg->val + 10, 1);
			argument_unlink(args, &arg);
			continue;
		}
	}
}
