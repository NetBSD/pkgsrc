/* $NetBSD: event.c,v 1.1.1.1 2007/06/19 19:49:58 joerg Exp $ */

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

#include <sys/ioctl.h>
#include <sys/time.h>
#include <event.h>
#include <stdlib.h>
#include <unistd.h>

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
deferred_read_handler(int fd, short event, void *arg)
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
	event_add(&data->ev, NULL);
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

	event_set(&data->ev, data->fd, EV_READ,
	    deferred_read_handler, data);
	event_add(&data->ev, NULL);
}

static void
deferred_write_handler(int fd, short event, void *arg)
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
	event_add(&data->ev, NULL);
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

	event_set(&data->ev, data->fd, EV_WRITE,
	    deferred_write_handler, data);
	event_add(&data->ev, NULL);
}
