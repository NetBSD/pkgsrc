$NetBSD: patch-src_osgPlugins_osc_osc_OscHostEndianness.h,v 1.1 2018/08/04 01:05:10 nia Exp $

Configure endianness for osc plug-in.

--- src/osgPlugins/osc/osc/OscHostEndianness.h.orig	2015-07-23 11:14:00.000000000 +0000
+++ src/osgPlugins/osc/osc/OscHostEndianness.h
@@ -64,7 +64,7 @@
         #else
             #error Unknown machine endianness detected.
         #endif
-    #elif defined(__FreeBSD__)
+    #elif defined(__FreeBSD__) || defined(__NetBSD__)
         #include <sys/endian.h>
         #if (_BYTE_ORDER == _LITTLE_ENDIAN)
             #ifndef __LITTLE_ENDIAN__
