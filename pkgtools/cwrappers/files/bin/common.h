/* $NetBSD: common.h,v 1.4 2015/04/19 13:30:35 tnn Exp $ */

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

#ifndef COMMON_H
#define COMMON_H

#include <nbcompat/types.h>
#include <nbcompat/queue.h>
#include <inttypes.h>
#include <stdio.h>
#include <unistd.h>

extern const char library_name_chars[];
extern char *exec_path;
extern char *exec_name;
extern char *wrksrc;
extern int debug;

TAILQ_HEAD(arglist, argument);

struct argument {
	TAILQ_ENTRY(argument) link;
	TAILQ_ENTRY(argument) tmp_link;
	char *val;
};

extern struct argument *prepend_after;

char	*concat(const char *, const char *);
char	*concat2(const char *, const char *, size_t);
void	arglist_from_argc(struct arglist *, int, char **);
void	arglist_apply_config(struct arglist *);
int	command_exec(struct arglist *, int);
size_t	wrapper_hash(const char *);
size_t	wrapper_hash2(const char *, size_t);

void	argument_unlink(struct arglist *, struct argument **);
struct argument *argument_new(char *);
struct argument *argument_copy(const char *);
void	argument_update(struct argument *, char *);

void	parse_config(const char *);

FILE	*worklog_open(void);
void	worklog_cmd(FILE *, const char *, const char *, struct arglist *);

#if defined(__GNUC__) && __GNUC__ >= 2
char	*xasprintf(const char *, ...)
			   __attribute__((__format__(__printf__, 1, 2)));
#else
char	*xasprintf(const char *, ...);
#endif

void	*xmalloc(size_t);
void	*xrealloc(void *, size_t);
char	*xstrdup(const char *);
char	*xstrndup(const char *, size_t);

void	normalise_cc(struct arglist *);
void	cleanup_cc(struct arglist *args);
void	transform_cc(struct arglist *args);

void	register_reorder(const char *);
void	reorder_cc(struct arglist *);

void	init_generic_transform(void);
void	register_generic_transform(const char *);
void	generic_transform_cc(struct arglist *);

void	normalise_ld(struct arglist *);
void	generic_transform_ld(struct arglist *);

void	register_unwrap(const char *);
void	fixup_libtool(struct arglist *);

#ifdef NEED_MI_VECTOR_HASH
void	mi_vector_hash(const void *, size_t, uint32_t, uint32_t[3]);
#endif

#endif
