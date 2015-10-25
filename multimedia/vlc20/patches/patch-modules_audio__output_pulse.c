$NetBSD: patch-modules_audio__output_pulse.c,v 1.1 2015/10/25 10:52:24 wiz Exp $

--- modules/audio_output/pulse.c.orig	2011-12-08 18:00:26.000000000 +0000
+++ modules/audio_output/pulse.c
@@ -664,7 +664,7 @@ static int StreamMove(vlc_object_t *obj,
  */
 static int Open(vlc_object_t *obj)
 {
-#if !PA_CHECK_VERSION(0,9,22)
+#if !PA_CHECK_VERSION(0,9,20)
     if (!vlc_xlib_init(obj))
         return VLC_EGENERIC;
 #endif
