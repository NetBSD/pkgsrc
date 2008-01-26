/* $NetBSD: master.c,v 1.6 2008/01/26 00:34:57 joerg Exp $ */

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

#include <nbcompat.h>

#include <nbcompat/types.h>
#include <sys/ioctl.h>
#ifdef __sun
#include <sys/filio.h>
#endif
#include <nbcompat/queue.h>
#include <sys/socket.h>
#include <nbcompat/time.h>
#include <sys/wait.h>
#include <nbcompat/err.h>
#include <event.h>
#include <signal.h>
#include <nbcompat/stdlib.h>
#include <nbcompat/stdio.h>
#include <nbcompat/string.h>

#include <arpa/inet.h>

#include "pbulk.h"
#include "pbuild.h"

static LIST_HEAD(, build_peer) active_peers, inactive_peers, unassigned_peers;
static struct event listen_event;
static int listen_event_socket;

struct build_peer {
	LIST_ENTRY(build_peer) peer_link;

	struct build_job *job;

	int fd;
	char tmp_buf[4];
	char *buf;
};

static void	assign_job(void *);
static void	recv_command(struct build_peer *);

static void
kill_peer(void *arg)
{
	struct build_peer *peer = arg;

	(void)close(peer->fd);
	LIST_REMOVE(peer, peer_link);
	if (peer->job != NULL)
		process_job(peer->job, JOB_OPEN, 1);
	free(peer->buf);
	free(peer);

	peer = LIST_FIRST(&unassigned_peers);
	if (peer != NULL)
		assign_job(peer);
}

static void
finish_job(void *arg)
{
	struct build_peer *peer = arg;

	LIST_REMOVE(peer, peer_link);
	if (peer->tmp_buf[0] == 'D')
		process_job(peer->job, JOB_DONE, 1);
	else if (peer->tmp_buf[0] == 'F')
		process_job(peer->job, JOB_FAILED, 1);
	else
		kill_peer(peer);
	peer->job = NULL;
	recv_command(peer);

	peer = LIST_FIRST(&unassigned_peers);
	if (peer != NULL)
		assign_job(peer);
}

static void
recv_status(void *arg)
{
	struct build_peer *peer = arg;

	deferred_read(peer->fd, peer->tmp_buf, 1, peer, finish_job,
	    kill_peer);
}

static void
send_build_info(void *arg)
{
	struct build_peer *peer = arg;

	deferred_write(peer->fd, peer->job->begin, peer->job->end - peer->job->begin, peer, recv_status,
	    kill_peer);
}

static void
sent_build_stats(void *arg)
{
	struct build_peer *peer = arg;

	free(peer->buf);
	peer->buf = NULL;

	assign_job(peer);
}

static void
send_build_stats(struct build_peer *peer)
{
	struct build_stat st;
	uint32_t tmp;

	build_stats(&st);

	peer->buf = xmalloc(7 * 4);

	tmp = htonl(st.open_jobs);
	(void)memcpy(peer->buf, &tmp, 4);

	tmp = htonl(st.in_processing);
	(void)memcpy(peer->buf + 4, &tmp, 4);

	tmp = htonl(st.failed);
	(void)memcpy(peer->buf + 8, &tmp, 4);

	tmp = htonl(st.prefailed);
	(void)memcpy(peer->buf + 12, &tmp, 4);

	tmp = htonl(st.indirect_failed);
	(void)memcpy(peer->buf + 16, &tmp, 4);

	tmp = htonl(st.indirect_prefailed);
	(void)memcpy(peer->buf + 20, &tmp, 4);

	tmp = htonl(st.done);
	(void)memcpy(peer->buf + 24, &tmp, 4);

	deferred_write(peer->fd, peer->buf, 7 * 4, peer, sent_build_stats, kill_peer);
}

static void
shutdown_master(void)
{
	struct timeval tv;
	struct build_peer *peer;

	event_del(&listen_event);
	(void)close(listen_event_socket);
	LIST_FOREACH(peer, &inactive_peers, peer_link)
		(void)shutdown(peer->fd, SHUT_RDWR);
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	event_loopexit(&tv);
}

static void
assign_job(void *arg)
{
	struct build_peer *peer = arg;
	size_t build_info_len;
	uint32_t net_build_info_len;

	if (peer->tmp_buf[0] == 'S') {
		send_build_stats(peer);
		return;
	}

	if (peer->tmp_buf[0] != 'G') {
		kill_peer(peer);
		return;
	}

	LIST_REMOVE(peer, peer_link);

	peer->job = get_job();
	if (peer->job == NULL) {
		LIST_INSERT_HEAD(&unassigned_peers, peer, peer_link);
		if (LIST_EMPTY(&active_peers))
			shutdown_master();
		return;
	}

	LIST_INSERT_HEAD(&active_peers, peer, peer_link);

	build_info_len = peer->job->end - peer->job->begin;
	if (build_info_len > 0xffffff)
		errx(1, "Build info too long");

	net_build_info_len = htonl(build_info_len);
	(void)memcpy(peer->tmp_buf, &net_build_info_len, 4);

	deferred_write(peer->fd, peer->tmp_buf, 4, peer, send_build_info,
	    kill_peer);

	peer = LIST_FIRST(&unassigned_peers);
	if (peer != NULL)
		assign_job(peer);
}

static void
recv_command(struct build_peer *peer)
{
	LIST_INSERT_HEAD(&inactive_peers, peer, peer_link);

	deferred_read(peer->fd, peer->tmp_buf, 1, peer, assign_job,
	    kill_peer);
}

static void
listen_handler(int sock, short event, void *arg)
{
	struct build_peer *peer;
	struct sockaddr_in src;
	socklen_t src_len;
	int fd;

	src_len = sizeof(src);
	if ((fd = accept(sock, (struct sockaddr *)&src, &src_len)) == -1) {
		warn("Could not accept connection");
		return;
	}
	if (set_nonblocking(fd) == -1) {
		(void)close(fd);
		warn("Could not set non-blocking IO");
		return;
	}

	peer = xmalloc(sizeof(*peer));
	peer->fd = fd;
	peer->buf = NULL;
	peer->job = NULL;
	recv_command(peer);
}

void
master_mode(const char *master_port, const char *start_script)
{
	struct sockaddr_in dst;
	int fd;

	LIST_INIT(&active_peers);
	LIST_INIT(&inactive_peers);
	LIST_INIT(&unassigned_peers);

	event_init();

	if (parse_sockaddr_in(master_port, &dst))
		errx(1, "Could not parse addr/port");

	fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == -1)
		err(1, "Could not create socket");
#ifdef FIOCLEX
	if (ioctl(fd, FIOCLEX, NULL) == -1)
		err(1, "Could not set close-on-exec flag");
#endif
	if (bind(fd, (struct sockaddr *)&dst, sizeof(dst)) == -1)
		err(1, "Could not bind socket");
	if (listen(fd, 5) == -1)
		err(1, "Could not listen on socket");

	if (start_script) {
		pid_t child;
		int status;
	
		if ((child = vfork()) == 0) {
			execlp(start_script, start_script, (char *)NULL);
			_exit(255);
		}
		if (child == -1)
			err(1, "Could not fork start script");
		waitpid(child, &status, 0);
		if (status != 0)
			err(1, "Start script failed");
	}

	event_set(&listen_event, fd, EV_READ | EV_PERSIST, listen_handler, NULL);
	event_add(&listen_event, NULL);
	listen_event_socket = fd;

	event_dispatch();

	(void)close(fd);
}
