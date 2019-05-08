$NetBSD: patch-configuration.c,v 1.1 2019/05/08 12:40:05 nia Exp $

Add audioio as a default audio driver on supported platforms.

--- configuration.c.orig	2019-05-08 06:06:22.000000000 +0000
+++ configuration.c
@@ -178,6 +178,7 @@ enum video_driver_enum
 enum audio_driver_enum
 {
    AUDIO_RSOUND             = VIDEO_NULL + 1,
+   AUDIO_AUDIOIO,
    AUDIO_OSS,
    AUDIO_ALSA,
    AUDIO_ALSATHREAD,
@@ -399,6 +400,8 @@ static enum audio_driver_enum AUDIO_DEFA
 static enum audio_driver_enum AUDIO_DEFAULT_DRIVER = AUDIO_ALSA;
 #elif defined(HAVE_TINYALSA)
 static enum audio_driver_enum AUDIO_DEFAULT_DRIVER = AUDIO_TINYALSA;
+#elif defined(HAVE_AUDIOIO)
+static enum audio_driver_enum AUDIO_DEFAULT_DRIVER = AUDIO_AUDIOIO;
 #elif defined(HAVE_OSS)
 static enum audio_driver_enum AUDIO_DEFAULT_DRIVER = AUDIO_OSS;
 #elif defined(HAVE_JACK)
@@ -664,6 +667,8 @@ const char *config_get_default_audio(voi
    {
       case AUDIO_RSOUND:
          return "rsound";
+      case AUDIO_AUDIOIO:
+         return "audioio";
       case AUDIO_OSS:
          return "oss";
       case AUDIO_ALSA:
