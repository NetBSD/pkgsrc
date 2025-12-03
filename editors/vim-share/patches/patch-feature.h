$NetBSD: patch-feature.h,v 1.8 2025/12/03 22:52:01 morr Exp $

Use pkgsrc configuration directory.

--- src/feature.h.orig	2025-12-03 21:01:37.000000000 +0000
+++ src/feature.h
@@ -703,7 +703,7 @@
 /*
  * SYS_VIMRC_FILE	Name of the system-wide .vimrc file.
  */
-// #define SYS_VIMRC_FILE	"/etc/vimrc"
+#define SYS_VIMRC_FILE "@PKG_SYSCONFDIR@/vimrc"
 
 /*
  * SYS_GVIMRC_FILE	Name of the system-wide .gvimrc file.
