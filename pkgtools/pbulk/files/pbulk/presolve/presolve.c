/* $NetBSD: presolve.c,v 1.1.1.1 2007/06/19 19:49:57 joerg Exp $ */

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

#include <sys/queue.h>
#include <sys/stat.h>
#include <ctype.h>
#include <err.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pbulk.h"

static int verbosity;
static FILE *incremental = NULL;

static void
usage(void)
{
	(void)fprintf(stderr, "usage: pbulk-resolve [ -i <missing> ] [ -v ] <pscan output> [ ... ]\n");
	exit(1);
}

SLIST_HEAD(pkg_entry_hash, pkg_entry);

struct pkg_entry {
	char *pkgname;
	char *depends;
	char *pkglocation;
	int active;
	const char *begin;
	const char *end;
	SLIST_ENTRY(pkg_entry) hash_link;
} *pkgs;

size_t len_pkgs, allocated_pkgs;

static char		*pkgname_dup(const char *);
static const char	*pbulk_item_end(const char *);
static void		 read_entries(const char *, int);
static int		 resolve_entry(struct pkg_entry *);
static void		 write_entries(void);
static void		 hash_entries(void);
static struct pkg_entry_hash *get_hash_chain(const char *);

int
main(int argc, char **argv)
{
	size_t i;
	int ch, ret;

	while ((ch = getopt(argc, argv, "i:v")) != -1) {
		switch (ch) {
		case 'i':
			if (incremental != NULL)
				(void)fclose(incremental);
			if ((incremental = fopen(optarg, "w")) == NULL)
				err(1, "Cannot open output file");
			break;
		case 'v':
			++verbosity;
			break;
		default:
			usage();
		}
	}

	argc -= optind;
	argv += optind;

	if (argc == 0 || (incremental == NULL && argc > 1))
		usage();

	read_entries(argv[0], 1);
	while (--argc > 0)
		read_entries(*++argv, 0);

	hash_entries();

	ret = 0;
	for (i = 0; i < len_pkgs; ++i) {
		if (resolve_entry(&pkgs[i]))
			ret = 1;
	}

	if (ret == 0)
		write_entries();

	return ret;
}

static const char *
find_content(struct pkg_entry *pkg, const char *prefix)
{
	size_t len = strlen(prefix);
	const char *line;

	for (line = pkg->begin; line != pkg->end; line = strchr(line, '\n') + 1) {
		if (strncmp(line, prefix, len) == 0)
			return line + len;
	}
	return NULL;
}

static void
log_multi_match(const char *pattern, const char *pkgname, const char *match)
{
	if (verbosity < 2)
		return;
	warnx("Multiple matches for dependency %s of package %s: %s", pattern, pkgname, match);
}

static void
find_match_iter(const char *pattern, const char *pkgname, struct pkg_entry **best, struct pkg_entry *cur, size_t *matches)
{
	if (pkg_match(pattern, cur->pkgname) == 0)
		return;
	if (*matches == 0) {
		*best = cur;
		++(*matches);
		return;
	}

	if (*matches == 1)
		log_multi_match(pattern, pkgname, (*best)->pkgname);
	log_multi_match(pattern, pkgname, (*best)->pkgname);

	if (pkg_order((*best)->pkgname, cur->pkgname) == cur->pkgname)
		*best = cur;
	++(*matches);
}

static void
validate_best_match(struct pkg_entry *match, const char *location,
    const char *pattern, const char *pkgname)
{
	if (verbosity < 1 || incremental != NULL)
		return;
	if (strcmp(match->pkglocation, location) != 0) {
		warnx("Best matching %s differs from location %s for dependency %s of package %s",
		    match->pkgname, location, pattern, pkgname);
	}
}

static struct pkg_entry *
find_match(const char *pkgname, const char *pattern, const char *location)
{
	size_t matches;
	struct pkg_entry *best;

	best = NULL;
	matches = 0;

	if ((isalnum((unsigned char)pattern[0]) || pattern[0] == '-') &&
	    (isalnum((unsigned char)pattern[1]) || pattern[1] == '-') &&
	    (isalnum((unsigned char)pattern[2]) || pattern[2] == '-') &&
	    (isalnum((unsigned char)pattern[3]) || pattern[3] == '-') &&
	    strchr(pattern, '{') == NULL) {
		struct pkg_entry *iter;

		SLIST_FOREACH(iter, get_hash_chain(pattern), hash_link)
			find_match_iter(pattern, pkgname, &best, iter, &matches);
	} else {
		size_t i;

		for (i = 0; i < len_pkgs; ++i)
			find_match_iter(pattern, pkgname, &best, &pkgs[i], &matches);
	}

	if (matches == 0) {
		if (incremental != NULL)
			(void)fprintf(incremental, "%s\n", location);
		else
			warnx("No match found for dependency %s of package %s", pattern, pkgname);
		return NULL;
	}
	validate_best_match(best, location, pattern, pkgname);
	return best;
}

static int
resolve_entry(struct pkg_entry *pkg)
{
	const char *line, *pattern_begin, *pattern_end, *location_begin;
	char *pattern, *location, *old_depends;
	struct pkg_entry *best_match;
	struct pkg_entry **depends_list;
	size_t i;
	int ret;

	if (pkg->active == 0)
		return 0;

	if (find_content(pkg, "DEPENDS=") != NULL)
		return 0;

	ret = 0;

	if ((line = find_content(pkg, "ALL_DEPENDS=")) == NULL)
		errx(1, "No ALL_DEPENDS line for %s", pkg->pkgname);

	depends_list = xmalloc(sizeof(struct pkg_entry *));
	depends_list[0] = NULL;

	line += strspn(line, " \t");

	while (*line != '\n') {
		pattern_begin = line;
		pattern_end = location_begin = strchr(pattern_begin, ':');
		if (location_begin == NULL ||
		    strncmp(location_begin, ":../../", 7) != 0) {
			free(depends_list);
			warnx("Incorrect dependency for %s, skipping", pkg->pkgname);
			return 1;
		}
		location_begin += 7;
		line = location_begin + strcspn(location_begin, " \t\n");
		pattern = xstrndup(pattern_begin, pattern_end - pattern_begin);
		location = xstrndup(location_begin, line - location_begin);
		line += strspn(line, " \t");

		for (i = 0; depends_list[i] != NULL; ++i) {
			if (pkg_match(pattern, depends_list[i]->pkgname))
				break;
		}
		if (depends_list[i] != NULL) {
			/*
			 * If we already have a match, assume that it is most
			 * likely stricter than this one. The best match check
			 * was therefore already done.
			 */
			if (strcmp(depends_list[i]->pkglocation, location) != 0)
				validate_best_match(depends_list[i], location, pattern, pkg->pkgname);
			best_match = NULL; /* XXX For GCC */
		} else
			best_match = find_match(pkg->pkgname, pattern, location);
		free(pattern);
		free(location);

		if (depends_list[i] != NULL)
			continue;

		if (best_match == NULL) {
			ret = 1;
			continue;
		}

		depends_list = xrealloc(depends_list, (i + 2) * sizeof(struct pkg_entry *));
		depends_list[i] = best_match;
		depends_list[i + 1] = NULL;

		if (pkg->depends == NULL)
			pkg->depends = xstrdup(best_match->pkgname);
		else {
			old_depends = pkg->depends;
			pkg->depends = xasprintf("%s %s", old_depends, best_match->pkgname);
			free(old_depends);
		}

		best_match->active = 1;
	}

	free(depends_list);
	if (ret == 1) {
		free(pkg->depends);
		pkg->depends = NULL;
		if (incremental != NULL)
			return 0;
		else
			return 1;
	}
	return 0;
}

static char *
pkgname_dup(const char *line)
{
	const char *pkgname;
	char *pkgname_end;
	size_t pkgname_len;

	if (strncmp(line, "PKGNAME=", 8) != 0)
		return NULL;
	pkgname = line + 8;
	pkgname_end = strchr(pkgname, '\n');
	pkgname_len = pkgname_end - pkgname;
	if (pkgname_end == NULL || pkgname_len < 4 ||
	    strcspn(pkgname, " \t\n") != pkgname_len)
		return NULL;
	return xstrndup(pkgname, pkgname_len);
}

static const char *
pbulk_item_end(const char *line)
{
	const char *line_end;

	do {
		line_end = strchr(line, '\n');
		if (line_end == NULL)
			return NULL;
		line = line_end + 1;
		if (strncmp(line, "PKGNAME=", 8) == 0)
			return line;
	} while (*line != '\0');

	return line;
}

static void
read_entries(const char *input_file, int def_active)
{
	char *input;
	const char *input_iter;
	const char *location_line, *location_line_end;
	int fd;

	if ((fd = open(input_file, O_RDONLY, 0)) == -1)
		err(1, "Cannot open input");

	input = read_from_file(fd);
	(void)close(fd);

	if (allocated_pkgs == 0) {
		allocated_pkgs = 1024;
		pkgs = xmalloc(allocated_pkgs * sizeof(*pkgs));
	}

	input_iter = input;
	while ((pkgs[len_pkgs].pkgname = pkgname_dup(input_iter)) != NULL) {
		pkgs[len_pkgs].active = def_active;
		pkgs[len_pkgs].begin = input_iter;
		pkgs[len_pkgs].end = pbulk_item_end(input_iter);
		pkgs[len_pkgs].depends = NULL;
		if (pkgs[len_pkgs].end == NULL)
			errx(1, "Invalid input");
		input_iter = pkgs[len_pkgs].end;
		location_line = find_content(&pkgs[len_pkgs], "PKG_LOCATION=");
		if (location_line == NULL)
			errx(1, "Invalid input");
		location_line_end = strchr(location_line, '\n');
		if (location_line_end == NULL)
			errx(1, "Invalid input");
		pkgs[len_pkgs].pkglocation = xstrndup(location_line, location_line_end - location_line);
		++len_pkgs;
		if (len_pkgs == allocated_pkgs) {
			allocated_pkgs *= 2;
			pkgs = xrealloc(pkgs, allocated_pkgs * sizeof(*pkgs));
		}
	}

	if (*input_iter != '\0')
		errx(1, "Invalid input");
}

static void
write_entries(void)
{
	size_t i;

	for (i = 0; i < len_pkgs; ++i) {
		if (pkgs[i].active == 0)
			continue;
		(void)fwrite(pkgs[i].begin, 1, pkgs[i].end - pkgs[i].begin, stdout);
		if (pkgs[i].depends != NULL)
			(void)printf("DEPENDS=%s\n", pkgs[i].depends);
	}
}

#define	HASH_SIZE 4096
#define	HASH_ITEM(x) (((unsigned char)(x)[0] + (unsigned char)(x)[1] * 257 + (unsigned char)(x)[1] * 65537) & (HASH_SIZE - 1))

static struct pkg_entry_hash hash_table[HASH_SIZE];

static void
hash_entries(void)
{
	size_t i, hash;

	for (i = 0; i < HASH_SIZE; ++i)
		SLIST_INIT(&hash_table[i]);

	for (i = 0; i < len_pkgs; ++i) {
		hash = HASH_ITEM(pkgs[i].pkgname);
		SLIST_INSERT_HEAD(&hash_table[hash], &pkgs[i], hash_link);
	}
}

static struct pkg_entry_hash *
get_hash_chain(const char *pkgname)
{
	return &hash_table[HASH_ITEM(pkgname)];
}
