$NetBSD: patch-CPP_Windows_System.cpp,v 1.1 2023/07/21 22:42:05 ryoon Exp $

* Use sys/sysinfo.h for Linux and the others use sys/sysctl.h.
  Fix NetBSD build at least.

--- CPP/Windows/System.cpp.orig	2023-06-26 07:32:05.849120590 +0000
+++ CPP/Windows/System.cpp
@@ -5,7 +5,7 @@
 #ifndef _WIN32
 #include <unistd.h>
 #include <limits.h>
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
 #include <sys/sysctl.h>
 #else
 #include <sys/sysinfo.h>
@@ -187,7 +187,7 @@ bool GetRamSize(UInt64 &size)
 {
   size = (UInt64)(sizeof(size_t)) << 29;
 
-  #ifdef __APPLE__
+  #if defined(__APPLE__) || defined(__NetBSD__)
 
     #ifdef HW_MEMSIZE
       uint64_t val = 0; // support 2Gb+ RAM
