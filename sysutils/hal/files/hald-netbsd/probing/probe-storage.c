/***************************************************************************
 *
 * probe-storage.c : Probe for storage devices
 *
 * Copyright 2008 Jared D. McNeill <jmcneill@NetBSD.org>
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 *
 * Licensed under the Academic Free License version 2.1
 *
 **************************************************************************/

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <errno.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/fdio.h>
#include <sys/statvfs.h>
#include <sys/syslog.h>

#include <sys/scsiio.h>
#include <dev/scsipi/scsi_spc.h>
#include <dev/scsipi/scsipi_all.h>

#include <libhal.h>
#include <cdutils.h>
#include <fsutils.h>
#include <logger.h>

#if notyet
/** Check if a filesystem on a special device file is mounted
 *
 *  @param  device_file         Special device file, e.g. /dev/cd0a
 *  @return                     TRUE iff there is a filesystem system mounted
 *                              on the special device file
 */
static dbus_bool_t
is_mounted (const char *device_file)
{
	int count;
	struct statvfs *statvfs;

	count = getmntinfo(&statvfs, ST_WAIT);
	while (count-- > 0) {
		if (strcmp(statvfs->f_mntfromname, device_file) == 0)
			return TRUE;
	}

	return FALSE;
}
#endif

static int
get_cdrom_properties_walker (void *arg, int profile, bool is_current)
{
	LibHalChangeSet	*cs = (LibHalChangeSet *)arg;

	switch (profile) {
	case 0x09:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.cdr", TRUE);
		break;
	case 0x0a:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.cdrw", TRUE);
		break;
	case 0x10:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.dvd", TRUE);
		break;
	case 0x11:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdr", TRUE);
		break;
	case 0x12:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdram", TRUE);
		break;
	case 0x13:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdrw", TRUE);
		break;
	case 0x14:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdrw", TRUE);
		break;
	case 0x1a:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdplusrw", TRUE);
		break;
	case 0x1b:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdplusr", TRUE);
		break;
	case 0x2b:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdplusrdl", TRUE);
		break;
	case 0x40:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.bd", TRUE);
		break;
	case 0x41:
	case 0x42:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.bdr", TRUE);
		break;
	case 0x43:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.bdre", TRUE);
		break;
	case 0x50:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.hddvd", TRUE);
		break;
	case 0x51:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.hddvdr", TRUE);
		break;
	case 0x52:
		libhal_changeset_set_property_bool (cs, "storage.cdrom.hddvdrw", TRUE);
		break;
	}

	return CDUTIL_WALK_CONTINUE;
}

#define	WSPLEN	64

static void
get_cdrom_properties (int fd, LibHalChangeSet *cs)
{
	int read_speed, write_speed;
	intlist_t *write_speeds, *write_speeds_mem, *sp;
	int n_wspeeds;
	char **wspeeds;
	char *wspeeds_mem;
	int i;
			
	libhal_changeset_set_property_bool (cs, "storage.cdrom.cdr", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.cdrw", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.dvd", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdr", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdrw", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdram", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdplusr", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdplusrw", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.dvdplusrdl", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.bd", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.bdr", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.bdre", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.hddvd", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.hddvdr", FALSE);
	libhal_changeset_set_property_bool (cs, "storage.cdrom.hddvdrw", FALSE);

	walk_profiles(fd, get_cdrom_properties_walker, cs);

	/* XXX */		
	libhal_changeset_set_property_bool (cs, "storage.cdrom.support_media_changed", TRUE);
			
	get_read_write_speeds(fd, &read_speed, &write_speed, &write_speeds, &n_wspeeds, &write_speeds_mem);

	libhal_changeset_set_property_int (cs, "storage.cdrom.read_speed", read_speed);
	libhal_changeset_set_property_int (cs, "storage.cdrom.write_speed", write_speed);

	if (n_wspeeds <= 0) {
		wspeeds_mem = NULL;
 		libhal_changeset_set_property_strlist (cs, "storage.cdrom.write_speeds", (const char **)&wspeeds_mem);
		return;
	}
	if ((wspeeds = (char **)calloc(n_wspeeds + 1, sizeof (char *))) == NULL) {
		free (write_speeds_mem);
		return;
	}
	if ((wspeeds_mem = (char *)calloc(n_wspeeds, WSPLEN)) == NULL) {
		free (wspeeds);
		free (write_speeds_mem);
		return;
	}
	for (i = 0; i < n_wspeeds; i++) {
		wspeeds[i] = &wspeeds_mem[i * WSPLEN];
	}

	for (sp = write_speeds, i = 0; sp != NULL; sp = sp->next, i++) {
		snprintf (wspeeds[i], WSPLEN, "%d", sp->val);
	}
	libhal_changeset_set_property_strlist (cs, "storage.cdrom.write_speeds", (const char **)wspeeds);

	free (wspeeds);
	free (wspeeds_mem);
	free (write_speeds_mem);
}

/*
 * Return a copy of a string without trailing spaces. If 'len' is non-zero,
 * it specifies max length, otherwise the string must be null-terminated.
 */
static char *
rtrim_copy(char *src, int len)
{
	char	*dst, *p;

	if (len == 0) {
		len = strlen(src);
	}
	if ((dst = calloc(1, len + 1)) != NULL) {
		strncpy(dst, src, len);
		p = dst + len - 1;
		while ((p >= dst) && (isspace((int)*p))) {
			*p-- = '\0';
		}
	}
	return (dst);
}

static void
get_disk_properties (int fd, LibHalChangeSet *cs)
{
	struct scsipi_inquiry_data inqbuf;
	struct scsipi_inquiry cmd;
	dbus_bool_t status;
	char		*s;

	/* INQUIRY */
	memset(&cmd, 0, sizeof(cmd));
	memset(&inqbuf, 0, sizeof(inqbuf));
	cmd.opcode = INQUIRY;
	cmd.length = sizeof(inqbuf);
	status = scsi_command(fd, &cmd, sizeof(cmd), &inqbuf, sizeof(inqbuf), 10000, SCCMD_READ);
	if (status == false)
		return;

	if ((s = rtrim_copy(inqbuf.vendor, sizeof (inqbuf.vendor))) != NULL) {
		libhal_changeset_set_property_string (cs, "storage.vendor", s);
		free(s);
	}
	if ((s = rtrim_copy(inqbuf.product, sizeof (inqbuf.product))) != NULL) {
		libhal_changeset_set_property_string (cs, "storage.model", s);
		free(s);
	}
	if ((s = rtrim_copy(inqbuf.revision, sizeof (inqbuf.revision))) != NULL) {
		libhal_changeset_set_property_string (cs, "storage.firmware_revision", s);
		free(s);
	}
	if ((s = rtrim_copy((char *)inqbuf.vendor_specific, sizeof (inqbuf.vendor_specific))) != NULL) {
		libhal_changeset_set_property_string (cs, "storage.serial", s);
		free(s);
	}
}

#if notyet
/*
 * returns TRUE if diskette is inserted.
 * also returns write protection status.
 */
static dbus_bool_t
check_floppy(int fd, dbus_bool_t *wprot)
{
	int	chg;

	if ((ioctl(fd, FDGETCHANGE, &chg) == 0) && !(chg & FDGC_CURRENT)) {
		*wprot = ((chg & FDGC_CURWPROT) != NULL);
		return (TRUE);
	} else {
		return (FALSE);
	}
}
#endif

int 
main (int argc, char *argv[])
{
	int ret = 1;
	int fd = -1;
	int rfd = -1;
	char *udi;
	char *device_file;
	char *raw_device_file;
	LibHalContext *ctx = NULL;
	DBusError error;
	char *bus;
	char *drive_type;
	dbus_bool_t is_cdrom;
	dbus_bool_t is_floppy;
	dbus_bool_t only_check_for_media;
	int got_media = FALSE;
	dbus_bool_t is_write_protected = FALSE;
	dbus_bool_t is_mbr = FALSE;
	dbus_bool_t is_smi = FALSE;
	dbus_bool_t is_gpt = FALSE;
	dbus_bool_t is_partitioned = FALSE;
	int dos_cnt = 0;
	const char *scheme = "";
	LibHalChangeSet *cs = NULL;

	HAL_INFO(("f0"));
	if ((udi = getenv ("UDI")) == NULL)
		goto out;
	HAL_INFO(("f0-1"));
	if ((device_file = getenv ("HAL_PROP_BLOCK_DEVICE")) == NULL)
		goto out;
	HAL_INFO(("f0-2"));
	if ((raw_device_file = getenv ("HAL_PROP_BLOCK_NETBSD_RAW_DEVICE")) == NULL)
		goto out;
	HAL_INFO(("f0-3"));
	if ((bus = getenv ("HAL_PROP_STORAGE_BUS")) == NULL)
		goto out;
	HAL_INFO(("f0-4"));
	if ((drive_type = getenv ("HAL_PROP_STORAGE_DRIVE_TYPE")) == NULL)
		goto out;

	HAL_INFO(("f1"));
	setup_logger ();

	if (argc == 2 && strcmp (argv[1], "--only-check-for-media") == 0)
		only_check_for_media = TRUE;
	else
		only_check_for_media = FALSE;

	is_cdrom = (strcmp (drive_type, "cdrom") == 0);
	is_floppy = (strcmp (drive_type, "floppy") == 0);

	HAL_INFO(("f2"));
	dbus_error_init (&error);
	HAL_INFO(("f3"));
	if ((ctx = libhal_ctx_init_direct (&error)) == NULL)
		goto out;

	HAL_INFO(("f4"));
	if ((cs = libhal_device_new_changeset (udi)) == NULL) {
		HAL_DEBUG (("Cannot allocate changeset"));
		goto out;
	}
	HAL_INFO(("f5"));

	HAL_DEBUG (("Doing probe-storage for %s (bus %s) (drive_type %s) (udi=%s) (--only-check-for-media==%d)", 
	     device_file, bus, drive_type, udi, only_check_for_media));

	if ((rfd = open (raw_device_file, O_RDONLY | O_NONBLOCK)) < 0) {
		HAL_DEBUG (("Cannot open %s: %s", raw_device_file, strerror (errno)));
		goto out;
	}

	if (!only_check_for_media) {
		if (strcmp (drive_type, "cdrom") == 0) {
			get_cdrom_properties (rfd, cs);
		} else if (strcmp (drive_type, "disk") == 0) {
			get_disk_properties (rfd, cs);
		}
	}

	ret = 0;

	if (is_cdrom) {
		uint64_t capacity;

		HAL_DEBUG (("Checking for optical disc on %s", raw_device_file));
		got_media = get_media_info(rfd, &capacity);
		if (!got_media) {
			goto out_cs;
		}
		/* XXX */
		is_write_protected = TRUE;
	} else if (is_floppy) {
#if 0
		HAL_DEBUG (("Checking for floppy on %s", raw_device_file));
		if (check_floppy(rfd, &is_write_protected)) {
			got_media = TRUE;
		}
#endif
		/* don't look for partitions on floppy */
		goto out_cs;
	} else {
		got_media = TRUE;
	}

	HAL_DEBUG (("Checking for partitions on %s", device_file));

	if ((fd = open (device_file, O_RDONLY | O_NONBLOCK)) < 0) {
		HAL_DEBUG (("Cannot open %s: %s", device_file, strerror (errno)));
		goto out_cs;
	}

	scheme = "mbr";
	dos_cnt = 1;

out_cs:
	is_partitioned = is_mbr || is_smi || is_gpt;
	libhal_changeset_set_property_bool (cs, "storage.no_partitions_hint", !is_partitioned);
	libhal_changeset_set_property_bool (cs, "block.no_partitions", !is_partitioned);
	libhal_changeset_set_property_string (cs, "storage.partitioning_scheme", scheme);
	libhal_changeset_set_property_int (cs, "storage.netbsd.num_dos_partitions", dos_cnt);
	/* XXX should only set for removable drives */
	libhal_changeset_set_property_bool (cs, "storage.removable.media_available", got_media);
	libhal_changeset_set_property_bool (cs, "storage.removable.netbsd.read_only", is_write_protected);

	libhal_device_commit_changeset (ctx, cs, &error);

out:
	if (cs != NULL) {
		libhal_device_free_changeset (cs);
	}
	if (fd >= 0) {
		close (fd);
	}
	if (rfd >= 0) {
		close (rfd);
	}
	if (ctx != NULL) {
		if (dbus_error_is_set(&error)) {
			dbus_error_free (&error);
		}
		libhal_ctx_shutdown (ctx, &error);
		libhal_ctx_free (ctx);
	}

	return ret;
}
