/* $NetBSD: reorder-cc.c,v 1.2 2015/04/19 14:30:07 jperkin Exp $ */

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

struct reorder_rule {
	TAILQ_ENTRY(reorder_rule) link;
	char *lib;
	char *lib2;
};

static TAILQ_HEAD(, reorder_rule) reorder_rules =
    TAILQ_HEAD_INITIALIZER(reorder_rules);

void
register_reorder(const char *rule)
{
	struct reorder_rule *r;
	const char *orig_rule = rule;
	size_t len;

	if (strncmp(rule, "l:", 2))
		goto failed;
	rule += 2;

	r = xmalloc(sizeof(*r));

	len = strspn(rule, library_name_chars);
	if (len == 0)
		goto failed;
	r->lib = concat2("-l", rule, len);
	rule +=len;

	if (*rule != ':')
		goto failed;
	++rule;

	len = strspn(rule, library_name_chars);
	if (len == 0 || rule[len] != '\0')
		goto failed;
	r->lib2 = concat2("-l", rule, len);

	TAILQ_INSERT_TAIL(&reorder_rules, r, link);

	return;

failed:
	errx(255, "Invalid reorder rule: %s", orig_rule);
}

void
reorder_cc(struct arglist *args)
{
	struct reorder_rule *rule;
	struct argument *arg, *arg2, *arg3;
	struct arglist matches;

	TAILQ_FOREACH(rule, &reorder_rules, link) {
		TAILQ_INIT(&matches);

		TAILQ_FOREACH(arg, args, link) {
			if (strcmp(arg->val, rule->lib2) == 0)
				break;
			if (strcmp(arg->val, rule->lib) == 0)
				TAILQ_INSERT_TAIL(&matches, arg, tmp_link);
		}
		if (arg == NULL || (arg3 = TAILQ_FIRST(&matches)) == NULL)
			continue;

		TAILQ_REMOVE(args, arg3, link);
		TAILQ_INSERT_AFTER(args, arg, arg3, link);

		TAILQ_REMOVE(&matches, arg3, tmp_link);
		TAILQ_FOREACH_SAFE(arg, &matches, tmp_link, arg2)
			argument_unlink(args, &arg);
	}
}
