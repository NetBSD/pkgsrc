$NetBSD: patch-feature.h,v 1.6.14.1 2025/07/20 14:42:00 maya Exp $

Use pkgsrc configuration directory.

--- src/feature.h.orig	2025-07-20 08:47:14.000000000 +0000
+++ src/feature.h
@@ -703,7 +703,7 @@
 /*
  * SYS_VIMRC_FILE	Name of the system-wide .vimrc file.
  */
-// #define SYS_VIMRC_FILE	"/etc/vimrc"
+#define SYS_VIMRC_FILE "@PKG_SYSCONFDIR@/vimrc"
 
 /*
  * SYS_GVIMRC_FILE	Name of the system-wide .gvimrc file.
