$NetBSD: patch-audio.c,v 1.1 2022/07/01 18:36:28 nia Exp $

Add support for Sun/NetBSD audio.

--- audio.c.orig	2020-12-01 12:16:11.000000000 +0000
+++ audio.c
@@ -37,6 +37,9 @@ extern audio_output audio_jack;
 #ifdef CONFIG_SNDIO
 extern audio_output audio_sndio;
 #endif
+#ifdef CONFIG_SUN
+extern audio_output audio_sun;
+#endif
 #ifdef CONFIG_AO
 extern audio_output audio_ao;
 #endif
@@ -66,6 +69,9 @@ static audio_output *outputs[] = {
 #ifdef CONFIG_SNDIO
     &audio_sndio,
 #endif
+#ifdef CONFIG_SUN
+    &audio_sun,
+#endif
 #ifdef CONFIG_PA
     &audio_pa,
 #endif
