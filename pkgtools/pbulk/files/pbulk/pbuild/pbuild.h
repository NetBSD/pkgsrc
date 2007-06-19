/* $NetBSD: pbuild.h,v 1.1.1.1 2007/06/19 19:49:56 joerg Exp $ */

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
#include <inttypes.h>

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
	char *pkgname;
	const char *begin;
	const char *end;
	enum job_state state;
	int pkg_depth;
	int unrestricted_subset;
	size_t open_depends;

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
