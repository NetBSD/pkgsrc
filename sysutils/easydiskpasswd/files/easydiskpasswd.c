/* $NetBSD: easydiskpasswd.c,v 1.2 2006/03/01 17:16:01 drochner Exp $ */
/*
 * Copyright (c) 2002
 *      Matthias Drochner.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * a tool to unlock a password protected USB "EasyDisk" (3SYSTEM) flash disk
 */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/scsiio.h>
#include <dev/scsipi/scsi_spc.h>
#include <util.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <err.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

static int getstatus(int, int *);
static void usage(void);
int main(int, char **);

/* SCSI command 0xff is in the "vendor defined" range */
static const u_char cmd_getstatus[12] = {0xff, 0x01};
static const u_char cmd_putpasswd[12] = {0xff, 0x05, 0x01};

static char passwdbuf[20] = "                    ";
static const char *defpasswd = "1111";

/*
 * status:
 *  1: OK, no password
 *  5, 7: password unlocked
 *  21: password, locked
 */
static int
getstatus(fd, statp)
	int fd;
	int *statp;
{
	int res;
	struct scsireq cmd;
	char status[1];

	bzero(&cmd, sizeof(cmd));
	cmd.flags = SCCMD_READ;
	cmd.timeout = 10000;
	bcopy(cmd_getstatus, &cmd.cmd, 12);
	cmd.cmdlen = 12;
	cmd.databuf = status;
	cmd.datalen = 1;
	cmd.senselen = SENSEBUFLEN;

	res = ioctl(fd, SCIOCCOMMAND, &cmd);
	if (res < 0)
		err(2, "SCIOCCOMMAND");
	if (cmd.retsts == SCCMD_SENSE)
		return (EINVAL);
	else if (cmd.retsts != SCCMD_OK)
		return (EIO);

	*statp = (unsigned char)status[0];
	return (0);
}

static void
usage()
{
	fprintf(stderr, "%s [ -d | -p <passwd> ] disk\n", getprogname());
	exit(1);
}

int
main(argc, argv)
	int argc;
	char **argv;
{
	int ch, fd, res, status;
	char pathbuf[MAXPATHLEN];
	const char *passwd = 0;
	struct scsireq cmd;
	struct scsi_sense_data *sd;

	while ((ch = getopt(argc, argv, "dp:")) != -1)
		switch (ch) {
		case 'd':
			passwd = defpasswd;
			break;
		case 'p':
			passwd = optarg;
			break;
		case '?':
		default:
			usage();
		}
	argc -= optind;
	argv += optind;

	if (argc != 1)
		usage();

	fd = opendisk(argv[0], O_RDWR, pathbuf, MAXPATHLEN, 0);
	if (fd < 0)
		err(2, "opendisk %s", argv[0]);

	res = getstatus(fd, &status);
	if (res)
		errx(2, "wrong device");
	if (status != 21) {
		warnx("no password set, or unlocked");
		exit (0);
	}

	if (!passwd)
		passwd = getpass("flash disk password: ");

	bcopy(passwd, passwdbuf, MIN(strlen(passwd), 20));

	bzero(&cmd, sizeof(cmd));
	cmd.flags = SCCMD_WRITE;
	cmd.timeout = 10000;
	bcopy(cmd_putpasswd, &cmd.cmd, 12);
	cmd.cmdlen = 12;
	cmd.databuf = passwdbuf;
	cmd.datalen = 20;
	cmd.datalen_used = 20;
	cmd.senselen = SENSEBUFLEN;

	res = ioctl(fd, SCIOCCOMMAND, &cmd);
	if (res < 0)
		err(2, "SCIOCCOMMAND");

	if (cmd.retsts == SCCMD_SENSE) {
		sd = (struct scsi_sense_data *)&cmd.sense;
		if (SSD_SENSE_KEY(sd->flags) == SKEY_ILLEGAL_REQUEST) {
			if (sd->asc == 0x24)
				errx(3, "wrong password");
			if (sd->asc == 0x20) {
				/* XXX shouldn't get here (caught above) */
				warnx("no password set");
				exit (0);
			}
		}
		errx(2, "SCSI command error");
	} else if (cmd.retsts != SCCMD_OK)
		errx(2, "scsi driver error %d", cmd.retsts);

	return (0);
}
