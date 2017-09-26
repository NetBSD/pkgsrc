$NetBSD: patch-src_audio_netbsd_SDL__netbsdaudio.c,v 1.1 2017/09/26 13:10:56 adam Exp $

Remove delay as there is already an inherent delay in writing audio.
https://bugzilla.libsdl.org/show_bug.cgi?id=3177

audio_prinfo needs 'struct' on NetBSD.
Use correct prinfo.
Inform upper layer of blocksize

--- src/audio/netbsd/SDL_netbsdaudio.c.orig	2017-09-26 12:34:35.000000000 +0000
+++ src/audio/netbsd/SDL_netbsdaudio.c
@@ -63,14 +63,14 @@ NETBSDAUDIO_Status(_THIS)
 #ifdef DEBUG_AUDIO
     /* *INDENT-OFF* */
     audio_info_t info;
-    const audio_prinfo *prinfo;
+    const struct audio_prinfo *prinfo;
 
     if (ioctl(this->hidden->audio_fd, AUDIO_GETINFO, &info) < 0) {
         fprintf(stderr, "AUDIO_GETINFO failed.\n");
         return;
     }
 
-    prinfo = this->iscapture ? &info.play : &info.record;
+    prinfo = this->iscapture ? &info.record : &info.play;
 
     fprintf(stderr, "\n"
             "[%s info]\n"
@@ -184,10 +184,6 @@ NETBSDAUDIO_PlayDevice(_THIS)
         fprintf(stderr, "Wrote %d bytes of audio data\n", written);
 #endif
 
-        if (p < this->hidden->mixlen
-            || ((written < 0) && ((errno == 0) || (errno == EAGAIN)))) {
-            SDL_Delay(1);       /* Let a little CPU time go by */
-        }
     } while (p < this->hidden->mixlen);
 
     /* If timer synchronization is enabled, set the next write frame */
@@ -274,7 +270,7 @@ NETBSDAUDIO_OpenDevice(_THIS, void *hand
     const int flags = iscapture ? OPEN_FLAGS_INPUT : OPEN_FLAGS_OUTPUT;
     SDL_AudioFormat format = 0;
     audio_info_t info;
-    audio_prinfo *prinfo = iscapture ? &info.play : &info.record;
+    struct audio_prinfo *prinfo = iscapture ? &info.record : &info.play;
 
     /* We don't care what the devname is...we'll try to open anything. */
     /*  ...but default to first name in the list... */
@@ -366,6 +362,7 @@ NETBSDAUDIO_OpenDevice(_THIS, void *hand
     (void) ioctl(this->hidden->audio_fd, AUDIO_SETINFO, &info);
     (void) ioctl(this->hidden->audio_fd, AUDIO_GETINFO, &info);
     this->spec.freq = prinfo->sample_rate;
+    this->spec.size = info.blocksize;
 
     if (!iscapture) {
         /* Allocate mixing buffer */
