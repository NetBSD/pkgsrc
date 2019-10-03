$NetBSD: patch-src_plugin__ppapi_plugin.cpp,v 1.2 2019/10/03 15:53:21 nia Exp $

These are undefined, take advantage of SDL defines instead.

--- src/plugin_ppapi/plugin.cpp.orig	2019-09-15 15:33:56.000000000 +0000
+++ src/plugin_ppapi/plugin.cpp
@@ -75,7 +75,7 @@
 #define GL_UNSIGNED_INT_8_8_8_8_HOST GL_UNSIGNED_BYTE
 #else
 //The interpretation of texture data change with the endianness
-#if __BYTE_ORDER == __BIG_ENDIAN
+#if SDL_BYTEORDER == SDL_BIG_ENDIAN
 // TODO
 // It's unclear if this needs special handling on big endian.
 // Needs to be tested on a big endian machine.
