$NetBSD: patch-src_audio_bsd_SDL__bsdaudio.c,v 1.3 2016/10/28 19:13:44 adam Exp $

# Remove delay as there is already an inherent delay in writing audio.
https://bugzilla.libsdl.org/show_bug.cgi?id=3177

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
