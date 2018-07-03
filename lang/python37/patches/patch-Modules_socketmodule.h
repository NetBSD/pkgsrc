$NetBSD: patch-Modules_socketmodule.h,v 1.1 2018/07/03 03:55:40 adam Exp $

--- Modules/socketmodule.h.orig	2017-03-21 07:32:38.000000000 +0100
+++ Modules/socketmodule.h	2017-05-30 12:36:59.254776235 +0200
@@ -91,6 +91,10 @@
 #include <linux/can/bcm.h>
 #endif
 
+#ifdef HAVE_NETCAN_CAN_H
+#include <netcan/can.h>
+#endif
+
 #ifdef HAVE_SYS_SYS_DOMAIN_H
 #include <sys/sys_domain.h>
 #endif
