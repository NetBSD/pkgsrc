/* $NetBSD: jobs.c,v 1.20 2023/02/12 21:17:24 joerg Exp $ */

/*-
 * Copyright (c) 2007, 2009, 2011 Joerg Sonnenberger <joerg@NetBSD.org>.
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
static struct buildhash *get_hash_chain(const char *, size_t);
static void hash_entries(void);
static void add_to_build_list(struct build_job *);

static struct build_job *jobs;
static size_t allocated_jobs, len_jobs;
static char *scan_output_content;

static struct build_job **buildable_jobs;
static size_t buildable_jobs_len;

#if defined(__GNUC__) && __GNUC__ >= 2
__attribute__((__format__(__printf__, 1, 2)))
#endif
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

static int
pkgname_dup(struct build_job *job, const char *line)
{
	const char *pkgname;
	char *pkgname_end;
	size_t pkgname_len;

	if (strncmp(line, "PKGNAME=", 8) != 0)
		return 0;
	pkgname = line + 8;
	pkgname_end = strchr(pkgname, '\n');
	pkgname_len = pkgname_end - pkgname;
	if (pkgname_end == NULL || pkgname_len < 4 ||
	    strcspn(pkgname, " \t\n") != pkgname_len)
		return 0;
	job->pkgname = xstrndup(pkgname, pkgname_len);
	job->pkgname_len = pkgname_len;
	return 1;
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

static int
compute_tree_depth_rec(struct build_job *job, struct build_job *root, char *seen)
{
	struct dependency_list *dep_iter;
	struct build_job *job_iter;

	if (job == root && root->pkg_depth != 0) {
		fprintf(stderr, "Cyclic dependency for package:\n%s\n", job->pkgname);
		return -1;
	}

	if (seen[job - jobs])
		return 0;
	seen[job - jobs] = 1;
	++root->pkg_depth;
	root->pkg_weighted_depth += job->pkg_weight;
	SLIST_FOREACH(dep_iter, &job->depending_pkgs, depends_link) {
		if (compute_tree_depth_rec(dep_iter->dependency, root, seen)) {
			fprintf(stderr, "%s\n", job->pkgname);
			return -1;
		}
	}
	return 0;
}

static void
compute_tree_depth(struct build_job *job, char *seen)
{
	memset(seen, 0, len_jobs);

	job->pkg_depth = 0;
	job->pkg_weighted_depth = 0;
	if (compute_tree_depth_rec(job, job, seen))
		exit(1);
}

void
init_jobs(const char *scan_output, const char *success_file, const char *error_file)
{
	char *input, *seen;
	const char *input_iter;
	int fd;
	size_t i;

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
	while (pkgname_dup(&jobs[len_jobs], input_iter)) {
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

	buildable_jobs = xmalloc(len_jobs * sizeof(*buildable_jobs));
	buildable_jobs_len = 0;

	hash_entries();
	build_tree();

	seen = xmalloc(len_jobs);
	for (i = 0; i < len_jobs; ++i)
		compute_tree_depth(&jobs[i], seen);
	free(seen);

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
		SLIST_FOREACH(iter, get_hash_chain(input_iter, len), hash_link) {
			if (iter->pkgname_len == len &&
			    strncmp(iter->pkgname, input_iter, len) == 0)
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
parse_weight(struct build_job *job)
{
	const char *line;
	char *eos;
	long long value;

	line = find_content(job, "PBULK_WEIGHT=");
	if (line == NULL) {
		job->pkg_weight = 100;
		return;
	}
	errno = 0;
	value = strtoll(line, &eos, 10);
	if (errno || line == eos || *eos != '\n')
		errx(1, "Invalid PBULK_WEIGHT for package %s", job->pkgname);
	if (value < 0 && value <= LLONG_MIN / len_jobs)
		errx(1, "PBULK_WEIGHT too small for package %s", job->pkgname);
	if (value > 0 && value >= LLONG_MAX / len_jobs)
		errx(1, "PBULK_WEIGHT too large for package %s", job->pkgname);
	job->pkg_weight = value;
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
swap_buildable_entries(size_t i, size_t j)
{
	struct build_job *job1, *job2;

	job1 = buildable_jobs[i];
	job2 = buildable_jobs[j];
	job1->buildable_index = j;
	job2->buildable_index = i;
	buildable_jobs[i] = job2;
	buildable_jobs[j] = job1;
}

static void
add_to_build_list(struct build_job *job)
{
	size_t idx;

	job->buildable_index = buildable_jobs_len++;
	buildable_jobs[job->buildable_index] = job;
	while ((idx = job->buildable_index)) {
		if (buildable_jobs[(idx - 1) / 2]->pkg_weighted_depth >=
		    job->pkg_weighted_depth)
			break;
		swap_buildable_entries(idx, (idx - 1) / 2);
	}
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

		parse_weight(job);

		if ((depends = find_content(job, "DEPENDS=")) == NULL)
			continue;

		depends += strspn(depends, " \t");

		while ((len = strcspn(depends, " \t\n")) != 0) {
			SLIST_FOREACH(iter, get_hash_chain(depends, len), hash_link) {
				if (iter->pkgname_len == len &&
				    strncmp(iter->pkgname, depends, len) == 0)
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

int
has_job(void)
{
	return buildable_jobs_len != 0;
}

static void
buildable_jobs_remove_head(void)
{
	size_t idx, idx2;

	--buildable_jobs_len;
	if (buildable_jobs_len == 0)
		return;

	/* Move last element to head */
	buildable_jobs[0] = buildable_jobs[buildable_jobs_len];
	buildable_jobs[0]->buildable_index = 0;

	idx = 0;
	for (;;) {
		/* Find biggest child. */
		idx2 = idx;
		if (idx * 2 + 1 < buildable_jobs_len &&
		    buildable_jobs[2 * idx + 1]->pkg_weighted_depth >
		    buildable_jobs[idx2]->pkg_weighted_depth) {
			idx2 = 2 * idx + 1;
		}
		if (idx * 2 + 2 < buildable_jobs_len &&
		    buildable_jobs[2 * idx + 2]->pkg_weighted_depth >
		    buildable_jobs[idx2]->pkg_weighted_depth) {
			idx2 = 2 * idx + 2;
		}
		if (idx == idx2)
			break;
		swap_buildable_entries(idx, idx2);
		idx = idx2;
	}
}

struct build_job *
get_job(void)
{
	struct build_job *job;

	if (buildable_jobs_len == 0)
		return NULL;

	job = buildable_jobs[0];
	process_job(job, JOB_IN_PROCESSING, 0);

	buildable_jobs_remove_head();

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
		fprintf(report, "%s|%s||%d|%lld\n", jobs[i].pkgname, status,
		    jobs[i].pkg_depth, jobs[i].pkg_weighted_depth);
	}
}

#define	HASH_SIZE 4096

static size_t
hash_item(const char *s, size_t len)
{
	return djb_hash2(s, s + len) % HASH_SIZE;
}

static struct buildhash hash_table[HASH_SIZE];

static void
hash_entries(void)
{
	size_t i, hash;

	for (i = 0; i < HASH_SIZE; ++i)
		SLIST_INIT(&hash_table[i]);

	for (i = 0; i < len_jobs; ++i) {
		hash = hash_item(jobs[i].pkgname, jobs[i].pkgname_len);
		SLIST_INSERT_HEAD(&hash_table[hash], &jobs[i], hash_link);
	}
}

static struct buildhash *
get_hash_chain(const char *pkgname, size_t len)
{
	return &hash_table[hash_item(pkgname, len)];
}
