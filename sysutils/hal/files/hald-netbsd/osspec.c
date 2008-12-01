/***************************************************************************
 *
 * osspec.c : NetBSD HAL backend entry points
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

#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#include "../osspec.h"
#include "../logger.h"
#include "../hald.h"
#include "../hald_dbus.h"
#include "../device_info.h"
#include "../util.h"
#include "../ids.h"
#include "osspec_netbsd.h"
#include "hotplug.h"
#include "drvctl.h"
#include "envsys.h"
#include "devinfo.h"
#include "devinfo_storage.h"

static void mntinfo_event_init ();
static gboolean mntinfo_timeout (gpointer user_data);

HalFileMonitor *
osspec_get_file_monitor (void)
{
#warning Please implement
        return NULL;
}

void
osspec_init (void)
{
	ids_init ();
	mntinfo_event_init ();
	envsys_init ();
}

void
osspec_privileged_init (void)
{
	drvctl_init ();
}

void
hotplug_queue_now_empty (void)
{
        if (hald_is_initialising) {
                osspec_probe_done ();
	}
}

void 
osspec_probe (void)
{
	/* add entire device tree */
	devinfo_add (NULL, "mainbus0");

	/* start processing events */
	hotplug_event_process_queue ();
}

gboolean
osspec_device_rescan (HalDevice *d)
{
	   return (devinfo_device_rescan (d));
}

gboolean
osspec_device_reprobe (HalDevice *d)
{
	   return FALSE;
}

DBusHandlerResult
osspec_filter_function (DBusConnection *connection, DBusMessage *message, void *user_data)
{
	return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
}

/** 
 *  hal_util_find_closest_ancestor:
 *  @devfs_path:           Path into devfs, e.g. /pci@0,0/pci1025,57@10,2/storage@1
 *
 *  Returns:               Parent Hal Device Object or #NULL if there is none
 *
 *  Find the closest ancestor by looking at devfs paths
 */
HalDevice *
hal_util_find_closest_ancestor (const gchar *devfs_path, gchar **ancestor_devfs_path, gchar **hotplug_devfs_path)
{
        gchar buf[512];
	gchar c;
        HalDevice *parent;

        parent = NULL;

	if (drvctl_find_parent (devfs_path, buf) == FALSE)
		return NULL;

	HAL_INFO (("hal_util_find_closest_ancestor: devnode=%s parent=%s\n", devfs_path, buf));

        parent = hal_device_store_match_key_value_string (hald_get_gdl (),
                                                          "netbsd.device",
                                                          buf);
        if (parent != NULL) {
		if (ancestor_devfs_path != NULL) {
			*ancestor_devfs_path = g_strdup (buf);
		}
		if (hotplug_devfs_path != NULL) {
			*hotplug_devfs_path = g_strdup (buf);
		}
	}

        return parent;
}

char *
dsk_to_rdsk(char *dsk)
{
        int     len, pos;
        char    *p;
        char    *rdsk;

	if ((len = strlen (dsk)) < sizeof ("/dev/AANA") - 1) {
		return (strdup(""));
	}
	p = strstr (dsk, "/dev/");
	if (p == NULL) {
		return (strdup(""));
	}

	pos = (uintptr_t)p - (uintptr_t)dsk;
	if ((rdsk = (char *)calloc (len + 2, 1)) != NULL) {
        	strncpy (rdsk, dsk, pos + 1);
        	rdsk[pos + 1] = 'r';
        	strcpy (rdsk + pos + 2, dsk + pos + 1);
	}

        return (rdsk);
}

/*
 * Setup to watch mntinfo changes
 */
static void
mntinfo_event_init ()
{
	g_timeout_add (1000, mntinfo_timeout, NULL);
}

static gboolean
mntinfo_timeout (gpointer user_data)
{
	if (!hald_is_initialising)
		vfsstat_event (NULL);

	return TRUE;
}

void
osspec_refresh_mount_state_for_block_device (HalDevice *d)
{
	vfsstat_event (d);
}
