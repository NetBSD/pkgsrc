$NetBSD: patch-libs_tk_ydk_config.h,v 1.3 2025/02/01 10:01:19 wiz Exp $

Only assume GNU ftw on Linux.
https://tracker.ardour.org/view.php?id=9886

--- libs/tk/ydk/config.h.orig	2024-10-17 04:04:34.000000000 +0000
+++ libs/tk/ydk/config.h
@@ -25,7 +25,7 @@
 #define HAVE_GETRESUID 1
 #endif
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__NetBSD__)
 /* Have GNU ftw */
 #define HAVE_GNU_FTW 1
 #endif
