/*	$NetBSD: lambd.c,v 1.1.1.1 2001/07/13 21:56:02 itojun Exp $	*/

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
#include <machine/sysarch.h>
#include <machine/pio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <err.h>

#define BASEPORT	(0x378)

int main __P((int, char **));
void usage __P((void));
void mainloop __P((unsigned long));
int monitor __P((void));
void led __P((int));

int foreground = 0;
int debug = 0;

int
main(argc, argv)
	int argc;
	char **argv;
{
	int ch;
	unsigned long delay;
	char *p, *ep;
	unsigned long ioperm[1024 / sizeof(unsigned long) / 8];
	int i, off, bit;

	while ((ch = getopt(argc, argv, "df")) != -1) {
		switch (ch) {
		case 'd':
			debug++;
			break;
		case 'f':
			foreground++;
			break;
		default:
			usage();
			exit(1);
		}
	}

	argc -= optind;
	argv += optind;

	switch (argc) {
	case 0:
		delay = 1 * 1000000;
		break;
	case 1:
		p = *argv;
		ep = NULL;
		delay = strtoul(*argv, &ep, 10);
		if (ep && !*ep)
			break;
		/* FALLTHROUGH */
	default:
		usage();
		exit(1);
	}

	if (i386_get_ioperm(ioperm) < 0) {
		err(1, "i386_get_ioperm");
		/* NOTREACHED */
	}
	for (i = 0; i < 3; i++) {
		off = (BASEPORT + i);
		bit = off % (sizeof(ioperm[0]) * 8);
		off /= (sizeof(ioperm[0]) * 8);
		ioperm[off] &= ~(1 << bit);
	}
	if (i386_set_ioperm(ioperm) < 0) {
		err(1, "i386_set_ioperm");
		/* NOTREACHED */
	}

	if (!foreground)
		daemon(0, 0);

	if (debug)
		fprintf(stderr, "delay=%lu\n", delay);
	mainloop(delay);
	/* NOTREACHED */

	exit(0);	/* silent gcc */
}

void
usage()
{
	fprintf(stderr, "usage: lambd [-f] [usec]\n");
}

void
mainloop(delay)
	unsigned long delay;
{
	unsigned int sec;

	delay /= 2;
	sec = delay / 1000000;
	delay %= 1000000;

	led(0);
	while (1) {
		if (monitor())
			break;
		led(1);
		if (sec)
			sleep(sec);
		usleep(delay);

		if (monitor())
			break;
		led(0);
		if (sec)
			sleep(sec);
		usleep(delay);
	}

	led(0);
	if (debug) {
		fprintf(stderr, "shutdown -h now\n");
		exit(0);
	} else {
		execl("/sbin/shutdown", "shutdown", "-h", "now", NULL);
		/* NOTREACHED */
	}
}

/* returns 1 if shutdown button is pressed */
int
monitor()
{
	if ((inb(BASEPORT + 1) & 0x20) == 0)
		return 1;
	else
		return 0;
}

void
led(on)
	int on;
{

	if (debug)
		fprintf(stderr, "led=%d\n", on);
	outb(BASEPORT + 2, on ? 8 : 0);
}
