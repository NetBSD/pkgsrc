$NetBSD: patch-beep_playback.c,v 1.1 2013/08/13 00:40:27 khorben Exp $

Required for audio/bmp-crossfade

--- beep/playback.c.orig	2005-01-26 05:56:15.000000000 +0000
+++ beep/playback.c
@@ -89,7 +89,7 @@ bmp_playback_initiate(void)
         return;
 
     if (bmp_playback_get_playing())
-        bmp_playback_stop();
+        bmp_playback_stop_for_restart();
 
     vis_clear_data(mainwin_vis);
     vis_clear_data(playlistwin_vis);
@@ -135,6 +135,15 @@ bmp_playback_pause(void)
     get_current_input_plugin()->pause(ip_data.paused);
 }
 
+gboolean input_stopped_for_restart = FALSE;
+void
+bmp_playback_stop_for_restart(void)
+{
+    input_stopped_for_restart = TRUE;
+    bmp_playback_stop();
+    input_stopped_for_restart = FALSE;
+}
+
 void
 bmp_playback_stop(void)
 {
