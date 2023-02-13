$NetBSD: patch-src_OSD_OSD__MemInfo.cxx,v 1.2 2023/02/13 15:59:14 tnn Exp $

From cad/oce 1.1 2017/01/20 11:00:50 fhajny:
Use stdlib.h instead of malloc.h

--- src/OSD/OSD_MemInfo.cxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/OSD/OSD_MemInfo.cxx
@@ -28,7 +28,10 @@
   #include <malloc/malloc.h>
 #else
   #include <unistd.h>
+  #if defined(__linux__)
   #include <malloc.h>
+  #endif
+  #include <stdlib.h>
 #endif
 
 #include <OSD_MemInfo.hxx>
