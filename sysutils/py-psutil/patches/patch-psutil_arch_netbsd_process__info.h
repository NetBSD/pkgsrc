$NetBSD: patch-psutil_arch_netbsd_process__info.h,v 1.1 2013/10/12 13:32:36 wiz Exp $

Port to NetBSD.

--- psutil/arch/netbsd/process_info.h.orig	2013-10-12 13:19:29.000000000 +0000
+++ psutil/arch/netbsd/process_info.h
@@ -0,0 +1,16 @@
+/*
+ * Copyright (c) 2009, Jay Loden, Giampaolo Rodola'. All rights reserved.
+ * Use of this source code is governed by a BSD-style license that can be
+ * found in the LICENSE file.
+ *
+ * Helper functions related to fetching process information. Used by _psutil_netbsd
+ * module methods.
+ */
+
+#include <Python.h>
+
+int  psutil_get_proc_list(struct kinfo_proc2 **procList, size_t *procCount);
+char *psutil_get_cmd_args(long pid, size_t *argsize);
+char *psutil_get_cmd_path(long pid, size_t *pathsize);
+int  psutil_pid_exists(long pid);
+PyObject* psutil_get_arg_list(long pid);
