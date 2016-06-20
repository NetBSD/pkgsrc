/* $NetBSD: jobs.c,v 1.9 2016/06/20 17:54:43 joerg Exp $ */

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

#include <sys/uio.h>
#include <nbcompat/err.h>
#include <fcntl.h>
#include <nbcompat/stdio.h>
#include <nbcompat/stdlib.h>
#include <nbcompat/string.h>
#include <nbcompat/unistd.h>

#include "pbulk.h"
#include "pscan.h"

#define UNCONST(x) ((void *)(uintptr_t)(x))

#define	STAT_HASH_SIZE	131072
#define	HASH_SIZE 32768

struct stat_cache {
	char *path;
	time_t mtime;
	SLIST_ENTRY(stat_cache) hash_link;
};
SLIST_HEAD(stat_cache_hash, stat_cache);

static struct stat_cache_hash stat_hash_table[STAT_HASH_SIZE];

static time_t
stat_path(const char *path)
{
	size_t val = djb_hash(path) % STAT_HASH_SIZE;
	struct stat_cache_hash *h = &stat_hash_table[val];
	struct stat_cache *e;
	struct stat sb;

	SLIST_FOREACH(e, h, hash_link) {
		if (strcmp(path, e->path) == 0)
			return e->mtime;
	}
	e = xmalloc(sizeof(*e));
	e->path = xstrdup(path);
	if (stat(path, &sb) == -1)
		e->mtime = -1;
	else
		e->mtime = sb.st_mtime;
	SLIST_INSERT_HEAD(h, e, hash_link);
	return e->mtime;
}

struct scan_entry {
	char *location;
	char *data;
	char *scan_depends;
	SLIST_ENTRY(scan_entry) hash_link;
};
SLIST_HEAD(scan_entry_hash, scan_entry);

static struct scan_entry_hash hash_table[HASH_SIZE];
static time_t scan_mtime;

static size_t
hash_entry(const char *path)
{
	return djb_hash(path) % HASH_SIZE;
}

static size_t
hash_entry2(const char *path, const char *path_end)
{

	return djb_hash2(path, path_end) % HASH_SIZE;
}

static void
add_entry(const char *l_start, const char *l_end,
	  const char *s_start, const char *s_end,
          const char *d_start, const char *d_end)
{
	struct scan_entry *e;
	struct scan_entry_hash *h;

	if (l_start == l_end)
		errx(1, "Location entry missing");

	h = &hash_table[hash_entry2(l_start, l_end)];
	SLIST_FOREACH(e, h, hash_link) {
		if (strncmp(e->location, l_start, l_end - l_start) == 0 &&
		    e->location[l_end - l_start] == '\0') {
			size_t l1, l2, l3;
			l1 = strlen(e->data);
			l2 = d_end - d_start;
			l_start -= 13;
			++l_end;
			l3 = l_start - d_start;
			e->data = xrealloc(e->data, l1 + l2 + 1);
			memcpy(e->data + l1, d_start, l3);
			memcpy(e->data + l1 + l3, l_end, d_end - l_end);
			e->data[l1 + l3 + d_end - l_end] = '\0';
			return;
		}
	}
	e = xmalloc(sizeof(*e));
	e->location = xstrndup(l_start, l_end - l_start);
	e->data = xmalloc(d_end - d_start + 1);
	l_start -= 13;
	++l_end;
	memcpy(e->data, d_start, l_start - d_start);
	memcpy(e->data + (l_start - d_start), l_end, d_end - l_end);
	e->data[l_start - d_start + d_end - l_end] = '\0';

	if (s_start != s_end)
		e->scan_depends = xstrndup(s_start, s_end - s_start);
	else
		e->scan_depends = NULL;
	SLIST_INSERT_HEAD(h, e, hash_link);
}

void
read_old_scan(const char *path)
{
	size_t i;
	int fd;
	char *buf;
	struct stat sb;
	const char *entry_start;
	const char *l_start, *l_end;
	const char *s_start, *s_end;
	const char *line, *eol;

	for (i = 0; i < HASH_SIZE; ++i)
		SLIST_INIT(&hash_table[i]);

	if (path == NULL)
		return;
	if ((fd = open(path, O_RDONLY)) == -1)
		return;
	if (fstat(fd, &sb) == -1) {
		close(fd);
		return;
	}
	scan_mtime = sb.st_mtime;
	buf = read_from_file(fd);
	entry_start = buf;
	l_start = l_end = NULL;
	entry_start = buf;
	s_start = s_end = NULL;
	for (line = buf; *line; line = eol) {
		eol = strchr(line, '\n');
		if (eol == NULL)
			errx(1, "Incomplete old scan");
		++eol;
		if (strncmp(line, "PKGNAME=", 8) == 0) {
			if (line == buf)
				continue;
			add_entry(l_start, l_end, s_start, s_end,
			    entry_start, line);
			l_start = l_end = NULL;
			entry_start = line;
			s_start = s_end = NULL;
		} else if (strncmp(line, "PKG_LOCATION=", 13) == 0) {
			l_start = line + 13;
			l_end = eol - 1;
		} else if (strncmp(line, "SCAN_DEPENDS=", 13) == 0) {
			s_start = line + 13;
			s_end = eol - 1;
		}
	}
	if (entry_start != line)
		add_entry(l_start, l_end, s_start, s_end,
		    entry_start, line);
}

static struct scan_entry *
find_old_scan(const char *location)
{
	struct scan_entry *e;
	char *dep, *dep2, *path, *fullpath;
	int is_current;
	time_t mtime;

	e = SLIST_FIRST(&hash_table[hash_entry(location)]);
	while (e) {
		if (strcmp(e->location, location) == 0)
			break;
		e = SLIST_NEXT(e, hash_link);
	}
	if (e == NULL)
		return NULL;

	if (e->scan_depends == NULL)
		return e;

	is_current = 1;
	dep2 = dep = xstrdup(e->scan_depends);
	while ((path = strtok(dep, " ")) != NULL) {
		dep = NULL;
		if (*path == '\0')
			continue;
		if (*path == '/') {
			mtime = stat_path(path);
			if (mtime == -1 || mtime >= scan_mtime) {
				is_current = 0;
				break;
			}
			continue;
		}
		if (strncmp("../../", path, 6) == 0) {
			const char *s1 = strrchr(location, '/');
			const char *s2 = strchr(location, '/');
			if (s1 == s2)
				fullpath = xasprintf("%s/%s", pkgsrc_tree,
				    path + 6);
			else
				fullpath = xasprintf("%s/%s/%s", pkgsrc_tree,
				    location, path);
		} else {
			fullpath = xasprintf("%s/%s/%s", pkgsrc_tree,
			    location, path);
		}
		mtime = stat_path(fullpath);
		if (mtime == -1 || mtime >= scan_mtime) {
			is_current = 0;
			break;
		}
	}
	free(dep2);
	return is_current ? e : NULL;
}

static struct scan_job *jobs;
static size_t len_jobs, allocated_jobs, first_undone_job, done_jobs;

struct pkgname_hash {
	struct pkgname_hash *next;
	char *pkgname;
};

void
add_job(const char *cat, size_t cat_len, const char *dir, size_t dir_len)
{
	char *location;

	location = xasprintf("%.*s/%.*s", (int)cat_len, cat, (int)dir_len, dir);
	add_job_full(location);
	free(location);
}

void
add_job_full(const char *location)
{
	if (len_jobs == allocated_jobs) {
		if (allocated_jobs == 0) {
			allocated_jobs = 1024;
			jobs = xmalloc(sizeof(*jobs) * allocated_jobs);
		} else {
			allocated_jobs *= 2;
			jobs = xrealloc(jobs, sizeof(*jobs) * allocated_jobs);
		}
	}
	jobs[len_jobs].pkg_location = xstrdup(location);
	jobs[len_jobs].scan_output = NULL;
	jobs[len_jobs].state = JOB_OPEN;
	++len_jobs;
}

int
has_job(void)
{
	size_t i;
	struct scan_entry *e;
	struct scan_job * job;

	for (i = first_undone_job; i < len_jobs; ++i) {
		job = &jobs[i];
		if (job->state != JOB_OPEN)
			continue;
		e = find_old_scan(job->pkg_location);
		if (e == NULL)
			return 1;
		job->scan_output = xstrdup(e->data);
		process_job(job, JOB_DONE);
		i = first_undone_job - 1;
	}

	return 0;
}

struct scan_job *
get_job(void)
{
	size_t i;
	struct scan_entry *e;
	struct scan_job * job;

	for (i = first_undone_job; i < len_jobs; ++i) {
		job = &jobs[i];
		if (job->state != JOB_OPEN)
			continue;
		e = find_old_scan(job->pkg_location);
		if (e == NULL) {
			job->state = JOB_IN_PROCESSING;
			return job;
		}
		job->scan_output = xstrdup(e->data);
		process_job(job, JOB_DONE);
		i = first_undone_job - 1;
	}

	return NULL;
}

static void
parse_full_tree(char *data) {
	char *eol;

	while (*data) {
		eol = strchr(data, '\n');
		if (eol == NULL)
			err(1, "Incomplete line in full tree list");
		if (data == eol)
			continue;
		*eol = '\0';
		add_job_full(data);
		data = eol + 1;
	}
}

void
process_job(struct scan_job *job, enum job_state state)
{
	job->state = state;

	if (state == JOB_DONE &&
	    strcmp(job->pkg_location, "find_full_tree") == 0) {
		parse_full_tree(job->scan_output);
	}

	for (; first_undone_job < len_jobs; ++first_undone_job) {
		if (jobs[first_undone_job].state != JOB_DONE)
			break;
	}

	if (state == JOB_DONE) {
		++done_jobs;
		if (verbosity >= 1) {
			if (done_jobs % 50)
				(void)putchar('.');
			else
				(void)printf(". %lu/%lu\n",
				    (unsigned long)done_jobs,
				    (unsigned long)len_jobs);
			(void)fflush(stdout);
		}
	}
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
	if (pkgname_end == NULL || pkgname_len < 2 ||
	    strcspn(pkgname, " \t\n") != pkgname_len)
		return NULL;
	return xstrndup(pkgname, pkgname_len);
}

#define	HASH_ITEM(x) (djb_hash(x) % HASH_SIZE)

static struct pkgname_hash *pkgname_hash[HASH_SIZE];

static int
pkgname_in_hash(const char *pkgname)
{
	struct pkgname_hash *iter;

	for (iter = pkgname_hash[HASH_ITEM(pkgname)]; iter != NULL;
	     iter = iter->next) {
		if (strcmp(iter->pkgname, pkgname) == 0)
			return 1;
	}
	return 0;
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
write_single_job(int fd, const char *begin_entry, struct scan_job *job)
{
	struct pkgname_hash *entry;
	const char *end_entry, *end_line;
	char *pkgname;
	int skip_current;
	struct iovec output[5];
	const int iovcnt = 5;
	ssize_t expected;

	for (; begin_entry != NULL && begin_entry[0] != '\0';) {
		pkgname = pkgname_dup(begin_entry);
		if (pkgname == NULL) {
			warnx("pbulk-index output not recognized for %s",
			    job->pkg_location);
			break;
		}

		if (pkgname_in_hash(pkgname)) {
			warnx("Duplicate package: %s", pkgname);
			skip_current = 1;
		} else {
			skip_current = 0;
		}

		end_entry = pbulk_item_end(begin_entry);
		if (end_entry == NULL) {
			free(pkgname);
			warnx("pbulk-index output not recognized for %s",
			    job->pkg_location);
			break;
		}

		if (skip_current == 0) {
			end_line = strchr(begin_entry, '\n');
			if (end_line == NULL || end_line > end_entry)
				errx(254, "internal error");

			output[0].iov_base = UNCONST(begin_entry);
			expected = output[0].iov_len =
			    end_line + 1 - begin_entry;

			output[1].iov_base = UNCONST("PKG_LOCATION=");
			output[1].iov_len = strlen(output[1].iov_base);
			expected += output[1].iov_len;

			output[2].iov_base = job->pkg_location;
			output[2].iov_len = strlen(output[2].iov_base);
			expected += output[2].iov_len;

			output[3].iov_base = UNCONST("\n");
			output[3].iov_len = 1;
			expected += output[3].iov_len;

			output[4].iov_base = UNCONST(end_line + 1);
			output[4].iov_len = end_entry - end_line - 1;
			expected += output[4].iov_len;

			if (writev(fd, output, iovcnt) != expected)
				err(1, "writev failed");

			entry = xmalloc(sizeof(*entry));
			entry->next = pkgname_hash[HASH_ITEM(pkgname)];
			entry->pkgname = pkgname;
			pkgname_hash[HASH_ITEM(pkgname)] = entry;
		} else {
			free(pkgname);
		}
		begin_entry = end_entry;
	}
}

void
write_jobs(const char *output_file)
{
	size_t i;
	int fd;

	if (verbosity >= 1) {
		if (done_jobs % 50)
			(void)printf(" %lu/%lu\n", (unsigned long)done_jobs,
			    (unsigned long)len_jobs);
		(void)fflush(stdout);
	}

	fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);

	for (i = 0; i < len_jobs; ++i) {
		if (jobs[i].state != JOB_DONE) {
			warnx("%s was not processed", jobs[i].pkg_location);
			continue;
		}
		if (strcmp(jobs[i].pkg_location, "find_full_tree") == 0)
			continue;
		if (jobs[i].scan_output == NULL) {
			warnx("Scan failed for %s", jobs[i].pkg_location);
			continue;
		}
		write_single_job(fd, jobs[i].scan_output, jobs + i);
	}
}
