/* $NetBSD: pbulk.h,v 1.5 2014/01/15 13:52:10 joerg Exp $ */

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

#include <netinet/in.h>
#include <nbcompat/queue.h>
#include <nbcompat/unistd.h>

struct event {
	LIST_ENTRY(event) ev_link;
	int ev_fd;
	int ev_write;
	int ev_persistent;
	void (*ev_handler)(int, void *);
	void *ev_arg;
};

struct signal_event {
	LIST_ENTRY(signal_event) sig_link;
	int sig_id;
	volatile int sig_received;
	void (*sig_handler)(struct signal_event *);
};

#if defined(__GNUC__) && __GNUC__ >= 2
__attribute__((__format__(__printf__, 1, 2)))
#endif
char		*xasprintf(const char *, ...);

void		 event_init(void);
void		 event_add(struct event *, int, int, int,
    void (*)(int, void *), void *);
void		 event_del(struct event *);
void		 signal_add(struct signal_event *, int,
    void (*)(struct signal_event *));
void		 signal_del(struct signal_event *);
void		 event_dispatch(void);
void		 event_loopexit(struct timeval *tv);
int		 set_nonblocking(int);

void		 deferred_read(int fd, void *, size_t, void *,
			       void (*)(void *), void (*)(void *));
void		 deferred_write(int fd, const void *, size_t,
			       void *, void (*)(void *), void (*)(void *));

ssize_t		 atomic_read(int, void *, size_t);
ssize_t		 atomic_write(int, const void *, size_t);


int		 parse_sockaddr_in(const char *, struct sockaddr_in *);
pid_t		 fork_chdir_exec(const char *, const char *,
				 const char * const *, int *);
char		*read_from_child(const char *, const char *,
				 const char * const *);
char		*read_from_file(int fd);
void		*xmalloc(size_t);
void		*xrealloc(void *, size_t);
char		*xstrdup(const char *);
char		*xstrndup(const char *, size_t);

int		 pkg_match(const char *, const char *);
const char	*pkg_order(const char *, const char *);

size_t		 djb_hash(const char *);
size_t		 djb_hash2(const char *, const char *);
