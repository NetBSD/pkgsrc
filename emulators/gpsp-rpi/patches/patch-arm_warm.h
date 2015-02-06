$NetBSD: patch-arm_warm.h,v 1.1 2015/02/06 02:02:03 jmcneill Exp $

--- arm/warm.h.orig	2015-01-06 20:57:45.000000000 +0000
+++ arm/warm.h
@@ -72,7 +72,7 @@ void warm_finish(void);
 /* internal */
 #ifdef WARM_CODE
 
-#include <linux/ioctl.h>
+#include <sys/ioctl.h>
 
 #define WARM_IOCTL_BASE 'A'
 
