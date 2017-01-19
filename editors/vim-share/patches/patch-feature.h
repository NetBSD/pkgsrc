$NetBSD: patch-feature.h,v 1.3 2017/01/19 09:54:56 markd Exp $

--- src/feature.h.orig	2014-12-23 13:34:10.000000000 +0000
+++ src/feature.h
@@ -548,7 +548,7 @@
  *			(used only with NO_BUILTIN_TCAPS not defined).
  */
 #ifdef HAVE_TGETENT
-/* #define NO_BUILTIN_TCAPS */
+#define NO_BUILTIN_TCAPS
 #endif
 
 #if !defined(NO_BUILTIN_TCAPS)
@@ -931,7 +931,7 @@
 /*
  * SYS_VIMRC_FILE	Name of the system-wide .vimrc file.
  */
-/* #define SYS_VIMRC_FILE	"/etc/vimrc" */
+#define SYS_VIMRC_FILE	"@PKG_SYSCONFDIR@/vimrc"
 
 /*
  * SYS_GVIMRC_FILE	Name of the system-wide .gvimrc file.
