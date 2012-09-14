$NetBSD: patch-src_audio_sun_SDL__sunaudio.c,v 1.2 2012/09/14 13:20:20 wiz Exp $

Use AUDIO_GETBUFINFO when available (jmcneill@).

--- src/audio/sun/SDL_sunaudio.c.orig	2009-10-12 23:07:14.000000000 +0000
+++ src/audio/sun/SDL_sunaudio.c
@@ -47,6 +47,10 @@
 /* Open the audio device for playback, and don't block if busy */
 #define OPEN_FLAGS	(O_WRONLY|O_NONBLOCK)
 
+#if defined(AUDIO_GETINFO) && !defined(AUDIO_GETBUFINFO) 
+#define AUDIO_GETBUFINFO AUDIO_GETINFO
+#endif
+
 /* Audio driver functions */
 static int DSP_OpenAudio(_THIS, SDL_AudioSpec *spec);
 static void DSP_WaitAudio(_THIS);
@@ -119,11 +123,11 @@ AudioBootStrap SUNAUDIO_bootstrap = {
 #ifdef DEBUG_AUDIO
 void CheckUnderflow(_THIS)
 {
-#ifdef AUDIO_GETINFO
+#ifdef AUDIO_GETBUFINFO
 	audio_info_t info;
 	int left;
 
-	ioctl(audio_fd, AUDIO_GETINFO, &info);
+	ioctl(audio_fd, AUDIO_GETBUFINFO, &info);
 	left = (written - info.play.samples);
 	if ( written && (left == 0) ) {
 		fprintf(stderr, "audio underflow!\n");
@@ -134,12 +138,12 @@ void CheckUnderflow(_THIS)
 
 void DSP_WaitAudio(_THIS)
 {
-#ifdef AUDIO_GETINFO
+#ifdef AUDIO_GETBUFINFO
 #define SLEEP_FUDGE	10		/* 10 ms scheduling fudge factor */
 	audio_info_t info;
 	Sint32 left;
 
-	ioctl(audio_fd, AUDIO_GETINFO, &info);
+	ioctl(audio_fd, AUDIO_GETBUFINFO, &info);
 	left = (written - info.play.samples);
 	if ( left > fragsize ) {
 		Sint32 sleepy;
