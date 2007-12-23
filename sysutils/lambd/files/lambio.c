/*	$NetBSD: lambio.c,v 1.3 2007/12/23 00:32:49 tnn Exp $	*/

/*
 * Copyright (C) 2001 WIDE Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <net/if_ether.h>
#include <ifaddrs.h>
#include <string.h>

#include <machine/sysarch.h>
#include <machine/pio.h>

#include "lambio.h"

#define BASEPORT	(0x378)

/* We get these from libi386.so, but there are no public prototypes. */

int i386_get_ioperm(u_long *);
int i386_set_ioperm(u_long *);

/*
 * These used to be provided by machine/pio.h as inline functions,
 * but that's not true anymore, so use a local copy.
 */

static void
lamb_outb(unsigned port, u_int8_t data)
{
	asm volatile("outb %0,%w1" : : "a" (data), "d" (port));
}

static u_int8_t
lamb_inb(unsigned port)
{
	u_int8_t data;
	__asm volatile("inb %w1,%0" : "=a" (data) : "id" (port));
	return data;
}

int
lamb_open()
{
	unsigned long ioperm[1024 / sizeof(unsigned long) / 8];
	int off, bit;
	int i;

	if (i386_get_ioperm(ioperm) < 0)
		return -1;
	for (i = 0; i < 3; i++) {
		off = (BASEPORT + i);
		bit = off % (sizeof(ioperm[0]) * 8);
		off /= (sizeof(ioperm[0]) * 8);
		ioperm[off] &= ~(1 << bit);
	}
	if (i386_set_ioperm(ioperm) < 0)
		return -1;

	return 0;
}

/* returns 1 if shutdown button is pressed */
int
lamb_reboot()
{

	if ((lamb_inb(BASEPORT + 1) & 0x20) == 0)
		return 1;
	else
		return 0;
}

void
lamb_led(on)
	int on;
{

	lamb_outb(BASEPORT + 2, on ? 8 : 0);
}

/*
 * check MAC address against IEEE-registered Wildlab MAC address
 */
int
islamb()
{
	struct ifaddrs *ifa, *ifap;
	struct sockaddr_dl *sdl;
	const u_int8_t wildlab[] = { 0x00, 0x30, 0xf5 };

	if (getifaddrs(&ifap) < 0)
		return 0;
	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr->sa_family != AF_LINK)
			continue;
		sdl = (struct sockaddr_dl *)ifa->ifa_addr;
		if (sdl->sdl_alen != sizeof(struct ether_addr))
			continue;
		if (memcmp(LLADDR(sdl), wildlab, sizeof(wildlab)) != 0)
			continue;

		freeifaddrs(ifap);
		return 1;
	}

	freeifaddrs(ifap);
	return 0;
}
