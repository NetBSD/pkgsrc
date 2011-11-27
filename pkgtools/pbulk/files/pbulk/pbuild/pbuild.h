/* $NetBSD: pbuild.h,v 1.6 2011/11/27 19:53:30 joerg Exp $ */

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

#include <nbcompat/queue.h>
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif

/**
 * At the very beginning of a pbulk, each job is in state JOB_INIT.
 *
 * (jobs.c, init_jobs:) If scanning the package failed or the package is
 * not available for this configuration, its state is changed to
 * JOB_PREFAILED. Packages that are listed in the "error" log are marked
 * as JOB_FAILED, those in the the "success" log are marked as JOB_DONE.
 * The remaining jobs are marked as JOB_OPEN.
 *
 * The packages that are ready to be built are those that have the state
 * JOB_OPEN and no pending dependencies. At most one job can be in the
 * state JOB_IN_PROCESSING. After trying to build a job, its state is
 * set to either JOB_DONE or to JOB_FAILED. In the latter case, all the
 * jobs that depend on this one are marked as JOB_INDIRECT_FAILED.
 */
enum job_state {
	JOB_INIT,
	JOB_OPEN,
	JOB_IN_PROCESSING,
	JOB_FAILED,
	JOB_PREFAILED,
	JOB_INDIRECT_FAILED,
	JOB_INDIRECT_PREFAILED,
	JOB_DONE
};

struct build_stat {
	size_t open_jobs;
	size_t in_processing;
	size_t failed;
	size_t prefailed;
	size_t indirect_failed;
	size_t indirect_prefailed;
	size_t done;
};

struct build_job;

struct dependency_list {
	struct build_job *dependency;
	SLIST_ENTRY(dependency_list) depends_link;
};

struct build_job {
	/** The package name, including the version number. */
	char *pkgname;
	size_t pkgname_len;

	/**
	 * Pointers into the output from pbulk-resolve. The lines
	 * between these two pointers describe additional properties
	 * of the job, such as the PKGPATH in which to build the
	 * package. The information can be accessed with the
	 * find_content function.
	 */
	const char *begin;
	const char *end;

	enum job_state state;
	int pkg_depth;

	/**
	 * The number of direct dependencies that must be built before
	 * this package can be tried.
	 */
	size_t open_depends;

	/** The packages that depend on this package. */
	SLIST_HEAD(, dependency_list) depending_pkgs;

	TAILQ_ENTRY(build_job) build_link;
	SLIST_ENTRY(build_job) hash_link;
	SLIST_ENTRY(build_job) depth_tree_link;
};

extern int		 verbosity;

void			 init_jobs(const char *, const char *, const char *);
struct build_job	*get_job(void);
void			 process_job(struct build_job *, enum job_state, int);
int			 build_package(const char *, size_t);
void			 finish_build(const char *);
void			 build_stats(struct build_stat *);

void			 client_mode(const char *);
void			 master_mode(const char *, const char *);
void			 stat_mode(const char *);
