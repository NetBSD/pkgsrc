$NetBSD: patch-mozilla_media_libsoundtouch_src_cpu__detect__x86.cpp,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/media/libsoundtouch/src/cpu_detect_x86.cpp.orig	2013-10-23 22:09:11.000000000 +0000
+++ mozilla/media/libsoundtouch/src/cpu_detect_x86.cpp
@@ -131,6 +131,9 @@ uint detectCPUextensions(void)
 
     return res & ~_dwDisabledISA;
 
+#elif defined(__GNUC__)
+    // No cpuid.h --> no cpuid support
+    return 0;
 #else
 
 /// One of these is true:
