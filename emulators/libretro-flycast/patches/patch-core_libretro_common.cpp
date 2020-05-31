$NetBSD: patch-core_libretro_common.cpp,v 1.1 2020/05/31 15:20:22 nia Exp $

Add support for NetBSD.

--- core/libretro/common.cpp.orig	2020-05-29 12:45:55.000000000 +0000
+++ core/libretro/common.cpp
@@ -298,7 +298,7 @@ static void sigill_handler(int sn, sigin
 #endif
 
 #if defined(__MACH__) || defined(__linux__) || defined(__HAIKU__) || \
-   defined(__FreeBSD__) || defined(__DragonFly__) || defined(HAVE_LIBNX)
+   defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(HAVE_LIBNX)
 //#define LOG_SIGHANDLER
 
 #ifdef HAVE_LIBNX
@@ -769,4 +769,4 @@ void __libnx_exception_handler(ThreadExc
 }
 }
 
-#endif
\ No newline at end of file
+#endif
