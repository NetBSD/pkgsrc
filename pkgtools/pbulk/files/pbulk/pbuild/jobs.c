/* $NetBSD: jobs.c,v 1.11 2010/02/26 16:25:49 joerg Exp $ */

/*-
 * Copyright (c) 2007, 2009 Joerg Sonnenberger <joerg@NetBSD.org>.
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

#include <nbcompat/stat.h>
#include <nbcompat/err.h>
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <nbcompat/stdio.h>
#include <nbcompat/stdlib.h>
#include <nbcompat/string.h>
#include <nbcompat/time.h>
#include <nbcompat/unistd.h>

#include "pbulk.h"
#include "pbuild.h"

static int post_initial;

static int log_success;
static int log_failed;

SLIST_HEAD(buildhash, build_job);

static void build_tree(void);
static void mark_initial(void);
static struct buildhash *get_hash_chain(const char *);
static void hash_entries(void);
static void add_to_build_list(struct build_job *);

static struct build_job *jobs;
static size_t allocated_jobs, len_jobs;
static char *scan_output_content;

static TAILQ_HEAD(, build_job) buildable_jobs;

static void
ts_printf(const char *fmt, ...)
{
	struct tm *tm;
	time_t now;
	va_list ap;
	char buf[512];
	struct build_stat st;

	if (verbosity >= 2) {
		now = time(NULL);
		tm = localtime(&now);
		if (strftime(buf, sizeof(buf), "%F %R", tm) == 0)
			errx(1, "Formatted time doesn't fit into buffer");

		(void)printf("%s ", buf);
	}

	if (verbosity >= 1) {
		build_stats(&st);
		printf("[%lu/%lu] ", (unsigned long)len_jobs - st.open_jobs,
		    (unsigned long)len_jobs);
	}

	va_start(ap, fmt);
	(void)vprintf(fmt, ap);
	va_end(ap);
	(void)fflush(stdout);
}

static const char *
find_content(struct build_job *job, const char *prefix)
{
	size_t len = strlen(prefix);
	const char *line;

	for (line = job->begin; line != job->end; line = strchr(line, '\n') + 1) {
		if (strncmp(line, prefix, len) == 0)
			return line + len;
	}
	return NULL;
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

SLIST_HEAD(depth_tree_head, build_job);

static void
compute_tree_depth_rec(struct build_job *job, struct build_job *root,
    struct depth_tree_head *head, int *count)
{
	struct dependency_list *dep_iter;
	struct build_job *job_iter;

	if (job == root && *count != 0)
		errx(1, "Cyclic dependency for package %s", job->pkgname);

	SLIST_FOREACH(job_iter, head, depth_tree_link) {
		if (job_iter == job)
			return;
	}
	SLIST_INSERT_HEAD(head, job, depth_tree_link);
	*count = *count + 1;
	SLIST_FOREACH(dep_iter, &job->depending_pkgs, depends_link)
		compute_tree_depth_rec(dep_iter->dependency, root, head, count);
}

static void
compute_tree_depth(struct build_job *job)
{
	struct depth_tree_head head;

	SLIST_INIT(&head);
	job->pkg_depth = 0;
	compute_tree_depth_rec(job, job, &head, &job->pkg_depth);
}

void
init_jobs(const char *scan_output, const char *success_file, const char *error_file)
{
	char *input;
	const char *input_iter;
	int fd;
	size_t i;

	TAILQ_INIT(&buildable_jobs);

	if ((fd = open(scan_output, O_RDONLY, 0)) == -1)
		err(1, "Cannot open input");

	log_success = open(success_file, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (log_success == -1)
		err(1, "Cannot open log file for successful builds");

	log_failed = open(error_file, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (log_failed == -1)
		err(1, "Cannot open log file for failed builds");

	input = read_from_file(fd);
	(void)close(fd);

	if (allocated_jobs == 0) {
		allocated_jobs = 1024;
		jobs = xmalloc(allocated_jobs * sizeof(*jobs));
	}

	input_iter = input;
	while ((jobs[len_jobs].pkgname = pkgname_dup(input_iter)) != NULL) {
		jobs[len_jobs].begin = input_iter;
		jobs[len_jobs].end = pbulk_item_end(input_iter);
		jobs[len_jobs].state = JOB_INIT;
		jobs[len_jobs].open_depends = 0;
		SLIST_INIT(&jobs[len_jobs].depending_pkgs);
		if (jobs[len_jobs].end == NULL)
			errx(1, "Invalid input");
		input_iter = jobs[len_jobs].end;
		++len_jobs;
		if (len_jobs == allocated_jobs) {
			allocated_jobs *= 2;
			jobs = xrealloc(jobs, allocated_jobs * sizeof(*jobs));
		}
	}

	if (*input_iter != '\0')
		errx(1, "Invalid input");
	scan_output_content = input;

	hash_entries();
	build_tree();

	for (i = 0; i < len_jobs; ++i)
		compute_tree_depth(&jobs[i]);

	mark_initial();

	for (i = 0; i < len_jobs; ++i) {
		if (jobs[i].state == JOB_INIT)
			process_job(&jobs[i], JOB_OPEN, 0);
	}
}

static void
mark_initial_state(int fd, enum job_state state, const char *type)
{
	char *input;
	const char *input_iter;
	struct build_job *iter;
	size_t len;

	input = read_from_file(fd);
	input_iter = input;

	while (*input_iter != '\0') {
		len = strcspn(input_iter, "\n");
		SLIST_FOREACH(iter, get_hash_chain(input_iter), hash_link) {
			if (strncmp(iter->pkgname, input_iter, len) == 0 &&
			    iter->pkgname[len] == '\0')
				break;
		}
		if (iter == NULL)
			errx(1, "Package from %s build log doesn't exist: %.*s", type, (int)len, input_iter);

		process_job(iter, state, 0);

		input_iter = strchr(input_iter, '\n');
		if (input_iter == NULL)
			errx(1, "Invalid input");		
		++input_iter;
	}
	free(input);
}

static void
mark_initial(void)
{
	const char *line;
	size_t i;

	for (i = 0; i < len_jobs; ++i) {
		if ((line = find_content(&jobs[i], "PKG_SKIP_REASON=")) == NULL)
			errx(1, "Invalid scan output");
		if (*line != '\n') {
			process_job(&jobs[i], JOB_PREFAILED, 0);
			continue;
		}
		if ((line = find_content(&jobs[i], "PKG_FAIL_REASON=")) == NULL)
			errx(1, "Invalid scan output");
		if (*line != '\n') {
			process_job(&jobs[i], JOB_PREFAILED, 0);
			continue;
		}
	}		

	mark_initial_state(log_success, JOB_DONE, "successful");
	mark_initial_state(log_failed, JOB_FAILED, "failing");

	if (verbosity >= 1)
		printf("Initialisation complete.\n");
	post_initial = 1;
}

static void
add_to_build_list(struct build_job *job)
{
	struct build_job *iter;

	TAILQ_FOREACH(iter, &buildable_jobs, build_link) {
		if (iter->pkg_depth < job->pkg_depth) {
			TAILQ_INSERT_BEFORE(iter, job, build_link);
			return;
		}
	}
	TAILQ_INSERT_TAIL(&buildable_jobs, job, build_link);
}

static void
build_tree(void)
{
	size_t i, len;
	struct build_job *iter, *job;
	struct dependency_list *dep;
	const char *depends;

	for (i = 0; i < len_jobs; ++i) {
		job = &jobs[i];

		if ((depends = find_content(job, "DEPENDS=")) == NULL)
			continue;

		depends += strspn(depends, " \t");

		while ((len = strcspn(depends, " \t\n")) != 0) {
			SLIST_FOREACH(iter, get_hash_chain(depends), hash_link) {
				if (strncmp(iter->pkgname, depends, len) == 0 &&
				    iter->pkgname[len] == '\0')
					break;
			}
			if (iter == NULL)
				errx(1, "Dependency `%.*s' doesn't exist", (int)strcspn(depends, " \t\n"), depends);

			dep = xmalloc(sizeof(*dep));
			dep->dependency = job;
			SLIST_INSERT_HEAD(&iter->depending_pkgs, dep, depends_link);
			++job->open_depends;

			depends += len;
			depends += strspn(depends, " \t");
		}
	}
}

struct build_job *
get_job(void)
{
	struct build_job *job;

	if ((job = TAILQ_FIRST(&buildable_jobs)) != NULL) {
		TAILQ_REMOVE(&buildable_jobs, job, build_link);

		process_job(job, JOB_IN_PROCESSING, 0);
	}
	return job;
}

static void
recursive_mark_broken(struct build_job *job, enum job_state state)
{
	struct dependency_list *iter;

	SLIST_FOREACH(iter, &job->depending_pkgs, depends_link) {
		if (iter->dependency->state == JOB_OPEN ||
		    iter->dependency->state == JOB_INIT)
			process_job(iter->dependency, state, 0);
	}	
}

/**
 * Changes the state of the ''job'' to ''state'' and runs some code
 * depending on the new state. If ''log_state'' is non-zero, the package
 * name is written to either the "error" or the "success" log, depending
 * on the ''state''.
 */
void
process_job(struct build_job *job, enum job_state state, int log_state)
{
	struct dependency_list *iter;
	char *buf;

	job->state = state;

	switch (state) {
	case JOB_INIT:
		errx(1, "Programming error");
	case JOB_DONE:
		SLIST_FOREACH(iter, &job->depending_pkgs, depends_link) {
			--iter->dependency->open_depends;
			if (iter->dependency->open_depends == 0 &&
			    iter->dependency->state == JOB_OPEN)
				add_to_build_list(iter->dependency);
		}
		if (log_state) {
			buf = xasprintf("%s\n", job->pkgname);
			if (write(log_success, buf, strlen(buf)) == -1)
				err(1, "Cannot log successful build");
			free(buf);
		}
		if (verbosity >= 1 && post_initial)
			ts_printf("Successfully built %s\n", job->pkgname);
		break;
	case JOB_FAILED:
		if (log_state) {
			buf = xasprintf("%s\n", job->pkgname);
			if (write(log_failed, buf, strlen(buf)) == -1)
				err(1, "Cannot log failed build");
			free(buf);
		}
		if (verbosity >= 1 && post_initial)
			ts_printf("Failed to build    %s\n", job->pkgname);
		/* FALLTHROUGH */
	case JOB_INDIRECT_FAILED:
		recursive_mark_broken(job, JOB_INDIRECT_FAILED);
		break;
	case JOB_PREFAILED:
	case JOB_INDIRECT_PREFAILED:
		/* FALLTHROUGH */
		recursive_mark_broken(job, JOB_INDIRECT_PREFAILED);
		break;
	case JOB_IN_PROCESSING:
		if (verbosity >= 1)
			ts_printf("Starting build of  %s\n", job->pkgname);
		break;
	case JOB_OPEN:
		if (job->open_depends == 0)
			add_to_build_list(job);
		break;
	}
}

void
build_stats(struct build_stat *st)
{
	size_t i;

	st->open_jobs = 0;
	st->in_processing = 0;
	st->failed = 0;
	st->prefailed = 0;
	st->indirect_failed = 0;
	st->indirect_prefailed = 0;
	st->done = 0;

	for (i = 0; i < len_jobs; ++i) {
		switch (jobs[i].state) {
		case JOB_DONE:
			++st->done;
			break;
		case JOB_FAILED:
			++st->failed;
			break;
		case JOB_PREFAILED:
			++st->prefailed;
			break;
		case JOB_INDIRECT_FAILED:
			++st->indirect_failed;
			break;
		case JOB_INDIRECT_PREFAILED:
			++st->indirect_prefailed;
			break;
		case JOB_OPEN:
			++st->open_jobs;
			break;
		case JOB_IN_PROCESSING:
			++st->in_processing;
			break;
		case JOB_INIT:
			break;
		}
	}
}

void
finish_build(const char *report_file)
{
	FILE *report;
	size_t i;
	const char *status;

	if ((report = fopen(report_file, "w")) == NULL)
		err(1, "Cannot open report file");

	for (i = 0; i < len_jobs; ++i) {
		switch (jobs[i].state) {
		case JOB_DONE:
			status = "done";
			break;
		case JOB_FAILED:
			status = "failed";
			break;
		case JOB_PREFAILED:
			status = "prefailed";
			break;
		case JOB_INDIRECT_FAILED:
			status = "indirect-failed";
			break;
		case JOB_INDIRECT_PREFAILED:
			status = "indirect-prefailed";
			break;
		case JOB_OPEN:
			status = "open";
			break;
		case JOB_IN_PROCESSING:
			status = "in_processing";
			break;
		default:
			errx(1, "internal error");
		}
		fprintf(report, "%s|%s||%d\n", jobs[i].pkgname, status,
		    jobs[i].pkg_depth);
	}
}

#define	HASH_SIZE 4096
#define	HASH_ITEM(x) (((unsigned char)(x)[0] + (unsigned char)(x)[1] * 257 + (unsigned char)(x)[1] * 65537) & (HASH_SIZE - 1))

static struct buildhash hash_table[HASH_SIZE];

static void
hash_entries(void)
{
	size_t i, hash;

	for (i = 0; i < HASH_SIZE; ++i)
		SLIST_INIT(&hash_table[i]);

	for (i = 0; i < len_jobs; ++i) {
		hash = HASH_ITEM(jobs[i].pkgname);
		SLIST_INSERT_HEAD(&hash_table[hash], &jobs[i], hash_link);
	}
}

static struct buildhash *
get_hash_chain(const char *pkgname)
{
	return &hash_table[HASH_ITEM(pkgname)];
}
