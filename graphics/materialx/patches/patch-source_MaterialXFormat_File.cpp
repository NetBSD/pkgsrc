$NetBSD: patch-source_MaterialXFormat_File.cpp,v 1.1 2026/11/08 15:15:55 ryoon Exp $

* Support NetBSD.

--- source/MaterialXFormat/File.cpp.orig	2026-09-12 13:33:30.895120619 +0000
+++ source/MaterialXFormat/File.cpp
@@ -21,7 +21,7 @@
 
 #if defined(__linux__)
     #include <linux/limits.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
     #include <sys/syslimits.h>
 #elif defined(__APPLE__)
     #include <mach-o/dyld.h>
