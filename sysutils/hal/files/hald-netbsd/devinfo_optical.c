/*
 * Copyright (c) 2008 Reinoud Zandijk
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
#include <machine/disklabel.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>

#include "../osspec.h"
#include "../logger.h"
#include "../hald.h"
#include "../hald_dbus.h"
#include "../device_info.h"
#include "../util.h"
#include "devinfo_optical.h"

#include "devinfo.h"


#define	DEVINFO_PROBE_STORAGE_TIMEOUT   60000
static HalDevice *devinfo_optical_add(HalDevice *, const char *, char *,char *);
static HalDevice *devinfo_optical_volume_add(HalDevice *, const char *, char *, char *);


static const gchar *
devinfo_storage_get_prober (HalDevice *d, int *timeout)
{
	        *timeout = DEVINFO_PROBE_STORAGE_TIMEOUT;
		        return "hald-probe-storage";
}

#if notyet
const gchar *
devinfo_volume_get_prober (HalDevice *d, int *timeout)
{
	        *timeout = DEVINFO_PROBE_VOLUME_TIMEOUT;
		        return "hald-probe-volume";
}
#endif

DevinfoDevHandler devinfo_optical_handler = {
        devinfo_optical_add,
	NULL,	/* remove */
	NULL,	/* hotplug_begin_add */
	NULL,	/* hotplug_begin_remove */
	NULL,	/* probing_done */
        NULL /* devinfo_storage_get_prober */	/* get_prober */
};


DevinfoDevHandler devinfo_optical_volume_handler = {
        devinfo_optical_volume_add,
	NULL,	/* remove */
	NULL,	/* hotplug_begin_add */
	NULL,	/* hotplug_begin_remove */
	NULL,	/* probing_done */
        NULL /* devinfo_storage_get_prober */	/* get_prober */
};


/* XXX i dont know how to link cdutils here XXX ! */
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


static void
optical_get_str(char *str, unsigned char *buf, int len)
{
	char *pos;
	int i;

	pos = str;
	for (i = 0; i < len; i++) {
		if (isprint(buf[i]))
			*pos++ = buf[i];
	}
	*pos = (char) 0;
	pos--;
	while (*pos == ' ')
		*pos-- = (char) 0;
}


static void
devinfo_optical_identify_drive(HalDevice *d, char *devstr)
{
	uint8_t cmd[12], buf[100];
	char str[100];
	int fd, ok;

	fd = open(devstr, O_RDONLY, 0);
	if(!fd)
		return;

	HAL_INFO(("devinfo_optical_identify_drive: SCSI call"));
	cmd[0] = 0x12;	/* INQUIRY */
	cmd[1] = 0;	/* basic inquiry */
	cmd[2] = 0;	/* no page or operation code */
	cmd[3] = 0;	/* reserved/MSB result */
	cmd[4] = 96;	/* all but vendor specific */
	cmd[5] = 0;	/* control */
	ok = scsi_command(fd, cmd, 6, buf, 96, 30000, SCCMD_READ);
	close(fd);

	if (!ok)
		return;

	optical_get_str(str, buf+8, 8);
	hal_device_property_set_string (d, "storage.vendor", str);
	optical_get_str(str, buf+16, 16);
	hal_device_property_set_string (d, "storage.model", str);
	optical_get_str(str, buf+32, 4);
	hal_device_property_set_string (d, "storage.firmware_version", str);
}


static char const *
get_profile_name(HalDevice *d, int profile)
{
	switch (profile) {
	case 0x00 : return NULL;	// "Unknown[0] profile";
	case 0x01 : return NULL;	// "Non removeable disc";
	case 0x02 : return NULL;	// "Removable disc";
	case 0x03 : return "mo";	// Magneto Optical with sector erase";
	case 0x04 : return "mo";	// "Magneto Optical write once";
	case 0x05 : return "mo";	// "Advance Storage Magneto Optical";
	case 0x08 : return "cd";	// "CD-ROM"; no writing
	case 0x09 : return "cdr";	// "CD-R recordable";
	case 0x0a : return "cdrw";	// "CD-RW rewritable";
	case 0x10 : return "dvd";	// "DVD-ROM"; no writing
	case 0x11 : return "dvdr";	// "DVD-R sequential";
	case 0x12 : return "dvdram";	// "DVD-RAM rewritable";
	case 0x13 : return "dvdrw";	// "DVD-RW restricted overwrite";
	case 0x14 : return "dvdrw";	// "DVD-RW sequential";
	case 0x15 : return "dvdr";	// "DVD-R dual layer sequential";
	case 0x16 : return "dvdr";	// "DVD-R dual layer jump";
	case 0x17 : return "dvdrw";	// "DVD-RW dual layer";
	case 0x18 : return NULL;	// "DVD-Download disc"; UNKNOWN
	case 0x1a : return "dvdplusrw";	// "DVD+RW rewritable";
	case 0x1b : return "dvdplusr";	// "DVD+R recordable";
	case 0x20 : return "ddcd";	// "DDCD readonly (retracted)"; no writing
	case 0x21 : return "ddcdr";	// "DDCD-R recordable (retracted)";	OK?
	case 0x22 : return "ddcdrw";	// "DDCD-RW rewritable (retracted)"; OK?
	case 0x2a : return "dvdplusrwdl";//"DVD+RW double layer";
	case 0x2b : return "dvdplusrdl";// "DVD+R double layer";
	case 0x40 : return "bd";	// "BD-ROM";
	case 0x41 : return "bdr";	// "BD-R Sequential Recording (SRM)";
	case 0x42 : return "bdr";	// "BD-R Random Recording (RRM)";
	case 0x43 : return "bdre";	// "BD-RE rewritable";
	case 0x50 : return "hddvd";	// "HD DVD-ROM (retracted)";
	case 0x51 : return "hddvdr";	// "HD DVD-R (retracted)";
	case 0x52 : return "hddvdram";	// "HD DVD-RAM (retracted)";
	case 0x53 : return "hddvdrw";	// "HD DVD-RW (retracted)";
	case 0x58 : return "hddvdrdl";	// "HD DVD-R dual layer (retracted)";
	case 0x5a : return "hddvdrwdl"; // "HD DVD-RW dual layer (retracted)";
	}
	/* reserved */
	return NULL;
}


#define feat_tbl_len 300
#define max_profile 255
static void
devinfo_optical_disc_caps(int fd, HalDevice *d)
{
	uint8_t cmd[12], buf[feat_tbl_len], *fpos, *pos;
	char str[100];
	uint8_t present[max_profile+1];
	char const *name;
	int feature, feature_cur, feature_len, req_feature;
	int cnt, profile;
	int mrw, mrw_w, ok;

	/* set defaults */
	for (profile = 0; profile <= max_profile; profile++) {
		present[profile] = FALSE;
	}

	HAL_INFO(("devinfo_optical_disc_caps: get feature 0 SCSI call"));
	req_feature = 0;
	cmd[0] = 0x46;			/* Get configuration */
	cmd[1] = 0;			/* RT=0 -> all independent of current setting */
	cmd[2] = (req_feature) >> 8;	/* MSB feature number */
	cmd[3] = (req_feature) & 0xff;	/* LSB feature number */
	cmd[7] = (feat_tbl_len) >> 8;	/* MSB buffersize */
	cmd[8] = (feat_tbl_len) & 0xff;	/* LSB buffersize */
	cmd[9] = 0;			/* control */
	ok = scsi_command(fd, cmd, 10, buf, feat_tbl_len, 30000, SCCMD_READ);

	if (!ok)
		return;

	HAL_INFO(("devinfo_optical_disc_caps: processing profiles\n"));
	fpos = buf + 8;

	feature     =  fpos[1] | (fpos[0] << 8);
	feature_cur = (fpos[2] & 1);
	feature_len =  fpos[3];
	if (feature != 0) {
		HAL_INFO(("cdrom drive on crack, its not returning feature 0\n"));
		return;
	}

	if ((feature_len & 3) != 0)
		HAL_INFO(("*** drive returned bad feature length ***"));

	/* process feature */
	pos = &fpos[4];
	for (cnt=0; cnt < feature_len; cnt += 4) {
		profile = pos[1] | (pos[0] << 8);
		if (profile <= max_profile) {
			present[profile] = TRUE;
		} else {
			if (profile != 0xffff)
				HAL_INFO(("devinfo_optical_disc_caps: bump max_profile!, "
					  "found profile %d", profile));
		}
		pos += 4;
	}

	/* set hal properties */
	for (profile = 0; profile <= max_profile; profile++) {
		/* process profile */
		name = get_profile_name(d, profile);
		if (name) {
			strcpy(str, "storage.cdrom.");
			strcat(str, name);
			HAL_INFO(("Profile %d : %s : %s", profile, str,
				present[profile] ? "true":"false"));
			hal_device_property_set_bool(d, str, present[profile]);
		}
	}

	/* set MRW support; feature 0x28, version 0/1 */
	HAL_INFO(("devinfo_optical_disc_caps: get feature 0x28 SCSI call"));
	req_feature = 0x28;
	cmd[0] = 0x46;			/* Get configuration */
	cmd[1] = 0;			/* RT=0 -> all independent of current setting */
	cmd[2] = (req_feature) >> 8;	/* MSB feature number */
	cmd[3] = (req_feature) & 0xff;	/* LSB feature number */
	cmd[7] = (feat_tbl_len) >> 8;	/* MSB buffersize */
	cmd[8] = (feat_tbl_len) & 0xff;	/* LSB buffersize */
	cmd[9] = 0;			/* control */
	ok = scsi_command(fd, cmd, 10, buf, feat_tbl_len, 30000, SCCMD_READ);

	if (!ok)
		return;

	feature     =  fpos[1] | (fpos[0] << 8);
	feature_cur = (fpos[2] & 1);
	feature_len =  fpos[3];

	if ((feature_len & 3) != 0)
		HAL_INFO(("*** drive returned bad feature length ***"));

	HAL_INFO(("devinfo_optical_disc_caps: processing MRW\n"));
	/* process feature */
	pos = &fpos[4];
	mrw   = FALSE;
	mrw_w = FALSE;
	if (feature == 0x28) {
		mrw = TRUE;
		if (pos[0] & 1)
			mrw_w = TRUE;
	}
	hal_device_property_set_bool(d, "storage.cdrom.mrw", mrw);
	hal_device_property_set_bool(d, "storage.cdrom.mrw_w", mrw_w);

	/*
	 * XXX very rare to now have multi-session support; could be detected
	 * in the change bits of page 5, but set to true for now
	 */
	hal_device_property_set_bool(d, "storage.cdrom.support_multisession", TRUE);

	/* XXX realy? */
	hal_device_property_set_bool(d, "storage.cdrom.support_media_changed", TRUE);

	/* media dependent; addon-storage will handle these */
	//hal_device_property_set_int(d,"storage.cdrom.read_speed", 0);
	//hal_device_property_set_int(d,"storage.cdrom.write_speed", 0);
	//hal_device_property_set_string(d, "storage.cdrom.write_speeds", FALSE);
	
}
#undef max_profile
#undef feat_tbl_len


static HalDevice *
devinfo_optical_volume_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	HalDevice *d;
	struct stat devstat;
	char *devstr;
	int error;

	HAL_INFO (("devinfo_optical_volume_add: parent=%p devnode=%s devfs_path=%s device_type=%s",
	    parent, devnode, devfs_path, device_type));

	d = hal_device_new ();

	devstr = malloc(strlen(devnode) + 10);

	/* info */
	devinfo_set_default_properties (d, parent, devnode, devnode);
	hal_device_add_capability (d, "block");
	hal_device_add_capability (d, "volume");
	hal_device_add_capability (d, "volume.disc");
	hal_device_property_set_string (d, "info.category", "volume");

	/* block */
	sprintf(devstr, "/dev/%s", devnode);
        hal_device_property_set_string (d, "block.device", devstr);
	error = stat(devstr, &devstat);
	if (!error) {
	        hal_device_property_set_int (d, "block.major", major(devstat.st_rdev));
	        hal_device_property_set_int (d, "block.minor", minor(devstat.st_rdev));
	}
	sprintf(devstr, "/dev/r%s", devnode);
        hal_device_property_set_string (d, "block.netbsd.raw_device", devstr);

        hal_device_property_set_bool (d, "block.is_volume", TRUE);
        hal_device_property_set_bool (d, "block.no_partitions", TRUE);
        hal_device_property_set_bool (d, "block.have_scanned", TRUE);
        hal_device_property_set_string (d, "block.storage_device",
            hal_device_property_get_string (parent, "info.udi"));

	/* volume */
	hal_device_property_set_bool  (d, "volume.ignore", FALSE);
	hal_device_property_set_string(d, "volume.fsusage", "filesytem");
	hal_device_property_set_string(d, "volume.fstype",  "");
	hal_device_property_set_string(d, "volume.label",   "");
	hal_device_property_set_bool  (d, "volume.is_disc", TRUE);
	hal_device_property_set_bool  (d, "volume.is_partition", FALSE);
	/* rest by addon */

	/* volume.disc */
	/* by addon */

	devinfo_add_enqueue (d, devnode, &devinfo_optical_volume_handler);

	return d;
}


static HalDevice *
devinfo_optical_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	HalDevice *d;
	struct stat devstat;
	char *devstr;
	char *parent_devnode;
	int fd, error;

	if (strncmp(devnode, "cd", 2) != 0) {
		return (NULL);
	}

	HAL_INFO (("devinfo_optical_add: parent=%p devnode=%s devfs_path=%s device_type=%s",
	    parent, devnode, devfs_path, device_type));

	d = hal_device_new ();

	devstr = malloc(strlen(devnode) + 10);

	/* info */
	devinfo_set_default_properties (d, parent, devnode, devnode);
//	hal_device_property_set_string (d, "netbsd.device", devfs_path);

        hal_device_property_set_string (d, "info.subsystem", "block");
	hal_device_add_capability (d, "block");
	hal_device_add_capability (d, "storage");
	hal_device_add_capability (d, "storage.cdrom");

	/* block */
	sprintf(devstr, "/dev/%s%c", devnode, 'a' + RAW_PART);
        hal_device_property_set_string (d, "block.device", devstr);
	error = stat(devstr, &devstat);
	if (!error) {
	        hal_device_property_set_int (d, "block.major", major(devstat.st_rdev));
	        hal_device_property_set_int (d, "block.minor", minor(devstat.st_rdev));
	}
	sprintf(devstr, "/dev/r%s%c", devnode, 'a' + RAW_PART);
        hal_device_property_set_string (d, "block.netbsd.raw_device", devstr);

        hal_device_property_set_bool (d, "block.is_volume", FALSE);
        hal_device_property_set_bool (d, "block.no_partitions", TRUE);
        hal_device_property_set_bool (d, "block.have_scanned", TRUE);

	/* storage */
	parent_devnode = hal_device_property_get_string (parent, "netbsd.device");
	if (strstr (parent_devnode, "umass") == parent_devnode)
		hal_device_property_set_string (d, "storage.bus", "usb");
	else if (strstr (parent_devnode, "atapi") == parent_devnode)
		hal_device_property_set_string (d, "storage.bus", "ide");
	else
		hal_device_property_set_string (d, "storage.bus", "scsi");

	hal_device_property_set_string (d, "storage.drive_type", "cdrom");
	hal_device_property_set_bool (d, "storage.removable", TRUE);
	/* "storage.removable.media_available" set by addon-storage */
	/* "storage.removable.media_size" set by addon-storage */
	hal_device_property_set_bool (d, "storage.removable.support_async_notification", FALSE);
	hal_device_property_set_bool (d, "storage.requires_eject", TRUE);
	hal_device_property_set_bool (d, "storage.hotpluggable", TRUE);
	hal_device_property_set_bool (d, "storage.media_check_enabled", TRUE);	   /* XXX */
	hal_device_property_set_bool (d, "storage.automount_enabled_hint", FALSE); /* multiple choice */
	hal_device_property_set_bool (d, "storage.no_partitions_hint", TRUE);
	hal_device_property_set_string (d, "storage.originating_device", "");      /* XXX */

	fd = open(devstr, O_RDONLY, 0);
	if (fd) {
		/* get drive's vendor and model name */
		devinfo_optical_identify_drive(d, devstr);

		/* get CD specific `storage.cdrom' values */
		devinfo_optical_disc_caps(fd, d);

	}
	devinfo_add_enqueue (d, devnode, &devinfo_optical_handler);
	if (fd) {
		/* create CD volume node */
		sprintf(devstr, "%s%c", devnode, 'a' + RAW_PART);
		devinfo_optical_volume_add(d, devstr, devfs_path, "volume");
	}
	close(fd);

	return (d);
}

