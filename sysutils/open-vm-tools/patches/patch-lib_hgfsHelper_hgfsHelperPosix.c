$NetBSD: patch-lib_hgfsHelper_hgfsHelperPosix.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- lib/hgfsHelper/hgfsHelperPosix.c.orig	2016-02-16 20:06:45.000000000 +0000
+++ lib/hgfsHelper/hgfsHelperPosix.c
@@ -24,7 +24,7 @@
  *
  */
 
-#if !defined __linux__ && !defined __FreeBSD__ && !defined sun && !defined __APPLE__
+#if !defined __linux__ && !defined __FreeBSD__ && !defined sun && !defined __APPLE__ && !defined __NetBSD__
 #   error This file should not be compiled
 #endif
 
@@ -39,6 +39,8 @@
 #define HGFSHLPR_DEFAULT_MOUNT_PATH      "/hgfs"
 #elif defined __APPLE__
 #define HGFSHLPR_DEFAULT_MOUNT_PATH      "/Volumes/VMware Shared Folders"
+#elif defined __NetBSD__
+#define HGFSHLPR_DEFAULT_MOUNT_PATH      "/mnt/hgfs"
 #endif
 
 
