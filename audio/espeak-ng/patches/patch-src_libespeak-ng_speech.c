$NetBSD: patch-src_libespeak-ng_speech.c,v 1.2 2024/12/26 11:45:00 wiz Exp $

* fifo_stop() creates a noticeable delay, call audio_object_flush() first.

--- src/libespeak-ng/speech.c.orig	2024-12-12 13:28:01.000000000 +0000
+++ src/libespeak-ng/speech.c
@@ -872,17 +872,17 @@ ESPEAK_API const char *espeak_TextToPhon
 
 ESPEAK_NG_API espeak_ng_STATUS espeak_ng_Cancel(void)
 {
-#if USE_ASYNC
-	fifo_stop();
-	event_clear_all();
-#endif
-
 #if USE_LIBPCAUDIO
 	if ((my_mode & ENOUTPUT_MODE_SPEAK_AUDIO) == ENOUTPUT_MODE_SPEAK_AUDIO)
 		audio_object_flush(my_audio);
 #endif
 	embedded_value[EMBED_T] = 0; // reset echo for pronunciation announcements
 
+#if USE_ASYNC
+	fifo_stop();
+	event_clear_all();
+#endif
+
 	for (int i = 0; i < N_SPEECH_PARAM; i++)
 		SetParameter(i, saved_parameters[i], 0);
 
