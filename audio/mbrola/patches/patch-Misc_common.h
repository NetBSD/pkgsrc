$NetBSD: patch-Misc_common.h,v 1.1 2024/01/26 12:58:05 wiz Exp $

Add NetBSD support and check for _LITTLE_ENDIAN

--- Misc/common.h.orig	2019-12-17 16:05:14.000000000 +0000
+++ Misc/common.h
@@ -70,11 +70,11 @@
 void swab( const char *from, char *to, int nbytes);
 #endif
 
-#if defined(__GLIBC__)
+#if defined(__GLIBC__) || defined(__NetBSD__)
 #include <endian.h>
 #undef BIG_ENDIAN
 #undef LITTLE_ENDIAN
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if __BYTE_ORDER == __LITTLE_ENDIAN || _BYTE_ORDER == _LITTLE_ENDIAN
 #  define LITTLE_ENDIAN
 #else
 #  define BIG_ENDIAN
