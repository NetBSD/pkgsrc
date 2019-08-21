$NetBSD: patch-agent_mibgroup_host_data__access_swrun__procfs__psinfo.c,v 1.2 2019/08/21 09:30:12 otis Exp $

Fix compilation on Solaris 11 and also on SmartOS.

--- agent/mibgroup/host/data_access/swrun_procfs_psinfo.c.orig	2014-12-08 20:23:22.000000000 +0000
+++ agent/mibgroup/host/data_access/swrun_procfs_psinfo.c
@@ -23,6 +23,8 @@
 #include <fcntl.h>
 #endif
 
+#include <sys/thread.h>
+
 #define HAVE_SYS_PROCFS_H    /* XXX - Needs a configure check! */
 #ifdef HAVE_SYS_PROCFS_H
 #define _KERNEL              /* For psinfo_t */
