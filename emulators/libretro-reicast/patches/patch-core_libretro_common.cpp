$NetBSD: patch-core_libretro_common.cpp,v 1.1 2018/10/13 17:02:17 nia Exp $

Add support for NetBSD.

--- core/libretro/common.cpp.orig	2018-10-12 17:39:34.000000000 +0000
+++ core/libretro/common.cpp
@@ -342,7 +342,7 @@ static void sigill_handler(int sn, sigin
 #endif
 
 #if defined(__MACH__) || defined(__linux__) || defined(__HAIKU__) || \
-   defined(__FreeBSD__) || defined(__DragonFly__)
+   defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 //#define LOG_SIGHANDLER
 
 static void signal_handler(int sn, siginfo_t * si, void *segfault_ctx)
