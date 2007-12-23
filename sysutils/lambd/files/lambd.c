/*	$NetBSD: lambd.c,v 1.6 2007/12/23 00:32:49 tnn Exp $	*/

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
#include <ctype.h>

#include "lambio.h"

#define BASEPORT	(0x378)

int main __P((int, char **));
void usage __P((void));
void mainloop __P((void));
void lsleep __P((unsigned long));
int monitor __P((void));
void led __P((int));

int cycle __P((void));
int loadavg __P((void));
int morse __P((void));

int foreground = 0;
int debug = 0;
#ifdef __i386__
int nohw = 0;
#else
const int nohw = 1;
#endif
unsigned long delay = 1 * 1000000;
const char *morsestr = "LAMB";

int (*func) __P((void)) = cycle;

int
main(argc, argv)
	int argc;
	char **argv;
{
	int ch;
	char *p, *ep;

	while ((ch = getopt(argc, argv, "LM:dfn")) != -1) {
		switch (ch) {
		case 'L':
			func = loadavg;
			break;
		case 'M':
			func = morse;
			morsestr = optarg;
			break;
		case 'd':
			debug++;
			break;
		case 'f':
			foreground++;
			break;
		case 'n':
			nohw++;
			break;
		default:
			usage();
			exit(1);
		}
	}

	if (!islamb()) {
		if (debug)
			fprintf(stderr, "it is not lamb\n");
		nohw++;
	} else
		if (debug)
			fprintf(stderr, "it is indeed lamb\n");

	argc -= optind;
	argv += optind;

	switch (argc) {
	case 0:
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

	if (!nohw) {
		if (lamb_open() < 0) {
			err(1, "lamb_open");
			/* NOTREACHED */
		}
	}

	if (!foreground)
		daemon(0, 0);

	if (debug)
		fprintf(stderr, "delay=%lu\n", delay);
	mainloop();
	/* NOTREACHED */

	exit(0);	/* silent gcc */
}

void
usage()
{
	fprintf(stderr, "usage: lambd [-LMdfn] [usec]\n");
}

void
mainloop()
{
	led(0);
	while (1) {
		if ((*func)())
			break;
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

void
lsleep(usec)
	unsigned long usec;
{

	sleep(usec / 1000000);
	usleep(usec % 1000000);
}

int
monitor()
{
	int i;

	if (nohw)
		return 0;

	for (i = 0; i < 10; i++)
		if (!lamb_reboot())
			return 0;
	return 1;
}

void
led(on)
	int on;
{

	if (debug)
		fprintf(stderr, "led=%d\n", on);
	if (nohw)
		return;

	lamb_led(on);
}

/*
 * define a interesting functions below!
 */

int
cycle()
{
	if (monitor())
		return 1;
	led(1);
	lsleep(delay / 2);

	if (monitor())
		return 1;
	led(0);
	lsleep(delay / 2);
	return 0;
}

int
loadavg()
{
	double v;
	int i;
	unsigned long t = delay / 10;

	getloadavg(&v, 1);
	if (debug)
		fprintf(stderr, "loadavg=%g\n", v);
	for (i = 0; i < v * 2; i++) {
		if (monitor())
			return 1;
		led(1);
		lsleep(t);
		led(0);
		lsleep(t);
	}
	lsleep(t * 5);
	return 0;
}

static const char *const digit[] = {
	"-----",
	".----",
	"..---",
	"...--",
	"....-",
	".....",
	"-....",
	"--...",
	"---..",
	"----.",
};
static const char *const alph[] = {
	".-",
	"-...",
	"-.-.",
	"-..",
	".",
	"..-.",
	"--.",
	"....",
	"..",
	".---",
	"-.-",
	".-..",
	"--",
	"-.",
	"---",
	".--.",
	"--.-",
	".-.",
	"...",
	"-",
	"..-",
	"...-",
	".--",
	"-..-",
	"-.--",
	"--..",
};

int
morse()
{
	unsigned const char *p, *q;
	int mark, blank;
	unsigned long t = delay / 10;

	for (p = (unsigned char*)morsestr; *p; p++) {
		if (monitor())
			return 1;

		if (isdigit(*p))
			q = (unsigned char*)digit[*p - '0'];
		else if (isalpha(*p) && isupper(*p))
			q = (unsigned char*)alph[*p - 'A'];
		else if (isalpha(*p) && islower(*p))
			q = (unsigned char*)alph[*p - 'a'];
		else
			q = NULL;

		if (debug)
			printf("%c <%s>\n", *p, q);
		for (/*nothing*/; *q; q++) {
			switch (*q) {
			case '-':
				mark = 3; blank = 1; break;
			case '.':
				mark = 1; blank = 1; break;
			default:
				mark = 0; blank = 3; break;
			}
			led(1);
			lsleep(mark * t);
			led(0);
			lsleep(blank * t);
		}
		lsleep(1 * t);
	}
	lsleep(10 * t);
	return 0;
}
