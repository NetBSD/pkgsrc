$NetBSD: patch-src_lib_fcitx-utils_endian__p.h,v 1.1 2022/03/27 12:45:04 tnn Exp $

Fix build on SunOS

--- src/lib/fcitx-utils/endian_p.h.orig	2020-12-19 01:28:15.422710700 +0000
+++ src/lib/fcitx-utils/endian_p.h
@@ -7,7 +7,7 @@
 #ifndef _FCITX_UTILS_ENDIAN_P_H_
 #define _FCITX_UTILS_ENDIAN_P_H_
 
-#if defined(__linux__) || defined(__GLIBC__)
+#if defined(__linux__) || defined(__GLIBC__) || defined(__sun)
 #include <endian.h>
 #elif defined(__APPLE__)
 
