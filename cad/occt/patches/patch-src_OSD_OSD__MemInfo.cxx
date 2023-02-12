$NetBSD: patch-src_OSD_OSD__MemInfo.cxx,v 1.1 2023/02/12 14:42:25 tnn Exp $

From cad/oce 1.1 2017/01/20 11:00:50 fhajny:
Use stdlib.h instead of malloc.h

--- src/OSD/OSD_MemInfo.cxx.orig	2022-11-11 22:19:44.000000000 +0000
+++ src/OSD/OSD_MemInfo.cxx
@@ -28,7 +28,7 @@
   #include <malloc/malloc.h>
 #else
   #include <unistd.h>
-  #include <malloc.h>
+  #include <stdlib.h>
 #endif
 
 #include <OSD_MemInfo.hxx>
