$NetBSD: patch-src_plugin__ppapi_plugin.cpp,v 1.1 2019/07/09 16:33:30 nia Exp $

These are undefined, take advantage of SDL defines instead.

--- src/plugin_ppapi/plugin.cpp.orig	2018-06-02 09:25:36.000000000 +0000
+++ src/plugin_ppapi/plugin.cpp
@@ -75,7 +75,7 @@
 #define GL_UNSIGNED_INT_8_8_8_8_HOST GL_UNSIGNED_BYTE
 #else
 //The interpretation of texture data change with the endianness
-#if __BYTE_ORDER == __BIG_ENDIAN
+#if SDL_BYTEORDER == SDL_BIG_ENDIAN
 #define GL_UNSIGNED_INT_8_8_8_8_HOST GL_UNSIGNED_INT_8_8_8_8_REV
 #else
 #define GL_UNSIGNED_INT_8_8_8_8_HOST GL_UNSIGNED_BYTE
