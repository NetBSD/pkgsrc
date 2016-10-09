$NetBSD: patch-lib_misc_hostinfoPosix.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- lib/misc/hostinfoPosix.c.orig	2016-02-16 20:06:46.000000000 +0000
+++ lib/misc/hostinfoPosix.c
@@ -3289,7 +3289,7 @@ HostinfoSysinfo(uint64 *totalRam,  // OU
 #endif // ifndef __APPLE__
 
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(sun)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(sun) || defined(__NetBSD__)
 /*
  *-----------------------------------------------------------------------------
  *
