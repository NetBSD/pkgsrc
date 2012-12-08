$NetBSD: patch-src_common_darktable.h,v 1.2 2012/12/08 00:15:26 jakllsch Exp $

--- src/common/darktable.h.orig	2012-11-23 23:23:21.000000000 +0000
+++ src/common/darktable.h
@@ -47,7 +47,7 @@
 #include <mach/mach.h>
 #include <sys/sysctl.h>
 #endif
-#if defined(__DragonFly__) || defined(__FreeBSD__)
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__DragonFly__)
 typedef	unsigned int	u_int;
 #include <sys/types.h>
 #include <sys/sysctl.h>
