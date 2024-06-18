$NetBSD: patch-sdk_include_mega_posix_megasys.h,v 1.1 2024/06/18 18:23:15 bsiegert Exp $

Add support to other BSDs.
Upstream pull req: https://github.com/meganz/sdk/pull/2662

--- sdk/include/mega/posix/megasys.h.orig	2024-05-17 14:19:43.000000000 +0000
+++ sdk/include/mega/posix/megasys.h
@@ -99,7 +99,8 @@
 #include <endian.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__minix)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__minix) || \
+    defined(__OpenBSD__)
 #include <sys/endian.h>
 #endif
 
