/* $NetBSD: event.c,v 1.5.4.1 2009/09/06 13:47:20 tron Exp $ */

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

#include <nbcompat/types.h>
#include <sys/ioctl.h>
#ifdef __sun
#include <sys/filio.h>
#endif
#if HAVE_POLL_H
#include <poll.h>
#endif
#if HAVE_SYS_POLL_H
#include <sys/poll.h>
#endif
#include <nbcompat/time.h>
#include <nbcompat/stdlib.h>
#include <nbcompat/unistd.h>

#include <signal.h>

#include "pbulk.h"

struct deferred_read_arg {
	void *cb_arg;
	void (*cb_ok)(void *);
	void (*cb_error)(void *);

	struct event ev;
	int fd;

	char *buf;
	size_t remaining;
};

struct deferred_write_arg {
	void *cb_arg;
	void (*cb_ok)(void *);
	void (*cb_error)(void *);

	struct event ev;
	int fd;

	const char *buf;
	size_t remaining;
};

static void
deferred_read_handler(int fd, void *arg)
{
	struct deferred_read_arg *data = arg;
	ssize_t received;

	received = read(data->fd, data->buf, data->remaining);
	if (received == -1 || received == 0) {
		(*data->cb_error)(data->cb_arg);
		free(data);
		return;
	}
	data->buf += received;
	data->remaining -= received;
	if (data->remaining == 0) {
		(*data->cb_ok)(data->cb_arg);
		free(data);
		return;
	}
	event_add(&data->ev, data->fd, 0, 0, deferred_read_handler, data);
}

void
deferred_read(int fd, void *buf, size_t buf_len, void *arg,
    void (*cb_ok)(void *), void (*cb_error)(void *))
{
	struct deferred_read_arg *data;

	data = xmalloc(sizeof(*data));
	data->cb_arg = arg;
	data->cb_ok = cb_ok;
	data->cb_error = cb_error;
	data->fd = fd;
	data->buf = buf;
	data->remaining = buf_len;

	event_add(&data->ev, data->fd, 0, 0, deferred_read_handler, data);
}

static void
deferred_write_handler(int fd, void *arg)
{
	struct deferred_write_arg *data = arg;
	ssize_t sent;

	sent = write(data->fd, data->buf, data->remaining);
	if (sent == -1 || sent == 0) {
		(*data->cb_error)(data->cb_arg);
		free(data);
		return;
	}
	data->buf += sent;
	data->remaining -= sent;
	if (data->remaining == 0) {
		(*data->cb_ok)(data->cb_arg);
		free(data);
		return;
	}
	event_add(&data->ev, data->fd, 1, 0, deferred_write_handler, data);
}

void
deferred_write(int fd, const void *buf, size_t buf_len, void *arg,
    void (*cb_ok)(void *), void (*cb_error)(void *))
{
	struct deferred_write_arg *data;

	data = xmalloc(sizeof(*data));
	data->cb_arg = arg;
	data->cb_ok = cb_ok;
	data->cb_error = cb_error;
	data->fd = fd;
	data->buf = buf;
	data->remaining = buf_len;

	event_add(&data->ev, data->fd, 1, 0, deferred_write_handler, data);
}

int
set_nonblocking(int fd)
{
	int ioctl_arg;

	ioctl_arg = 1;
	if (ioctl(fd, FIONBIO, &ioctl_arg) == -1)
		return -1;
	return 0;
}

static size_t active_events;
static LIST_HEAD(, event) all_events;
static LIST_HEAD(, signal_event) all_signals;
static struct pollfd *poll_list;
static size_t poll_allocated;

static int signal_pipe[2];
static struct event signal_event;

static void signal_read_handler(int, void *);

void
event_init(void)
{
	LIST_INIT(&all_events);
	LIST_INIT(&all_signals);

	if (pipe(signal_pipe))
		err(1, "can't create signal pipe");

	event_add(&signal_event, signal_pipe[0], 0, 1, signal_read_handler,
	    NULL);
	set_nonblocking(signal_pipe[0]);
	set_nonblocking(signal_pipe[1]);
}

void
event_add(struct event *ev, int fd, int do_write, int is_persistent,
    void (*handler)(int, void *), void *arg)
{
	ev->ev_fd = fd;
	ev->ev_write = do_write;
	ev->ev_persistent = is_persistent;
	ev->ev_handler = handler;
	ev->ev_arg = arg;
	LIST_INSERT_HEAD(&all_events, ev, ev_link);
	++active_events;
}

void
event_del(struct event *ev)
{
	LIST_REMOVE(ev, ev_link);
	--active_events;
}

static void
mask_all(void)
{
	sigset_t mask;

	sigfillset(&mask);

	sigprocmask(SIG_SETMASK, &mask, NULL);
}

static void
unmask_all(void)
{
	sigset_t mask;

	sigemptyset(&mask);

	sigprocmask(SIG_SETMASK, &mask, NULL);
}

static void
signal_read_handler(int fd, void *arg)
{
	struct signal_event *sig, *next;
	int got_something;
	char buf[256];

	for (;;) {
		got_something = 0;

		while (read(signal_pipe[0], buf, sizeof(buf)) >	0)
		        got_something = 1;
		if (got_something == 0)
			break;

		for (sig = LIST_FIRST(&all_signals);
		    sig && (next = LIST_NEXT(sig, sig_link), 1);
		    sig = next) {
			if (sig->sig_received) {
				sig->sig_received = 0;
				(*sig->sig_handler)(sig);
			}
		}
	}
}

static void
signal_handler(int sig_id)
{
	struct signal_event *sig;
	char buf = 0;
	int old_errno;

	LIST_FOREACH(sig, &all_signals, sig_link) {
		if (sig->sig_id == sig_id)
			sig->sig_received = 1;
	}

	old_errno = errno;
	write(signal_pipe[1], &buf, 1);
	errno = old_errno;
}

void
signal_add(struct signal_event *sig, int sigtype,
    void (*handler)(struct signal_event *))
{
	sig->sig_id = sigtype;
	sig->sig_received = 0;
	sig->sig_handler = handler;

	mask_all();
	LIST_INSERT_HEAD(&all_signals, sig, sig_link);
	signal(sigtype, signal_handler);
	unmask_all();
}

void
signal_del(struct signal_event *sig)
{
	mask_all();
	LIST_REMOVE(sig, sig_link);
	/* XXX Unset signal handler */
	unmask_all();
}

static struct timeval exit_time;

void
event_dispatch(void)
{
	struct timeval now;
	struct event *ev, *next;
	struct pollfd *iter, *last_iter;
	int ret, timeout;

loop:
	if (active_events > poll_allocated) {
		if (poll_allocated == 0)
			poll_allocated = 512;
		while (active_events > poll_allocated)
			poll_allocated <<= 1;
		poll_list = xrealloc(poll_list,
		    sizeof(struct pollfd) * poll_allocated);
	}

	iter = poll_list;
	LIST_FOREACH(ev, &all_events, ev_link) {
		iter->fd = ev->ev_fd;
		if (ev->ev_write)
			iter->events = POLLOUT;
		else
			iter->events = POLLIN;
		++iter;
	}
	last_iter = iter;

	if (exit_time.tv_sec || exit_time.tv_usec) {
		gettimeofday(&now, NULL);
		timeout = (exit_time.tv_sec - now.tv_sec) * 1000;
		timeout += (exit_time.tv_usec - now.tv_usec + 999) / 1000;
		if (timeout < 0)
			timeout = 0;
	} else
		timeout = -1;

	ret = poll(poll_list, active_events, timeout);
	if (ret < 0 && errno != EINTR)
		return;
	if (ret == 0 && timeout == 0)
		return;
	if (ret > 0) {
		iter = poll_list;
		for (ev = LIST_FIRST(&all_events);
		    iter < last_iter && ev && (next = LIST_NEXT(ev, ev_link), 1);
		    ev = next, ++iter) {
			if (iter->revents) {
				if (!ev->ev_persistent) {
					--active_events;
					LIST_REMOVE(ev, ev_link);
				}
				(*ev->ev_handler)(ev->ev_fd, ev->ev_arg);
				--ret;
			}
		}
	}
	goto loop;
}

void
event_loopexit(struct timeval *tv)
{
	gettimeofday(&exit_time, NULL);
	exit_time.tv_sec += tv->tv_sec;
	exit_time.tv_usec += tv->tv_usec;
	while (exit_time.tv_usec >= 1000000) {
		exit_time.tv_usec -= 1000000;
		++exit_time.tv_sec;
	}
	while (exit_time.tv_usec < 0) {
		exit_time.tv_usec += 1000000;
		--exit_time.tv_sec;
	}
}
