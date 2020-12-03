$NetBSD: patch-src_platforms_engineutils.cpp,v 1.2 2020/12/03 22:23:33 nia Exp $

These are undefined, take advantage of SDL defines instead.

--- src/platforms/engineutils.cpp.orig	2020-07-05 10:31:09.000000000 +0000
+++ src/platforms/engineutils.cpp
@@ -33,7 +33,7 @@
 #include "scripting/flash/events/flashevents.h"
 
 //The interpretation of texture data change with the endianness
-#if __BYTE_ORDER == __BIG_ENDIAN
+#if SDL_BYTEORDER == SDL_BIG_ENDIAN
 #define GL_UNSIGNED_INT_8_8_8_8_HOST GL_UNSIGNED_INT_8_8_8_8_REV
 #else
 #define GL_UNSIGNED_INT_8_8_8_8_HOST GL_UNSIGNED_BYTE
