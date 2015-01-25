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

#include <sys/types.h>
#include <sys/sysctl.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/utsname.h>
#include <stdio.h>
#include <string.h>

#include "../osspec.h"
#include "../logger.h"
#include "../hald.h"
#include "../hald_dbus.h"
#include "../device_info.h"
#include "../util.h"
#include "devinfo_misc.h"
#include "drvctl.h"

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
	HalDevice *d;
	struct utsname un;
	char acpi_supported_states[20];
	size_t len = sizeof(acpi_supported_states);

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

	if (sysctlbyname ("hw.acpi.supported_states", acpi_supported_states, &len, NULL, 0) == 0 ||
	    sysctlbyname ("hw.acpi.sleep.states", acpi_supported_states, &len, NULL, 0) == 0) {
		hal_device_property_set_string (d, "power_management.type", "acpi");
		if (strstr (acpi_supported_states, "S3") != NULL)
			hal_device_property_set_bool (d, "power_management.can_suspend", TRUE);
		else
			hal_device_property_set_bool (d, "power_management.can_suspend", FALSE);

		hal_device_property_set_bool (d, "power_management.can_hibernate", FALSE);
	}

	if (drvctl_find_device ("acpibat0", NULL) == TRUE)
		hal_device_property_set_string (d, "system.formfactor", "laptop");
	else
		hal_device_property_set_string (d, "system.formfactor", "desktop");	/* XXX */

	devinfo_add_enqueue (d, devnode, &devinfo_default_handler);

	return d;
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

static void
devinfo_default_apply_quirks(HalDevice *d, const char *devnode)
{

/* acpiacad(4) */
	if (strncmp (devnode, "acpiacad", 8) == 0) {
		HAL_INFO (("%s: applying acpiacad quirks",devnode));
		hal_device_add_capability (d, "ac_adapter");

/* acpibat(4) */
	} else if (strncmp (devnode, "acpibat", 7) == 0) {
		HAL_INFO (("%s: applying acpibat quirks",devnode));
		hal_device_add_capability (d, "battery");
		hal_device_property_set_string (d, "battery.type", "primary");
	}

}

static HalDevice *
devinfo_default_add(HalDevice *parent, const char *devnode, char *devfs_path, char *device_type)
{
	char *driver_name;
	const char *parent_path;
	HalDevice *d;

	d = hal_device_new ();

	devinfo_set_default_properties (d, parent, devnode, devnode);

	devinfo_default_apply_quirks (d, devnode);

	devinfo_add_enqueue (d, devnode, &devinfo_default_handler);

	return (d);
}
