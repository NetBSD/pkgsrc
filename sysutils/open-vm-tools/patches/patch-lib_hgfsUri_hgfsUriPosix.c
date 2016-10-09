$NetBSD: patch-lib_hgfsUri_hgfsUriPosix.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- lib/hgfsUri/hgfsUriPosix.c.orig	2016-02-16 20:06:45.000000000 +0000
+++ lib/hgfsUri/hgfsUriPosix.c
@@ -23,7 +23,7 @@
  *    x-vmware-share:// style URIs
  */
 
-#if !defined __linux__ && !defined __APPLE__ && !defined __FreeBSD__
+#if !defined __linux__ && !defined __APPLE__ && !defined __FreeBSD__ && !defined __NetBSD__
 #   error This file should not be compiled
 #endif
 
