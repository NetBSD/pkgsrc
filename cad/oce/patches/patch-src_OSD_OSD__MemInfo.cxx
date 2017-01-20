$NetBSD: patch-src_OSD_OSD__MemInfo.cxx,v 1.1 2017/01/20 11:00:50 fhajny Exp $

Use stdlib.h instead of malloc.h

--- src/OSD/OSD_MemInfo.cxx.orig	2016-06-02 12:18:16.000000000 +0000
+++ src/OSD/OSD_MemInfo.cxx
@@ -32,7 +32,7 @@
   #include <malloc/malloc.h>
 #else
   #include <unistd.h>
-  #include <malloc.h>
+  #include <stdlib.h>
 #endif
 
 #include <string>
