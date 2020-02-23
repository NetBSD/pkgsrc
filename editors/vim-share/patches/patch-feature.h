$NetBSD: patch-feature.h,v 1.4 2020/02/23 10:39:33 morr Exp $

--- src/feature.h.orig	2019-12-03 21:59:23.000000000 +0000
+++ src/feature.h
@@ -454,7 +454,7 @@
  *			(used only with NO_BUILTIN_TCAPS not defined).
  */
 #ifdef HAVE_TGETENT
-// #define NO_BUILTIN_TCAPS
+#define NO_BUILTIN_TCAPS
 #endif
 
 #if !defined(NO_BUILTIN_TCAPS)
@@ -814,7 +814,7 @@
 /*
  * SYS_VIMRC_FILE	Name of the system-wide .vimrc file.
  */
-// #define SYS_VIMRC_FILE	"/etc/vimrc"
+#define SYS_VIMRC_FILE "@PKG_SYSCONFDIR@/vimrc"
 
 /*
  * SYS_GVIMRC_FILE	Name of the system-wide .gvimrc file.
