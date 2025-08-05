$NetBSD: patch-audio.c,v 1.2 2025/08/05 19:33:02 schmonz Exp $

Add support for Sun/NetBSD audio.

--- audio.c.orig	2025-01-31 14:57:31.000000000 +0000
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
@@ -69,6 +72,9 @@ static audio_output *outputs[] = {
 #ifdef CONFIG_SNDIO
     &audio_sndio,
 #endif
+#ifdef CONFIG_SUN
+    &audio_sun,
+#endif
 #ifdef CONFIG_PW
     &audio_pw,
 #endif
