/* $NetBSD: vfsstat.c,v 1.1 2008/12/01 02:02:33 jmcneill Exp $ */

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

#include <sys/types.h>
#include <sys/statvfs.h>
#include <sys/ioctl.h>
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
#include "../hald_runner.h"
#include "../device_info.h"
#include "../util.h"
#include "../ids.h"
#include "hotplug.h"
#include "devinfo.h"
#include "vfsstat.h"
#include "drvctl.h"

static void
vfsstat_cleanup_mountpoint_cb(HalDevice *d, guint32 exit_type,
    gint return_code, gchar **error, gpointer data1, gpointer data2)
{
	char *mount_point = data1;

	HAL_INFO (("cleaned up mount point %s", mount_point));

	g_free (mount_point);
}

void
vfsstat_event(HalDevice *volume)
{
	GSList *volumes, *v;
	HalDevice *d;
	struct statvfs *statvfs;
	int nmounts, i;

	if (volume == NULL)
		volumes = hal_device_store_match_multiple_key_value_string (hald_get_gdl (), "info.category", "volume");
	else
		volumes = g_slist_append (NULL, volume);

	if (volumes == NULL)
		return;

	nmounts = getvfsstat (NULL, 0, ST_WAIT);
	if (nmounts <= 0)
		return;
	statvfs = calloc (nmounts, sizeof (*statvfs));
	if (statvfs == NULL)
		return;
	nmounts = getvfsstat (statvfs, nmounts * sizeof (*statvfs), ST_WAIT);
	if (nmounts <= 0)
		goto done;

	for (i = 0; i < nmounts; i++)
		for (v = volumes; v; v = g_slist_next (v)) {
			const char *devpath;

			d = HAL_DEVICE (v->data);
			devpath = hal_device_property_get_string (d, "block.device");
			if (devpath == NULL || strlen (devpath) == 0)
				continue;
			if (strcmp (devpath, statvfs[i].f_mntfromname) != 0)
				continue;

			device_property_atomic_update_begin ();
			hal_device_property_set_bool (d, "volume.is_mounted", TRUE);
			hal_device_property_set_bool (d, "volume.is_mounted_read_only",
			    statvfs[i].f_flag & ST_RDONLY ? TRUE : FALSE);
			hal_device_property_set_string (d, "volume.mount_point", statvfs[i].f_mntonname);
			device_property_atomic_update_end ();

			volumes = g_slist_delete_link (volumes, v);
		}

	for (v = volumes; v; v = g_slist_next (v)) {
		const char *mount_path;

		d = HAL_DEVICE (v->data);
		mount_path = g_strdup (hal_device_property_get_string (d, "volume.mount_point"));
		if (mount_path == NULL || strlen (mount_path) == 0) {
			if (mount_path)
				g_free (mount_path);
			continue;
		}

		device_property_atomic_update_begin ();
		hal_device_property_set_bool (d, "volume.is_mounted", FALSE);
		hal_device_property_set_bool (d, "volume.is_mounted_read_only", FALSE);
		hal_device_property_set_string (d, "volume.mount_point", "");
		device_property_atomic_update_end ();

		if (hal_util_is_mounted_by_hald (mount_path)) {
			char *cleanup_stdin;
			char *extra_env[2];

			extra_env[0] = g_strdup_printf ("HALD_CLEANUP=%s", mount_path);
			extra_env[1] = NULL;
			cleanup_stdin = "\n";

			hald_runner_run_method (d,
						"hal-storage-cleanup-mountpoint",
						extra_env,
						cleanup_stdin, TRUE,
						0,
						vfsstat_cleanup_mountpoint_cb,
						g_strdup (mount_path), NULL);

			g_free (extra_env[0]);
		}

		g_free (mount_path);
	}

	g_slist_free (volumes);

done:
	free (statvfs);
}
