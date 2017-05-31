/* $NetBSD: autocue.c,v 1.5 2017/05/31 23:05:55 agc Exp $ */

/*
 * Copyright (c) 2006,2017 Alistair Crooks.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <err.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* symbolic constants */
enum {
	MaxCutBuffers = 4,

	FmtGoal = 45,
	FmtMax = 50,

	SlowDenom = 3,
	MediumDenom = 7,
	FastDenom = 12
};

static int	speed;

/* send process a USR1 to make the display go faster */
static void
sigusr1(int s)
{
	printf("moving from speed %d to %d (faster)\n", speed, speed + 1);
	speed += 1;
}

/* send process a USR2 to make the display go slower */
static void
sigusr2(int s)
{
	printf("moving from speed %d to %d (slower)\n", speed, speed - 1);
	speed -= 1;
}

/* show the contents of the buffer `buf', which is `cc' chars long */
/* maxcut is the number of xcb cut buffers you have displayed */
/* speed is a numeric value for the number of seconds denominator */
static void
showbuffer(char *buf, int cc, int maxcut)
{
	static int	 cut;
	char		 cmd[BUFSIZ * 20];
	FILE		*pp;
	int		 s;

	(void) snprintf(cmd, sizeof(cmd), "fmt %d %d | xcb -s %d", FmtGoal, FmtMax, cut);
	if ((pp = popen(cmd, "w")) == NULL) {
		errx(EXIT_FAILURE, "can't open pipe to xcb");
	}
	buf[cc] = 0x0;
	(void) fprintf(pp, "%s                    - \n", buf);
	(void) pclose(pp);
	s = cc / speed;
	printf("%.20s...\nBuffer contents are in cut buffer %d, sleeping %d secs\a\n", buf, cut, s);
	while ((s = sleep(s)) > 0) {
	}
	cut = (cut + 1) % maxcut;
}

int
main(int argc, char **argv)
{
	char	 buf[BUFSIZ * 20];
	char	 line[BUFSIZ];
	FILE	*fp;
	int	 maxcut;
	int	 cc;
	int	 c;
	int	 i;

	maxcut = MaxCutBuffers;
	speed = SlowDenom;
	signal(SIGUSR1, sigusr1);
	signal(SIGUSR2, sigusr2);
	while ((i = getopt(argc, argv, "S:c:s:")) != -1) {
		switch(i) {
		case 'S':
			speed = atoi(optarg);
			break;
		case 'c':
			maxcut = atoi(optarg);
			break;
		case 's':
			if (strcmp(optarg, "slow") == 0) {
				speed = SlowDenom;
			} else if (strcmp(optarg, "medium") == 0) {
				speed = MediumDenom;
			} else if (strcmp(optarg, "fast") == 0) {
				speed = FastDenom;
			}
			break;
		}
	}
	if (argc - optind < 1) {
		errx(EXIT_FAILURE, "Usage: %s [-S numeric-speed] [-c max cut buffers] [-s speed] file", *argv);
	}
	if (speed == 0) {
		err(EXIT_FAILURE, "Speed cannot be '0'");
	}
	if (maxcut == 0) {
		err(EXIT_FAILURE, "Maximum cut buffers cannot be '0'");
	}
	if ((fp = fopen(argv[optind], "r")) == NULL) {
		errx(EXIT_FAILURE, "can't open `%s'", argv[optind]);
	}
	printf("send this process - %ld - a USR1 to make the display go faster, a USR2 to make it go slower\n", (long)getpid());
	for (cc = 0 ; fgets(line, sizeof(line), fp) != NULL ; ) {
		if (line[0] == '\n') {
			showbuffer(buf, cc, maxcut);
			cc = 0;
			continue;
		}
		c = strlen(line);
		(void) memcpy(&buf[cc], line, c);
		cc += c;
	}
	exit(EXIT_SUCCESS);
}
