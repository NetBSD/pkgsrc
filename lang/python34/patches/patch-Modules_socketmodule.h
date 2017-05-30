$NetBSD: patch-Modules_socketmodule.h,v 1.1 2017/05/30 14:04:53 bouyer Exp $

--- Modules/socketmodule.h.orig	2017-01-17 08:57:45.000000000 +0100
+++ Modules/socketmodule.h	2017-05-30 15:51:47.251527645 +0200
@@ -84,6 +84,10 @@
 #include <linux/can/bcm.h>
 #endif
 
+#ifdef HAVE_NETCAN_CAN_H
+#include <netcan/can.h>
+#endif
+
 #ifdef HAVE_SYS_SYS_DOMAIN_H
 #include <sys/sys_domain.h>
 #endif
