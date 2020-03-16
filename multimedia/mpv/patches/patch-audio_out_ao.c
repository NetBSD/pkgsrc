$NetBSD: patch-audio_out_ao.c,v 1.1 2020/03/16 20:31:44 nia Exp $

NetBSD audio support.

--- audio/out/ao.c.orig	2020-01-26 20:31:54.000000000 +0000
+++ audio/out/ao.c
@@ -40,6 +40,7 @@ extern const struct ao_driver audio_out_
 extern const struct ao_driver audio_out_audiounit;
 extern const struct ao_driver audio_out_coreaudio;
 extern const struct ao_driver audio_out_coreaudio_exclusive;
+extern const struct ao_driver audio_out_netbsd;
 extern const struct ao_driver audio_out_rsound;
 extern const struct ao_driver audio_out_sndio;
 extern const struct ao_driver audio_out_pulse;
@@ -64,6 +65,9 @@ static const struct ao_driver * const au
 #if HAVE_COREAUDIO
     &audio_out_coreaudio,
 #endif
+#if HAVE_NETBSD_AUDIO
+    &audio_out_netbsd,
+#endif
 #if HAVE_PULSE
     &audio_out_pulse,
 #endif
