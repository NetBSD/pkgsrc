$NetBSD: patch-Modules_socketmodule.h,v 1.1 2020/10/10 20:20:12 adam Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.h.orig	2020-10-05 15:07:58.000000000 +0000
+++ Modules/socketmodule.h
@@ -148,6 +148,10 @@ typedef int socklen_t;
 #include <linux/can/j1939.h>
 #endif
 
+#ifdef HAVE_NETCAN_CAN_H
+#include <netcan/can.h>
+#endif
+
 #ifdef HAVE_SYS_SYS_DOMAIN_H
 #include <sys/sys_domain.h>
 #endif
