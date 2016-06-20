/* $NetBSD: pscan.h,v 1.5 2016/06/20 17:54:43 joerg Exp $ */

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

#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif

enum job_state {
	JOB_OPEN,
	JOB_IN_PROCESSING,
	JOB_DONE
};

struct scan_job {
	char *pkg_location;
	char *scan_output;
	enum job_state state;
};

extern int	 verbosity;
extern const char *pkgsrc_tree;

char		*scan_pkglocation(const char *);

void		 client_mode(const char *, const char *);
void		 master_mode(const char *, const char *);

void		 add_job(const char *, size_t, const char *, size_t);
void		 add_job_full(const char *);
struct scan_job	*get_job(void);
void		 process_job(struct scan_job *, enum job_state);
void		 write_jobs(const char *);
int		 has_job(void);

void		 read_old_scan(const char *);
