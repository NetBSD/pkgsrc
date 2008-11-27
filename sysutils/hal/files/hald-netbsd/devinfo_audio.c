/* $NetBSD: devinfo_audio.c,v 1.2 2008/11/27 18:00:44 jmcneill Exp $ */

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

#include <sys/audioio.h>
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
#include "devinfo_audio.h"
#include "drvctl.h"

HalDevice *devinfo_audio_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type);
HalDevice *devinfo_audio_mixer_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type);
HalDevice *devinfo_audio_dsp_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type);

DevinfoDevHandler devinfo_audio_handler = {
	devinfo_audio_add,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};
DevinfoDevHandler devinfo_audio_mixer_handler = {
	devinfo_audio_mixer_add,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};
DevinfoDevHandler devinfo_audio_dsp_handler = {
	devinfo_audio_dsp_add,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

HalDevice *
devinfo_audio_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	HalDevice *d = NULL, *mixer, *dsp;
	prop_dictionary_t dict;
	const char *driver, *parent_udi;
	char *childnode;
	int16_t unit;
	char *audioctl;
	struct audio_device audiodev;
	int fd;

	if (drvctl_find_device (devnode, &dict) == FALSE || dict == NULL)
		return NULL;

	if (prop_dictionary_get_int16 (dict, "device-unit", &unit) == false ||
	    prop_dictionary_get_cstring_nocopy (dict, "device-driver", &driver) == false) {
		prop_object_release (dict);
		return NULL;
	}

	if (strcmp (driver, "audio") != 0) {
		prop_object_release (dict);
		return NULL;
	}

	audioctl = g_strdup_printf (_PATH_AUDIOCTL "%d", unit);
	fd = open (audioctl, O_RDONLY);
	if (fd < 0) {
		HAL_WARNING (("couldn't open %s: %s", audioctl, strerror(errno)));
		goto done;
	}

	if (ioctl (fd, AUDIO_GETDEV, &audiodev) == -1) {
		HAL_WARNING (("couldn't query %s: %s", audioctl, strerror(errno)));
		goto done;
	}

	d = hal_device_new ();

	devinfo_set_default_properties (d, parent, devnode, devfs_path);
	hal_device_add_capability (d, "sound");
	hal_device_property_set_string (d, "info.category", "sound");
	hal_device_property_set_string (d, "info.subsystem", "sound");

	hal_device_property_set_int (d, "sound.card", unit);
	hal_device_property_set_string (d, "sound.card_id", audiodev.name);
	hal_device_property_set_string (d, "netbsd.sound.hardware", audiodev.config);

	parent_udi = hal_device_property_get_string (parent, "info.udi");
	if (parent_udi)
		hal_device_property_set_string (d, "sound.originating_device", parent_udi);

	devinfo_add_enqueue (d, devfs_path, &devinfo_audio_handler);

	childnode = g_strdup_printf ("oss_mixer_%d", unit);
	devinfo_add_node (d, childnode);
	g_free (childnode);

	childnode = g_strdup_printf ("oss_dsp_%d", unit);
	devinfo_add_node (d, childnode);
	g_free (childnode);

done:
	if (dict)
		prop_object_release (dict);
	if (audioctl)
		g_free (audioctl);
	if (fd >= 0)
		close (fd);

	return d;
}

HalDevice *
devinfo_audio_mixer_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	HalDevice *d = NULL;
	char *device_file, *parent_udi, *card_id, *device_id;
	int16_t unit;

	if (strstr (devnode, "oss_mixer_") != devnode)
		return NULL;

	d = hal_device_new ();

	devinfo_set_default_properties (d, parent, devnode, devfs_path);
	hal_device_add_capability (d, "oss");
	hal_device_property_set_string (d, "info.category", "oss");
	hal_device_property_set_string (d, "info.subsystem", "sound");

	card_id = hal_device_property_get_string (parent, "sound.card_id");
	hal_device_property_set_string (d, "oss.card_id", card_id);
	unit = hal_device_property_get_int (parent, "sound.card");
	hal_device_property_set_int (d, "oss.card", unit);
	hal_device_property_set_int (d, "oss.device", unit + 16);
	device_id = hal_device_property_get_string (parent, "netbsd.sound.hardware");
	hal_device_property_set_string (d, "oss.device_id", device_id);
	hal_device_property_set_string (d, "oss.type", "mixer");

	device_file = g_strdup_printf (_PATH_MIXER "%d", unit);
	hal_device_property_set_string (d, "oss.device_file", device_file);
	g_free (device_file);

	parent_udi = hal_device_property_get_string (parent, "info.udi");
	if (parent_udi)
		hal_device_property_set_string (d, "sound.originating_device", parent_udi);

	devinfo_add_enqueue (d, devfs_path, &devinfo_audio_mixer_handler);

	return d;
}

HalDevice *
devinfo_audio_dsp_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	HalDevice *d = NULL;
	char *device_file, *parent_udi, *card_id, *device_id;
	int16_t unit;

	if (strstr (devnode, "oss_dsp_") != devnode)
		return NULL;

	d = hal_device_new ();

	devinfo_set_default_properties (d, parent, devnode, devfs_path);
	hal_device_add_capability (d, "oss");
	hal_device_property_set_string (d, "info.category", "oss");
	hal_device_property_set_string (d, "info.subsystem", "sound");

	card_id = hal_device_property_get_string (parent, "sound.card_id");
	hal_device_property_set_string (d, "oss.card_id", card_id);
	unit = hal_device_property_get_int (parent, "sound.card");
	hal_device_property_set_int (d, "oss.card", unit);
	hal_device_property_set_int (d, "oss.device", unit);
	device_id = hal_device_property_get_string (parent, "netbsd.sound.hardware");
	hal_device_property_set_string (d, "oss.device_id", device_id);
	hal_device_property_set_string (d, "oss.type", "pcm");

	device_file = g_strdup_printf (_PATH_SOUND "%d", unit);
	hal_device_property_set_string (d, "oss.device_file", device_file);
	g_free (device_file);

	parent_udi = hal_device_property_get_string (parent, "info.udi");
	if (parent_udi)
		hal_device_property_set_string (d, "sound.originating_device", parent_udi);

	devinfo_add_enqueue (d, devfs_path, &devinfo_audio_dsp_handler);

	return d;
}
