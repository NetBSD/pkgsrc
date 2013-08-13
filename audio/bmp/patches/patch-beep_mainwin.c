$NetBSD: patch-beep_mainwin.c,v 1.1 2013/08/13 00:40:27 khorben Exp $

Required for audio/bmp-crossfade

--- beep/mainwin.c.orig	2005-05-09 08:45:39.000000000 +0000
+++ beep/mainwin.c
@@ -655,9 +655,11 @@ mainwin_shade_toggle(void)
     mainwin_set_shade(!cfg.player_shaded);
 }
 
+gboolean is_quitting = FALSE;
 void
 mainwin_quit_cb(void)
 {
+    is_quitting = TRUE;
     gtk_widget_hide(equalizerwin);
     gtk_widget_hide(playlistwin);
     gtk_widget_hide(mainwin);
@@ -1318,7 +1320,7 @@ static void
 change_song(guint pos)
 {
     if (bmp_playback_get_playing())
-        bmp_playback_stop();
+        bmp_playback_stop_for_restart();
 
     playlist_set_position(pos);
     bmp_playback_initiate();
