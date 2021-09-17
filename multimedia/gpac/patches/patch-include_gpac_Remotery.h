$NetBSD: patch-include_gpac_Remotery.h,v 1.1 2021/09/17 00:10:21 nia Exp $

Add support for NetBSD.

--- include/gpac/Remotery.h.orig	2020-09-10 16:38:49.000000000 +0000
+++ include/gpac/Remotery.h
@@ -120,7 +120,7 @@ documented just below this comment.
 // Platform identification
 #if defined(_WINDOWS) || defined(_WIN32)
     #define RMT_PLATFORM_WINDOWS
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     #define RMT_PLATFORM_LINUX
     #define RMT_PLATFORM_POSIX
 #elif defined(__APPLE__)
