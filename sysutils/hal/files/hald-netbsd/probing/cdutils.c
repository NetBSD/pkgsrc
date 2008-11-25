/***************************************************************************
 *
 * cdutils.h : CD/DVD utilities
 *
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Licensed under the Academic Free License version 2.1
 *
 **************************************************************************/

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include <sys/types.h>
#include <sys/scsiio.h>
#include <sys/disklabel.h>
#include <dev/scsipi/scsi_spc.h>
#include <dev/scsipi/scsipi_all.h>
#include <dev/scsipi/scsipi_cd.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/dkio.h>
#include <libintl.h>

#include <logger.h>

#include "cdutils.h"

#define	RQLEN	32
#define SENSE_KEY(rqbuf)        (rqbuf[2])      /* scsi error category */
#define ASC(rqbuf)              (rqbuf[12])     /* additional sense code */
#define ASCQ(rqbuf)             (rqbuf[13])     /* ASC qualifier */

#define	GET16(a) (((a)[0] << 8) | (a)[1])
#define	GET32(a) (((a)[0] << 24) | ((a)[1] << 16) | ((a)[2] << 8) | (a)[3])

bool
scsi_command (int fd, void *cmd, size_t cmdlen, void *data, size_t datalen,
    int timeout, int flags)
{
	scsireq_t req;

	memset(&req, 0, sizeof(req));
	memcpy(req.cmd, cmd, cmdlen);
	req.cmdlen = cmdlen;
	req.databuf = data;
	req.datalen = datalen;
	req.timeout = timeout;
	req.flags = flags;
	req.senselen = SENSEBUFLEN;

	if (ioctl(fd, SCIOCCOMMAND, &req) == -1)
		return false;
	if (req.retsts == SCCMD_OK)
		return true;
	return false;
}

int
mode_sense(int fd, u_char pc, int dbd, int page_len, u_char *buffer)
{
	struct scsi_mode_sense_10 sms10;

        memset(&sms10, 0, sizeof(sms10));
	sms10.opcode = SCSI_MODE_SENSE_10; 
	if (dbd)
		sms10.byte2 = SMS_DBD; /* no block descriptors */
	sms10.page = pc;
	sms10.length[0] = (page_len >> 8) & 0xff;
	sms10.length[1] = page_len & 0xff;

        return (scsi_command(fd, &sms10, sizeof(sms10), buffer, page_len, 10000, SCCMD_READ) == true);
}

/*
 * will get the mode page only i.e. will strip off the header.
 */
int
get_mode_page(int fd, int page_no, int pc, int buf_len, u_char *buffer, int *plen)
{
	int ret;
	u_char byte2;
	u_char buf[256];
	u_int header_len, page_len, copy_cnt;

	byte2 = (u_char)(((pc << 6) & 0xC0) | (page_no & 0x3f));

	/* Ask 254 bytes only to make our IDE driver happy */
	if ((ret = mode_sense(fd, byte2, 1, 254, buf)) == 0) {
		return (0);
	}

	header_len = 8 + GET16(&buf[6]);
	page_len = buf[header_len + 1] + 2;

	copy_cnt = ((int)page_len > buf_len) ? (u_int)buf_len : page_len;
	(void) memcpy(buffer, &buf[header_len], copy_cnt);

	if (plen) {
		*plen = page_len;
	}

	return (1);
}

/* Get information about the Logical Unit's capabilities */
int
get_configuration(int fd, uint16_t feature, int bufsize, u_char *buf)
{
	struct scsipi_get_configuration conf;

	memset(&conf, 0, sizeof(conf));
	conf.opcode = GET_CONFIGURATION;
	conf.request_type = 0x2;
	conf.start_at_feature[0] = (feature >> 8) & 0xff;
	conf.start_at_feature[1] = feature & 0xff;
	conf.data_len[0] = (bufsize >> 8) & 0xff;
	conf.data_len[1] = bufsize & 0xff;

        return (scsi_command(fd, &conf, sizeof(conf), buf, bufsize, 10000, SCCMD_READ) == true);
}

bool
get_current_profile(int fd, int *profile)
{
	u_char smallbuf[4];
	size_t buflen;
	u_char *bufp;
	int ret = false;

	/* first determine amount of memory needed to hold all profiles */
	if (get_configuration(fd, 0, 4, &smallbuf[0])) {
		buflen = GET32(smallbuf) + 4;
		bufp = (u_char *)malloc(buflen);

	 	/* now get all profiles */
		if (get_configuration(fd, 0, buflen, bufp)) {
			*profile = GET16(&bufp[6]);
			ret = true;
		}
		free(bufp);
	}

	return (ret);
}

void
walk_profiles(int fd, int (*f)(void *, int, bool), void *arg)
{
	size_t i;
	uint16_t profile, current_profile;
	u_char smallbuf[4];
	size_t buflen;
	u_char *bufp;
	int ret;

	/* first determine amount of memory needed to hold all profiles */
	if (get_configuration(fd, 0, 4, &smallbuf[0])) {
		buflen = GET32(smallbuf) + 4;
		bufp = (u_char *)malloc(buflen);

	 	/* now get all profiles */
		if (get_configuration(fd, 0, buflen, bufp)) {
			current_profile = GET16(&bufp[6]);
			for (i = 8 + 4;  i < buflen; i += 4) {
				profile = GET16(&bufp[i]);
				ret = f(arg, profile, (profile == current_profile));
				if (ret == CDUTIL_WALK_STOP) {
					break;
				}
			}
		}

		free(bufp);
	}
}

/* retrieve speed list from the Write Speed Performance Descriptor Blocks
 */
static void
get_write_speeds(u_char *page, int n, intlist_t **speeds, int *n_speeds, intlist_t **speeds_mem)
{
	u_char	*p = page + 2;
	int	i;
	intlist_t **nextp;
	intlist_t *current;
	bool skip;

	*n_speeds = 0;
	*speeds = NULL;
	*speeds_mem = (intlist_t *)calloc(n, sizeof (intlist_t));
	if (*speeds_mem == NULL) {
		return;
	}

	for (i = 0; i < n; i++, p += 4) {
		current = &(*speeds_mem)[i];
		current->val = GET16(p);

		/* keep the list sorted */
		skip = false;
		for (nextp = speeds; *nextp != NULL; nextp = &((*nextp)->next)) {
			if (current->val == (*nextp)->val) {
				skip = true; /* skip duplicates */
				break;
			} else if (current->val > (*nextp)->val) {
				break;
			}
		}
		if (!skip) {
			current->next = *nextp;
			*nextp = current;
			*n_speeds++;
		}
	}
}

void
get_read_write_speeds(int fd, int *read_speed, int *write_speed,
    intlist_t **speeds, int *n_speeds, intlist_t **speeds_mem)
{
	int page_len;
	u_char	p[254];
	int n; /* number of write speed performance descriptor blocks */

	*read_speed = *write_speed = 0;
	*speeds = *speeds_mem = NULL;

	if (!get_mode_page(fd, 0x2A, 0, sizeof (p), p, &page_len)) {
		return;
	}

	if (page_len > 8) {
		*read_speed = GET16(&p[8]);
	}
	if (page_len > 18) {
		*write_speed = GET16(&p[18]);
	}
	if (page_len < 28) {
		printf("MMC-2\n");
		return;
	} else {
		printf("MMC-3\n");
	}

	*write_speed = GET16(&p[28]);

	if (page_len < 30) {
		return;
	}

	/* retrieve speed list */
	n = GET16(&p[30]);
	n = min(n, (sizeof (p) - 32) / 4);

	get_write_speeds(&p[32], n, speeds, n_speeds, speeds_mem);

	if (*speeds != NULL) {
		*write_speed = max(*write_speed, (*speeds)[0].val);
	}
}

bool
get_disc_info(int fd, disc_info_t *di)
{
	struct scsipi_read_discinfo discinfo;
	uint8_t	buf[32];
	int bufsize = sizeof (buf);

	bzero(buf, bufsize);
	memset(&discinfo, 0, sizeof(discinfo));
	discinfo.opcode = READ_DISCINFO;
	discinfo.data_len[0] = (bufsize >> 8) & 0xff;
	discinfo.data_len[1] = bufsize & 0xff;

        if (scsi_command(fd, &discinfo, sizeof(discinfo), buf, bufsize, 10000, SCCMD_READ) == false)
		return false;

	di->disc_status = buf[2] & 0x03;
	di->erasable = buf[2] & 0x10;
	if ((buf[21] != 0) && (buf[21] != 0xff)) {
		di->capacity = ((buf[21] * 60) + buf[22]) * 75;
	} else {
		di->capacity = 0;
        }

	return true;
}

/*
 * returns current/maximum format capacity in bytes
 */
bool
read_format_capacity(int fd, uint64_t *capacity)
{
	char cdb[12];
	uint8_t	buf[32];
	int bufsize = sizeof (buf);
	uint32_t num_blocks;
	uint32_t block_len;

	memset(buf, 0, bufsize);
	memset(cdb, 0, sizeof(cdb));
	cdb[0] = 0x23;	/* READ FORMAT CAPACITIES */
	cdb[7] = (bufsize >> 8) & 0xff;	/* allocation length */
	cdb[8] = bufsize & 0xff;

        if (scsi_command(fd, &cdb, sizeof(cdb), buf, bufsize, 10000, SCCMD_READ) == false)
		return false;

	num_blocks = (uint32_t)(buf[4] << 24) + (buf[5] << 16) + (buf[6] << 8) + buf[7];
	block_len = (uint32_t)(buf[9] << 16) + (buf[10] << 8) + buf[11];
	*capacity = (uint64_t)num_blocks * block_len;

	return (true);
}

bool
get_media_info(int fd, uint64_t *capacity)
{
	struct disklabel d;
	int ret;

	ret = ioctl(fd, DIOCGDINFO, &d);
	if (ret == -1)
		return false;
	*capacity = d.d_secsize * d.d_secperunit;
	return true;
}

/*
 * given current profile, use the best method for determining
 * disc capacity (in bytes)
 */
bool
get_disc_capacity_for_profile(int fd, int profile, uint64_t *capacity)
{
	disc_info_t	di;
	bool	ret = false;

	switch (profile) {
	case 0x08: /* CD-ROM */
	case 0x10: /* DVD-ROM */
		if (get_media_info(fd, capacity))
			ret = true;
		break;
	default:
		if (read_format_capacity(fd, capacity) && (*capacity > 0)) {
			ret = true;
		} else if (get_disc_info(fd, &di) && (di.capacity > 0)) {
			if (get_media_info(fd, capacity))
				ret = true;
		}
	}

	return (ret);
}

bool
read_toc(int fd, int format, int trackno, int buflen, u_char *buf)
{
	struct scsipi_read_toc toc;

	memset(buf, 0, buflen);
	toc.opcode = READ_TOC;
	toc.resp_format = format & 0xf;
	toc.from_track = trackno;
	toc.data_len[0] = (buflen >> 8) & 0xff;
	toc.data_len[1] = buflen & 0xff;

        return scsi_command(fd, &toc, sizeof(toc), buf, buflen, 10000, SCCMD_READ);
}
