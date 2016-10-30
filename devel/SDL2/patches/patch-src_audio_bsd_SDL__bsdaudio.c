$NetBSD: patch-src_audio_bsd_SDL__bsdaudio.c,v 1.4 2016/10/30 10:37:17 wiz Exp $

# Remove delay as there is already an inherent delay in writing audio.
https://bugzilla.libsdl.org/show_bug.cgi?id=3177

# audio_prinfo needs 'struct' on NetBSD.

--- src/audio/bsd/SDL_bsdaudio.c.orig	2016-10-20 03:56:26.000000000 +0000
+++ src/audio/bsd/SDL_bsdaudio.c
@@ -190,10 +190,6 @@ BSDAUDIO_PlayDevice(_THIS)
         fprintf(stderr, "Wrote %d bytes of audio data\n", written);
 #endif
 
-        if (p < this->hidden->mixlen
-            || ((written < 0) && ((errno == 0) || (errno == EAGAIN)))) {
-            SDL_Delay(1);       /* Let a little CPU time go by */
-        }
     } while (p < this->hidden->mixlen);
 
     /* If timer synchronization is enabled, set the next write frame */
@@ -280,7 +276,7 @@ BSDAUDIO_OpenDevice(_THIS, void *handle,
     const int flags = iscapture ? OPEN_FLAGS_INPUT : OPEN_FLAGS_OUTPUT;
     SDL_AudioFormat format = 0;
     audio_info_t info;
-    audio_prinfo *prinfo = iscapture ? &info.play : &info.record;
+    struct audio_prinfo *prinfo = iscapture ? &info.play : &info.record;
 
     /* We don't care what the devname is...we'll try to open anything. */
     /*  ...but default to first name in the list... */
