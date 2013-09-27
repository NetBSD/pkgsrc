$NetBSD: patch-hotspot_src_share_vm_runtime_os.cpp,v 1.1 2013/09/27 13:26:47 ryoon Exp $

--- hotspot/src/share/vm/runtime/os.cpp.orig	2013-06-26 01:19:44.000000000 +0000
+++ hotspot/src/share/vm/runtime/os.cpp
@@ -1102,6 +1102,7 @@ bool os::set_boot_path(char fileSep, cha
         "%/lib/jce.jar:"
         "%/lib/charsets.jar:"
         "%/lib/jfr.jar:"
+        "%/lib/rhino.jar:"
 #ifdef __APPLE__
         "%/lib/JObjC.jar:"
 #endif
