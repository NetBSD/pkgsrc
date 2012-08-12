$NetBSD: patch-src_common_darktable.h,v 1.1 2012/08/12 07:47:29 marino Exp $

--- src/common/darktable.h.orig	2012-07-21 10:44:08.000000000 +0000
+++ src/common/darktable.h
@@ -43,7 +43,7 @@
 #include <mach/mach.h>
 #include <sys/sysctl.h>
 #endif
-#if defined(__DragonFly__) || defined(__FreeBSD__)
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__DragonFly__)
 typedef	unsigned int	u_int;
 #include <sys/types.h>
 #include <sys/sysctl.h>
