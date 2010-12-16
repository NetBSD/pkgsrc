/* $NetBSD: envsys.c,v 1.6 2010/12/16 11:34:51 ahoka Exp $ */

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
#include <sys/ioctl.h>
#include <sys/envsys.h>

#include <prop/proplib.h>

#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../osspec.h"
#include "../logger.h"
#include "../hald.h"
#include "../hald_dbus.h"
#include "../device_info.h"
#include "../util.h"
#include "devinfo.h"
#include "envsys.h"

#define _DEV_SYSMON	"/dev/sysmon"

static int envsys_fd = -1;

static gboolean	envsys_timeout(gpointer user_data);
static void envsys_handle_devnode(const char *devnode, prop_array_t properties);

static void envsys_acadapter_handler(HalDevice *d, prop_array_t properties);
static void envsys_battery_handler(HalDevice *d, prop_array_t properties);

enum battery_state {
	CHARGING,
	DISCHARGING,
	NORMAL
};

static struct envsys_devmap {
	const char *capability;
	void (*handler)(HalDevice *d, prop_array_t properties);
} devmap[] = {
	{ "ac_adapter",	envsys_acadapter_handler },
	{ "battery",	envsys_battery_handler },
};

void
envsys_init(void)
{
	envsys_fd = open (_DEV_SYSMON, O_RDONLY);
	if (envsys_fd == -1) {
		HAL_WARNING (("Couldn't open " _DEV_SYSMON ": %s", strerror(errno)));
		return;
	}

	g_timeout_add (1000, envsys_timeout, NULL);
}

static gboolean
envsys_timeout(gpointer user_data)
{
	prop_dictionary_t global_dict;
	prop_array_t global_array;
	prop_object_iterator_t iter;
	prop_dictionary_keysym_t keysym;
	int status;

	status = prop_dictionary_recv_ioctl (envsys_fd, ENVSYS_GETDICTIONARY, &global_dict);
	if (status) {
		HAL_WARNING (("envsys_timeout: ENVSYS_GETDICTIONARY failed: %s", strerror(status)));
		return FALSE;
	}

	global_array = prop_dictionary_all_keys (global_dict);
	if (global_array == NULL) {
		HAL_WARNING (("envsys_timeout: prop_dictionary_all_keys returned NULL"));
		return FALSE;
	}
	iter = prop_array_iterator (global_array);
	while ((keysym = (prop_dictionary_keysym_t)prop_object_iterator_next (iter)) != NULL) {
		const char *devnode;
		prop_object_t obj;

		devnode = prop_dictionary_keysym_cstring_nocopy (keysym);
		obj = prop_dictionary_get_keysym (global_dict, keysym);
		if (obj == NULL || prop_object_type (obj) != PROP_TYPE_ARRAY)
			continue;

		envsys_handle_devnode (devnode, (prop_array_t)obj);
	}
	prop_object_iterator_release (iter);

	prop_object_release (global_array);
	prop_object_release (global_dict);
	return TRUE;
}

static void
envsys_handle_devnode(const char *devnode, prop_array_t properties)
{
	HalDevice *d;
	unsigned int i;

	d = hal_device_store_match_key_value_string (hald_get_gdl (), "netbsd.device", devnode);
	if (d == NULL)
		return;

	for (i = 0; i < __arraycount (devmap); i++) {
		if (!hal_device_has_capability (d, devmap[i].capability))
			continue;
		devmap[i].handler (d, properties);
	}

	return;
}

static void
envsys_acadapter_handler(HalDevice *d, prop_array_t properties)
{
	prop_object_iterator_t iter;
	prop_dictionary_t prop;

	iter = prop_array_iterator (properties);
	while ((prop = (prop_dictionary_t)prop_object_iterator_next (iter)) != NULL) {
		const char *descr;
		uint8_t connected;

		if (prop_dictionary_get_cstring_nocopy (prop, "description", &descr) == false)
			continue;

		if (strcmp (descr, "connected") != 0)
			continue;

		if (prop_dictionary_get_uint8 (prop, "cur-value", &connected) == false)
			continue;

		hal_device_property_set_bool (d, "ac_adapter.present", connected);
	}

	prop_object_iterator_release (iter);
}

static void
envsys_battery_handler(HalDevice *d, prop_array_t properties)
{
	prop_object_iterator_t iter;
	prop_dictionary_t prop;
	enum battery_state battstate = NORMAL;

	device_property_atomic_update_begin ();

	hal_device_property_set_bool (d, "battery.is_rechargeable", TRUE);

	iter = prop_array_iterator (properties);
	while ((prop = (prop_dictionary_t)prop_object_iterator_next (iter)) != NULL) {
		const char *descr;
		const char *valid;
		int64_t intval;

		if (prop_dictionary_get_cstring_nocopy (prop, "description", &descr) == false ||
		    prop_dictionary_get_int64 (prop, "cur-value", &intval) == false ||
		    prop_dictionary_get_cstring_nocopy (prop, "state", &valid) == false ||
		    strcmp (valid, "valid") != 0)
			continue;

		if (strcmp (descr, "present") == 0)
			hal_device_property_set_bool (d, "battery.present", intval);
		else if (strcmp (descr, "design cap") == 0)
			hal_device_property_set_int (d, "battery.charge_level.design", intval);
		else if (strcmp (descr, "last full cap") == 0)
			hal_device_property_set_int (d, "battery.charge_level.last_full", intval);
		else if (strcmp (descr, "charge") == 0) {
			int64_t maxval;
			const char *type;

			if (prop_dictionary_get_cstring_nocopy (prop, "type", &type))
				if (strcmp (type, "Ampere hour") == 0) {
					/* HAL 0.5.12 spec discourages this, but what can we do about it? */
					hal_device_property_set_string (d, "battery.charge_level.unit", "mAh");
				}

			hal_device_property_set_int (d, "battery.charge_level.current", intval);

			if (prop_dictionary_get_int64 (prop, "max-value", &maxval) && maxval > 0)
				hal_device_property_set_int (d, "battery.charge_level.percentage", intval * 100 / maxval);
			else
				hal_device_property_set_int (d, "battery.charge_level.percentage", 0);
		}
		else if (strcmp (descr, "charge rate") == 0) {
			battstate = CHARGING;
			hal_device_property_set_int (d, "battery.charge_level.rate", intval);
		} else if (strcmp (descr, "discharge rate") == 0) {
			battstate = DISCHARGING;
			hal_device_property_set_int (d, "battery.charge_level.rate", intval);
		}
	}

	switch (battstate) {
	case NORMAL:
		hal_device_property_set_bool (d, "battery.rechargeable.is_charging", FALSE);
		hal_device_property_set_bool (d, "battery.rechargeable.is_discharging", FALSE);
		hal_device_property_set_int (d, "battery.charge_level.rate", 0);
		break;
	case CHARGING:
		hal_device_property_set_bool (d, "battery.rechargeable.is_charging", TRUE);
		hal_device_property_set_bool (d, "battery.rechargeable.is_discharging", FALSE);
		break;
	case DISCHARGING:
		hal_device_property_set_bool (d, "battery.rechargeable.is_charging", FALSE);
		hal_device_property_set_bool (d, "battery.rechargeable.is_discharging", TRUE);
		break;
	}

	device_property_atomic_update_end ();

	prop_object_iterator_release (iter);
}
