/* $NetBSD: devinfo_mass.c,v 1.6 2015/01/31 12:08:55 wiz Exp $ */

/*-
 * Copyright (c) 2008 Jared D. McNeill <jmcneill@invisible.ca>
 * All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/disklabel.h>
#include <sys/bootblock.h>
#include <sys/ioctl.h>
#include <sys/scsiio.h>
#include <dev/scsipi/scsipi_all.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <paths.h>
#include <unistd.h>

#include "../osspec.h"
#include "../logger.h"
#include "../hald.h"
#include "../hald_dbus.h"
#include "../device_info.h"
#include "../util.h"
#include "../ids.h"
#include "hotplug.h"
#include "devinfo.h"
#include "devinfo_mass.h"
#include "drvctl.h"

#include <libvolume_id.h>

HalDevice *devinfo_mass_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type);
HalDevice *devinfo_mass_disklabel_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type);

/* XXX from devinfo_optical */
extern bool scsi_command(int, void *, size_t, void *, size_t, int, int);

DevinfoDevHandler devinfo_mass_handler = {
	devinfo_mass_add,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};
DevinfoDevHandler devinfo_mass_disklabel_handler = {
	devinfo_mass_disklabel_add,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

static char *
rtrim_copy(char *src, int len)
{
        char    *dst, *p;

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

static const char *
devinfo_mass_get_fstype(uint8_t fstype)
{
	switch (fstype) {
	case FS_BSDFFS:
		return "ffs";
	case FS_MSDOS:
		return "vfat";
	case FS_EX2FS:
		return "ext2";
	case FS_NTFS:
		return "ntfs";
	case FS_APPLEUFS:
		return "ffs";
	default:
		return NULL;
	}
}

static uint8_t
devinfo_mass_get_mbrtype(uint8_t fstype)
{
	switch (fstype) {
	case FS_BSDFFS:
		return MBR_PTYPE_NETBSD;
	case FS_MSDOS:
		return MBR_PTYPE_FAT32;	/* XXX */
	case FS_EX2FS:
		return MBR_PTYPE_LNXEXT2;
	case FS_NTFS:
		return MBR_PTYPE_NTFS;
	case FS_APPLEUFS:
		return MBR_PTYPE_APPLE_UFS;
	default:
		return MBR_PTYPE_UNUSED;
	}
}

HalDevice *
devinfo_mass_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	HalDevice *d = NULL, *gparent = NULL;
	prop_dictionary_t dict;
	struct disklabel label;
	struct stat st;
	const char *driver;
	char *rdevpath, *devpath;
	char *childnode;
	char *parent_devnode, *gparent_devnode = NULL;
	char *gparent_udi;
	int16_t unit;
	int i, fd;
	struct scsipi_inquiry_data inqbuf;
	struct scsipi_inquiry cmd;
	bool scsiinq_status;
	char *storage_model = NULL, *storage_vendor = NULL;

	if (drvctl_find_device (devnode, &dict) == FALSE || dict == NULL)
		return NULL;

	if (prop_dictionary_get_int16 (dict, "device-unit", &unit) == false ||
	    prop_dictionary_get_cstring_nocopy (dict, "device-driver", &driver) == false) {
		prop_object_release (dict);
		return NULL;
	}

	if (strcmp (driver, "wd") != 0 && strcmp (driver, "sd") != 0 &&
	    strcmp (driver, "ld") != 0) {
		prop_object_release (dict);
		return NULL;
	}

	sleep (1);

	devpath = g_strdup_printf ("/dev/%s%c", devnode, RAW_PART + 'a');
	rdevpath = g_strdup_printf ("/dev/r%s%c", devnode, RAW_PART + 'a');
	HAL_INFO (("  going to open %s", rdevpath));
	fd = open (rdevpath, O_RDONLY);
	if (fd < 0) {
		HAL_WARNING (("couldn't open %s: %s", rdevpath, strerror (errno)));
		g_free (rdevpath);
		g_free (devpath);
		return NULL;
	}

	HAL_INFO (("  going to DIOCGDINFO %s", rdevpath));
	if (ioctl (fd, DIOCGDINFO, &label) == -1) {
		HAL_WARNING (("DIOCGDINFO failed on %s: %s", rdevpath, strerror (errno)));
		g_free (rdevpath);
		g_free (devpath);
		close (fd);
		return NULL;
	}

	if (strcmp (driver, "sd") == 0) {
		memset(&cmd, 0, sizeof (cmd));
		memset(&inqbuf, 0, sizeof (inqbuf));
		cmd.opcode = INQUIRY;
		cmd.length = sizeof (inqbuf);

		scsiinq_status = scsi_command (fd, &cmd, sizeof (cmd), &inqbuf, sizeof (inqbuf), 10000, SCCMD_READ);
	} else
		scsiinq_status = false;

	close (fd);

	d = hal_device_new ();

	devinfo_set_default_properties (d, parent, devnode, devfs_path);

	hal_device_add_capability (d, "block");
	hal_device_property_set_string (d, "info.subsystem", "block");
	hal_device_property_set_string (d, "block.device", devpath);
	if (stat (devpath, &st) == 0) {
		hal_device_property_set_int (d, "block.major", major (st.st_rdev));
		hal_device_property_set_int (d, "block.minor", minor (st.st_rdev));
	}
	hal_device_property_set_bool (d, "block.is_volume", FALSE);
	hal_device_property_set_bool (d, "block.no_partitions", FALSE);
	hal_device_property_set_bool (d, "block.have_scanned", TRUE);

	hal_device_add_capability (d, "storage");
	hal_device_property_set_string (d, "info.category", "storage");
	parent_devnode = hal_device_property_get_string (parent, "netbsd.device");
	gparent_udi = hal_device_property_get_string (parent, "info.parent");
	if (gparent_udi) {
		gparent = hal_device_store_find (hald_get_gdl (), gparent_udi);
		if (gparent)
			gparent_devnode = hal_device_property_get_string (gparent, "netbsd.device");
	}
	if (gparent_devnode && strstr (gparent_devnode, "umass") == gparent_devnode)
		hal_device_property_set_string (d, "storage.bus", "usb");
	else if (parent_devnode && strstr (parent_devnode, "atabus") == parent_devnode)
		hal_device_property_set_string (d, "storage.bus", "ide");
	else
		hal_device_property_set_string (d, "storage.bus", "scsi");
	hal_device_property_set_string (d, "storage.device_type", "disk");
	hal_device_property_set_bool (d, "storage.removable", label.d_flags & D_REMOVABLE ? TRUE : FALSE);
	if (label.d_flags & D_REMOVABLE) {
		hal_device_property_set_bool (d, "storage.removable.media_available", TRUE);
		hal_device_property_set_uint64 (d, "storage.removable.media_size",
		    (uint64_t)label.d_secsize * (uint64_t)label.d_secperunit);
		hal_device_property_set_uint64 (d, "storage.size", 0);
		hal_device_property_set_bool (d, "storage.hotpluggable", TRUE);
		hal_device_property_set_bool (d, "storage.automount_enabled_hint", TRUE);
	} else {
		hal_device_property_set_bool (d, "storage.removable.media_available", FALSE);
		hal_device_property_set_uint64 (d, "storage.removable.media_size", 0);
		hal_device_property_set_uint64 (d, "storage.size",
		    (uint64_t)label.d_secsize * (uint64_t)label.d_secperunit);
		hal_device_property_set_bool (d, "storage.hotpluggable", FALSE);
		hal_device_property_set_bool (d, "storage.automount_enabled_hint", FALSE);
	}
	hal_device_property_set_bool (d, "storage.no_partitions_hint", FALSE);
	hal_device_property_set_bool (d, "storage.requires_eject", FALSE);
	hal_device_property_set_bool (d, "storage.removable.support_async_notification", FALSE);
	hal_device_property_set_string (d, "storage.partitioning_scheme", "mbr");
	hal_device_property_set_string (d, "storage.originating_device",
	    hal_device_property_get_string (d, "info.udi"));

	if (scsiinq_status == true) {
		storage_model = rtrim_copy(inqbuf.product, sizeof (inqbuf.product));
		storage_vendor = rtrim_copy(inqbuf.vendor, sizeof (inqbuf.vendor));
	}

	if (storage_model) {
		hal_device_property_set_string (d, "storage.model", storage_model);
		free (storage_model);
	} else
		hal_device_property_set_string (d, "storage.model", label.d_packname);

	if (storage_vendor) {
		hal_device_property_set_string (d, "storage.vendor", storage_vendor);
		free (storage_vendor);
	} else
		hal_device_property_set_string (d, "storage.vendor", label.d_typename);

	devinfo_add_enqueue (d, devfs_path, &devinfo_mass_handler);

	for (i = 0; i < MAXPARTITIONS; i++) {
		const char *fstype;

		fstype = devinfo_mass_get_fstype(label.d_partitions[i].p_fstype);
		if (fstype == NULL)
			continue;

		childnode = g_strdup_printf ("%s%c", devnode, 'a' + i);
		HAL_INFO (("  adding %s on %s", childnode, rdevpath));
		devinfo_mass_disklabel_add (d, childnode, childnode, childnode);
		g_free (childnode);
	}

	HAL_INFO (("  returning"));
	g_free (rdevpath);
	g_free (devpath);

done:
	prop_object_release (dict);

	return d;
}

HalDevice *
devinfo_mass_disklabel_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	HalDevice *d = NULL;
	struct disklabel label;
	struct partition *part;
	struct stat st;
	const char *driver;
	char *devpath, *rdevpath, *partname;
	char *childnode;
	char unit;
	struct volume_id *vid;
	uint64_t psize, msize;
	int i, fd;

	partname = devnode;
	unit = partname[strlen (partname) - 1] - 'a';

	if (unit >= MAXPARTITIONS)
		return NULL;

	devpath = g_strdup_printf ("/dev/%s", partname);
	rdevpath = g_strdup_printf ("/dev/r%s", partname);
	fd = open (rdevpath, O_RDONLY);
	if (fd < 0) {
		HAL_WARNING (("couldn't open %s: %s", rdevpath, strerror (errno)));
		g_free (rdevpath);
		return NULL;
	}

	if (ioctl (fd, DIOCGDINFO, &label) == -1) {
		HAL_WARNING (("DIOCGDINFO failed on %s: %s", rdevpath, strerror (errno)));
		g_free (rdevpath);
		close (fd);
		return NULL;
	}
	part = &label.d_partitions[unit];

	d = hal_device_new ();

	devinfo_set_default_properties (d, parent, devnode, devfs_path);

	hal_device_add_capability (d, "block");
	hal_device_property_set_string (d, "info.subsystem", "block");
	hal_device_property_set_string (d, "info.category", "volume");
	hal_device_property_set_string (d, "block.device", devpath);
	hal_device_property_set_string (d, "block.storage_device",
	    hal_device_property_get_string (parent, "info.udi"));

	if (stat (devpath, &st) == 0) {
		hal_device_property_set_int (d, "block.major", major (st.st_rdev));
		hal_device_property_set_int (d, "block.minor", minor (st.st_rdev));
	}

	hal_device_property_set_bool (d, "block.is_volume", TRUE);
	hal_device_property_set_bool (d, "block.no_partitions", FALSE);
	hal_device_property_set_bool (d, "block.have_scanned", TRUE);

	hal_device_add_capability (d, "volume");
	hal_device_property_set_bool (d, "volume.ignore", FALSE);
	hal_device_property_set_bool (d, "volume.is_mounted", FALSE);
	hal_device_property_set_bool (d, "volume.is_mounted_read_only", FALSE);
	hal_device_property_set_string (d, "volume.mount_point", "");
	hal_device_property_set_string (d, "volume.fsusage", "filesystem");
	hal_device_property_set_string (d, "volume.fstype", devinfo_mass_get_fstype (part->p_fstype));
	hal_device_property_set_bool (d, "volume.is_disc", FALSE);

	hal_device_property_set_string (d, "volume.label", "");
	hal_device_property_set_string (d, "volume.partition.label", "");
	hal_device_property_set_string (d, "volume.uuid", "");
	hal_device_property_set_string (d, "volume.partition.uuid", "");

	psize = (uint64_t)part->p_size * (uint64_t)label.d_secsize;
	msize = (uint64_t)label.d_secsize * (uint64_t)label.d_secperunit;

	hal_device_property_set_uint64 (d, "volume.size", psize);
	hal_device_property_set_int (d, "volume.block_size", label.d_secsize);
	hal_device_property_set_uint64 (d, "volume.num_blocks", part->p_size);
	hal_device_property_set_uint64 (d, "volume.partition.media_size", msize);

	hal_device_property_set_bool (d, "volume.is_partition", TRUE);
	hal_device_property_set_int (d, "volume.partition.number", unit);
	hal_device_property_set_string (d, "volume.partition.scheme", "mbr");

	vid = volume_id_open_fd (fd);
	if (vid) {
		if (volume_id_probe_all (vid, 0, psize) == 0) {
			const char *type,*fstype;

			hal_device_property_set_string (d, "volume.label", vid->label);
			hal_device_property_set_string (d, "volume.partition.label", vid->label);
			hal_device_property_set_string (d, "volume.uuid", vid->uuid);
			hal_device_property_set_string (d, "volume.partition.uuid", vid->uuid);

			if ( type && volume_id_get_type (vid, &type)) {
				fstype=devinfo_mass_get_fstype (part->p_fstype);
				if (strcmp (type, fstype)) {
					HAL_INFO (("%s disklabel reports [%s] but libvolume_id says it is "
					    "[%s], assuming disklabel is incorrect",
					    devpath, fstype, type));
					hal_device_property_set_string (d, "volume.fstype", type);
				}
			}
		}
		volume_id_close (vid);
	}

	devinfo_add_enqueue (d, devfs_path, &devinfo_mass_disklabel_handler);

	close (fd);

	g_free (rdevpath);
	g_free (devpath);

	return d;
}
