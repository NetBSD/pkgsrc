$NetBSD: patch-src_audio_netbsd_SDL_netbsdaudio.c,v 1.1 2021/03/09 20:41:08 mrg Exp $

check the return value of ioctl() on audio device and report error
if it doesn't work.  stops eg mpv from hanging when it thinks that
it opened the audio device.

--- src/audio/netbsd/SDL_netbsdaudio.c.orig	2020-12-21 11:44:36.000000000 -0600
+++ src/audio/netbsd/SDL_netbsdaudio.c	2021-03-09 14:27:27.994211006 -0600
@@ -291,9 +291,14 @@
     info.lowat = 3;
     prinfo->sample_rate = this->spec.freq;
     prinfo->channels = this->spec.channels;
-    (void) ioctl(this->hidden->audio_fd, AUDIO_SETINFO, &info);
 
-    (void) ioctl(this->hidden->audio_fd, AUDIO_GETINFO, &info);
+    if (ioctl(this->hidden->audio_fd, AUDIO_SETINFO, &info) < 0) {
+        return SDL_SetError("Couldn't AUDIO_SETINFO %s: %s", devname, strerror(errno));
+    }
+
+    if (ioctl(this->hidden->audio_fd, AUDIO_GETINFO, &info) < 0) {
+        return SDL_SetError("Couldn't AUDIO_GETINFO %s: %s", devname, strerror(errno));
+    }
     this->spec.freq = prinfo->sample_rate;
     this->spec.channels = prinfo->channels;
 
