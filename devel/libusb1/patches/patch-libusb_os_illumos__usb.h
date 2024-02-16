$NetBSD: patch-libusb_os_illumos__usb.h,v 1.1 2024/02/16 08:13:13 nia Exp $

illumos support; via OmniOS.

From 57b0bd0b3624eea8f7a56cb477649f2f35b0bab7 Mon Sep 17 00:00:00 2001
From: "Joshua M. Clulow" <josh@sysmgr.org>
Date: Mon, 27 Dec 2021 16:08:38 -0800
Subject: [PATCH] illumos: split off from Solaris backend

--- libusb/os/illumos_usb.h.orig	2024-02-16 08:09:37.474490330 +0000
+++ libusb/os/illumos_usb.h
@@ -0,0 +1,81 @@
+/*
+ *
+ * Copyright (c) 2016, Oracle and/or its affiliates.
+ * Copyright 2021 Oxide Computer Company
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
+#define	READ	0
+#define	WRITE	1
+
+typedef struct illumos_device_priv {
+	uint8_t	cfgvalue;		/* active config value */
+	uint8_t	*raw_cfgdescr;		/* active config descriptor */
+	char	*ugenpath;		/* name of the ugen(4) node */
+	char	*phypath;		/* physical path */
+} illumos_dev_priv_t;
+
+typedef	struct endpoint {
+	int datafd;	/* data file */
+	int statfd;	/* state file */
+} illumos_ep_priv_t;
+
+typedef struct illumos_device_handle_priv {
+	uint8_t			altsetting[USB_MAXINTERFACES];	/* a interface's alt */
+	uint8_t			config_index;
+	illumos_ep_priv_t		eps[USB_MAXENDPOINTS];
+	illumos_dev_priv_t	*dpriv; /* device private */
+} illumos_dev_handle_priv_t;
+
+typedef	struct illumos_transfer_priv {
+	struct aiocb		aiocb;
+	struct libusb_transfer	*transfer;
+	int			ugen_status;
+} illumos_xfer_priv_t;
+
+struct node_args {
+	struct libusb_context	*ctx;
+	struct discovered_devs	**discdevs;
+	const char		*last_ugenpath;
+	di_devlink_handle_t	dlink_hdl;
+};
+
+struct devlink_cbarg {
+	struct node_args	*nargs;	/* di node walk arguments */
+	di_node_t		myself;	/* the di node */
+	di_minor_t		minor;
+};
+
+typedef struct walk_link {
+	char *path;
+	int len;
+	char **linkpp;
+} walk_link_t;
+
+/* AIO callback args */
+struct aio_callback_args{
+	struct libusb_transfer *transfer;
+	struct aiocb aiocb;
+};
+
+#endif /* LIBUSB_ILLUMOS_H */
