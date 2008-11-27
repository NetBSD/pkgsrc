/* $NetBSD: devinfo_video.c,v 1.1 2008/11/27 22:19:10 jmcneill Exp $ */

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

#include <sys/videoio.h>
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
#include "../device_info.h"
#include "../util.h"
#include "../ids.h"
#include "hotplug.h"
#include "devinfo.h"
#include "devinfo_video.h"
#include "drvctl.h"

HalDevice *devinfo_video_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type);

DevinfoDevHandler devinfo_video_handler = {
	devinfo_video_add,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

HalDevice *
devinfo_video_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	HalDevice *d = NULL;
	prop_dictionary_t dict;
	const char *driver, *parent_udi;
	char *videodev;
	int16_t unit;
	struct v4l2_capability caps;
	int fd;

	if (drvctl_find_device (devnode, &dict) == FALSE || dict == NULL)
		return NULL;

	if (prop_dictionary_get_int16 (dict, "device-unit", &unit) == false ||
	    prop_dictionary_get_cstring_nocopy (dict, "device-driver", &driver) == false) {
		prop_object_release (dict);
		return NULL;
	}

	prop_object_release (dict);

	if (strcmp (driver, "video") != 0)
		return NULL;

	videodev = g_strdup_printf ("/dev/video%d", unit);
	fd = open (videodev, O_RDONLY);
	if (fd < 0) {
		HAL_WARNING (("couldn't open %s: %s", videodev, strerror(errno)));
		goto done;
	}

	if (ioctl (fd, VIDIOC_QUERYCAP, &caps) == -1) {
		HAL_WARNING (("couldn't query %s: %s", videodev, strerror(errno)));
		close (fd);
		goto done;
	}

	close (fd);

	d = hal_device_new ();

	devinfo_set_default_properties (d, parent, devnode, devfs_path);
	hal_device_add_capability (d, "video4linux");
	if (caps.capabilities & V4L2_CAP_VIDEO_CAPTURE)
		hal_device_add_capability (d, "video4linux.video_capture");
	hal_device_property_set_string (d, "info.category", "video4linux");
	hal_device_property_set_string (d, "info.subsystem", "video4linux");

	hal_device_property_set_string (d, "video4linux.device", videodev);
	hal_device_property_set_int (d, "video4linux.version", 2);
	hal_device_property_set_string (d, "info.product", caps.card);

	devinfo_add_enqueue (d, devfs_path, &devinfo_video_handler);

done:
	if (videodev)
		g_free (videodev);

	return d;
}
