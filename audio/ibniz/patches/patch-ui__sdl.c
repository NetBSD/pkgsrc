$NetBSD: patch-ui__sdl.c,v 1.1 2026/03/16 12:20:08 nia Exp $

Recent GCC versions do not like implicit int any more.

--- ui_sdl.c.orig	2026-03-16 11:48:10.338991820 +0000
+++ ui_sdl.c
@@ -295,7 +295,7 @@ void getkeystates()
 
 /*** audio-related ***/
 
-void pauseaudio(s)
+void pauseaudio(int s)
 {
   if(!ui.opt_nonrealtime)
     SDL_PauseAudio(s);
