$NetBSD: patch-platforms_netbsd_hax__entry.c,v 1.3 2023/08/17 21:36:20 gutteridge Exp $

Fix builds on NetBSD >= 9.99.96.

--- platforms/netbsd/hax_entry.c.orig	2021-05-24 08:15:13.000000000 +0000
+++ platforms/netbsd/hax_entry.c
@@ -32,6 +32,10 @@
 #include <sys/types.h>
 #include <sys/conf.h>
 #include <sys/device.h>
+#if __NetBSD_Version__ >= 999009600
+/* Needs dv_xname from struct device */
+#include <sys/device_impl.h>
+#endif
 #include <sys/module.h>
 #include <sys/cpu.h>
 
