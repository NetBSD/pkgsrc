/* $NetBSD: jobs.c,v 1.1.1.1 2007/06/19 19:49:57 joerg Exp $ */

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

#include <sys/uio.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pbulk.h"
#include "pscan.h"

#define UNCONST(x) ((void *)(uintptr_t)(x))

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

	location = xasprintf("%.*s/%.*s", (int)cat_len, cat, dir_len, dir);
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

struct scan_job *
get_job(void)
{
	size_t i;

	for (i = first_undone_job; i < len_jobs; ++i) {
		if (jobs[i].state == JOB_OPEN) {
			jobs[i].state = JOB_IN_PROCESSING;
			return &jobs[i];
		}
	}

	return NULL;
}

void
process_job(struct scan_job *job, enum job_state state)
{
	job->state = state;

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
				(void)printf(". %zd/%zd\n", done_jobs, len_jobs);
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

#define	HASH_SIZE 1024
#define	HASH_ITEM(x) (((unsigned char)(x)[0] + (unsigned char)(x)[1] * 257) & (HASH_SIZE - 1))

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
			(void)printf(" %zd/%zd\n", done_jobs, len_jobs);
		(void)fflush(stdout);
	}

	fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);

	for (i = 0; i < len_jobs; ++i) {
		if (jobs[i].state != JOB_DONE) {
			warnx("%s was not processed", jobs[i].pkg_location);
			continue;
		}
		if (jobs[i].scan_output == NULL) {
			warnx("Scan failed for %s", jobs[i].pkg_location);
			continue;
		}
		write_single_job(fd, jobs[i].scan_output, jobs + i);
	}
}
