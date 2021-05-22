$NetBSD: patch-Modules_socketmodule.h,v 1.2 2021/05/22 11:36:01 bouyer Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.h.orig	2021-05-03 16:54:42.000000000 +0200
+++ Modules/socketmodule.h	2021-05-22 11:52:19.072276647 +0200
@@ -131,6 +131,8 @@
 
 #ifdef HAVE_LINUX_CAN_H
 # include <linux/can.h>
+#elif defined(HAVE_NETCAN_CAN_H)
+# include <netcan/can.h>
 #else
 # undef AF_CAN
 # undef PF_CAN
