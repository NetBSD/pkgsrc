$NetBSD: patch-libusb_os_illumos__usb.h,v 1.2 2026/08/11 09:07:42 jperkin Exp $

illumos support; via OmniOS.

From 57b0bd0b3624eea8f7a56cb477649f2f35b0bab7 Mon Sep 17 00:00:00 2001
From: "Joshua M. Clulow" <josh@sysmgr.org>
Date: Mon, 27 Dec 2021 16:08:38 -0800
Subject: [PATCH] illumos: split off from Solaris backend

--- libusb/os/illumos_usb.h.orig	2026-08-06 12:39:09.177667736 +0000
+++ libusb/os/illumos_usb.h
@@ -0,0 +1,111 @@
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
+#ifndef	LIBUSB_ILLUMOS_H
+#define	LIBUSB_ILLUMOS_H
+
+#include <libdevinfo.h>
+#include <pthread.h>
+#include "libusbi.h"
+
+typedef enum illumos_iodir {
+	ILLUMOS_DIR_READ,
+	ILLUMOS_DIR_WRITE,
+} illumos_iodir_t;
+
+typedef struct illumos_dev_priv {
+	/*
+	 * Active configuration descriptor and value:
+	 */
+	uint8_t			*idp_raw_cfgdescr;
+	uint8_t			idp_cfgvalue;
+
+	/*
+	 * /dev path of the directory that contains the ugen(4D) minor nodes
+	 * for this device; e.g., "/dev/usb/483.3754/0".
+	 */
+	char			*idp_ugenpath;
+
+	/*
+	 * The physical /devices path of this device, without a minor node
+	 * suffix.
+	 */
+	char			*idp_physpath;
+} illumos_dev_priv_t;
+
+typedef struct illumos_ep_priv {
+	int datafd;	/* data file */
+	int statfd;	/* state file */
+} illumos_ep_priv_t;
+
+typedef struct illumos_dev_handle_priv {
+	uint8_t			ihp_altsetting[USB_MAXINTERFACES];
+	uint8_t			ihp_config_index;
+	illumos_ep_priv_t	ihp_eps[USB_MAXENDPOINTS];
+	illumos_dev_priv_t	*ihp_idp;
+} illumos_dev_handle_priv_t;
+
+typedef enum illumos_xfer_type {
+	ILLUMOS_XFT_AIO,
+	ILLUMOS_XFT_CTRL,
+} illumos_xfer_type_t;
+
+typedef struct illumos_transfer_priv {
+	illumos_xfer_type_t	type;
+	struct aiocb		aiocb;
+	struct libusb_transfer	*transfer;
+	int			ugen_status;
+	size_t			ctrl_len;
+} illumos_xfer_priv_t;
+
+#define	MAX_BUSES		256
+
+typedef struct illumos_get_device_list {
+	struct libusb_context	*gdl_ctx;
+	struct discovered_devs	**gdl_discdevs;
+	di_devlink_handle_t	gdl_devlink;
+	char			*gdl_buses[MAX_BUSES];
+	int			gdl_error;
+} illumos_get_device_list_t;
+
+typedef struct illumos_make_session_id {
+	uint64_t		msi_session_id;
+	uint8_t			msi_bus_number;
+	int			msi_is_root_hub;
+} illumos_make_session_id_t;
+
+typedef struct illumos_gdl_find_hubs {
+	struct libusb_context	*dlfh_ctx;
+	int			dlfh_is_hub;
+} illumos_gdl_find_hubs_t;
+
+typedef struct illumos_gdl_find_ugenpath {
+	const char		*fup_physpath;
+	int			fup_len;
+	struct libusb_device	*fup_dev;
+	illumos_dev_priv_t	fup_idp;
+} illumos_gdl_find_ugenpath_t;
+
+/* AIO callback args */
+struct aio_callback_args {
+	struct libusb_transfer *transfer;
+	struct aiocb aiocb;
+};
+
+#endif /* LIBUSB_ILLUMOS_H */
