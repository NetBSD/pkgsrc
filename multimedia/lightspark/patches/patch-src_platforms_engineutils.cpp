$NetBSD: patch-src_platforms_engineutils.cpp,v 1.3 2021/03/15 11:04:56 nia Exp $

These are undefined, take advantage of SDL defines instead.

--- src/platforms/engineutils.cpp.orig	2021-02-10 15:43:30.000000000 +0000
+++ src/platforms/engineutils.cpp
@@ -37,7 +37,7 @@
 #include <sys/stat.h>
 
 //The interpretation of texture data change with the endianness
-#if __BYTE_ORDER == __BIG_ENDIAN
+#if SDL_BYTEORDER == SDL_BIG_ENDIAN
 #define GL_UNSIGNED_INT_8_8_8_8_HOST GL_UNSIGNED_INT_8_8_8_8_REV
 #else
 #define GL_UNSIGNED_INT_8_8_8_8_HOST GL_UNSIGNED_BYTE
