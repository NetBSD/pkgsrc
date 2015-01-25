/***************************************************************************
 *
 * drvctl.c : NetBSD drvctl events
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
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/drvctlio.h>
#include <sys/dkio.h>
#include <sys/stat.h>
#include <sys/drvctlio.h>
#include <glib.h>

#include "../osspec.h"
#include "../logger.h"
#include "../hald.h"
#include "../hald_dbus.h"
#include "../device_info.h"
#include "../util.h"
#include "osspec_netbsd.h"
#include "hotplug.h"
#include "devinfo.h"
#include "devinfo_storage.h"
#include "drvctl.h"

static gboolean drvctl_iochannel_data(GIOChannel *, GIOCondition, gpointer);
static void	drvctl_dev_add(gchar *);
static void	drvctl_dev_remove(gchar *);
static void	drvctl_dev_branch(gchar *);

static int drvctl_fd;
static GIOChannel *drvctl_iochannel;

gboolean
drvctl_init(void)
{
	drvctl_fd = open (DRVCTLDEV, O_RDWR);
	if (drvctl_fd == -1) {
		HAL_INFO (("open(%s, O_RDWR) failed: %s", DRVCTLDEV, strerror(errno)));
		return FALSE;
	}

        drvctl_iochannel = g_io_channel_unix_new (drvctl_fd);
	if (drvctl_iochannel == NULL) {
                HAL_INFO (("g_io_channel_unix_new failed"));
		return FALSE;
	}
        g_io_add_watch (drvctl_iochannel, G_IO_IN, drvctl_iochannel_data, NULL);

	return TRUE;
}

void
drvctl_fini(void)
{
	HAL_INFO (("drvctl_fini"));
}

static gboolean
drvctl_iochannel_data (GIOChannel *source,
                    GIOCondition condition,
                    gpointer user_data)
{
	prop_dictionary_t ev;
	const char *event, *device;
	int res;

	HAL_INFO (("drvctl_iochannel_data"));

	res = prop_dictionary_recv_ioctl (drvctl_fd, DRVGETEVENT, &ev);
	if (res) {
		HAL_WARNING (("DRVGETEVENT failed: %s", strerror(errno)));
		return FALSE;
	}

	if (!prop_dictionary_get_cstring_nocopy (ev, "event", &event)) {
		HAL_WARNING (("DRVGETEVENT missing \"event\" parameter"));
		goto done;
	}
	if (!prop_dictionary_get_cstring_nocopy (ev, "device", &device)) {
		HAL_WARNING (("DRVGETEVENT missing \"device\" parameter"));
		goto done;
	}

	HAL_INFO (("DRVGETEVENT event=%s device=%s", event, device));

	if (strcmp (event, "device-attach") == 0) {
		drvctl_dev_add (device);
	} else {
		drvctl_dev_remove (device);
	}

done:
	prop_object_release(ev);
	return TRUE;
}

static void
drvctl_dev_add(gchar *name)
{
	HalDevice *parent, *d;
	gchar pdevnode[512];

	if (drvctl_find_parent (name, pdevnode) == FALSE) {
		HAL_INFO (("dev_add: name=%s orphan", name));
		parent = NULL;
	} else {
		parent = hal_device_store_match_key_value_string (
		    hald_get_gdl(), "netbsd.device", pdevnode);
		if (parent == NULL)
			HAL_INFO (("dev_add: name=%s but netbsd.device=%s not found",name, pdevnode));
	}

	d = devinfo_add_node (parent, name);
	if (d == NULL)
		HAL_WARNING (("dev_add: couldn't add %s node (parent=%p)", name, parent));

	hotplug_event_process_queue ();
}

static void
drvctl_dev_remove(gchar *name)
{
	HAL_INFO (("dev_remove: %s", name));

	devinfo_remove_branch (name, NULL);
	hotplug_event_process_queue ();
}

static void
drvctl_dev_branch(gchar *name)
{
	HAL_INFO (("branch_remove: %s", name));

	devinfo_remove_branch (name, NULL);
	hotplug_event_process_queue ();
}

int
drvctl_list(const gchar *name, struct devlistargs *laa)
{
	size_t children;

	/* HAL_INFO (("drvctl_list: %s", name)); */

	memset (laa, 0, sizeof (*laa));
	strlcpy (laa->l_devname, name, sizeof (laa->l_devname));
	if (ioctl (drvctl_fd, DRVLISTDEV, laa) == -1) {
		HAL_INFO (("DRVLISTDEV/1 failed: %s", strerror(errno)));
		return -1;
	}
	children = laa->l_children;
	/* HAL_INFO (("%s: found %d children", name, children)); */
	if (children == 0)
		return -1;
	laa->l_childname = malloc (children * sizeof (laa->l_childname[0]));
	if (laa->l_childname == NULL) {
		HAL_INFO (("drvctl_list couldn't allocate %d children: %s\n", children, strerror(errno)));
		return -1;
	}
	if (ioctl (drvctl_fd, DRVLISTDEV, laa) == -1) {
		HAL_INFO (("DRVLISTDEV/2 failed: %s", strerror(errno)));
		return -1;
	}
	if (children != laa->l_children)
		HAL_WARNING (("DRVLISTDEV/3 expected %d children, got %d", children, laa->l_childname));
}

gboolean
drvctl_find_device(const gchar *devnode, prop_dictionary_t *properties)
{
	prop_dictionary_t command_dict;
	prop_dictionary_t args_dict;
	prop_dictionary_t results_dict;
	int err;
	   
	command_dict = prop_dictionary_create ();
	args_dict = prop_dictionary_create ();
		
	prop_dictionary_set_cstring_nocopy (command_dict, "drvctl-command", "get-properties");
	prop_dictionary_set_cstring_nocopy (args_dict, "device-name", devnode);  
	prop_dictionary_set (command_dict, "drvctl-arguments", args_dict);
	prop_object_release (args_dict);

	err = prop_dictionary_sendrecv_ioctl (command_dict, drvctl_fd,
					      DRVCTLCOMMAND, &results_dict);
	prop_object_release (command_dict);
	if (err)
		return FALSE;

	if (prop_dictionary_get_int8 (results_dict, "drvctl-error", &err) == false || err != 0) {
		prop_object_release (results_dict);
		return FALSE;
	}

	if (properties) {
		prop_dictionary_t result_data;
		result_data = prop_dictionary_get (results_dict, "drvctl-result-data");
		if (result_data)
			*properties = prop_dictionary_copy (result_data);
	}

	prop_object_release (results_dict);

	return TRUE;
}

static gboolean
drvctl_find_device_with_child(const gchar *curnode, const gchar *devnode,
    char *parent)
{
	struct devlistargs laa;
	u_int i;

	if (drvctl_list (curnode, &laa) == -1)
		return FALSE;

	for (i = 0; i < laa.l_children; i++) {
		if (strcmp (laa.l_childname[i], devnode) == 0) {
			strlcpy(parent, curnode, 16);
			free(laa.l_childname);
			return TRUE;
		}
		if (drvctl_find_device_with_child (laa.l_childname[i], devnode, parent) == TRUE) {
			free(laa.l_childname);
			return TRUE;
		}
	}

	if (laa.l_childname)
		free(laa.l_childname);

	HAL_INFO (("%s: couldn't find device with child %s", curnode, devnode));
	return FALSE;
}

gboolean
drvctl_find_parent(const gchar *devnode, char *parent)
{
	return drvctl_find_device_with_child("mainbus0", devnode, parent);
}

#if 0
static void
drvctl_lofi_add(gchar *devfs_path, gchar *name)
{
	di_node_t node;
	const char *parent_udi;
	HalDevice *d, *parent;

	HAL_INFO (("lofi_add: %s %s", name, devfs_path));

	if ((d = hal_device_store_match_key_value_string (hald_get_gdl (),
	    "solaris.devfs_path", devfs_path)) == NULL) {
		HAL_INFO (("device not found in GDL %s", devfs_path));
		return;
	}
	parent_udi = hal_device_property_get_string (d, "info.parent");
	if ((parent_udi == NULL) || (strlen(parent_udi) == 0)) {
		HAL_INFO (("parent not found in GDL %s", parent_udi));
		return;
	}
	if ((parent = hal_device_store_match_key_value_string (hald_get_gdl (),
	    "info.udi", parent_udi)) == NULL) {
		HAL_INFO (("parent not found in GDL %s", parent_udi));
		return;
	}

	if ((node = di_init (devfs_path, DINFOCPYALL)) == DI_NODE_NIL) {
		HAL_INFO (("device not found in devinfo %s", devfs_path));
		return;
	}

	HAL_INFO (("device %s parent %s", hal_device_get_udi (d), parent_udi));
	devinfo_lofi_add_major (parent, node, devfs_path, NULL, TRUE, d);

	di_fini (node);

	hotplug_event_process_queue ();
}

static void
drvctl_lofi_remove(gchar *parent_devfs_path, gchar *name)
{
	devinfo_lofi_remove_minor(parent_devfs_path, name);
	hotplug_event_process_queue ();
}
#endif
