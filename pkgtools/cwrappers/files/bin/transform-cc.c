/* $NetBSD: transform-cc.c,v 1.2 2015/04/19 14:30:07 jperkin Exp $ */

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
#include <string.h>
#include "common.h"

struct transformation {
	const char *pattern;
	size_t len;
	struct argument *(*transform)(struct arglist *, struct argument *,
	    const char *);
	const char *opt;
};

static struct argument *transform_pass(struct arglist *,
    struct argument *, const char *);
static struct argument *transform_pass_with_warning(struct arglist *,
    struct argument *, const char *);
static struct argument *transform_discard(struct arglist *,
    struct argument *, const char *);
static struct argument *transform_replace(struct arglist *,
    struct argument *, const char *);

#include "transform-gcc.c"

static struct argument *
transform_pass(struct arglist *args, struct argument *arg, const char *opt)
{
	return TAILQ_NEXT(arg, link);
}

static struct argument *
transform_pass_with_warning(struct arglist *args, struct argument *arg,
    const char *opt)
{
	warnx("Unsupported option: %s", arg->val);

	return TAILQ_NEXT(arg, link);
}

static struct argument *
transform_discard(struct arglist *args, struct argument *arg, const char *opt)
{
	argument_unlink(args, &arg);
	return arg;
}

static struct argument *
transform_replace(struct arglist *args, struct argument *arg, const char *opt)
{
	argument_update(arg, xstrdup(opt));

	return TAILQ_NEXT(arg, link);
}

void
transform_cc(struct arglist *args)
{
	struct argument *arg, *arg2;
	size_t len;
	struct transformation *t;

	TAILQ_FOREACH_SAFE(arg, args, link, arg2) {
		if (arg->val[0] != '-')
			continue;

		len = strlen(arg->val);
		t = fixed_transforms + transform_cc_fixed(arg->val, len);
		if (t->len == len && strcmp(t->pattern, arg->val) == 0) {
			arg2 = (*t->transform)(args, arg, t->opt);
			continue;
		}
		for (t = var_transforms; t->pattern != NULL; ++t) {
			if (t->len > len &&
			    strncmp(t->pattern, arg->val, t->len) == 0)
				break;
		}
		if (t->pattern != NULL) {
			arg2 = (*t->transform)(args, arg, t->opt);
			continue;
		}
	}
}
