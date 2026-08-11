$NetBSD: patch-libusb_os_illumos__usb.c,v 1.2 2026/08/11 09:07:42 jperkin Exp $

illumos support; via OmniOS.

From 57b0bd0b3624eea8f7a56cb477649f2f35b0bab7 Mon Sep 17 00:00:00 2001
From: "Joshua M. Clulow" <josh@sysmgr.org>
Date: Mon, 27 Dec 2021 16:08:38 -0800
Subject: [PATCH] illumos: split off from Solaris backend

--- libusb/os/illumos_usb.c.orig	2026-08-06 12:39:03.187773814 +0000
+++ libusb/os/illumos_usb.c
@@ -0,0 +1,1856 @@
+/*
+ * Copyright (c) 2016, Oracle and/or its affiliates.
+ * Copyright 2024 Oxide Computer Company
+ *
+ * This library is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU Lesser General Public
+ * License as published by the Free Software Foundation; either
+ * version 2.1 of the License, or (at your option) any later version.
+ *
+ * This library is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * Lesser General Public License for more details.
+ *
+ * You should have received a copy of the GNU Lesser General Public
+ * License along with this library; if not, write to the Free Software
+ * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
+ */
+
+#include <config.h>
+
+#include <sys/time.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <strings.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <wait.h>
+#include <unistd.h>
+#include <aio.h>
+#include <libdevinfo.h>
+#include <sys/nvpair.h>
+#include <sys/devctl.h>
+#include <sys/usb/clients/ugen/usb_ugen.h>
+#include <sys/usb/usba.h>
+#include <sys/pci.h>
+
+#include "libusbi.h"
+#include "illumos_usb.h"
+
+#define	DEVICES_PREFIX	"/devices"
+
+#if !defined(ARRAY_SIZE)
+#define	ARRAY_SIZE(x)	(sizeof (x) / sizeof (x[0]))
+#endif
+
+struct {
+	const char *name;
+	enum libusb_speed speed;
+} illumos_speed_props[] = {
+	{ .name = "low-speed",		.speed = LIBUSB_SPEED_LOW },
+	{ .name = "high-speed",		.speed = LIBUSB_SPEED_HIGH },
+	{ .name = "full-speed",		.speed = LIBUSB_SPEED_FULL },
+	{ .name = "super-speed",	.speed = LIBUSB_SPEED_SUPER },
+};
+
+/*
+ * Backend functions
+ */
+static int illumos_get_device_list(struct libusb_context *,
+    struct discovered_devs **);
+static int illumos_open(struct libusb_device_handle *);
+static void illumos_close(struct libusb_device_handle *);
+static int illumos_get_active_config_descriptor(struct libusb_device *,
+    void *, size_t);
+static int illumos_get_config_descriptor(struct libusb_device *, uint8_t,
+    void *, size_t);
+static int illumos_get_configuration(struct libusb_device_handle *, uint8_t *);
+static int illumos_set_configuration(struct libusb_device_handle *, int);
+static int illumos_claim_interface(struct libusb_device_handle *, uint8_t);
+static int illumos_release_interface(struct libusb_device_handle *, uint8_t);
+static int illumos_set_interface_altsetting(struct libusb_device_handle *,
+    uint8_t, uint8_t);
+static int illumos_clear_halt(struct libusb_device_handle *, unsigned char);
+static void illumos_destroy_device(struct libusb_device *);
+static int illumos_submit_transfer(struct usbi_transfer *);
+static int illumos_cancel_transfer(struct usbi_transfer *);
+static int illumos_handle_transfer_completion(struct usbi_transfer *);
+static int illumos_kernel_driver_active(struct libusb_device_handle *, uint8_t);
+static int illumos_usb_open_ep0(struct libusb_context *,
+    illumos_dev_handle_priv_t *ihp, illumos_dev_priv_t *idp);
+
+static void
+illumos_ensure_closed(struct libusb_context *ctx, int *fd)
+{
+	if (*fd < 0) {
+		return;
+	}
+
+	if (close(*fd) != 0) {
+		usbi_err(ctx, "close fd %d failed: errno %d", *fd, errno);
+	}
+	*fd = -1;
+}
+
+static int
+illumos_gdl_find_ugenpath_walk(di_devlink_t devlink, void *arg)
+{
+	struct libusb_device *dev = arg;
+	illumos_dev_priv_t *idp = usbi_get_device_priv(dev);
+
+	const char *content = di_devlink_content(devlink);
+	if (content == NULL) {
+		return (DI_WALK_CONTINUE);
+	}
+
+	usbi_dbg(DEVICE_CTX(dev), "link content: %s", content);
+
+	/*
+	 * Links from /dev are relative links back up out and down into
+	 * the parallel /devices tree.  Strip the prefix off so that
+	 * our path is anchored directly below /devices:
+	 */
+	const char *start = strstr(content, DEVICES_PREFIX);
+	if (start == NULL) {
+		return (DI_WALK_CONTINUE);
+	}
+	start += strlen(DEVICES_PREFIX);
+	if (start[0] != '/') {
+		return (DI_WALK_CONTINUE);
+	}
+
+	/*
+	 * Make sure that this link targets the same /devices path as the one
+	 * we were passed, and that it has a minor node suffix (after the
+	 * separating colon):
+	 */
+	size_t len = strlen(idp->idp_physpath);
+	if (strncmp(start, idp->idp_physpath, len) != 0 || start[len] != ':') {
+		return (DI_WALK_CONTINUE);
+	}
+
+	/*
+	 * Get the link name; e.g., "/dev/usb/483.3754/0/cntrl0":
+	 */
+	const char *p = di_devlink_path(devlink);
+	if (p == NULL) {
+		return (DI_WALK_CONTINUE);
+	}
+
+	usbi_dbg(DEVICE_CTX(dev), "link path: %s", p);
+
+	/*
+	 * Trim out the last path component to get the containing directory:
+	 */
+	const char *q = strrchr(p, '/');
+	if (q == NULL || (idp->idp_ugenpath = strndup(p, q - p)) == NULL) {
+		return (DI_WALK_CONTINUE);
+	}
+
+	return (DI_WALK_TERMINATE);
+}
+
+/*
+ * Given a device with a base /devices path (no minor node suffix) locate the
+ * /dev directory that contains the ugen(4D) device nodes; e.g.,
+ * "/dev/usb/483.3754/0".  We do this by walking devlinks to look for one that
+ * targets a minor node for that /devices path.
+ */
+static int
+illumos_gdl_find_ugenpath(illumos_get_device_list_t *gdl,
+    struct libusb_device *dev)
+{
+	illumos_dev_priv_t *idp = usbi_get_device_priv(dev);
+
+	if (idp->idp_ugenpath != NULL) {
+		free(idp->idp_ugenpath);
+		idp->idp_ugenpath = NULL;
+	}
+
+	/*
+	 * We only wish to consider /dev links for our vendor and product ID:
+	 */
+	char match[PATH_MAX];
+	(void) snprintf(match, sizeof (match), "^usb/%x.%x",
+	    dev->device_descriptor.idVendor,
+	    dev->device_descriptor.idProduct);
+	usbi_dbg(DEVICE_CTX(dev), "/dev match regex is \"%s\"", match);
+
+	if (di_devlink_walk(gdl->gdl_devlink, match, NULL, DI_PRIMARY_LINK,
+	    dev, illumos_gdl_find_ugenpath_walk) != 0) {
+		usbi_err(DEVICE_CTX(dev), "di_devlink_walk() failed: "
+		    "errno %d (%s)", errno, strerror(errno));
+		return (-1);
+	}
+
+	if (idp->idp_ugenpath == NULL) {
+		usbi_err(DEVICE_CTX(dev), "ugen path not found for "
+		    "device (match \"%s\", physpath \"%s\")", match,
+		    idp->idp_physpath);
+		return (-1);
+	}
+
+	usbi_dbg(DEVICE_CTX(dev), "selected ugen path: %s", idp->idp_ugenpath);
+	return (0);
+}
+
+static int
+illumos_kernel_driver_active(struct libusb_device_handle *dev_handle,
+    uint8_t interface)
+{
+	illumos_dev_priv_t *idp = usbi_get_device_priv(dev_handle->dev);
+
+	UNUSED(interface);
+
+	usbi_dbg(HANDLE_CTX(dev_handle), "ugenpath: %s", idp->idp_ugenpath);
+
+	/*
+	 * The only way for libusb to take control of a USB device is if it has
+	 * ugen(4D) device nodes.  Some drivers, like hid(4D), expose ugen
+	 * nodes even though there is a kernel driver attached to the device.
+	 * Such drivers are willing to mediate between in-kernel access and
+	 * access from user programs.  Other devices may be explictly bound to
+	 * ugen, or ugen nodes may be exposed as a fall-back by usb_mid(4D)
+	 * when no other driver ends up matching the device.
+	 *
+	 * In summary: if we were able to find ugen(4D) nodes device
+	 * enumeration, we treat the device as something we can try to open.
+	 * Otherwise, we report that the kernel is holding the device.
+	 */
+	return (idp->idp_ugenpath == NULL);
+}
+
+/*
+ * Private functions
+ */
+static int _errno_to_libusb(int);
+static int illumos_usb_get_status(struct libusb_context *ctx, int fd);
+
+static int
+illumos_gdl_bus_number(illumos_get_device_list_t *gdl, di_node_t root_hub,
+    illumos_make_session_id_t *msi)
+{
+	/*
+	 * Determine the driver name and instance number for the root hub.
+	 * We will use this to assign a USB bus number.
+	 */
+	char *driver;
+	int inum;
+	if ((driver = di_driver_name(root_hub)) == NULL ||
+	    (inum = di_instance(root_hub)) < 0) {
+		usbi_err(gdl->gdl_ctx, "could not get driver/instance");
+		return (EIO);
+	}
+
+	char *instance;
+	if (asprintf(&instance, "%s%d", driver, inum) < 0) {
+		usbi_err(gdl->gdl_ctx, "could not make driver/instance string");
+		return (EIO);
+	}
+
+	/*
+	 * Walk through to check if we have assigned this already:
+	 */
+	for (uint_t n = 0; n < MAX_BUSES; n++) {
+		if (gdl->gdl_buses[n] == NULL) {
+			/*
+			 * If we reach an unused slot, use that slot for
+			 * this root hub:
+			 */
+			usbi_dbg(gdl->gdl_ctx, "new bus: %s -> bus %u",
+			    instance, n);
+			gdl->gdl_buses[n] = instance;
+			msi->msi_bus_number = n;
+			return (0);
+		} else if (strcmp(gdl->gdl_buses[n], instance) == 0) {
+			/*
+			 * This root hub was already assigned a device:
+			 */
+			free(instance);
+			msi->msi_bus_number = n;
+			return (0);
+		}
+	}
+
+	/*
+	 * We have run out of bus IDs!
+	 */
+	free(instance);
+	usbi_err(gdl->gdl_ctx, "ran out of bus IDs!");
+	return (EOVERFLOW);
+}
+
+/*
+ * Our 64-bit session IDs for devices other than root hubs have the
+ * following format:
+ *
+ *	BITS
+ *	0-7		device assigned-address
+ *	8-15		hub level 0 (immediate parent) assigned-address
+ *	16-23		hub level 1 (if present)
+ *	24-31		hub level 2 (if present)
+ *	32-39		hub level 3 (if present)
+ *	40-47		hub level 4 (if present)
+ *	48-50		root hub PCI function
+ *	51-55		root hub PCI device
+ *	56-63		root hub PCI bus
+ *
+ * For a root hub, only bits 48-63 will be populated and the rest will be
+ * zero.
+ */
+static int
+illumos_gdl_make_session_id(illumos_get_device_list_t *gdl, di_node_t node,
+     illumos_make_session_id_t *msi)
+{
+	uint_t byt = 0;
+
+	/*
+	 * Devices are assumed to be root hubs until we discover otherwise:
+	 */
+	msi->msi_is_root_hub = 1;
+
+	while (node != DI_NODE_NIL) {
+		int r;
+		int *unused;
+		int has_root_hub_prop = 0;
+
+		usbi_dbg(NULL, "loop %p", node);
+
+		/*
+		 * Look for the "root-hub" property on this device node.
+		 * The property is a boolean, so its mere existence
+		 * represents "true".  If true, this node is a root hub.
+		 */
+		if ((r = di_prop_lookup_ints(DDI_DEV_T_ANY, node,
+		    "root-hub", &unused)) == 0) {
+			has_root_hub_prop = 1;
+		} else if (r >= 1) {
+			/*
+			 * This should never happen for a boolean property.
+			 */
+			usbi_err(NULL, "unexpected root-hub "
+			    "lookup return %d", r);
+			return (EIO);
+		} else if (r < 0 && errno != ENXIO) {
+			/*
+			 * Report errors other than a failure to find the
+			 * property.
+			 */
+			usbi_err(NULL, "unexpected root-hub "
+			    "lookup error %d", errno);
+			return (EIO);
+		}
+
+		if (!has_root_hub_prop) {
+			int *addr;
+
+			/*
+			 * If we see any other device, this is not a root hub.
+			 */
+			msi->msi_is_root_hub = 0;
+
+			/*
+			 * Get the "assigned-address" value of the current
+			 * node.  Root hubs don't have this property, but
+			 * all other USB devices (including external hubs)
+			 * must.
+			 */
+			if ((r = di_prop_lookup_ints(DDI_DEV_T_ANY, node,
+			    "assigned-address", &addr)) < 0) {
+				/*
+				 * XXX report error
+				 */
+				usbi_err(NULL, "unexpected address "
+				    "lookup error %d", errno);
+				return (EIO);
+			} else if (r != 1) {
+				/*
+				 * XXX Expected just one integer here, not a
+				 * boolean or a list.
+				 */
+				usbi_err(NULL, "unexpected address "
+				    "lookup return %d", r);
+				return (EIO);
+			} else if (*addr > UINT8_MAX || *addr < 1) {
+				/*
+				 * We need USB addresses to fit in a byte
+				 * and to be non-zero.
+				 */
+				usbi_err(NULL, "unexpected address %d",
+				    *addr);
+				return (EIO);
+			}
+
+			/*
+			 * Store the USB address in the session ID in the
+			 * next available byte.
+			 */
+			if (byt >= 5) {
+				/*
+				 * We have run out of slots.
+				 */
+				usbi_err(NULL, "ran out of slots");
+				return (EIO);
+			}
+			usbi_dbg(NULL, "slot %u = %x", byt, *addr & 0xFF);
+			msi->msi_session_id |= (*addr & 0xFF) << (byt++ * 8);
+
+			/*
+			 * Walk one node up the device tree.
+			 */
+			node = di_parent_node(node);
+			continue;
+		}
+
+		/*
+		 * Assign a bus number to this root hub if we have not done
+		 * that already.
+		 */
+		if ((r = illumos_gdl_bus_number(gdl, node, msi)) != 0) {
+			usbi_err(NULL, "bus number failure %d", r);
+			return (r);
+		}
+
+		/*
+		 * This is the USB host controller.  Determine the PCI BDF
+		 * for this device and include it at the top of the session
+		 * ID:
+		 */
+		int *regs;
+		if (di_prop_lookup_ints(DDI_DEV_T_ANY, node, "reg",
+		    &regs) <= 0) {
+			/*
+			 * XXX
+			 */
+			usbi_err(NULL, "reg lookup failure %d %d", r, errno);
+			return (EIO);
+		}
+		msi->msi_session_id |=
+		    ((uint64_t)(PCI_REG_FUNC_G(regs[0])) << 48) |
+		    ((uint64_t)(PCI_REG_DEV_G(regs[0])) << 51) |
+		    ((uint64_t)(PCI_REG_BUS_G(regs[0])) << 56);
+
+		/*
+		 * Once we have found the root hub, the session ID is complete.
+		 */
+		return (0);
+	}
+
+	/*
+	 * If we get down here, it means we have walked out of the tree without
+	 * finding the root hub.
+	 */
+	usbi_err(NULL, "could not find root hub!");
+	return (ENOENT);
+}
+
+static void
+illumos_dev_priv_reset(illumos_dev_priv_t *idp)
+{
+	free(idp->idp_raw_cfgdescr);
+	idp->idp_raw_cfgdescr = NULL;
+	idp->idp_cfgvalue = 0;
+
+	free(idp->idp_ugenpath);
+	idp->idp_ugenpath = NULL;
+
+	/*
+	 * This string is allocated with di_devfs_path(3DEVINFO) and thus must
+	 * be freed accordingly:
+	 */
+	di_devfs_path_free(idp->idp_physpath);
+	idp->idp_physpath = NULL;
+}
+
+static int
+illumos_gdl_dev_load(illumos_get_device_list_t *gdl, di_node_t node,
+    struct libusb_device *dev)
+{
+	int proplen;
+	int n, *addr, *port_prop;
+	uint8_t *rdata;
+	illumos_dev_priv_t *idp = usbi_get_device_priv(dev);
+	di_node_t parent;
+	int r = LIBUSB_ERROR_IO;
+
+	/* Device descriptors */
+	proplen = di_prop_lookup_bytes(DDI_DEV_T_ANY, node,
+	    "usb-dev-descriptor", &rdata);
+	if (proplen <= 0) {
+		usbi_err(DEVICE_CTX(dev), "could not get device descriptor");
+		goto bail;
+	}
+	bcopy(rdata, &dev->device_descriptor, LIBUSB_DT_DEVICE_SIZE);
+
+	/* Raw configuration descriptors */
+	proplen = di_prop_lookup_bytes(DDI_DEV_T_ANY, node,
+	    "usb-raw-cfg-descriptors", &rdata);
+	if (proplen <= 0) {
+		usbi_err(DEVICE_CTX(dev), "could not get raw config");
+		goto bail;
+	}
+	free(idp->idp_raw_cfgdescr);
+	if ((idp->idp_raw_cfgdescr = calloc(1, proplen)) == NULL) {
+		r = LIBUSB_ERROR_NO_MEM;
+		goto bail;
+	}
+
+	bcopy(rdata, idp->idp_raw_cfgdescr, proplen);
+	idp->idp_cfgvalue = ((struct libusb_config_descriptor *)
+	    rdata)->bConfigurationValue;
+
+	/*
+	 * The "reg" property contains the port number that this device
+	 * is connected to, which is of course only unique within the hub
+	 * to which the device is attached.
+	 */
+	n = di_prop_lookup_ints(DDI_DEV_T_ANY, node, "reg", &port_prop);
+	if (n != 1 || *port_prop <= 0) {
+		usbi_err(DEVICE_CTX(dev), "could not get reg property");
+		goto bail;
+	}
+	dev->port_number = *port_prop;
+
+	/*
+	 * In addition to the port number, we must also populate the
+	 * parent device pointer so that USB devices can be correctly
+	 * treated as a tree.  The parent links are used by
+	 * libusb_get_port_numbers() to construct the full path back to
+	 * the root hub (not just the local port number), which is then
+	 * used by software like hidapi to uniquely identify a device.
+	 */
+	if ((parent = di_parent_node(node)) == DI_NODE_NIL) {
+		usbi_err(DEVICE_CTX(dev), "could not get parent node");
+		goto bail;
+	} else {
+		illumos_make_session_id_t msi = {};
+		if (illumos_gdl_make_session_id(gdl, parent, &msi) != 0) {
+			usbi_err(DEVICE_CTX(dev), "could not get "
+			    "session ID for parent node");
+			goto bail;
+		}
+
+		if (msi.msi_is_root_hub) {
+			usbi_dbg(DEVICE_CTX(dev), "parent device %llx "
+			    "for session ID %llx is a root hub",
+			    (unsigned long long)msi.msi_session_id,
+			    (unsigned long long)dev->session_data);
+			dev->parent_dev = NULL;
+		} else if ((dev->parent_dev = usbi_get_device_by_session_id(
+		    gdl->gdl_ctx, msi.msi_session_id)) == NULL) {
+			usbi_err(DEVICE_CTX(dev), "could not locate "
+			    "parent device %llx for session ID %llx",
+			    (unsigned long long)msi.msi_session_id,
+			    (unsigned long long)dev->session_data);
+			goto bail;
+		}
+	}
+
+	/*
+	 * Get the /devices path for this device, and use it to locate the
+	 * ugen(4D) /dev path:
+	 */
+	di_devfs_path_free(idp->idp_physpath);
+	if ((idp->idp_physpath = di_devfs_path(node)) == NULL) {
+		if (errno == EAGAIN) {
+			r = LIBUSB_ERROR_NO_MEM;
+		}
+		usbi_err(DEVICE_CTX(dev), "could not get /devices path: "
+		    "errno %d", errno);
+		goto bail;
+	}
+
+	if (illumos_gdl_find_ugenpath(gdl, dev) != 0) {
+		/*
+		 * Not every device will be accessible via ugen(4D).  We still
+		 * need to enumerate devices even if they cannot currently be
+		 * controlled, so this is not a fatal error.
+		 */
+		usbi_warn(DEVICE_CTX(dev), "could not get ugen path");
+	}
+
+	/* address */
+	n = di_prop_lookup_ints(DDI_DEV_T_ANY, node, "assigned-address",
+	    &addr);
+	if (n != 1 || *addr == 0) {
+		usbi_err(DEVICE_CTX(dev), "can't get address");
+	} else {
+		dev->device_address = *addr;
+	}
+
+	/*
+	 * Device speed is reported as a boolean node property; e.g.,
+	 * "high-speed".  Find the highest reported speed property for this
+	 * device:
+	 */
+	dev->speed = LIBUSB_SPEED_UNKNOWN;
+	for (uint_t i = 0; i < ARRAY_SIZE(illumos_speed_props); i++) {
+		int *unused;
+
+		if (di_prop_lookup_ints(DDI_DEV_T_ANY, node,
+		    illumos_speed_props[i].name, &unused) >= 0) {
+			dev->speed = illumos_speed_props[i].speed;
+			break;
+		}
+	}
+
+	usbi_dbg(DEVICE_CTX(dev),
+	    "vid=%x pid=%x, path=%s, bus=%u, port_number=%d, speed=%d",
+	    dev->device_descriptor.idVendor,
+	    dev->device_descriptor.idProduct,
+	    idp->idp_physpath, dev->bus_number, dev->port_number, dev->speed);
+
+	return (LIBUSB_SUCCESS);
+
+bail:
+	illumos_dev_priv_reset(idp);
+	return (r);
+}
+
+static int
+illumos_gdl_dev_append(illumos_get_device_list_t *gdl,
+    struct libusb_device *dev)
+{
+	struct discovered_devs *dd = *gdl->gdl_discdevs;
+	int r = 0;
+
+	/*
+	 * This routine will automatically realloc(3C) the device list if
+	 * required, but unlike realloc() it will automatically free the
+	 * original list on failure.  Either way, we always want to replace our
+	 * pointer with the returned pointer.
+	 */
+	if ((dd = discovered_devs_append(dd, dev)) == NULL) {
+		usbi_err(NULL, "could not append device");
+		r = -1;
+	}
+
+	*gdl->gdl_discdevs = dd;
+	return (r);
+}
+
+static int
+illumos_gdl_scan_hub(illumos_get_device_list_t *gdl, di_node_t hub_node)
+{
+	struct libusb_context *ctx = gdl->gdl_ctx;
+	char *hpath = di_devfs_path(hub_node);
+	usbi_dbg(gdl->gdl_ctx, "scanning under hub: %s", hpath);
+	di_devfs_path_free(hpath);
+
+	for (di_node_t node = di_child_node(hub_node); node != DI_NODE_NIL;
+	    node = di_sibling_node(node)) {
+		int r;
+		illumos_make_session_id_t msi = {};
+		if ((r = illumos_gdl_make_session_id(gdl, node, &msi) != 0)) {
+			usbi_err(ctx, "could not generate session ID (%d)", r);
+			continue;
+		}
+
+		char *path = di_devfs_path(node);
+		if (path == NULL) {
+			usbi_err(ctx, "di_devfs_path() failure!");
+			continue;
+		}
+
+		usbi_dbg(ctx,
+		    "bus number = %u, session ID = 0x%llx, path = %s",
+		    (uint_t)msi.msi_bus_number,
+		    (unsigned long long)msi.msi_session_id,
+		    path);
+
+		di_devfs_path_free(path);
+
+		if (msi.msi_is_root_hub) {
+			usbi_dbg(ctx, "skipping root hub (%llx)",
+			    (unsigned long long)msi.msi_session_id);
+			continue;
+		}
+
+		/*
+		 * Whether we locate the device by its session ID, or allocate
+		 * a new device here, we need to unref the device afterwards.
+		 */
+		struct libusb_device *dev =
+		    usbi_get_device_by_session_id(gdl->gdl_ctx,
+		    msi.msi_session_id);
+		if (dev == NULL) {
+			if ((dev = usbi_alloc_device(gdl->gdl_ctx,
+			    msi.msi_session_id)) == NULL) {
+				usbi_err(ctx, "can't alloc device");
+				continue;
+			}
+
+			usbi_dbg(DEVICE_CTX(dev), "device allocated");
+		} else {
+			usbi_warn(DEVICE_CTX(dev), "device exists already");
+		}
+
+		dev->bus_number = msi.msi_bus_number;
+
+		if (illumos_gdl_dev_load(gdl, node, dev) !=
+		    LIBUSB_SUCCESS) {
+			usbi_err(ctx, "device info load (id 0x%" PRIx64 ")",
+			    msi.msi_session_id);
+			goto unref;
+		}
+
+		if (usbi_sanitize_device(dev) < 0) {
+			usbi_err(ctx, "sanatize failed");
+			goto unref;
+		}
+
+		if (illumos_gdl_dev_append(gdl, dev) != 0) {
+			goto unref;
+		}
+
+		illumos_dev_priv_t *idp = usbi_get_device_priv(dev);
+		usbi_dbg(ctx, "Device %s %s id=0x%" PRIx64 ", "
+		    "devcount:%" PRIuPTR,
+		    idp->idp_ugenpath, idp->idp_physpath,
+		    msi.msi_session_id, (*gdl->gdl_discdevs)->len);
+
+unref:
+		libusb_unref_device(dev);
+	}
+
+	return (DI_WALK_CONTINUE);
+}
+
+static int
+illumos_gdl_find_hub_walk(di_devlink_t link, void *arg)
+{
+	illumos_gdl_find_hubs_t *dlfh = arg;
+
+	usbi_dbg(dlfh->dlfh_ctx, "found hub link: %s -> %s",
+	    di_devlink_path(link) == NULL ? "?" : di_devlink_path(link),
+	    di_devlink_content(link) == NULL ? "?" : di_devlink_content(link));
+
+	dlfh->dlfh_is_hub = 1;
+
+	return (DI_WALK_TERMINATE);
+}
+
+static int
+illumos_gdl_find_hubs(di_node_t node, void *arg)
+{
+	illumos_get_device_list_t *gdl = arg;
+
+	/*
+	 * Walk the minor nodes of this device to see if it is a USB hub:
+	 */
+	for (di_minor_t minor = di_minor_next(node, DI_MINOR_NIL);
+	    minor != DI_MINOR_NIL; minor = di_minor_next(node, minor)) {
+		char *minor_path = di_devfs_minor_path(minor);
+
+		/*usbi_dbg(gdl->gdl_ctx, "finding hubs: %s", minor_path);*/
+
+		illumos_gdl_find_hubs_t dlfh = {
+			.dlfh_ctx = gdl->gdl_ctx,
+		};
+		int r = di_devlink_walk(gdl->gdl_devlink, "^usb/hub[0-9]+",
+		    minor_path, DI_PRIMARY_LINK, &dlfh,
+		    illumos_gdl_find_hub_walk);
+		if (r != 0) {
+			usbi_err(gdl->gdl_ctx, "di_devlink_walk() failed: "
+			    "errno %d (%s)", errno, strerror(errno));
+		}
+
+		if (dlfh.dlfh_is_hub) {
+			illumos_gdl_scan_hub(gdl, node);
+		}
+
+		di_devfs_path_free(minor_path);
+	}
+
+	return (DI_WALK_CONTINUE);
+}
+
+/*
+ * Locate USB devices by locating all USB hub device nodes (linked as
+ * /dev/usb/hub[0-9]+) and then enumerating all child device nodes under the
+ * hub devices.
+ */
+int
+illumos_get_device_list(struct libusb_context *ctx,
+    struct discovered_devs **discdevs)
+{
+	di_node_t root_node = DI_NODE_NIL;
+	di_devlink_handle_t dlh = NULL;
+	int r = LIBUSB_ERROR_IO;
+
+	if ((root_node = di_init("/", DINFOCPYALL)) == DI_NODE_NIL) {
+		usbi_err(ctx, "di_init() failed: errno %d (%s)", errno,
+		    strerror(errno));
+		goto out;
+	}
+
+	if ((dlh = di_devlink_init(NULL, 0)) == NULL) {
+		usbi_err(ctx, "di_devlink_init() failed: errno %d (%s)", errno,
+		    strerror(errno));
+		goto out;
+	}
+
+	/*
+	 * Walk all device nodes to locate USB hubs.
+	 */
+	illumos_get_device_list_t gdl = {
+		.gdl_ctx = ctx,
+		.gdl_discdevs = discdevs,
+		.gdl_devlink = dlh,
+	};
+	if (di_walk_node(root_node, DI_WALK_SIBFIRST, &gdl,
+	    illumos_gdl_find_hubs) != 0) {
+		usbi_err(ctx, "di_walk_node() failed: errno %d (%s)", errno,
+		    strerror(errno));
+		goto out;
+	}
+
+	usbi_dbg(ctx, "%zu devices", (*discdevs)->len);
+	r = (*discdevs)->len;
+
+out:
+	if (dlh != NULL) {
+		di_devlink_fini(&dlh);
+	}
+	if (root_node != DI_NODE_NIL) {
+		di_fini(root_node);
+	}
+
+	return (r);
+}
+
+static int
+illumos_usb_open_ep0(struct libusb_context *ctx, illumos_dev_handle_priv_t *ihp,
+    illumos_dev_priv_t *idp)
+{
+	char filename[PATH_MAX + 1];
+	int e;
+
+	/*
+	 * If we get here, the device must be one that we believe we can open;
+	 * viz., we must have found a ugen(4D) device node for it:
+	 */
+	assert(idp->idp_ugenpath != NULL);
+
+	if (ihp->ihp_eps[0].datafd >= 0) {
+		usbi_warn(ctx, "ep0 already open!");
+		assert(ihp->ihp_eps[0].statfd > 0);
+		return (LIBUSB_SUCCESS);
+	}
+
+	(void) snprintf(filename, PATH_MAX, "%s/cntrl0", idp->idp_ugenpath);
+	usbi_dbg(ctx, "opening default endpoint: %s", filename);
+	if ((ihp->ihp_eps[0].datafd = open(filename, O_RDWR)) < 0) {
+		e = errno;
+		usbi_err(ctx, "failed to open default endpoint: %s: errno %d",
+		    filename, e);
+		goto fail;
+
+	}
+
+	(void) snprintf(filename, PATH_MAX, "%s/cntrl0stat", idp->idp_ugenpath);
+	if ((ihp->ihp_eps[0].statfd = open(filename, O_RDONLY)) < 0) {
+		e = errno;
+		usbi_err(ctx, "failed to open default endpoint status: %s: "
+		    "errno %d", filename, e);
+		goto fail;
+	}
+
+	return (LIBUSB_SUCCESS);
+
+fail:
+	illumos_ensure_closed(ctx, &ihp->ihp_eps[0].datafd);
+	illumos_ensure_closed(ctx, &ihp->ihp_eps[0].statfd);
+	return (_errno_to_libusb(e));
+}
+
+static void
+illumos_usb_close_all_eps(struct libusb_context *ctx,
+    illumos_dev_handle_priv_t *ihp)
+{
+	/*
+	 * Skip the default endpoint (endpoint 0), closing all the others:
+	 */
+	for (uint_t i = 1; i < USB_MAXENDPOINTS; i++) {
+		illumos_ensure_closed(ctx, &ihp->ihp_eps[i].datafd);
+		illumos_ensure_closed(ctx, &ihp->ihp_eps[i].statfd);
+	}
+}
+
+static void
+illumos_usb_close_ep0(struct libusb_context *ctx,
+    illumos_dev_handle_priv_t *ihp)
+{
+	if (ihp->ihp_eps[0].datafd >= 0) {
+		illumos_ensure_closed(ctx, &ihp->ihp_eps[0].datafd);
+		illumos_ensure_closed(ctx, &ihp->ihp_eps[0].statfd);
+	}
+}
+
+static uchar_t
+illumos_usb_ep_index(uint8_t ep_addr)
+{
+	return ((ep_addr & LIBUSB_ENDPOINT_ADDRESS_MASK) +
+	    ((ep_addr & LIBUSB_ENDPOINT_DIR_MASK) ? 16 : 0));
+}
+
+static int
+illumos_find_interface(struct libusb_device_handle *hdev,
+    uint8_t endpoint, uint8_t *interface)
+{
+	struct libusb_config_descriptor *config;
+	int r;
+	int iface_idx;
+
+	r = libusb_get_active_config_descriptor(hdev->dev, &config);
+	if (r < 0) {
+		usbi_err(HANDLE_CTX(hdev), "could not get active desc");
+		return (LIBUSB_ERROR_INVALID_PARAM);
+	}
+
+	for (iface_idx = 0; iface_idx < config->bNumInterfaces; iface_idx++) {
+		const struct libusb_interface *iface =
+		    &config->interface[iface_idx];
+		int altsetting_idx;
+
+		usbi_dbg(HANDLE_CTX(hdev), "check iface %d", iface_idx);
+		for (altsetting_idx = 0; altsetting_idx < iface->num_altsetting;
+		    altsetting_idx++) {
+			const struct libusb_interface_descriptor *altsetting =
+			    &iface->altsetting[altsetting_idx];
+			int ep_idx;
+
+			usbi_dbg(HANDLE_CTX(hdev), "check iface %d alt %d",
+			    iface_idx, altsetting_idx);
+			for (ep_idx = 0; ep_idx < altsetting->bNumEndpoints;
+			    ep_idx++) {
+				const struct libusb_endpoint_descriptor *ep =
+				    &altsetting->endpoint[ep_idx];
+
+				usbi_dbg(HANDLE_CTX(hdev), "check iface %d "
+				    "alt %d ep_idx %d; has epa %02x",
+				    iface_idx, altsetting_idx, ep_idx,
+				    (uint32_t)ep->bEndpointAddress);
+
+				if (ep->bEndpointAddress == endpoint) {
+					*interface = iface_idx;
+					libusb_free_config_descriptor(config);
+
+					return (LIBUSB_SUCCESS);
+				}
+			}
+		}
+	}
+	libusb_free_config_descriptor(config);
+
+	return (LIBUSB_ERROR_INVALID_PARAM);
+}
+
+static int
+illumos_check_device_and_status_open(struct libusb_device_handle *hdl,
+    uint8_t ep_addr, int ep_type)
+{
+	char filename[PATH_MAX + 1], statfilename[PATH_MAX + 1];
+	char cfg_num[16], alt_num[16];
+	int fd, fdstat, mode, e;
+	uint8_t ifc = 0;
+	uint8_t ep_index;
+	illumos_dev_handle_priv_t *ihp;
+
+	usbi_dbg(HANDLE_CTX(hdl), "open ep 0x%02x", ep_addr);
+	ihp = usbi_get_device_handle_priv(hdl);
+	ep_index = illumos_usb_ep_index(ep_addr);
+	/* ep already opened */
+	if ((ihp->ihp_eps[ep_index].datafd > 0) &&
+	    (ihp->ihp_eps[ep_index].statfd > 0)) {
+		usbi_dbg(HANDLE_CTX(hdl),
+		    "ep 0x%02x already opened, return success", ep_addr);
+
+		return (0);
+	}
+
+	if (illumos_find_interface(hdl, ep_addr, &ifc) < 0) {
+		usbi_err(HANDLE_CTX(hdl),
+		    "can't find interface for endpoint 0x%02x", ep_addr);
+		return (EACCES);
+	}
+
+	/* create filename */
+	if (ihp->ihp_config_index > 0) {
+		(void) snprintf(cfg_num, sizeof(cfg_num), "cfg%d",
+		    ihp->ihp_config_index + 1);
+	} else {
+		bzero(cfg_num, sizeof(cfg_num));
+	}
+
+	if (ihp->ihp_altsetting[ifc] > 0) {
+		(void) snprintf(alt_num, sizeof(alt_num), ".%d",
+		    ihp->ihp_altsetting[ifc]);
+	} else {
+		bzero(alt_num, sizeof(alt_num));
+	}
+
+	if ((e = snprintf(filename, sizeof (filename), "%s/%sif%d%s%s%d",
+	    ihp->ihp_idp->idp_ugenpath, cfg_num, ifc, alt_num,
+	    (ep_addr & LIBUSB_ENDPOINT_DIR_MASK) ? "in" :
+	    "out", (ep_addr & LIBUSB_ENDPOINT_ADDRESS_MASK))) < 0 ||
+	    e >= (int)sizeof (filename) ||
+	    (e = snprintf(statfilename, sizeof (statfilename), "%sstat",
+	    filename)) < 0 || e >= (int)sizeof (statfilename)) {
+		usbi_err(HANDLE_CTX(hdl),
+		    "path buffer overflow for endpoint 0x%02x", ep_addr);
+		return (EINVAL);
+	}
+
+	/*
+	 * In case configuration has been switched, the xfer endpoint needs
+	 * to be opened before the status endpoint, due to a ugen issue.
+	 * However, to enable the one transfer mode for an Interrupt-In pipe,
+	 * the status endpoint needs to be opened before the xfer endpoint.
+	 * So, open the xfer mode first and close it immediately
+	 * as a workaround. This will handle the configuration switch.
+	 * Then, open the status endpoint.  If for an Interrupt-in pipe,
+	 * write the USB_EP_INTR_ONE_XFER control to the status endpoint
+	 * to enable the one transfer mode.  Then, re-open the xfer mode.
+	 */
+	if (ep_type == LIBUSB_TRANSFER_TYPE_ISOCHRONOUS) {
+		mode = O_RDWR;
+	} else if (ep_addr & LIBUSB_ENDPOINT_IN) {
+		mode = O_RDONLY;
+	} else {
+		mode = O_WRONLY;
+	}
+	/* Open the xfer endpoint first */
+	if ((fd = open(filename, mode)) < 0) {
+		usbi_err(HANDLE_CTX(hdl), "can't open %s: errno %d (%s)",
+		    filename, errno, strerror(errno));
+		return (errno);
+	}
+	/* And immediately close the xfer endpoint */
+	illumos_ensure_closed(HANDLE_CTX(hdl), &fd);
+
+	/*
+	 * Open the status endpoint.
+	 * If for an Interrupt-IN pipe, need to enable the one transfer mode
+	 * by writing USB_EP_INTR_ONE_XFER control to the status endpoint
+	 * before opening the xfer endpoint
+	 */
+	if ((ep_type == LIBUSB_TRANSFER_TYPE_INTERRUPT) &&
+	    (ep_addr & LIBUSB_ENDPOINT_IN)) {
+		char control = USB_EP_INTR_ONE_XFER;
+		ssize_t count;
+
+		/* Open the status endpoint with RDWR */
+		if ((fdstat = open(statfilename, O_RDWR)) < 0) {
+			usbi_err(HANDLE_CTX(hdl),
+			    "can't open %s RDWR: errno %d (%s)",
+			    statfilename, errno, strerror(errno));
+			return (errno);
+		} else {
+			count = write(fdstat, &control, sizeof(control));
+			if (count != 1) {
+				/* this should have worked */
+				e = errno;
+				usbi_err(HANDLE_CTX(hdl),
+				    "can't write to %s: errno %d (%s)",
+				    statfilename, e, strerror(e));
+				illumos_ensure_closed(HANDLE_CTX(hdl), &fdstat);
+				return (e);
+			}
+		}
+	} else {
+		if ((fdstat = open(statfilename, O_RDONLY)) < 0) {
+			usbi_err(HANDLE_CTX(hdl),
+			    "can't open %s: errno %d (%s)", statfilename, errno,
+			    strerror(errno));
+			return (errno);
+		}
+	}
+
+	/* Re-open the xfer endpoint */
+	if ((fd = open(filename, mode)) < 0) {
+		e = errno;
+		usbi_err(HANDLE_CTX(hdl), "can't open %s: errno %d (%s)",
+		    filename, e, strerror(errno));
+		illumos_ensure_closed(HANDLE_CTX(hdl), &fdstat);
+		return (e);
+	}
+
+	ihp->ihp_eps[ep_index].datafd = fd;
+	ihp->ihp_eps[ep_index].statfd = fdstat;
+	usbi_dbg(HANDLE_CTX(hdl), "ep=0x%02x datafd=%d, statfd=%d", ep_addr,
+	    fd, fdstat);
+	return (0);
+}
+
+int
+illumos_open(struct libusb_device_handle *handle)
+{
+	struct libusb_context *ctx = HANDLE_CTX(handle);
+	illumos_dev_handle_priv_t *ihp = usbi_get_device_handle_priv(handle);
+	illumos_dev_priv_t *idp = usbi_get_device_priv(handle->dev);
+	int i;
+	int ret;
+
+	ihp->ihp_idp = idp;
+
+	/*
+	 * Reset the file descriptor state on our device handle object.  We
+	 * assert that the memory was zeroed prior to being handed to us.
+	 */
+	for (i = 0; i < USB_MAXENDPOINTS; i++) {
+		assert(ihp->ihp_eps[i].datafd == 0);
+		ihp->ihp_eps[i].datafd = -1;
+		assert(ihp->ihp_eps[i].statfd == 0);
+		ihp->ihp_eps[i].statfd = -1;
+	}
+
+	if (illumos_kernel_driver_active(handle, 0)) {
+		/*
+		 * We don't have a ugen(4D) path for the device, so just
+		 * pretend that we can open it.  This allows a program to open
+		 * any enumerated device.  Any subsequent operation that
+		 * requires ugen access will fail, but the consumer won't get
+		 * confused about the inability to open the otherwise
+		 * enumerated device.
+		 */
+		return (LIBUSB_SUCCESS);
+	}
+
+	if ((ret = illumos_usb_open_ep0(ctx, ihp, idp)) != LIBUSB_SUCCESS) {
+		usbi_err(ctx, "open failed: %d", ret);
+		return (ret);
+	}
+
+	return (LIBUSB_SUCCESS);
+}
+
+void
+illumos_close(struct libusb_device_handle *handle)
+{
+	struct libusb_context *ctx = HANDLE_CTX(handle);
+	illumos_dev_handle_priv_t *ihp = usbi_get_device_handle_priv(handle);
+
+	usbi_dbg(ctx, "closing");
+
+	illumos_usb_close_all_eps(ctx, ihp);
+	illumos_usb_close_ep0(ctx, ihp);
+}
+
+int
+illumos_get_active_config_descriptor(struct libusb_device *dev,
+    void *buf, size_t len)
+{
+	illumos_dev_priv_t *idp = usbi_get_device_priv(dev);
+	struct libusb_config_descriptor *cfg;
+	int proplen;
+	di_node_t node;
+	uint8_t *rdata;
+
+	/*
+	 * Keep raw configuration descriptors updated, in case config
+	 * has ever been changed through setCfg.
+	 */
+	if ((node = di_init(idp->idp_physpath, DINFOCPYALL)) == DI_NODE_NIL) {
+		usbi_err(DEVICE_CTX(dev), "di_int() failed: errno %d (%s)",
+		    errno, strerror(errno));
+		return (LIBUSB_ERROR_IO);
+	}
+	proplen = di_prop_lookup_bytes(DDI_DEV_T_ANY, node,
+	    "usb-raw-cfg-descriptors", &rdata);
+	if (proplen <= 0) {
+		usbi_err(DEVICE_CTX(dev), "can't find raw config descriptors");
+		return (LIBUSB_ERROR_IO);
+	}
+	idp->idp_raw_cfgdescr = realloc(idp->idp_raw_cfgdescr, proplen);
+	if (idp->idp_raw_cfgdescr == NULL) {
+		return (LIBUSB_ERROR_NO_MEM);
+	} else {
+		bcopy(rdata, idp->idp_raw_cfgdescr, proplen);
+		idp->idp_cfgvalue = ((struct libusb_config_descriptor *)
+		    rdata)->bConfigurationValue;
+	}
+	di_fini(node);
+
+	cfg = (struct libusb_config_descriptor *)idp->idp_raw_cfgdescr;
+	len = MIN(len, libusb_le16_to_cpu(cfg->wTotalLength));
+	memcpy(buf, idp->idp_raw_cfgdescr, len);
+	usbi_dbg(DEVICE_CTX(dev), "path:%s len %zu", idp->idp_physpath, len);
+
+	return (len);
+}
+
+int
+illumos_get_config_descriptor(struct libusb_device *dev, uint8_t idx,
+    void *buf, size_t len)
+{
+	UNUSED(idx);
+	/* XXX */
+	return (illumos_get_active_config_descriptor(dev, buf, len));
+}
+
+int
+illumos_get_configuration(struct libusb_device_handle *handle, uint8_t *config)
+{
+	illumos_dev_priv_t *idp = usbi_get_device_priv(handle->dev);
+
+	*config = idp->idp_cfgvalue;
+
+	usbi_dbg(HANDLE_CTX(handle), "bConfigurationValue %u", *config);
+
+	return (LIBUSB_SUCCESS);
+}
+
+int
+illumos_set_configuration(struct libusb_device_handle *handle, int config)
+{
+	illumos_dev_priv_t *idp = usbi_get_device_priv(handle->dev);
+	illumos_dev_handle_priv_t *ihp;
+
+	usbi_dbg(HANDLE_CTX(handle), "bConfigurationValue %d", config);
+	ihp = usbi_get_device_handle_priv(handle);
+
+	if (idp->idp_ugenpath == NULL)
+		return (LIBUSB_ERROR_NOT_SUPPORTED);
+
+	if (config < 1)
+		return (LIBUSB_ERROR_NOT_SUPPORTED);
+
+	idp->idp_cfgvalue = config;
+	ihp->ihp_config_index = config - 1;
+
+	return (LIBUSB_SUCCESS);
+}
+
+int
+illumos_claim_interface(struct libusb_device_handle *handle, uint8_t iface)
+{
+	UNUSED(handle);
+
+	usbi_dbg(HANDLE_CTX(handle), "iface %u", iface);
+
+	return (LIBUSB_SUCCESS);
+}
+
+int
+illumos_release_interface(struct libusb_device_handle *handle, uint8_t iface)
+{
+	illumos_dev_handle_priv_t *ihp = usbi_get_device_handle_priv(handle);
+
+	usbi_dbg(HANDLE_CTX(handle), "iface %u", iface);
+
+	/* XXX: can we release it? */
+	ihp->ihp_altsetting[iface] = 0;
+
+	return (LIBUSB_SUCCESS);
+}
+
+int
+illumos_set_interface_altsetting(struct libusb_device_handle *handle,
+    uint8_t iface, uint8_t altsetting)
+{
+	illumos_dev_priv_t *idp = usbi_get_device_priv(handle->dev);
+	illumos_dev_handle_priv_t *ihp = usbi_get_device_handle_priv(handle);
+
+	usbi_dbg(HANDLE_CTX(handle), "iface %u, setting %u", iface, altsetting);
+
+	if (idp->idp_ugenpath == NULL)
+		return (LIBUSB_ERROR_NOT_FOUND);
+
+	/* XXX: can we switch altsetting? */
+	ihp->ihp_altsetting[iface] = altsetting;
+
+	return (LIBUSB_SUCCESS);
+}
+
+static void
+usb_dump_data(libusb_context *ctx, const void *data, size_t size)
+{
+	const uint8_t *p = data;
+	char buf[256];
+	char *l = buf;
+
+	if (ctx->debug < LIBUSB_LOG_LEVEL_DEBUG) {
+		return;
+	}
+
+	usbi_dbg(ctx, "data dump:");
+	for (size_t i = 0; i < size; i++) {
+		if (i % 16 == 0) {
+			if (l != buf) {
+				usbi_dbg(ctx, "%s", buf);
+				l = buf;
+			}
+
+			l += snprintf(l, sizeof (buf) - (l - buf), "%08zx  ",
+			    i);
+		}
+
+		l += snprintf(l, sizeof (buf) - (l - buf), "%02x ", p[i]);
+	}
+
+	if (l != buf) {
+		l = buf;
+		usbi_dbg(ctx, "%s", buf);
+	}
+}
+
+static void
+illumos_async_callback(union sigval arg)
+{
+	illumos_xfer_priv_t *tpriv = arg.sival_ptr;
+	struct libusb_transfer *xfer = tpriv->transfer;
+	struct usbi_transfer *ixfer = LIBUSB_TRANSFER_TO_USBI_TRANSFER(xfer);
+	struct aiocb *aiocb = &tpriv->aiocb;
+	illumos_dev_handle_priv_t *ihp;
+	uint8_t ep;
+	libusb_device_handle *dev_handle;
+
+	if ((dev_handle = xfer->dev_handle) == NULL) {
+		/* libusb can forcibly interrupt transfer in do_close() */
+		return;
+	}
+
+	if (aio_error(aiocb) != ECANCELED) {
+		ihp = usbi_get_device_handle_priv(dev_handle);
+		ep = illumos_usb_ep_index(xfer->endpoint);
+
+		/*
+		 * Fetch the status for the last command on this endpoint from
+		 * ugen(4D) so that we can translate and report it later.
+		 */
+		tpriv->ugen_status = illumos_usb_get_status(TRANSFER_CTX(xfer),
+		    ihp->ihp_eps[ep].statfd);
+	} else {
+		tpriv->ugen_status = USB_LC_STAT_NOERROR;
+	}
+
+	usbi_signal_transfer_completion(ixfer);
+}
+
+static int
+illumos_do_async_io(struct libusb_transfer *transfer)
+{
+	int ret = -1;
+	struct aiocb *aiocb;
+	illumos_dev_handle_priv_t *ihp;
+	uint8_t ep;
+	illumos_xfer_priv_t *tpriv;
+
+	usbi_dbg(TRANSFER_CTX(transfer), " ");
+
+	tpriv = usbi_get_transfer_priv(
+	    LIBUSB_TRANSFER_TO_USBI_TRANSFER(transfer));
+	ihp = usbi_get_device_handle_priv(transfer->dev_handle);
+	ep = illumos_usb_ep_index(transfer->endpoint);
+
+	tpriv->type = ILLUMOS_XFT_AIO;
+	tpriv->transfer = transfer;
+	aiocb = &tpriv->aiocb;
+	bzero(aiocb, sizeof(*aiocb));
+	aiocb->aio_fildes = ihp->ihp_eps[ep].datafd;
+	aiocb->aio_buf = transfer->buffer;
+	aiocb->aio_nbytes = transfer->length;
+	aiocb->aio_lio_opcode =
+	    ((transfer->endpoint & LIBUSB_ENDPOINT_DIR_MASK) ==
+	    LIBUSB_ENDPOINT_IN) ? LIO_READ : LIO_WRITE;
+	aiocb->aio_sigevent.sigev_notify = SIGEV_THREAD;
+	aiocb->aio_sigevent.sigev_value.sival_ptr = tpriv;
+	aiocb->aio_sigevent.sigev_notify_function = illumos_async_callback;
+
+	if (aiocb->aio_lio_opcode == LIO_READ) {
+		ret = aio_read(aiocb);
+	} else {
+		ret = aio_write(aiocb);
+	}
+
+	return (ret);
+}
+
+/* return the number of bytes read/written */
+static ssize_t
+illumos_usb_do_io(struct libusb_context *ctx, illumos_ep_priv_t *ep,
+    illumos_xfer_priv_t *tpriv, void *data, size_t size, illumos_iodir_t dir)
+{
+	int error;
+	ssize_t ret = -1;
+
+	usbi_dbg(ctx,
+	    "illumos_usb_do_io(): datafd=%d statfd=%d size=0x%zx dir=%s",
+	    ep->datafd, ep->statfd, size,
+	    dir == ILLUMOS_DIR_WRITE ? "WRITE" : "READ");
+
+	switch (dir) {
+	case ILLUMOS_DIR_READ:
+		errno = 0;
+		ret = read(ep->datafd, data, size);
+		error = errno;
+		usb_dump_data(ctx, data, size);
+		break;
+	case ILLUMOS_DIR_WRITE:
+		usb_dump_data(ctx, data, size);
+		errno = 0;
+		ret = write(ep->datafd, data, size);
+		error = errno;
+		break;
+	default:
+		abort();
+		break;
+	}
+
+	/*
+	 * Fetch the status for the last command on this endpoint from
+	 * ugen(4D) so that we can translate and report it later.
+	 */
+	tpriv->ugen_status = illumos_usb_get_status(ctx, ep->statfd);
+
+	usbi_dbg(ctx, "illumos_usb_do_io(): amount=%zd error=%d status=%d",
+	    ret, error, tpriv->ugen_status);
+
+	if (ret < 0) {
+		usbi_err(ctx, "TID=%x io %s errno %d (%s)", pthread_self(),
+		    dir == ILLUMOS_DIR_WRITE ? "WRITE" : "READ",
+		    error, strerror(error));
+
+		errno = error;
+		return (-1);
+	}
+
+	return (ret);
+}
+
+static int
+illumos_submit_ctrl_on_default(struct libusb_transfer *xfer)
+{
+	struct libusb_context *ctx = TRANSFER_CTX(xfer);
+	struct usbi_transfer *ixfer = LIBUSB_TRANSFER_TO_USBI_TRANSFER(xfer);
+	illumos_xfer_priv_t *tpriv = usbi_get_transfer_priv(ixfer);
+	struct libusb_device_handle *hdl = xfer->dev_handle;
+	illumos_dev_handle_priv_t *ihp = usbi_get_device_handle_priv(hdl);
+	uint8_t *data = xfer->buffer;
+	size_t datalen = xfer->length;
+	illumos_iodir_t dir =
+	    (data[0] & LIBUSB_ENDPOINT_DIR_MASK) == LIBUSB_ENDPOINT_IN ?
+	    ILLUMOS_DIR_READ : ILLUMOS_DIR_WRITE;
+	ssize_t ret;
+
+	tpriv->type = ILLUMOS_XFT_CTRL;
+	tpriv->transfer = xfer;
+	tpriv->ctrl_len = 0;
+
+	if (ihp->ihp_eps[0].datafd < 0) {
+		usbi_err(ctx, "ep0 not opened");
+		return (LIBUSB_ERROR_NOT_FOUND);
+	}
+
+	if (dir == ILLUMOS_DIR_READ) {
+		/*
+		 * As per ugen(4D), to perform a control-IN transfer we must
+		 * first write(2) the USB setup data.
+		 */
+		usbi_dbg(ctx, "control IN request: write setup");
+		if ((ret = illumos_usb_do_io(ctx, &ihp->ihp_eps[0], tpriv,
+		    data, LIBUSB_CONTROL_SETUP_SIZE, ILLUMOS_DIR_WRITE)) < 0) {
+			int e = errno;
+			usbi_dbg(ctx, "IN request: setup failed (%d, %s)",
+			    e, strerror(e));
+			return (_errno_to_libusb(e));
+		} else if (ret != LIBUSB_CONTROL_SETUP_SIZE) {
+			usbi_dbg(ctx, "IN request: setup short write (%d)",
+			    (int)ret);
+			return (LIBUSB_ERROR_IO);
+		}
+
+		/*
+		 * Trim the setup data out of the buffer for the subsequent
+		 * read:
+		 */
+		datalen -= LIBUSB_CONTROL_SETUP_SIZE;
+		data += LIBUSB_CONTROL_SETUP_SIZE;
+	}
+
+	usbi_dbg(ctx, "%s request: data",
+	    dir == ILLUMOS_DIR_READ ? "IN" : "OUT");
+	ret = illumos_usb_do_io(ctx, &ihp->ihp_eps[0], tpriv, data, datalen,
+	    dir);
+	if (ret < 0) {
+		int e = errno;
+		usbi_err(ctx, "%s request: failed! error=%d",
+		    dir == ILLUMOS_DIR_READ ? "IN" : "OUT", e);
+		return (_errno_to_libusb(e));
+	}
+
+	if (dir == ILLUMOS_DIR_WRITE) {
+		if (ret < (ssize_t)LIBUSB_CONTROL_SETUP_SIZE) {
+			usbi_err(ctx, "%s request: control write shorter than "
+			    "setup size! (%d)\n",
+			    dir == ILLUMOS_DIR_READ ? "IN" : "OUT", (int)ret);
+			return (LIBUSB_ERROR_IO);
+		}
+
+		/*
+		 * For a control OUT transfer, we need to subtract the
+		 * size of the header we wrote before the data from the
+		 * caller.
+		 */
+		ret -= LIBUSB_CONTROL_SETUP_SIZE;
+	}
+
+	tpriv->ctrl_len += ret;
+	usbi_dbg(ctx, "Done: ctrl data bytes %zd", ret);
+	usbi_signal_transfer_completion(ixfer);
+	return (LIBUSB_SUCCESS);
+}
+
+int
+illumos_clear_halt(struct libusb_device_handle *handle, unsigned char endpoint)
+{
+	int ret;
+
+	usbi_dbg(HANDLE_CTX(handle), "endpoint=0x%02x", endpoint);
+
+	ret = libusb_control_transfer(handle, LIBUSB_ENDPOINT_OUT |
+	    LIBUSB_RECIPIENT_ENDPOINT | LIBUSB_REQUEST_TYPE_STANDARD,
+	    LIBUSB_REQUEST_CLEAR_FEATURE, 0, endpoint, NULL, 0, 1000);
+
+	usbi_dbg(HANDLE_CTX(handle), "ret=%d", ret);
+
+	return (ret);
+}
+
+void
+illumos_destroy_device(struct libusb_device *dev)
+{
+	usbi_dbg(DEVICE_CTX(dev), "destroy everything");
+
+	illumos_dev_priv_reset(usbi_get_device_priv(dev));
+}
+
+int
+illumos_submit_transfer(struct usbi_transfer *itransfer)
+{
+	struct libusb_transfer *transfer;
+	struct libusb_device_handle *hdl;
+	int err = 0;
+
+	transfer = USBI_TRANSFER_TO_LIBUSB_TRANSFER(itransfer);
+	hdl = transfer->dev_handle;
+
+	err = illumos_check_device_and_status_open(hdl,
+	    transfer->endpoint, transfer->type);
+	if (err != 0) {
+		return (_errno_to_libusb(err));
+	}
+
+	switch (transfer->type) {
+	case LIBUSB_TRANSFER_TYPE_CONTROL:
+		/* sync transfer */
+		usbi_dbg(ITRANSFER_CTX(itransfer),
+		    "CTRL transfer: %d", transfer->length);
+		err = illumos_submit_ctrl_on_default(transfer);
+		break;
+
+	case LIBUSB_TRANSFER_TYPE_BULK:
+		usbi_dbg(ITRANSFER_CTX(itransfer),
+		    "BULK transfer: %d", transfer->length);
+		err = illumos_do_async_io(transfer);
+		break;
+
+	case LIBUSB_TRANSFER_TYPE_INTERRUPT:
+		usbi_dbg(ITRANSFER_CTX(itransfer),
+		    "INTR transfer: %d", transfer->length);
+		err = illumos_do_async_io(transfer);
+		break;
+
+	/* Isochronous/Stream is not supported */
+	case LIBUSB_TRANSFER_TYPE_ISOCHRONOUS:
+		usbi_dbg(ITRANSFER_CTX(itransfer),
+		    "ISOC transfer: %d", transfer->length);
+		err = LIBUSB_ERROR_NOT_SUPPORTED;
+		break;
+
+	case LIBUSB_TRANSFER_TYPE_BULK_STREAM:
+		usbi_dbg(ITRANSFER_CTX(itransfer),
+		    "BULK STREAM transfer: %d", transfer->length);
+		err = LIBUSB_ERROR_NOT_SUPPORTED;
+		break;
+	}
+
+	return (err);
+}
+
+int
+illumos_cancel_transfer(struct usbi_transfer *itransfer)
+{
+	illumos_xfer_priv_t *tpriv;
+	illumos_dev_handle_priv_t *ihp;
+	struct libusb_transfer *transfer;
+	struct aiocb *aiocb;
+	uint8_t ep;
+	int ret;
+
+	tpriv = usbi_get_transfer_priv(itransfer);
+	aiocb = &tpriv->aiocb;
+	transfer = USBI_TRANSFER_TO_LIBUSB_TRANSFER(itransfer);
+	ihp = usbi_get_device_handle_priv(transfer->dev_handle);
+	ep = illumos_usb_ep_index(transfer->endpoint);
+
+	ret = aio_cancel(ihp->ihp_eps[ep].datafd, aiocb);
+
+	usbi_dbg(ITRANSFER_CTX(itransfer), "aio->fd=%d fd=%d ret = %d, %s",
+	    aiocb->aio_fildes, ihp->ihp_eps[ep].datafd, ret,
+	    (ret == AIO_CANCELED) ? "AIO canceled" : strerror(errno));
+
+	if (ret != AIO_CANCELED) {
+		ret = _errno_to_libusb(errno);
+	} else {
+		ret = LIBUSB_SUCCESS;
+	}
+
+	return (ret);
+}
+
+static int
+illumos_libusb_status(illumos_xfer_priv_t *tpriv)
+{
+	/*
+	 * Convert the ugen(4D)-level status to a libusb-level status:
+	 */
+	switch (tpriv->ugen_status) {
+	case USB_LC_STAT_TIMEOUT:
+		return (LIBUSB_TRANSFER_TIMED_OUT);
+	case USB_LC_STAT_STALL:
+		return (LIBUSB_TRANSFER_STALL);
+	case USB_LC_STAT_DISCONNECTED:
+		return (LIBUSB_TRANSFER_NO_DEVICE);
+	case USB_LC_STAT_INTERRUPTED:
+		return (LIBUSB_TRANSFER_CANCELLED);
+	case USB_LC_STAT_BUFFER_OVERRUN:
+		/*
+		 * XXX Is this right? (*_DATA_OVERRUN?)
+		 */
+		return (LIBUSB_TRANSFER_OVERFLOW);
+	default:
+		/*
+		 * Not every ugen(4D) status maps to a specific libusb-level
+		 * failure case.  Nonetheless, we must report all failures as
+		 * failures:
+		 */
+		return (LIBUSB_TRANSFER_ERROR);
+	}
+}
+
+int
+illumos_handle_transfer_completion(struct usbi_transfer *ixfer)
+{
+	illumos_xfer_priv_t *tpriv = usbi_get_transfer_priv(ixfer);
+	struct libusb_transfer *xfer = USBI_TRANSFER_TO_LIBUSB_TRANSFER(ixfer);
+	struct aiocb *aiocb = &tpriv->aiocb;
+	int ret;
+	enum libusb_transfer_status status;
+
+	if (tpriv->type == ILLUMOS_XFT_CTRL) {
+		ixfer->transferred = tpriv->ctrl_len;
+		if (tpriv->ugen_status == USB_LC_STAT_NOERROR) {
+			status = LIBUSB_TRANSFER_COMPLETED;
+		} else {
+			status = illumos_libusb_status(tpriv);
+		}
+
+	} else if ((ret = aio_error(aiocb)) == 0) {
+		/*
+		 * The command completed.  Update the transferred length:
+		 */
+		xfer->actual_length = ixfer->transferred = aio_return(aiocb);
+
+		usbi_dbg(TRANSFER_CTX(xfer), "ret=%d, len=%d, actual_len=%d",
+		    ret, xfer->length, xfer->actual_length);
+		usb_dump_data(TRANSFER_CTX(xfer),
+		    xfer->buffer, xfer->actual_length);
+
+		status = LIBUSB_TRANSFER_COMPLETED;
+
+	} else if (ret == ECANCELED) {
+		/*
+		 * We used aio_cancel() to cancel this; report cancellation to
+		 * libusb so that timeouts can be handled correctly.
+		 */
+		usbi_dbg(TRANSFER_CTX(xfer),
+		    "aio cancelled, len=%d, actual_len=%d",
+		    xfer->length, xfer->actual_length);
+
+		status = LIBUSB_TRANSFER_CANCELLED;
+
+	} else {
+		status = illumos_libusb_status(tpriv);
+	}
+
+	if (status == LIBUSB_TRANSFER_CANCELLED) {
+		return (usbi_handle_transfer_cancellation(ixfer));
+	} else {
+		return (usbi_handle_transfer_completion(ixfer, status));
+	}
+}
+
+int
+_errno_to_libusb(int err)
+{
+	usbi_dbg(NULL, "error: %s (%d)", strerror(err), err);
+
+	switch (err) {
+	case EIO:
+		return (LIBUSB_ERROR_IO);
+	case EACCES:
+		return (LIBUSB_ERROR_ACCESS);
+	case ENOENT:
+		return (LIBUSB_ERROR_NO_DEVICE);
+	case ENOMEM:
+		return (LIBUSB_ERROR_NO_MEM);
+	case ETIMEDOUT:
+		return (LIBUSB_ERROR_TIMEOUT);
+	case EBUSY:
+		return (LIBUSB_ERROR_BUSY);
+	}
+
+	return (LIBUSB_ERROR_OTHER);
+}
+
+/*
+ * illumos_usb_get_status:
+ *	gets status of endpoint
+ *
+ * Returns: ugen's last cmd status
+ */
+static int
+illumos_usb_get_status(struct libusb_context *ctx, int fd)
+{
+	int status;
+	ssize_t ret;
+
+	usbi_dbg(ctx, "illumos_usb_get_status(): fd=%d", fd);
+
+	errno = 0;
+	ret = read(fd, &status, sizeof(status));
+	if (ret == sizeof (status)) {
+		switch (status) {
+		case USB_LC_STAT_NOERROR:
+			usbi_dbg(ctx, "No Error");
+			break;
+		case USB_LC_STAT_CRC:
+			usbi_dbg(ctx, "CRC Timeout Detected");
+			break;
+		case USB_LC_STAT_BITSTUFFING:
+			usbi_dbg(ctx, "Bit Stuffing Violation");
+			break;
+		case USB_LC_STAT_DATA_TOGGLE_MM:
+			usbi_dbg(ctx, "Data Toggle Mismatch");
+			break;
+		case USB_LC_STAT_STALL:
+			usbi_dbg(ctx, "End Point Stalled");
+			break;
+		case USB_LC_STAT_DEV_NOT_RESP:
+			usbi_dbg(ctx, "Device is Not Responding");
+			break;
+		case USB_LC_STAT_PID_CHECKFAILURE:
+			usbi_dbg(ctx, "PID Check Failure");
+			break;
+		case USB_LC_STAT_UNEXP_PID:
+			usbi_dbg(ctx, "Unexpected PID");
+			break;
+		case USB_LC_STAT_DATA_OVERRUN:
+			usbi_dbg(ctx, "Data Exceeded Size");
+			break;
+		case USB_LC_STAT_DATA_UNDERRUN:
+			usbi_dbg(ctx, "Less data received");
+			break;
+		case USB_LC_STAT_BUFFER_OVERRUN:
+			usbi_dbg(ctx, "Buffer Size Exceeded");
+			break;
+		case USB_LC_STAT_BUFFER_UNDERRUN:
+			usbi_dbg(ctx, "Buffer Underrun");
+			break;
+		case USB_LC_STAT_TIMEOUT:
+			usbi_dbg(ctx, "Command Timed Out");
+			break;
+		case USB_LC_STAT_NOT_ACCESSED:
+			usbi_dbg(ctx, "Not Accessed by h/w");
+			break;
+		case USB_LC_STAT_UNSPECIFIED_ERR:
+			usbi_dbg(ctx, "Unspecified Error");
+			break;
+		case USB_LC_STAT_NO_BANDWIDTH:
+			usbi_dbg(ctx, "No Bandwidth");
+			break;
+		case USB_LC_STAT_HW_ERR:
+			usbi_dbg(ctx, "Host Controller h/w Error");
+			break;
+		case USB_LC_STAT_SUSPENDED:
+			usbi_dbg(ctx, "Device was Suspended");
+			break;
+		case USB_LC_STAT_DISCONNECTED:
+			usbi_dbg(ctx, "Device was Disconnected");
+			break;
+		case USB_LC_STAT_INTR_BUF_FULL:
+			usbi_dbg(ctx, "Interrupt buffer was full");
+			break;
+		case USB_LC_STAT_INVALID_REQ:
+			usbi_dbg(ctx, "Request was Invalid");
+			break;
+		case USB_LC_STAT_INTERRUPTED:
+			usbi_dbg(ctx, "Request was Interrupted");
+			break;
+		case USB_LC_STAT_NO_RESOURCES:
+			usbi_dbg(ctx, "No resources available for "
+			    "request");
+			break;
+		case USB_LC_STAT_INTR_POLLING_FAILED:
+			usbi_dbg(ctx, "Failed to Restart Poll");
+			break;
+		default:
+			usbi_err(ctx, "Error Not Determined %d", status);
+			status = USB_LC_STAT_UNSPECIFIED_ERR;
+			break;
+		}
+	} else {
+		usbi_err(ctx, "read stat error: (ret %ld, error %d) %s",
+		    (long)ret, errno, strerror(errno));
+		status = USB_LC_STAT_UNSPECIFIED_ERR;
+	}
+
+	return (status);
+}
+
+const struct usbi_os_backend usbi_backend = {
+	.name = "illumos",
+	.get_device_list = illumos_get_device_list,
+	.open = illumos_open,
+	.close = illumos_close,
+
+	.get_active_config_descriptor = illumos_get_active_config_descriptor,
+	.get_config_descriptor = illumos_get_config_descriptor,
+
+	.get_configuration = illumos_get_configuration,
+	.set_configuration = illumos_set_configuration,
+
+	.claim_interface = illumos_claim_interface,
+	.release_interface = illumos_release_interface,
+
+	.set_interface_altsetting = illumos_set_interface_altsetting,
+	.clear_halt = illumos_clear_halt,
+	.destroy_device = illumos_destroy_device,
+
+	.submit_transfer = illumos_submit_transfer,
+	.cancel_transfer = illumos_cancel_transfer,
+
+	.handle_transfer_completion = illumos_handle_transfer_completion,
+
+	.device_priv_size = sizeof(illumos_dev_priv_t),
+	.device_handle_priv_size = sizeof (illumos_dev_handle_priv_t),
+
+	.kernel_driver_active = illumos_kernel_driver_active,
+	.transfer_priv_size = sizeof (illumos_xfer_priv_t),
+};
