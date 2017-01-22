$NetBSD: patch-src_emacs.c,v 1.1 2017/01/22 14:06:07 abs Exp $

Fix build for non HPUX on HP PA platforms 

--- src/emacs.c.orig	2015-03-25 11:25:33.000000000 +0000
+++ src/emacs.c
@@ -2368,7 +2368,7 @@ main_1 (int argc, char **argv, char **en
 #if defined (WIN32_NATIVE) || defined (CYGWIN)
   init_win32 ();
 #endif
-#if defined (HAVE_NATIVE_SOUND) && defined (hp9000s800)
+#if defined (HAVE_NATIVE_SOUND) && defined (HPUX) && defined (hp9000s800)
   init_hpplay ();
 #endif
 #ifdef HAVE_TTY
