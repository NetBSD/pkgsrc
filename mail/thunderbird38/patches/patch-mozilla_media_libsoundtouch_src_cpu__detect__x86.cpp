$NetBSD: patch-mozilla_media_libsoundtouch_src_cpu__detect__x86.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/media/libsoundtouch/src/cpu_detect_x86.cpp.orig	2014-07-18 00:05:38.000000000 +0000
+++ mozilla/media/libsoundtouch/src/cpu_detect_x86.cpp
@@ -125,7 +125,9 @@ uint detectCPUextensions(void)
 #endif
 
     return res & ~_dwDisabledISA;
-
+#elif defined(__GNUC__)
+    // No cpuid.h --> no cpuid support
+    return 0;
 #else
 
 /// One of these is true:
