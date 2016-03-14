/* $NetBSD: generic-transform-cc.c,v 1.4 2016/03/14 20:16:08 markd Exp $ */

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

#if defined(WRAPPER_LIBTOOL)
#include <sys/stat.h>
#endif

#include <nbcompat.h>
#include <nbcompat/err.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#if defined(WRAPPER_LD)
#define generic_transform_cc generic_transform_ld
#endif

#define	OPT_HASH 256

struct transform_rule {
	TAILQ_ENTRY(transform_rule) link;
	char *src;
	char *dst;
	size_t src_len;
};

struct lib_transform_rule {
	TAILQ_ENTRY(lib_transform_rule) link;
	char *src;
	char **dst;
	size_t src_len;
};

TAILQ_HEAD(transform_ruleset, transform_rule);
TAILQ_HEAD(lib_transform_ruleset, lib_transform_rule);

static struct transform_ruleset opt_rules[OPT_HASH];

#if !defined(WRAPPER_LD)
static struct transform_ruleset include_rules =
    TAILQ_HEAD_INITIALIZER(include_rules);
#endif
static struct transform_ruleset lib_rules =
    TAILQ_HEAD_INITIALIZER(lib_rules);
static struct transform_ruleset rpath_rules =
    TAILQ_HEAD_INITIALIZER(rpath_rules);
#if defined(WRAPPER_LIBTOOL)
static struct transform_ruleset libpath_rules =
    TAILQ_HEAD_INITIALIZER(libpath_rules);
#endif

static struct lib_transform_ruleset libname_rules =
    TAILQ_HEAD_INITIALIZER(libname_rules);

void
init_generic_transform(void)
{
	size_t i;

	for (i = 0; i < OPT_HASH; ++i)
		TAILQ_INIT(opt_rules + i);
}

static void
register_generic_transform_path(const char *orig_rule, const char *rule,
    struct transform_ruleset *ruleset)
{
	const char *sep;
	struct transform_rule *r;

	sep = strchr(rule, ':');
	if (sep == NULL)
		goto failure;
	if (strchr(sep + 1, ':') != NULL)
		goto failure;

	r = xmalloc(sizeof(*r));
	r->src = xstrndup(rule, sep - rule);
	if (sep[1])
		r->dst = xstrdup(sep + 1);
	else
		r->dst = NULL;
	r->src_len = sep - rule;

	TAILQ_INSERT_TAIL(ruleset, r, link);

	return;

failure:
	errx(255, "Invalid transform rule: %s", orig_rule);
}

static void
register_generic_transform_lib(const char *orig_rule, const char *rule)
{
	struct lib_transform_rule *r;
	const char *sep;
	size_t count;

	sep = strchr(rule, ':');
	if (sep == NULL)
		goto failure;

	r = xmalloc(sizeof(*r));
	r->src = concat2("-l", rule, sep - rule);
	r->src_len = sep - rule + 2;
	rule = sep;
	for (count = 0; sep != NULL; ++count)
		sep = strchr(sep + 1, ':');

	r->dst = xmalloc(sizeof(char *) * (count + 1));
	for (count = 0; rule != NULL; ++count, rule = sep) {
		++rule;
		sep = strchr(rule, ':');
		if (sep == rule || *rule == '\0')
			goto failure;
		if (sep)
			r->dst[count] = concat2("-l", rule, sep - rule);
		else
			r->dst[count] = concat("-l", rule);
	}
	r->dst[count] = NULL;	

	TAILQ_INSERT_TAIL(&libname_rules, r, link);

	return;
failure:
	errx(255, "Invalid transform rule: %s", orig_rule);
}

static void
register_opt_transform(const char *orig_rule, const char *rule)
{
	const char *sep;
	struct transform_rule *r;
	size_t i;

	sep = strchr(rule, ':');
	if (sep == NULL)
		goto failure;
	if (strchr(sep + 1, ':') != NULL)
		goto failure;

	r = xmalloc(sizeof(*r));
	r->src = xstrndup(rule, sep - rule);
	if (sep[1])
		r->dst = xstrdup(sep + 1);
	else
		r->dst = NULL;
	r->src_len = sep - rule;

	i = wrapper_hash(r->src) & (OPT_HASH - 1);

	TAILQ_INSERT_TAIL(opt_rules + i, r, link);

	return;

failure:
	errx(255, "Invalid transform rule: %s", orig_rule);
}

static void
register_rm_transform(const char *orig_rule, const char *rule)
{
	struct transform_rule *r;
	size_t i;

	if (strchr(rule, ':') != NULL)
		goto failure;

	r = xmalloc(sizeof(*r));
	r->src = xstrdup(rule);
	r->dst = NULL;
	r->src_len = strlen(r->src);

	i = wrapper_hash(r->src) & (OPT_HASH - 1);

	TAILQ_INSERT_TAIL(opt_rules + i, r, link);

	return;

failure:
	errx(255, "Invalid transform rule: %s", orig_rule);
}

void
register_generic_transform(const char *rule)
{
	if (strncmp(rule, "I:", 2) == 0) {
#if !defined(WRAPPER_LD)
		register_generic_transform_path(rule, rule + 2,
		    &include_rules);
#endif
	} else if (strncmp(rule, "L:", 2) == 0) {
		register_generic_transform_path(rule, rule + 2,
		    &lib_rules);
	} else if (strncmp(rule, "R:", 2) == 0) {
		register_generic_transform_path(rule, rule + 2,
		    &rpath_rules);
	} else if (strncmp(rule, "l:", 2) == 0) {
		register_generic_transform_lib(rule, rule + 2);
	} else if (strncmp(rule, "P:", 2) == 0) {
#if defined(WRAPPER_LIBTOOL)
		register_generic_transform_path(rule, rule + 2,
		    &libpath_rules);
#endif
	} else if (strncmp(rule, "opt:", 4) == 0) {
		register_opt_transform(rule, rule + 4);
	} else if (strncmp(rule, "rm:", 3) == 0) {
		register_rm_transform(rule, rule + 3);
	} else
		errx(255, "Unknown transform rule: %s", rule);
}

#if defined(WRAPPER_LIBTOOL)
static void
generic_transform_cc_absolute(struct arglist *args, struct argument *arg)
{
	struct transform_rule *rule;
	const char *fname, *iter;
	size_t len;

	fname = strrchr(arg->val, '/');
	if (strncmp(fname + 1, "lib", 3))
		return;
	iter = fname + 4;
	len = strspn(iter, library_name_chars);
	if (len == 0)
		return;
	iter += len;
	if (strcmp(iter, ".la") && strcmp(iter, ".a"))
		return;

	len = fname - arg->val;

	TAILQ_FOREACH(rule, &libpath_rules, link) {
		if (rule->src_len > len)
			continue;
		if (arg->val[rule->src_len] != '/')
			continue;
		if (strncmp(arg->val, rule->src, rule->src_len))
			continue;
		argument_update(arg, concat(rule->dst, arg->val + rule->src_len));
		break;
	}
}

static int
generic_transform_libtool_lib(struct arglist *args, struct argument *arg)
{
	struct argument *arg2;
	struct stat sb;
	char *fname;
	int rv;
	size_t len;

	TAILQ_FOREACH(arg2, args, link) {
		if (arg == arg2)
			break;
		if (strncmp(arg2->val, "-L", 2))
			continue;
		len = strlen(arg2->val);
		if (len >= 6 && strcmp(arg2->val + len - 6, "/.libs") == 0)
			continue;
		fname = xasprintf("%s/lib%s.la", arg2->val + 2, arg->val + 2);
		rv = stat(fname, &sb);
		if (rv == -1 ||
		    !(S_ISREG(sb.st_mode) || S_ISLNK(sb.st_mode))) {
			free(fname);
			continue;
		}
		if (arg2->val[2] == '/') {
			if (wrksrc == NULL)
				return 0;
			if (strncmp(arg2->val + 2, wrksrc, len))
				return 0;
		}
		argument_update(arg, fname);
		return 1;
	}
	return 0;
}
#endif

void
generic_transform_cc(struct arglist *args)
{
	struct argument *arg, *arg2, *opt_arg;
	struct transform_rule *rule;
	struct transform_ruleset *ruleset;
	struct lib_transform_rule *lib_rule;
	const char *path, *prefix;
	char *transformed;
	int rpath_mode;
	size_t i, len;

	TAILQ_FOREACH_SAFE(arg, args, link, arg2) {
		len = strlen(arg->val);
		i = wrapper_hash2(arg->val, len) & (OPT_HASH - 1);
		rpath_mode = 0;
		TAILQ_FOREACH(rule, opt_rules + i, link) {
			if (rule->src_len == len &&
			    strcmp(rule->src, arg->val) == 0)
				break;
		}
		if (rule != NULL) {
			if (rule->dst == NULL) {
				argument_unlink(args, &arg);
				continue;
			}
			argument_update(arg, xstrdup(rule->dst));
			len = strlen(rule->dst);
		}

#if defined(WRAPPER_LIBTOOL)
		if (strncmp(arg->val, "-l", 2) == 0 &&
		    generic_transform_libtool_lib(args, arg))
			continue;
#endif

		if (arg->val[0] == '/') {
#if defined(WRAPPER_LIBTOOL)
			generic_transform_cc_absolute(args, arg);
#endif
			continue;
		}
#if !defined(WRAPPER_LD)
		else if (strncmp(arg->val, "-I", 2) == 0) {
			len -= 2;
			prefix = "-I";
			path = arg->val + 2;
			ruleset = &include_rules;
			opt_arg = NULL;
		}
		else if (strcmp(arg->val, "-isystem") == 0) {
			opt_arg = arg;
			arg = arg2;
			if (arg == NULL || arg->val[0] == '-') {
				errx(255, "Missing argument for %s",
				    opt_arg->val);
			}
			ruleset = &include_rules;
			arg2 = TAILQ_NEXT(arg, link);
			len = strlen(arg->val);
			prefix = "";
			path = arg->val;
		}
#endif
		else if (strncmp(arg->val, "-L", 2) == 0) {
			len -= 2;
			prefix = "-L";
			path = arg->val + 2;
			ruleset = &lib_rules;
			opt_arg = NULL;
		}
#if !defined(WRAPPER_LD)
		else if (strncmp(arg->val, "-Wl,-rpath,", 11) == 0) {
			len -= 11;
			prefix = "-Wl,-rpath,";
			path = arg->val + 11;
			ruleset = &rpath_rules;
			opt_arg = NULL;
			rpath_mode = 1;
		} else if (strncmp(arg->val, "-Wl,-rpath-link,", 15) == 0) {
			len -= 15;
			prefix = "-Wl,-rpath-link,";
			path = arg->val + 15;
			ruleset = &rpath_rules;
			opt_arg = NULL;
			rpath_mode = 1;
		}
#else
		else if (strcmp(arg->val, "-rpath") == 0 ||
			 strcmp(arg->val, "-rpath-link") == 0) {
			opt_arg = arg;
			arg = arg2;
			if (arg == NULL || arg->val[0] == '-') {
				errx(255, "Missing argument for %s",
				    opt_arg->val);
			}
			ruleset = &rpath_rules;
			arg2 = TAILQ_NEXT(arg, link);
			len = strlen(arg->val);
			prefix = "";
			path = arg->val;
			rpath_mode = 1;
		}
#endif
		else if (strncmp(arg->val, "-l", 2) == 0) {
			TAILQ_FOREACH(lib_rule, &libname_rules, link) {
				if (lib_rule->src_len != len)
					continue;
				if (strcmp(lib_rule->src, arg->val) == 0)
					break;
			}
			if (lib_rule == NULL)
				continue;
			argument_unlink(args, &arg);
			for (i = 0; lib_rule->dst[i] != NULL; ++i) {
				arg = argument_copy(lib_rule->dst[i]);
				if (arg2 == NULL)
					TAILQ_INSERT_TAIL(args, arg, link);
				else
					TAILQ_INSERT_BEFORE(arg2, arg, link);
			}
			continue;
		} else
			continue;

		if (*path != '/')
			continue;

		while (len > 1 && path[len - 1] == '/')
			--len;

		TAILQ_FOREACH(rule, ruleset, link) {
			if (rule->src[rule->src_len - 1] == '/') {
				if (rule->src_len - 1 != len)
					continue;
				if (memcmp(path, rule->src, len) != 0)
					continue;
				break;
			}
			if (rule->src_len > len)
				continue;
			if (path[rule->src_len] != '\0' &&
			    path[rule->src_len] != '/')
				continue;
			if (strncmp(path, rule->src, rule->src_len) == 0)
				break;
		}
		if (rule == NULL || rule->dst == NULL) {
			if (rpath_mode) {
				if (len >= 6 &&
				    strcmp(path + len - 6, "/.libs") == 0)
					continue;
			}
			if (opt_arg)
				argument_unlink(args, &opt_arg);
			argument_unlink(args, &arg);
			continue;
		}
		transformed = xasprintf("%s%s%s", prefix, rule->dst,
		    path + rule->src_len);
		argument_update(arg, transformed);
	}
}
