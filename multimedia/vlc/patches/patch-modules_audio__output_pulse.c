$NetBSD: patch-modules_audio__output_pulse.c,v 1.2 2011/09/12 17:25:28 drochner Exp $
To enable build against pulse-audio 0.9.21 - seems to work

--- modules/audio_output/pulse.c.orig	2011-06-06 22:53:14.000000000 +0000
+++ modules/audio_output/pulse.c
@@ -272,7 +272,7 @@ static int Open(vlc_object_t *obj)
 {
     aout_instance_t *aout = (aout_instance_t *)obj;
 
-#if !defined(PA_CHECK_VERSION) || !PA_CHECK_VERSION(0,9,22)
+#if !defined(PA_CHECK_VERSION) || !PA_CHECK_VERSION(0,9,20)
     if( !vlc_xlib_init( obj ) )
         return VLC_EGENERIC;
 #endif
