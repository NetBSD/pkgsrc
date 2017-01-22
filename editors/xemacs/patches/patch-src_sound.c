$NetBSD: patch-src_sound.c,v 1.1 2017/01/22 14:06:07 abs Exp $

Fix build for non HPUX on HP PA platforms 

--- src/sound.c.orig	2015-03-25 11:25:33.000000000 +0000
+++ src/sound.c
@@ -653,7 +653,7 @@ This variable only applies to native sou
 */ );
   Vnative_sound_only_on_console = Qt;
 
-#if defined (HAVE_NATIVE_SOUND) && defined (hp9000s800)
+#if defined (HAVE_NATIVE_SOUND) && defined (HPUX) && defined (hp9000s800)
   {
     void vars_of_hpplay (void);
     vars_of_hpplay ();
