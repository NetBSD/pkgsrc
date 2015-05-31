$NetBSD: patch-src_audio_bsd_SDL__bsdaudio.c,v 1.1 2015/05/31 09:20:48 nat Exp $

# Remove delay as there is already an inherent delay in writing audio.
--- src/audio/bsd/SDL_bsdaudio.c.orig	2014-03-16 02:31:44.000000000 +0000
+++ src/audio/bsd/SDL_bsdaudio.c
@@ -181,11 +181,6 @@ BSDAUDIO_PlayDevice(_THIS)
             perror("audio");
             break;
         }
-
-        if (p < written
-            || ((written < 0) && ((errno == 0) || (errno == EAGAIN)))) {
-            SDL_Delay(1);       /* Let a little CPU time go by */
-        }
     } while (p < written);
 
     /* If timer synchronization is enabled, set the next write frame */
