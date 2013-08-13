$NetBSD: patch-beep_playback.h,v 1.1 2013/08/13 00:40:27 khorben Exp $

Required for audio/bmp-crossfade

--- beep/playback.h.orig	2004-12-04 09:04:26.000000000 +0000
+++ beep/playback.h
@@ -26,6 +26,7 @@ gint bmp_playback_get_time(void);
 void bmp_playback_initiate(void);
 void bmp_playback_pause(void);
 void bmp_playback_stop(void);
+void bmp_playback_stop_for_restart(void);
 gboolean bmp_playback_play_file(const gchar * filename);
 gboolean bmp_playback_get_playing(void);
 gboolean bmp_playback_get_paused(void);
