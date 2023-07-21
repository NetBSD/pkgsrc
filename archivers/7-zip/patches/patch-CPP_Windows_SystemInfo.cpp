$NetBSD: patch-CPP_Windows_SystemInfo.cpp,v 1.1 2023/07/21 22:42:05 ryoon Exp $

* Fix NetBSD build.

--- CPP/Windows/SystemInfo.cpp.orig	2021-11-06 08:19:39.000000000 +0000
+++ CPP/Windows/SystemInfo.cpp
@@ -16,7 +16,7 @@
 #include <sys/utsname.h>
 #ifdef __APPLE__
 #include <sys/sysctl.h>
-#elif !defined(_AIX)
+#elif !defined(_AIX) && !defined(__NetBSD__)
 
 #include <sys/auxv.h>
 
