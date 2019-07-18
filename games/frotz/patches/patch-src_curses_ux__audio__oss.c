$NetBSD: patch-src_curses_ux__audio__oss.c,v 1.1 2019/07/18 11:54:26 nia Exp $

Avoid colliding with another symbol.

--- src/curses/ux_audio_oss.c.orig	2015-05-20 09:29:14.000000000 +0000
+++ src/curses/ux_audio_oss.c
@@ -80,7 +80,7 @@ static void sigterm_handler(int signal) 
   _exit(0);
 }
 
-static void sigint_handler(int signal) {
+static void sigint_handler_oss(int signal) {
   num_repeats = 1;
 }
 
@@ -141,7 +141,7 @@ static void play_sound(int volume, int r
   sigaddset(&sa.sa_mask, SIGTERM);
   sa.sa_flags = 0;
   sigaction(SIGTERM, &sa, NULL);
-  sa.sa_handler = sigint_handler;
+  sa.sa_handler = sigint_handler_oss;
   sigaction(SIGINT, &sa, NULL);
 
   for (num_repeats = repeats; num_repeats > 0;
