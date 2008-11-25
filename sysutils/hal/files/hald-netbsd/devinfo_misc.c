/***************************************************************************
 *
 * devinfo_misc : misc devices
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
#include <string.h>
#include <sys/utsname.h>

#include "../osspec.h"
#include "../logger.h"
#include "../hald.h"
#include "../hald_dbus.h"
#include "../device_info.h"
#include "../util.h"
#include "devinfo_misc.h"

static HalDevice *devinfo_computer_add(HalDevice *, const char *, char *, char *);
static HalDevice *devinfo_cpu_add(HalDevice *, const char *, char *,char *);
static HalDevice *devinfo_default_add(HalDevice *, const char *, char *, char *);

DevinfoDevHandler devinfo_computer_handler = {
        devinfo_computer_add,
	NULL,
	NULL,
	NULL,
	NULL,
        NULL
};
DevinfoDevHandler devinfo_cpu_handler = {
        devinfo_cpu_add,
	NULL,
	NULL,
	NULL,
	NULL,
        NULL
};
DevinfoDevHandler devinfo_default_handler = {
        devinfo_default_add,
	NULL,
	NULL,
	NULL,
	NULL,
        NULL
};

static HalDevice *
devinfo_computer_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	HalDevice *d, *local_d;
	struct utsname un;

	if (strcmp (devnode, "mainbus0") != 0) {
		return (NULL);
	}

	HAL_INFO (("devinfo_computer_add parent=%p devnode=%s devfs_path=%s device_type=%s",
	    parent, devnode, devfs_path, device_type));

	d = hal_device_new ();

        hal_device_property_set_string (d, "info.subsystem", "unknown");
        hal_device_property_set_string (d, "info.product", "Computer");
        hal_device_set_udi (d, "/org/freedesktop/Hal/devices/computer");
	hal_device_property_set_string (d, "netbsd.device", devnode);

	if (uname (&un) >= 0) {
		hal_device_property_set_string (d, "system.kernel.name", un.sysname);
		hal_device_property_set_string (d, "system.kernel.version", un.release);
		hal_device_property_set_string (d, "system.kernel.machine", un.machine);
	}

	devinfo_add_enqueue (d, devfs_path, &devinfo_computer_handler);

	/* all devinfo devices belong to the 'local' branch */
	local_d = hal_device_new ();

	hal_device_property_set_string (local_d, "info.parent", hal_device_get_udi (d));
        hal_device_property_set_string (local_d, "info.subsystem", "unknown");
        hal_device_property_set_string (local_d, "info.product", "Local devices");
	hal_device_property_set_string (local_d, "netbsd.device", devnode);

	devinfo_add_enqueue (local_d, devnode, &devinfo_default_handler);

	return (local_d);
}

static HalDevice *
devinfo_cpu_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	HalDevice *d;

	if (strncmp(devnode, "cpu", 3) != 0) {
		return (NULL);
	}

	HAL_INFO (("devinfo_cpu_add: parent=%p devnode=%s devfs_path=%s device_type=%s",
	    parent, devnode, devfs_path, device_type));

	d = hal_device_new ();

	devinfo_set_default_properties (d, parent, devnode, devnode);
	hal_device_add_capability (d, "processor");

	devinfo_add_enqueue (d, devnode, &devinfo_cpu_handler);

	return (d);
}

static HalDevice *
devinfo_default_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	char *driver_name;
	const char *parent_path;
	HalDevice *d;

	d = hal_device_new ();

	devinfo_set_default_properties (d, parent, devnode, devnode);

	devinfo_add_enqueue (d, devnode, &devinfo_default_handler);

	return (d);
}
