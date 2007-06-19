/* $NetBSD: netaddr.c,v 1.1.1.1 2007/06/19 19:49:58 joerg Exp $ */

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

#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

#include "pbulk.h"

int
parse_sockaddr_in(const char *str, struct sockaddr_in *addr)
{
	const char *port_sep;
	char *port_end;
	struct in_addr in;
	unsigned long tmp;

	if ((port_sep = strrchr(str, ':')) != NULL) {
		char *addr_part = strdup(str);

		addr_part[port_sep - str] = '\0';
		if (inet_aton(addr_part, &in) == 0) {
			free(addr_part);
			return -1;
		}
		free(addr_part);
		str = port_sep + 1;
	} else {
		memset(&in, 0, sizeof(in));
	}

	errno = 0;
	tmp = strtoul(str, &port_end, 10);
	if (*str == '\0' || *port_end != '\0' || errno != 0 || tmp > 0xfffful)
		return -1;
	addr->sin_port = htons((in_port_t)tmp);
	addr->sin_addr = in;
	addr->sin_len = sizeof(*addr);
	addr->sin_family = AF_INET;
	return 0;
}
