$NetBSD: patch-src_audio_netbsd_SDL__netbsdaudio.c,v 1.5 2020/04/08 14:41:33 nia Exp $

Use the preferred hardware sample rate
https://bugzilla.libsdl.org/show_bug.cgi?id=5080

Support 32-bit LPCM
https://bugzilla.libsdl.org/show_bug.cgi?id=5076

--- src/audio/netbsd/SDL_netbsdaudio.c.orig	2020-03-11 01:36:18.000000000 +0000
+++ src/audio/netbsd/SDL_netbsdaudio.c
@@ -205,7 +205,7 @@ static int
 NETBSDAUDIO_OpenDevice(_THIS, void *handle, const char *devname, int iscapture)
 {
     SDL_AudioFormat format = 0;
-    audio_info_t info;
+    audio_info_t info, hwinfo;
     struct audio_prinfo *prinfo = iscapture ? &info.record : &info.play;
 
     /* We don't care what the devname is...we'll try to open anything. */
@@ -232,8 +232,16 @@ NETBSDAUDIO_OpenDevice(_THIS, void *hand
     }
 
     AUDIO_INITINFO(&info);
+    AUDIO_INITINFO(&hwinfo);
+
+    if (ioctl(this->hidden->audio_fd, AUDIO_GETFORMAT, &hwinfo) == -1) {
+        return SDL_SetError("Couldn't get device format %s: %s", devname, strerror(errno));
+    }
 
     prinfo->encoding = AUDIO_ENCODING_NONE;
+    prinfo->channels = this->spec.channels;
+    prinfo->sample_rate = this->spec.freq = iscapture ?
+        hwinfo.record.sample_rate : hwinfo.play.sample_rate;
 
     for (format = SDL_FirstAudioFormat(this->spec.format); format;) {
         switch (format) {
@@ -261,6 +269,14 @@ NETBSDAUDIO_OpenDevice(_THIS, void *hand
             prinfo->encoding = AUDIO_ENCODING_ULINEAR_BE;
             prinfo->precision = 16;
             break;
+        case AUDIO_S32LSB:
+            prinfo->encoding = AUDIO_ENCODING_SLINEAR_LE;
+            prinfo->precision = 32;
+            break;
+        case AUDIO_S32MSB:
+            prinfo->encoding = AUDIO_ENCODING_SLINEAR_BE;
+            prinfo->precision = 32;
+            break;
         }
         if (prinfo->encoding != AUDIO_ENCODING_NONE) {
             break;
@@ -274,21 +290,18 @@ NETBSDAUDIO_OpenDevice(_THIS, void *hand
 
     this->spec.format = format;
 
-    /* Calculate spec parameters based on our chosen format */
-    SDL_CalculateAudioSpec(&this->spec);
-
     info.mode = iscapture ? AUMODE_RECORD : AUMODE_PLAY;
-    info.blocksize = this->spec.size;
     info.hiwat = 5;
     info.lowat = 3;
-    prinfo->sample_rate = this->spec.freq;
-    prinfo->channels = this->spec.channels;
     (void) ioctl(this->hidden->audio_fd, AUDIO_SETINFO, &info);
 
     (void) ioctl(this->hidden->audio_fd, AUDIO_GETINFO, &info);
     this->spec.freq = prinfo->sample_rate;
     this->spec.channels = prinfo->channels;
 
+    /* Calculate spec parameters based on our chosen format */
+    SDL_CalculateAudioSpec(&this->spec);
+
     if (!iscapture) {
         /* Allocate mixing buffer */
         this->hidden->mixlen = this->spec.size;
