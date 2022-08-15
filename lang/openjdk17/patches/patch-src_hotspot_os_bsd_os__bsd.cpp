$NetBSD: patch-src_hotspot_os_bsd_os__bsd.cpp,v 1.2 2022/08/15 12:23:05 tnn Exp $

add pkgsrc library paths

--- src/hotspot/os/bsd/os_bsd.cpp.orig	2022-07-20 05:25:50.000000000 +0000
+++ src/hotspot/os/bsd/os_bsd.cpp
@@ -386,7 +386,7 @@ void os::init_system_properties_values()
     #ifdef __APPLE__
       #define DEFAULT_LIBPATH "/lib:/usr/lib"
     #elif defined(__NetBSD__)
-      #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
+      #define DEFAULT_LIBPATH "@PREFIX@/lib/jni:@PREFIX@/lib:/lib:/usr/lib"
     #else
       #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
     #endif
