$NetBSD: patch-Modules_socketmodule.h,v 1.2 2021/05/22 09:48:02 bouyer Exp $

--- Modules/socketmodule.h.orig	2021-05-03 11:47:56.000000000 +0200
+++ Modules/socketmodule.h	2021-05-21 23:47:53.387781121 +0200
@@ -90,6 +90,8 @@
 
 #ifdef HAVE_LINUX_CAN_H
 # include <linux/can.h>
+#elif defined(HAVE_NETCAN_CAN_H)
+#include <netcan/can.h>
 #else
 # undef AF_CAN
 # undef PF_CAN
