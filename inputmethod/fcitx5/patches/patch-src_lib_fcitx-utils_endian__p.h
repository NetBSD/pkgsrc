$NetBSD: patch-src_lib_fcitx-utils_endian__p.h,v 1.2 2024/02/10 09:58:33 ryoon Exp $

Fix build on SunOS

--- src/lib/fcitx-utils/endian_p.h.orig	2024-01-13 02:04:45.526720000 +0000
+++ src/lib/fcitx-utils/endian_p.h
@@ -8,7 +8,7 @@
 #define _FCITX_UTILS_ENDIAN_P_H_
 
 #include <cstdint>
-#if defined(__linux__) || defined(__GLIBC__)
+#if defined(__linux__) || defined(__GLIBC__) || defined(__sun)
 #include <endian.h>
 #elif defined(__APPLE__)
 
