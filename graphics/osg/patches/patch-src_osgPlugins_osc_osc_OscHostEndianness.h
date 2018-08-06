$NetBSD: patch-src_osgPlugins_osc_osc_OscHostEndianness.h,v 1.2 2018/08/06 11:12:27 jperkin Exp $

Configure endianness for osc plug-in.

--- src/osgPlugins/osc/osc/OscHostEndianness.h.orig	2017-08-28 16:50:49.000000000 +0000
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
@@ -77,6 +77,17 @@
         #else
             #error Unknown machine endianness detected.
         #endif
+    #elif defined(__sun)
+        #include <sys/byteorder.h>
+        #if defined(_BIG_ENDIAN)
+            #ifndef __BIG_ENDIAN__
+                #define __BIG_ENDIAN__
+            #endif
+        #else
+            #ifndef __LITTLE_ENDIAN__
+                #define __LITTLE_ENDIAN__
+            #endif
+        #endif
     #endif
 
     #if   defined(__LITTLE_ENDIAN__)
