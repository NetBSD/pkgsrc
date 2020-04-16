$NetBSD: patch-src_hotspot_os_bsd_os__bsd.cpp,v 1.4 2020/04/16 11:51:26 ryoon Exp $

--- src/hotspot/os/bsd/os_bsd.cpp.orig	2020-01-15 18:29:57.000000000 +0000
+++ src/hotspot/os/bsd/os_bsd.cpp
@@ -379,7 +379,7 @@ void os::init_system_properties_values()
 #ifdef __APPLE__
   #define DEFAULT_LIBPATH "/lib:/usr/lib"
 #elif defined(__NetBSD__)
-  #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
+  #define DEFAULT_LIBPATH "@PREFIX@/lib/jni:@PREFIX@/lib:/lib:/usr/lib"
 #else
   #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
 #endif
