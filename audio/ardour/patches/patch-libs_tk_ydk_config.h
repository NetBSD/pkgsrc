$NetBSD: patch-libs_tk_ydk_config.h,v 1.1 2025/01/31 17:15:11 wiz Exp $

Only assume GNU ftw on Linux.

--- libs/tk/ydk/config.h.orig	2024-10-17 04:04:34.000000000 +0000
+++ libs/tk/ydk/config.h
@@ -25,7 +25,7 @@
 #define HAVE_GETRESUID 1
 #endif
 
-#ifndef __APPLE__
+#ifdef __Linux__
 /* Have GNU ftw */
 #define HAVE_GNU_FTW 1
 #endif
