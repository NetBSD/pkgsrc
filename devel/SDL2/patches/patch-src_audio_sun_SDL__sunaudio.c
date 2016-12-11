$NetBSD: patch-src_audio_sun_SDL__sunaudio.c,v 1.1 2016/12/11 19:42:46 wiedi Exp $

move decleration up because SDL wants to use -Werror=declaration-after-statement

--- src/audio/sun/SDL_sunaudio.c.orig	2016-10-20 03:56:26.000000000 +0000
+++ src/audio/sun/SDL_sunaudio.c
@@ -193,6 +193,10 @@ SUNAUDIO_CloseDevice(_THIS)
 static int
 SUNAUDIO_OpenDevice(_THIS, void *handle, const char *devname, int iscapture)
 {
+#ifdef AUDIO_SETINFO
+    int enc;
+#endif
+    int desired_freq = 0;
     const int flags = ((iscapture) ? OPEN_FLAGS_INPUT : OPEN_FLAGS_OUTPUT);
     SDL_AudioFormat format = 0;
     audio_info_t info;
@@ -220,10 +224,7 @@ SUNAUDIO_OpenDevice(_THIS, void *handle,
         return SDL_SetError("Couldn't open %s: %s", devname, strerror(errno));
     }
 
-#ifdef AUDIO_SETINFO
-    int enc;
-#endif
-    int desired_freq = this->spec.freq;
+    desired_freq = this->spec.freq;
 
     /* Determine the audio parameters from the AudioSpec */
     switch (SDL_AUDIO_BITSIZE(this->spec.format)) {
