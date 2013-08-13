$NetBSD: patch-beep_playlist.c,v 1.1 2013/08/13 00:40:27 khorben Exp $

Required for audio/bmp-crossfade

--- beep/playlist.c.orig	2005-08-11 07:25:51.000000000 +0000
+++ beep/playlist.c
@@ -817,7 +817,7 @@ playlist_next(void)
     if (bmp_playback_get_playing()) {
         /* We need to stop before changing playlist_position */
         PLAYLIST_UNLOCK();
-        bmp_playback_stop();
+        bmp_playback_stop_for_restart();
         PLAYLIST_LOCK();
         restart_playing = TRUE;
     }
@@ -868,7 +868,7 @@ playlist_prev(void)
     if (bmp_playback_get_playing()) {
         /* We need to stop before changing playlist_position */
         PLAYLIST_UNLOCK();
-        bmp_playback_stop();
+        bmp_playback_stop_for_restart();
         PLAYLIST_LOCK();
         restart_playing = TRUE;
     }
@@ -1018,7 +1018,7 @@ playlist_set_position(guint pos)
     if (bmp_playback_get_playing()) {
         /* We need to stop before changing playlist_position */
         PLAYLIST_UNLOCK();
-        bmp_playback_stop();
+        bmp_playback_stop_for_restart();
         PLAYLIST_LOCK();
         restart_playing = TRUE;
     }
@@ -1047,7 +1047,10 @@ playlist_eof_reached(void)
 {
     GList *plist_pos_list;
 
-    bmp_playback_stop();
+    if (cfg.repeat)
+	bmp_playback_stop_for_restart();
+    else
+	bmp_playback_stop();
 
     PLAYLIST_LOCK();
     plist_pos_list = find_playlist_position_list();
