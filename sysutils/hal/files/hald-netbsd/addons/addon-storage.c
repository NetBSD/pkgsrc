/***************************************************************************
 *
 * addon-storage.c : watch removable media state changes
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

#include <errno.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/statvfs.h>
#include <sys/dkio.h>
#include <dev/scsipi/scsi_spc.h>
#include <dev/scsipi/scsipi_all.h>
#include <dev/scsipi/scsipi_cd.h>
#include <sys/scsiio.h>

#include <libhal.h>

#include <logger.h>

#define	SLEEP_PERIOD	5

enum discstate {
	DISC_INSERTED,
	DISC_EJECTED,
	DISC_NONE,
	DISC_UNKNOWN
};

static enum discstate
scsi_test_unit_ready (int fd)
{
	struct scsi_test_unit_ready tur;
	scsireq_t req;

	memset(&tur, 0, sizeof(tur));
	tur.opcode = SCSI_TEST_UNIT_READY;

	memset(&req, 0, sizeof(req));
	memcpy(req.cmd, &tur, sizeof(tur));
	req.cmdlen = sizeof(tur);
	req.databuf = NULL;
	req.datalen = 0;
	req.timeout = 10000;
	req.flags = SCCMD_READ;
	req.senselen = SENSEBUFLEN;

	if (ioctl(fd, SCIOCCOMMAND, &req) == -1)
		return DISC_UNKNOWN;
	if (req.retsts == SCCMD_OK)
		return DISC_INSERTED;
	return DISC_EJECTED;
}

static void
my_dbus_error_free(DBusError *error)
{
	if (dbus_error_is_set(error)) {
		dbus_error_free(error);
	}
}

static void
force_unmount (LibHalContext *ctx, const char *udi)
{
	DBusError error;
	DBusMessage *msg = NULL;
	DBusMessage *reply = NULL;
	char **options = NULL;
	unsigned int num_options = 0;
	DBusConnection *dbus_connection;
	char *device_file;

	dbus_error_init (&error);

	dbus_connection = libhal_ctx_get_dbus_connection (ctx);

	msg = dbus_message_new_method_call ("org.freedesktop.Hal", udi,
					    "org.freedesktop.Hal.Device.Volume",
					    "Unmount");
	if (msg == NULL) {
		HAL_DEBUG (("Could not create dbus message for %s", udi));
		goto out;
	}


	options = calloc (1, sizeof (char *));
	if (options == NULL) {
		HAL_DEBUG (("Could not allocate options array"));
		goto out;
	}

	device_file = libhal_device_get_property_string (ctx, udi, "block.device", &error);
	if (device_file != NULL) {
		libhal_free_string (device_file);
	}
	dbus_error_free (&error);

	if (!dbus_message_append_args (msg, 
				       DBUS_TYPE_ARRAY, DBUS_TYPE_STRING, &options, num_options,
				       DBUS_TYPE_INVALID)) {
		HAL_DEBUG (("Could not append args to dbus message for %s", udi));
		goto out;
	}
	
	if (!(reply = dbus_connection_send_with_reply_and_block (dbus_connection, msg, -1, &error))) {
		HAL_DEBUG (("Unmount failed for %s: %s : %s\n", udi, error.name, error.message));
		goto out;
	}

	if (dbus_error_is_set (&error)) {
		HAL_DEBUG (("Unmount failed for %s\n%s : %s\n", udi, error.name, error.message));
		goto out;
	}

	HAL_DEBUG (("Succesfully unmounted udi '%s'", udi));

out:
	dbus_error_free (&error);
	if (options != NULL)
		free (options);
	if (msg != NULL)
		dbus_message_unref (msg);
	if (reply != NULL)
		dbus_message_unref (reply);
}

static void 
unmount_childs (LibHalContext *ctx, const char *udi)
{
	DBusError error;
	int num_volumes;
	char **volumes;

	dbus_error_init (&error);

	/* need to force unmount all partitions */
	if ((volumes = libhal_manager_find_device_string_match (
	     ctx, "block.storage_device", udi, &num_volumes, &error)) != NULL) {
		dbus_error_free (&error);
		int i;

		for (i = 0; i < num_volumes; i++) {
			char *vol_udi;

			vol_udi = volumes[i];
			if (libhal_device_get_property_bool (ctx, vol_udi, "block.is_volume", &error)) {
				dbus_error_free (&error);
				if (libhal_device_get_property_bool (ctx, vol_udi, "volume.is_mounted", &error)) {
					dbus_error_free (&error);
					HAL_DEBUG (("Forcing unmount of child '%s'", vol_udi));
					force_unmount (ctx, vol_udi);
				}
			}
		}
		libhal_free_string_array (volumes);
	}
	my_dbus_error_free (&error);
}

/** Check if a filesystem on a special device file is mounted
 *
 *  @param  device_file         Special device file, e.g. /dev/cdrom
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

static void
close_device (int *fd)
{
	if (*fd > 0) {
		close (*fd);
		*fd = -1;
	}
}

int 
main (int argc, char *argv[])
{
	char *udi;
	char *device_file, *raw_device_file;
	LibHalContext *ctx = NULL;
	DBusError error;
	char *bus;
	char *drive_type;
	int state, last_state;
	char *support_media_changed_str;
	int support_media_changed;
	int fd = -1;

	if ((udi = getenv ("UDI")) == NULL)
		goto out;
	if ((device_file = getenv ("HAL_PROP_BLOCK_DEVICE")) == NULL)
		goto out;
	if ((raw_device_file = getenv ("HAL_PROP_BLOCK_NETBSD_RAW_DEVICE")) == NULL)
		goto out;
	if ((bus = getenv ("HAL_PROP_STORAGE_BUS")) == NULL)
		goto out;
	if ((drive_type = getenv ("HAL_PROP_STORAGE_DRIVE_TYPE")) == NULL)
		goto out;

	setup_logger ();

	support_media_changed_str = getenv ("HAL_PROP_STORAGE_CDROM_SUPPORT_MEDIA_CHANGED");
	if (support_media_changed_str != NULL && strcmp (support_media_changed_str, "true") == 0)
		support_media_changed = TRUE;
	else
		support_media_changed = FALSE;

	dbus_error_init (&error);

	if ((ctx = libhal_ctx_init_direct (&error)) == NULL) {
		goto out;
	}
	my_dbus_error_free (&error);

	if (!libhal_device_addon_is_ready (ctx, udi, &error)) {
		goto out;
	}
	my_dbus_error_free (&error);

	printf ("Doing addon-storage for %s (bus %s) (drive_type %s) (udi %s)\n", device_file, bus, drive_type, udi);

	last_state = state = DISC_NONE;

	/* Linux version of this addon attempts to re-open the device O_EXCL
	 * every 2 seconds, trying to figure out if some other app,
	 * like a cd burner, is using the device. Aside from questionable
	 * value of this (apps should use HAL's locked property or/and
	 * Solaris in_use facility), but also frequent opens/closes
	 * keeps media constantly spun up. All this needs more thought.
	 */
	for (;;) {
		sleep (SLEEP_PERIOD);
		if (is_mounted (device_file)) {
			close_device (&fd);
		} else if ((fd < 0) && ((fd = open (raw_device_file, O_RDONLY | O_NONBLOCK)) < 0)) {
			HAL_DEBUG (("open failed for %s: %s", raw_device_file, strerror (errno)));
		} else {
			/* Check if a disc is in the drive */
			state = scsi_test_unit_ready (fd);

			if (state == last_state) {
				HAL_DEBUG (("state has not changed %d %s", state, device_file));
				continue;
			} else {
				HAL_DEBUG (("new state %d %s", state, device_file));
			}

			switch (state) {
			case DISC_EJECTED:
				HAL_DEBUG (("Media removal detected on %s", device_file));
				last_state = state;

				libhal_device_set_property_bool (ctx, udi, "storage.removable.media_available", FALSE, &error);
				my_dbus_error_free (&error);

				/* attempt to unmount all childs */
				unmount_childs (ctx, udi);

				/* could have a fs on the main block device; do a rescan to remove it */
				libhal_device_rescan (ctx, udi, &error);
				my_dbus_error_free (&error);
				break;

			case DISC_INSERTED:
				HAL_DEBUG (("Media insertion detected on %s", device_file));
				last_state = state;

				libhal_device_set_property_bool (ctx, udi, "storage.removable.media_available", TRUE, &error);
				my_dbus_error_free (&error);

				/* could have a fs on the main block device; do a rescan to add it */
				libhal_device_rescan (ctx, udi, &error);
				my_dbus_error_free (&error);
				break;

			case DISC_UNKNOWN:
			default:
				HAL_DEBUG (("Device gone detected on %s", device_file));
				last_state = state;

				unmount_childs (ctx, udi);
				close_device (&fd);
				goto out;

			}
		}
	}

out:
	if (ctx != NULL) {
		my_dbus_error_free (&error);
		libhal_ctx_shutdown (ctx, &error);
		libhal_ctx_free (ctx);
	}

	return 0;
}
