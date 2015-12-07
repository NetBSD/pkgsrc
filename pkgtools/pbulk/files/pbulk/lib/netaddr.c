/* $NetBSD: netaddr.c,v 1.11 2015/12/07 16:52:39 joerg Exp $ */

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

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <nbcompat/netdb.h>
#include <nbcompat/stdlib.h>
#include <nbcompat/string.h>

#include "pbulk.h"

struct listener {
	LIST_ENTRY(listener) ls_link;
	struct event ls_event;
	int ls_fd;
};

static LIST_HEAD(, listener) all_listener = LIST_HEAD_INITIALIZER(&all_listener);

void
shutdown_listeners(void)
{
	struct listener *ls;
	while ((ls = LIST_FIRST(&all_listener)) != NULL) {
		LIST_REMOVE(ls, ls_link);
		event_del(&ls->ls_event);
		close(ls->ls_fd);
		free(ls);
	}
}

static int
split_netaddr(const char *str, char **host, char **port, int *numeric)
{
	const char *sep = strrchr(str, ':');
	if (sep == NULL) {
		*numeric = 0;
		*host = NULL;
		*port = xstrdup(str);
		return 0;
	}
	if (sep[1] == '\0') {
		warnx("invalid network address with empty port: %s", str);
		return -1;
	}
	if (sep == str) {
		/* Consider ":port" as equivalent to just "port". */
		*numeric = 0;
		*host = NULL;
		*port = xstrdup(sep + 1);
		return 0;
	}
	if (str[0] == '[' && sep[-1] == ']') {
		/* Recognize URL-style numeric IPv6 addresses in []. */
		*numeric = 1;
		*host = xstrndup(str + 1, sep - str - 2);
		*port = xstrdup(sep + 1);
		return 0;
	}
	if (memchr(str, ':', sep - str) != NULL) {
		warnx("invalid network with colon in host name: %s", str);
		return -1;
	}
	*numeric = 0;
	*host = xstrndup(str, sep - str);
	*port = xstrdup(sep + 1);
	return 0;
}

static struct addrinfo *
prepare_getaddrinfo(const char *netaddr, int passive)
{
	struct addrinfo hints, *result;
	char *host, *port;
	int numeric, rv;

	if (split_netaddr(netaddr, &host, &port, &numeric))
		return NULL;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	if (passive)
		hints.ai_flags |= AI_PASSIVE;
	if (numeric)
		hints.ai_flags |= AI_NUMERICHOST;
	rv = getaddrinfo(host, port, &hints, &result);
	free(host);
	free(port);
	if (rv != 0) {
		if (rv == EAI_SYSTEM)
			warn("getaddrinfo failed");
		else
			warnx("getaddrinfo failed: %s", gai_strerror(rv));
		return NULL;
	}
	return result;
}

int
connect_sockaddr(const char *netaddr)
{
	struct addrinfo *result, *res;
	int s;

	if ((result = prepare_getaddrinfo(netaddr, 0)) == NULL)
		return -1;

	s = -1;
	for (res = result; res != NULL; res = res->ai_next) {
		s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (s == -1)
			continue;
		if (connect(s, res->ai_addr, res->ai_addrlen) != -1)
			break;
		close(s);
		s = -1;
	}
	freeaddrinfo(result);
	return s;
}

static int
bind_and_listen(struct addrinfo *res, void (*cb)(int, void *))
{
	static const int one = 1;
	struct listener *ls;
	int s;

	s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (s == -1)
		return 0;
	if (fcntl(s, F_SETFD, FD_CLOEXEC) == -1) {
		close(s);
		return 0;
	}
#ifdef IPV6_V6ONLY
	/*
	 * Disable mapped IPv4, which is still the default at least on Linux.
	 * It doesn't matter if an error occurs, but success allows binding
	 * to both IPv4 and IPv6 wild card addresses. Otherwise,
	 * the second bind would fail.
	 */
	if (res->ai_family == AF_INET6)
		setsockopt(s, IPPROTO_IPV6, IPV6_V6ONLY, &one, sizeof(one));
#endif
	if (bind(s, res->ai_addr, res->ai_addrlen) == -1) {
		close(s);
		return 0;
	}
	if (listen(s, 5) == -1) {
		close(s);
		return 0;
	}
	ls = xmalloc(sizeof(*ls));
	ls->ls_fd = s;
	LIST_INSERT_HEAD(&all_listener, ls, ls_link);
	event_add(&ls->ls_event, s, 0, 1, cb, NULL);
	return 1;
}

int
listen_sockaddr(const char *netaddr, void (*cb)(int, void *))
{
	struct addrinfo *result, *res;
	int got_address;

	if ((result = prepare_getaddrinfo(netaddr, 0)) == NULL)
		return -1;

	got_address = 0;
	for (res = result; res != NULL; res = res->ai_next)
		got_address |= bind_and_listen(res, cb);

	freeaddrinfo(result);
	return got_address ? 0 : -1;
}
