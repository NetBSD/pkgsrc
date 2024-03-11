$NetBSD: patch-src_libespeak-ng_speech.c,v 1.1 2024/03/11 08:03:45 wiz Exp $

* fifo_stop() creates a noticeable delay, call audio_object_flush() first.

--- src/libespeak-ng/speech.c.orig	2022-04-02 19:24:41.000000000 +0000
+++ src/libespeak-ng/speech.c
@@ -881,15 +881,14 @@ ESPEAK_API const char *espeak_TextToPhon
 
 ESPEAK_NG_API espeak_ng_STATUS espeak_ng_Cancel(void)
 {
-#ifdef USE_ASYNC
-	fifo_stop();
-	event_clear_all();
-#endif
-
 #ifdef HAVE_PCAUDIOLIB_AUDIO_H
 	if ((my_mode & ENOUTPUT_MODE_SPEAK_AUDIO) == ENOUTPUT_MODE_SPEAK_AUDIO)
 		audio_object_flush(my_audio);
 #endif
+#ifdef USE_ASYNC
+	fifo_stop();
+	event_clear_all();
+#endif
 	embedded_value[EMBED_T] = 0; // reset echo for pronunciation announcements
 
 	for (int i = 0; i < N_SPEECH_PARAM; i++)
