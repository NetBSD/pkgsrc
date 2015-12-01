$NetBSD: patch-psutil_arch_bsd_netbsd__socks.h,v 1.1 2015/12/01 14:07:36 ryoon Exp $

--- psutil/arch/bsd/netbsd_socks.h.orig	2015-11-29 09:43:19.000000000 +0000
+++ psutil/arch/bsd/netbsd_socks.h
@@ -0,0 +1,10 @@
+/*
+ * Copyright (c) 2009, Giampaolo Rodola'.
+ * Copyright (c) 2015, Ryo ONODERA.
+ * All rights reserved.
+ * Use of this source code is governed by a BSD-style license that can be
+ * found in the LICENSE file.
+ */
+
+PyObject *psutil_proc_connections(PyObject *, PyObject *);
+PyObject *psutil_net_connections(PyObject *, PyObject *);
