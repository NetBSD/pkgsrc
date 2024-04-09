$NetBSD: patch-lib_misc_hostinfoPosix.c,v 1.2 2024/04/09 01:12:36 pho Exp $

Fix build on NetBSD.

--- lib/misc/hostinfoPosix.c.orig	2024-02-06 15:08:41.000000000 +0000
+++ lib/misc/hostinfoPosix.c
@@ -93,7 +93,7 @@
 #include <paths.h>
 #endif
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__NetBSD__)
 #include <dlfcn.h>
 #endif
 
@@ -4184,7 +4184,7 @@ HostinfoSysinfo(uint64 *totalRam,  // OU
 #endif // ifndef __APPLE__
 
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(sun)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(sun) || defined(__NetBSD__)
 /*
  *-----------------------------------------------------------------------------
  *
