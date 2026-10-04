$NetBSD: patch-info_filesys.h,v 1.2 2026/10/04 08:41:22 wiz Exp $

Use PKGSRC_INFOPATH.

--- info/filesys.h.orig	2026-03-01 17:03:26.000000000 +0000
+++ info/filesys.h
@@ -70,7 +70,7 @@ int is_dir_name (const char *filename);
 #ifdef __DJGPP__
 #  define DEFAULT_INFOPATH "c:/djgpp/info;/usr/local/info;/usr/info;."
 #else
-#  define DEFAULT_INFOPATH "PATH:/usr/local/info:/usr/info:/usr/local/lib/info:/usr/lib/info:/usr/local/gnu/info:/usr/local/gnu/lib/info:/usr/gnu/info:/usr/gnu/lib/info:/opt/gnu/info:/usr/share/info:/usr/share/lib/info:/usr/local/share/info:/usr/local/share/lib/info:/usr/gnu/lib/emacs/info:/usr/local/gnu/lib/emacs/info:/usr/local/lib/emacs/info:/usr/local/emacs/info:."
+#  define DEFAULT_INFOPATH ".:" PKGSRC_INFOPATH ":PATH:/usr/local/info:/usr/info:/usr/local/lib/info:/usr/lib/info:/usr/local/gnu/info:/usr/local/gnu/lib/info:/usr/gnu/info:/usr/gnu/lib/info:/opt/gnu/info:/usr/share/info:/usr/share/lib/info:/usr/local/share/info:/usr/local/share/lib/info:/usr/gnu/lib/emacs/info:/usr/local/gnu/lib/emacs/info:/usr/local/lib/emacs/info:/usr/local/emacs/info"
 #endif
 
 #if !defined (S_ISREG) && defined (S_IFREG)
