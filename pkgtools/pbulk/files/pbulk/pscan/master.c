/* $NetBSD: master.c,v 1.12 2016/06/23 15:07:39 joerg Exp $ */

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
#include <nbcompat/queue.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <nbcompat/time.h>
#include <sys/wait.h>
#include <nbcompat/err.h>
#include <signal.h>
#include <fcntl.h>
#include <nbcompat/stdlib.h>
#include <nbcompat/stdio.h>
#include <nbcompat/string.h>

#include <arpa/inet.h>

#include "pbulk.h"
#include "pscan.h"

static int clients_started;
static LIST_HEAD(, scan_peer) active_peers, inactive_peers;
static struct signal_event child_event;
static pid_t child_pid;

struct scan_peer {
	LIST_ENTRY(scan_peer) peer_link;

	struct scan_job *job;

	int fd;
	char tmp_buf[4];

	size_t output_len;
};

static void	assign_job(struct scan_peer *);
static void	reassign_jobs(void);

static void
do_nothing(void *arg)
{
}

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
	reassign_jobs();
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
shutdown_master(void)
{
	struct timeval tv;
	struct scan_peer *peer;

	shutdown_listeners();

	LIST_FOREACH(peer, &inactive_peers, peer_link) {
		uint16_t net_job_len = htons(0);
		(void)memcpy(peer->tmp_buf, &net_job_len, 2);

		deferred_write(peer->fd, peer->tmp_buf, 2, peer, do_nothing,
		    kill_peer);
	}

	/* Give clients a second to close connections to prevent TIME_WAIT. */
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	event_loopexit(&tv);
}

static void
assign_job(struct scan_peer *peer)
{
	size_t job_len;
	uint16_t net_job_len;

	peer->job = clients_started ? get_job() : NULL;
	if (peer->job == NULL) {
		LIST_INSERT_HEAD(&inactive_peers, peer, peer_link);
		if (LIST_EMPTY(&active_peers) && clients_started)
			shutdown_master();
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
reassign_jobs(void)
{
	struct scan_peer *peer;

	while ((peer = LIST_FIRST(&inactive_peers)) != NULL) {
		if (!has_job())
			break;
		LIST_REMOVE(peer, peer_link);
		assign_job(peer);
		if (peer-> job == NULL)
			break;
	}
}

static void
listen_handler(int sock, void *arg)
{
	struct scan_peer *peer;
	int fd;

	if ((fd = accept(sock, NULL, 0)) == -1) {
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
	assign_job(peer);
}

static void
child_handler(struct signal_event *ev)
{
	int status;

	if (waitpid(child_pid, &status, WNOHANG) == -1) {
		if (errno == ECHILD)
			return;
		err(1, "Could not wait for child");
	}
	if (status != 0)
		err(1, "Start script failed");

	clients_started = 1;
	signal_del(ev);
	reassign_jobs();
}

void
master_mode(const char *master_port, const char *start_script)
{
	LIST_INIT(&active_peers);
	LIST_INIT(&inactive_peers);

	event_init();

	if (listen_sockaddr(master_port, listen_handler))
		errx(1, "Could not create listen socket for %s", master_port);

	if (start_script) {
		signal_add(&child_event, SIGCHLD, child_handler);

		if ((child_pid = vfork()) == 0) {
			execlp(start_script, start_script, (char *)NULL);
			_exit(255);
		}
		if (child_pid == -1)
			err(1, "Could not fork start script");
	} else {
		clients_started = 1;
	}

	event_dispatch();
}
