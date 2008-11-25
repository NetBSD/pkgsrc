/***************************************************************************
 *
 * fsutils.c : filesystem utilities
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
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/dkio.h>
#include <libintl.h>
#include <sys/disklabel.h>
#include <sys/bootblock.h>

#include <libhal.h>
#include "fsutils.h"

/*
 * Separates dos notation device spec into device and drive number
 */
bool
dos_to_dev(char *path, char **devpath, int *num)
{
	char *p;

	if ((p = strrchr(path, ':')) == NULL) {
		return (false);
	}
	if ((*num = atoi(p + 1)) == 0) {
		return (false);
	}
	p[0] = '\0';
	*devpath = strdup(path);
	p[0] = ':';
	return (*devpath != NULL);
}

char *
get_slice_name (char *devlink)
{
	char	*part, *slice, *disk;
	char	*s = NULL;
	char	*p;

	if ((p = strstr(devlink, "/lofi/")) != 0) {
		return (p + sizeof ("/lofi/") - 1);
	}

	part = strrchr(devlink, 'p');
	slice = strrchr(devlink, 's');
	disk = strrchr(devlink, 'd');

	if ((part != NULL) && (part > slice) && (part > disk)) {
		s = part;
	} else if ((slice != NULL) && (slice > disk)) {
		s = slice;
	} else {
		s = disk;
	}
	if ((s != NULL) && isdigit(s[1])) {
		return (s);
	} else {
		return ("");
	}
}

bool
is_dos_drive(u_char type)
{
	return ((type == 1) || (type == 4) || (type == 5) || (type == 6) ||
	    ((type >= 8) && (type <= 0xf)));
}

bool
is_dos_extended(u_char id)
{
	return MBR_IS_EXTENDED(id);
}

struct part_find_s {
	int	num;
	int	count;
	int	systid;
	int	r_systid;
	int	r_relsect;
	int	r_numsect;
};

enum { WALK_CONTINUE, WALK_TERMINATE };

/*
 * Walk partition tables and invoke a callback for each.
 */
static void
walk_partitions(int fd, int startsec, int (*f)(void *, int, int, int),
    void *arg)
{
	uint32_t buf[1024/4];
	int bufsize = 1024;
	struct mbr_sector *msect = (struct mbr_sector *)&buf[0];
	struct mbr_partition mpart[MBR_PART_COUNT];
	int sec = startsec;
	int lastsec = sec + 1;
	int relsect;
	int ext = 0;
	int systid;
	bool valid;
	int i;

	while (sec != lastsec) {
		if (pread(fd, buf, bufsize, (off_t)sec * 512) != bufsize) {
			break;
		}
		lastsec = sec;
		if (le16toh(msect->mbr_magic) != MBR_MAGIC) {
			break;
		}
		memcpy(mpart, msect->mbr_parts, MBR_PART_COUNT * sizeof (struct mbr_partition));

		for (i = 0; i < MBR_PART_COUNT; i++) {
			systid = mpart[i].mbrp_type;
			relsect = sec + le32toh(mpart[i].mbrp_start);
			if (systid == 0) {
				continue;
			}
			valid = true;
			if (is_dos_extended(systid) && (sec == lastsec)) {
				sec = startsec + le32toh(mpart[i].mbrp_start);
				if (ext++ == 0) {
					relsect = startsec = sec;
				} else {
					valid = false;
				}
			}
			if (valid && f(arg, mpart[i].mbrp_type, relsect,
			    le32toh(mpart[i].mbrp_size)) == WALK_TERMINATE) {
				return;
			}
		}
	}
}

static int
find_dos_drive_cb(void *arg, int systid, int relsect, int numsect)
{
	struct part_find_s *p = arg;

	if (is_dos_drive(systid)) {
		if (++p->count == p->num) {
			p->r_relsect = relsect;
			p->r_numsect = numsect;
			p->r_systid = systid;
			return (WALK_TERMINATE);
		}
	}

	return (WALK_CONTINUE);
}

/*
 * Given a dos drive number, return its relative sector number,
 * number of sectors in partition and the system id.
 */
bool
find_dos_drive(int fd, int num, int *relsect, int *numsect, int *systid)
{
	struct part_find_s p = { 0, 0, 0, 0, 0, 0 };

	p.num = num;

	if (num > 0) {
		walk_partitions(fd, 0, find_dos_drive_cb, &p);
		if (p.count == num) {
			*relsect = p.r_relsect;
			*numsect = p.r_numsect;
			*systid = p.r_systid;
			return (true);
		}
	}

	return (false);
}

static int
get_num_dos_drives_cb(void *arg, int systid, int relsect, int numsect)
{
	if (is_dos_drive(systid)) {
		(*(int *)arg)++;
	}
	return (WALK_CONTINUE);
}

int
get_num_dos_drives(int fd)
{
	int count = 0;

	walk_partitions(fd, 0, get_num_dos_drives_cb, &count);

	return (count);
}
