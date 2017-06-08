/* $NetBSD: plist_tree.c,v 1.2 2017/06/08 18:14:51 adam Exp $ */

/*-
 * Copyright (c) 2016 The NetBSD Foundation, Inc.
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

#include <sys/cdefs.h>
__RCSID("$NetBSD: plist_tree.c,v 1.2 2017/06/08 18:14:51 adam Exp $");

#include <sys/param.h>
#include <sys/types.h>
#include <sys/rbtree.h>
#include <assert.h>
#include <regex.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

struct plist_pair_entry {
	char *first;  /* key   */
	char *second; /* value */
	rb_node_t pair_node;
};

static int
plist_compare_key(void *ctx, const void *n1, const void *keyp)
{
	const char *a1;
	const char *a2;

	assert(n1);
	assert(keyp);
	assert(((const char *)keyp)[0]);
	assert(((struct plist_pair_entry*)n1)->first);
	assert(((struct plist_pair_entry*)n1)->first[0]);

	a1 = ((struct plist_pair_entry*)n1)->first;
	a2 = (const char *)keyp;

	return strcmp(a1, a2);
}

static int
plist_compare_nodes(void *ctx, const void *n1, const void *n2)
{
	const char *key2;

	assert(n1);
	assert(n2);
	assert(((struct plist_pair_entry*)n2)->first);
	assert(((struct plist_pair_entry*)n2)->first[0]);

	key2 = ((struct plist_pair_entry*)n2)->first;

	return plist_compare_key(ctx, n1, key2);
}

static const rb_tree_ops_t plist_tree_ops = {
	.rbto_compare_nodes = plist_compare_nodes,
	.rbto_compare_key = plist_compare_key,
	.rbto_node_offset = offsetof(struct plist_pair_entry, pair_node),
	.rbto_context = NULL,
};

/* plist_tree_singleton */

static struct plist_tree_type {
	rb_tree_t plist_tree;
	rb_tree_t plist_vars_tree;
	int initialized;
	regex_t plist_regex_options;
} plist_tree_singleton = {
	.initialized = 0
};

void
plist_tree_init(void)
{
	int ret;

	assert(plist_tree_singleton.initialized == 0);

	rb_tree_init(&plist_tree_singleton.plist_tree, &plist_tree_ops);
	rb_tree_init(&plist_tree_singleton.plist_vars_tree, &plist_tree_ops);

#define MAX_ERROR_MSG 0x1000
#define REGEX_STRING_PLIST "\\${PLIST.[^}]*}"

	if ((ret = regcomp(&plist_tree_singleton.plist_regex_options,
	                   REGEX_STRING_PLIST, REG_EXTENDED)) != 0) {
		char error_message[MAX_ERROR_MSG];
		regerror(ret, &plist_tree_singleton.plist_regex_options,
		         error_message, MAX_ERROR_MSG);
		errx(EXIT_FAILURE, "Regex error compiling '%s': %s\n",
		                   REGEX_STRING_PLIST, error_message);
	}

	plist_tree_singleton.initialized = 1;
}

char *
get_key(const char *entry)
{
	char *copy;
	size_t n = 0;
	char *s;
	regmatch_t rm[10];
	int ret;
	size_t i;

	assert(entry);

	/* 1. Strip all ${PLIST.option}-like strings */
	ret = regexec(&plist_tree_singleton.plist_regex_options, entry,
	              sizeof(rm)/sizeof(rm[0]), rm, 0);
	if (!ret) { /* Something found! */
		/* Set pointer just after the matched string */
		for(i = 0; i < sizeof(rm)/sizeof(rm[0]); i++) {
			if (rm[i].rm_so == -1)
				break;

			n = rm[i].rm_eo;
		}
	}

	/* Set copy that now contains an entry with removed '${PLIST.*}' */
	copy = strdup(entry + n);
	if (copy == NULL)
		err(EXIT_FAILURE, "strdup");

	return copy;
}

int
plist_tree_insert(const char *entry)
{
	struct plist_pair_entry *pair;
	struct plist_pair_entry *opair;

	assert(plist_tree_singleton.initialized == 1);
	assert(entry);
	assert(entry[0]);

	pair = malloc(sizeof(*pair));
	if (pair == NULL)
		err(EXIT_FAILURE, "malloc");

	pair->first = get_key(entry);
	if (pair->first == NULL)
		err(EXIT_FAILURE, "malloc");
	pair->second = strndup(entry, MAXPATHLEN * 2);
	if (pair->second == NULL)
		err(EXIT_FAILURE, "malloc");

	opair = rb_tree_insert_node(&plist_tree_singleton.plist_tree, pair);
	if (opair != pair) {
		warnx("Duplicate entry detected key='%s' value='%s' "
		      "(okey='%s' ovalue='%s') -- skipping",
		      pair->first, pair->second, opair->first, opair->second);
		free(pair->first);
		free(pair->second);
		free(pair);

		return -1;
	}

	return 0;
}

int
plist_tree_remove(const char *entry)
{
	struct plist_pair_entry *pair;

	assert(plist_tree_singleton.initialized == 1);
	assert(entry);

	pair = rb_tree_find_node(&plist_tree_singleton.plist_tree, entry);
	if (pair == NULL) {
		warnx("Cannot remove entry='%s' -- not found", entry);
		return -1;
	}

	assert(pair->first);
	assert(pair->first[0]);
	assert(pair->second);
	assert(pair->second[0]);

        rb_tree_remove_node(&plist_tree_singleton.plist_tree, pair);

	free(pair->first);
	free(pair->second);
	free(pair);

	return 0;
}

int
plist_tree_dump(FILE *stream)
{
	struct plist_pair_entry *pair;

	assert(stream);
        assert(plist_tree_singleton.initialized == 1);

	RB_TREE_FOREACH(pair, &plist_tree_singleton.plist_tree) {
		assert(pair);
		assert(pair->first);
		assert(pair->first[0]);
		assert(pair->second);
		assert(pair->second[0]);

		fprintf(stream, "%s\n", pair->second);
	}

	return 0;
}
