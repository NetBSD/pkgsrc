/* $NetBSD: master.c,v 1.1.1.1 2007/06/19 19:49:57 joerg Exp $ */

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
#include <sys/queue.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <err.h>
#include <event.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pbulk.h"
#include "pscan.h"

static LIST_HEAD(, scan_peer) active_peers, inactive_peers;

struct scan_peer {
	LIST_ENTRY(scan_peer) peer_link;

	struct scan_job *job;

	int fd;
	char tmp_buf[4];

	size_t output_len;
};

static void	assign_job(struct scan_peer *);

static void
kill_peer(void *arg)
{
	struct scan_peer *peer = arg;

	(void)close(peer->fd);
	LIST_REMOVE(peer, peer_link);
	free(peer->job->scan_output);
	peer->job->scan_output = NULL;
	process_job(peer->job, JOB_OPEN);
	free(peer);

	peer = LIST_FIRST(&inactive_peers);
	if (peer == NULL)
		return;
	LIST_REMOVE(peer, peer_link);
	assign_job(peer);
}

static void
finish_job(void *arg)
{
	struct scan_peer *peer = arg;

	if (strlen(peer->job->scan_output) != peer->output_len) {
		warnx("Invalid output len received from peer");
		kill_peer(peer);
		return;
	}
	LIST_REMOVE(peer, peer_link);
	process_job(peer->job, JOB_DONE);
	assign_job(peer);
}

static void
recv_output(void *arg)
{
	struct scan_peer *peer = arg;
	uint32_t output_len;

	(void)memcpy(&output_len, peer->tmp_buf, 4);
	output_len = ntohl(output_len);
	if (output_len == 0) {
		LIST_REMOVE(peer, peer_link);
		process_job(peer->job, JOB_DONE);
		assign_job(peer);
		return;
	}
	if (output_len == 0xffffff) {
		warnx("Invalid output len received from peer");
		kill_peer(peer);
		return;
	}
	peer->job->scan_output = xmalloc(output_len + 1);
	peer->job->scan_output[output_len] = '\0';
	peer->output_len = output_len;
	deferred_read(peer->fd, peer->job->scan_output, output_len, peer, finish_job, kill_peer);
}

static void
recv_output_len(void *arg)
{
	struct scan_peer *peer = arg;

	deferred_read(peer->fd, peer->tmp_buf, 4, peer, recv_output, kill_peer);
}

static void
send_job_path(void *arg)
{
	struct scan_peer *peer = arg;

	deferred_write(peer->fd, peer->job->pkg_location,
	    strlen(peer->job->pkg_location), peer, recv_output_len,
	    kill_peer);
}

static void
assign_job(struct scan_peer *peer)
{
	size_t job_len;
	uint16_t net_job_len;

	peer->job = get_job();
	if (peer->job == NULL) {
		LIST_INSERT_HEAD(&inactive_peers, peer, peer_link);
		if (LIST_EMPTY(&active_peers))
			event_loopexit(NULL);
		return;
	}

	LIST_INSERT_HEAD(&active_peers, peer, peer_link);

	peer->job->scan_output = NULL;

	job_len = strlen(peer->job->pkg_location);
	if (job_len > 0xffff)
		errx(1, "Location inside pkgsrc tree too long");
	net_job_len = htons(job_len);
	(void)memcpy(peer->tmp_buf, &net_job_len, 2);

	deferred_write(peer->fd, peer->tmp_buf, 2, peer, send_job_path,
	    kill_peer);
}

static void
listen_handler(int sock, short event, void *arg)
{
	struct scan_peer *peer;
	struct sockaddr_in src;
	socklen_t src_len;
	int fd, ioctl_arg;

	src_len = sizeof(src);
	if ((fd = accept(sock, (struct sockaddr *)&src, &src_len)) == -1) {
		warn("Could not accept connection");
		return;
	}
	ioctl_arg = 1;
	if (ioctl(fd, FIONBIO, &ioctl_arg) == -1) {
		(void)close(fd);
		warn("Could not set non-blocking IO");
		return;
	}

	peer = xmalloc(sizeof(*peer));
	peer->fd = fd;
	assign_job(peer);
}

void
master_mode(const char *master_port, const char *start_script)
{
	struct event listen_event;
	struct sockaddr_in dst;
	int fd;

	LIST_INIT(&active_peers);
	LIST_INIT(&inactive_peers);

	event_init();

	if (parse_sockaddr_in(master_port, &dst))
		errx(1, "Could not parse addr/port");

	fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == -1)
		err(1, "Could not create socket");	
	if (ioctl(fd, FIOCLEX, NULL) == -1)
		err(1, "Could not set close-on-exec flag");
	if (bind(fd, (struct sockaddr *)&dst, dst.sin_len) == -1)
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

	event_dispatch();

	(void)close(fd);
}
