/* $NetBSD: base-wrapper.c,v 1.2 2015/04/19 14:30:07 jperkin Exp $ */

/*-
 * Copyright (c) 2007 Joerg Sonnenberger <joerg@NetBSD.org>.
 * All rights reserved.
 *
 * This code was developed as part of Google's Summer of Code 2007 program.
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
#include <sys/wait.h>
#include <nbcompat/err.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "common.h"

static const char wrapper_name[] = WRAPPER_NAME;

#if !defined(WRAPPER_LIBTOOL) && !defined(WRAPPER_SHLIBTOOL)
void
register_unwrap(const char *rule)
{
}
#endif

#if defined(WRAPPER_LIBTOOL) || defined(WRAPPER_SHLIBTOOL)
static int
libtool_mode(struct arglist *args)
{
	struct argument *arg;
	const char *mode = NULL;

	mode = NULL;
	TAILQ_FOREACH(arg, args, link) {
		if (arg->val[0] != '-') {
			prepend_after = arg;
			break;
		}
		if (strncmp(arg->val, "--mode=", 7) == 0) {
			mode = arg->val + 7;
			continue;
		}
		if (strcmp(arg->val, "--mode") == 0) {
			arg = TAILQ_NEXT(arg, link);
			if (arg == NULL || *arg->val == '-')
				errx(255, "Misssing --mode argument");
			mode = arg->val;
			continue;
		}
		if (strcmp(arg->val, "--finish") == 0) {
			mode = arg->val + 2;
			continue;
		}
		if (strcmp(arg->val, "--tag") == 0) {
			arg = TAILQ_NEXT(arg, link);
			if (arg == NULL || *arg->val == '-')
				errx(255, "Misssing --tag argument");
			continue;
		}
	}
	if (arg == NULL)
		return 1;
	if (mode == NULL)
		errx(255, "Misssing --mode=XXX");
	
	if (strcmp(mode, "compile") == 0 ||
	    strcmp(mode, "link") == 0)
		return 0;
	else
		return 1;
}
#endif

int
main(int argc, char **argv)
{
	int do_fork, rv;
	FILE *fp;
	struct arglist args;
	struct argument *arg;
	char **argv2;

	init_generic_transform();

	parse_config(wrapper_name);

	if (argc == 2 && strcmp(argv[1], "--wrappee-name") == 0) {
		puts(exec_name);
		return 0;
	}

	arglist_from_argc(&args, argc, argv);

	fp = worklog_open();
	worklog_cmd(fp, "[*]", wrapper_name, &args); 

#if defined(WRAPPER_LIBTOOL) || defined(WRAPPER_SHLIBTOOL)
	if (libtool_mode(&args))
		goto skip_transforms;
#endif

	arglist_apply_config(&args);
#if defined(WRAPPER_LD)
	normalise_ld(&args);
#else
	normalise_cc(&args);
#endif
	cleanup_cc(&args);
#if defined(WRAPPER_LD)
	generic_transform_ld(&args);
#else
	generic_transform_cc(&args);
#endif
	reorder_cc(&args);
#if defined(WRAPPER_CC) || defined(WRAPPER_CXX)
	transform_cc(&args);
#endif
	cleanup_cc(&args);

#if defined(WRAPPER_LIBTOOL) || defined(WRAPPER_SHLIBTOOL)
skip_transforms:
#endif

	argc = 1;
	TAILQ_FOREACH(arg, &args, link)
		++argc;

	argv2 = xmalloc(sizeof(void *) * argc);
	argv2[0] = exec_name;
	argv = argv2 + 1;
	TAILQ_FOREACH(arg, &args, link)
		*argv++ = arg->val;

	worklog_cmd(fp, "<.>", exec_name, &args); 

	fclose(fp);

#if defined(WRAPPER_LIBTOOL) || defined(WRAPPER_SHLIBTOOL)
	do_fork = 1;
#else
	do_fork = 0;
#endif

	rv = command_exec(&args, do_fork);

#if defined(WRAPPER_LIBTOOL) || defined(WRAPPER_SHLIBTOOL)
	if (rv == 0)
		fixup_libtool(&args);
#endif

	return rv;
}
