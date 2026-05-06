$NetBSD: patch-feature.h,v 1.9 2026/05/06 20:26:50 morr Exp $

Use pkgsrc configuration directory.

--- src/feature.h.orig	2026-05-06 18:17:00.000000000 +0000
+++ src/feature.h
@@ -700,7 +700,7 @@
 /*
  * SYS_VIMRC_FILE	Name of the system-wide .vimrc file.
  */
-// #define SYS_VIMRC_FILE	"/etc/vimrc"
+#define SYS_VIMRC_FILE "@PKG_SYSCONFDIR@/vimrc"
 
 /*
  * SYS_GVIMRC_FILE	Name of the system-wide .gvimrc file.
