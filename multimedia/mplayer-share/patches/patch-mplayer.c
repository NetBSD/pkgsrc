$NetBSD: patch-mplayer.c,v 1.2 2025/11/15 12:43:18 ryoon Exp $

NetBSD implements no "perfect audio delay measurement"
(suggested to be required by mplayer's man page).

This allows video to be played at full speed without perfect
audio delay measurement.

--- mplayer.c.orig	2024-09-21 09:30:15.000000000 +0000
+++ mplayer.c
@@ -209,7 +209,11 @@ static int loop_seek;
 static m_time_size_t end_at = { .type = END_AT_NONE, .pos = 0 };
 
 // A/V sync:
+#ifdef __NetBSD__
+int autosync = 30;
+#else
 int autosync;        // 30 might be a good default value.
+#endif
 
 // may be changed by GUI:  (FIXME!)
 float rel_seek_secs;
