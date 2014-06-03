$NetBSD: patch-hotspot_src_share_vm_runtime_os.cpp,v 1.3 2014/06/03 03:20:15 ryoon Exp $

--- hotspot/src/share/vm/runtime/os.cpp.orig	2014-05-01 13:10:09.000000000 +0000
+++ hotspot/src/share/vm/runtime/os.cpp
@@ -1132,6 +1132,7 @@ bool os::set_boot_path(char fileSep, cha
         "%/lib/jce.jar:"
         "%/lib/charsets.jar:"
         "%/lib/jfr.jar:"
+        "%/lib/rhino.jar:"
         "%/classes";
     char* sysclasspath = format_boot_path(classpath_format, home, home_len, fileSep, pathSep);
     if (sysclasspath == NULL) return false;
