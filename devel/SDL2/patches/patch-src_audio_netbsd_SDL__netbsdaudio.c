$NetBSD: patch-src_audio_netbsd_SDL__netbsdaudio.c,v 1.2 2019/05/24 18:13:36 nia Exp $

Remove delays and use blocking i/o
https://bugzilla.libsdl.org/show_bug.cgi?id=3177

audio_prinfo needs 'struct' on NetBSD.
Use correct prinfo type (play/record)
Rework initialization

--- src/audio/netbsd/SDL_netbsdaudio.c.orig	2018-10-31 15:07:22.000000000 +0000
+++ src/audio/netbsd/SDL_netbsdaudio.c
@@ -43,12 +43,7 @@
 #include "../SDL_audiodev_c.h"
 #include "SDL_netbsdaudio.h"
 
-/* Use timer for synchronization */
-/* #define USE_TIMER_SYNC */
-
 /* #define DEBUG_AUDIO */
-/* #define DEBUG_AUDIO_STREAM */
-
 
 static void
 NETBSDAUDIO_DetectDevices(void)
@@ -63,14 +58,14 @@ NETBSDAUDIO_Status(_THIS)
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
@@ -115,90 +110,37 @@ NETBSDAUDIO_Status(_THIS)
             (info.mode == AUMODE_PLAY) ? "PLAY"
             : (info.mode = AUMODE_RECORD) ? "RECORD"
             : (info.mode == AUMODE_PLAY_ALL ? "PLAY_ALL" : "?"));
+
+    fprintf(stderr, "\n"
+            "[audio spec]\n"
+            "format		:   0x%x\n"
+            "size		:   %u\n"
+            "",
+            this->spec.format,
+            this->spec.size);
     /* *INDENT-ON* */
 #endif /* DEBUG_AUDIO */
 }
 
 
-/* This function waits until it is possible to write a full sound buffer */
-static void
-NETBSDAUDIO_WaitDevice(_THIS)
-{
-#ifndef USE_BLOCKING_WRITES     /* Not necessary when using blocking writes */
-    /* See if we need to use timed audio synchronization */
-    if (this->hidden->frame_ticks) {
-        /* Use timer for general audio synchronization */
-        Sint32 ticks;
-
-        ticks = ((Sint32) (this->hidden->next_frame - SDL_GetTicks())) - FUDGE_TICKS;
-        if (ticks > 0) {
-            SDL_Delay(ticks);
-        }
-    } else {
-        /* Use SDL_IOReady() for audio synchronization */
-#ifdef DEBUG_AUDIO
-        fprintf(stderr, "Waiting for audio to get ready\n");
-#endif
-        if (SDL_IOReady(this->hidden->audio_fd, SDL_TRUE, 10 * 1000)
-            <= 0) {
-            const char *message =
-                "Audio timeout - buggy audio driver? (disabled)";
-            /* In general we should never print to the screen,
-               but in this case we have no other way of letting
-               the user know what happened.
-             */
-            fprintf(stderr, "SDL: %s\n", message);
-            SDL_OpenedAudioDeviceDisconnected(this);
-            /* Don't try to close - may hang */
-            this->hidden->audio_fd = -1;
-#ifdef DEBUG_AUDIO
-            fprintf(stderr, "Done disabling audio\n");
-#endif
-        }
-#ifdef DEBUG_AUDIO
-        fprintf(stderr, "Ready!\n");
-#endif
-    }
-#endif /* !USE_BLOCKING_WRITES */
-}
-
 static void
 NETBSDAUDIO_PlayDevice(_THIS)
 {
-    int written, p = 0;
+    struct SDL_PrivateAudioData *h = this->hidden;
+    int written;
 
-    /* Write the audio data, checking for EAGAIN on broken audio drivers */
-    do {
-        written = write(this->hidden->audio_fd,
-                        &this->hidden->mixbuf[p], this->hidden->mixlen - p);
-
-        if (written > 0)
-            p += written;
-        if (written == -1 && errno != 0 && errno != EAGAIN && errno != EINTR) {
-            /* Non recoverable error has occurred. It should be reported!!! */
-            perror("audio");
-            break;
-        }
+    /* Write the audio data */
+    written = write(h->audio_fd, h->mixbuf, h->mixlen);
+    if (written == -1) {
+        /* Non recoverable error has occurred. It should be reported!!! */
+        SDL_OpenedAudioDeviceDisconnected(this);
+        perror("audio");
+        return;
+    }
 
 #ifdef DEBUG_AUDIO
-        fprintf(stderr, "Wrote %d bytes of audio data\n", written);
+    fprintf(stderr, "Wrote %d bytes of audio data\n", written);
 #endif
-
-        if (p < this->hidden->mixlen
-            || ((written < 0) && ((errno == 0) || (errno == EAGAIN)))) {
-            SDL_Delay(1);       /* Let a little CPU time go by */
-        }
-    } while (p < this->hidden->mixlen);
-
-    /* If timer synchronization is enabled, set the next write frame */
-    if (this->hidden->frame_ticks) {
-        this->hidden->next_frame += this->hidden->frame_ticks;
-    }
-
-    /* If we couldn't write, assume fatal error for now */
-    if (written < 0) {
-        SDL_OpenedAudioDeviceDisconnected(this);
-    }
 }
 
 static Uint8 *
@@ -212,28 +154,19 @@ static int
 NETBSDAUDIO_CaptureFromDevice(_THIS, void *_buffer, int buflen)
 {
     Uint8 *buffer = (Uint8 *) _buffer;
-    int br, p = 0;
+    int br;
 
-    /* Capture the audio data, checking for EAGAIN on broken audio drivers */
-    do {
-        br = read(this->hidden->audio_fd, buffer + p, buflen - p);
-        if (br > 0)
-            p += br;
-        if (br == -1 && errno != 0 && errno != EAGAIN && errno != EINTR) {
-            /* Non recoverable error has occurred. It should be reported!!! */
-            perror("audio");
-            return p ? p : -1;
-        }
+    br = read(this->hidden->audio_fd, buffer, buflen);
+    if (br == -1) {
+        /* Non recoverable error has occurred. It should be reported!!! */
+        perror("audio");
+        return -1;
+    }
 
 #ifdef DEBUG_AUDIO
-        fprintf(stderr, "Captured %d bytes of audio data\n", br);
+    fprintf(stderr, "Captured %d bytes of audio data\n", br);
 #endif
-
-        if (p < buflen
-            || ((br < 0) && ((errno == 0) || (errno == EAGAIN)))) {
-            SDL_Delay(1);       /* Let a little CPU time go by */
-        }
-    } while (p < buflen);
+    return 0;
 }
 
 static void
@@ -271,10 +204,9 @@ NETBSDAUDIO_CloseDevice(_THIS)
 static int
 NETBSDAUDIO_OpenDevice(_THIS, void *handle, const char *devname, int iscapture)
 {
-    const int flags = iscapture ? OPEN_FLAGS_INPUT : OPEN_FLAGS_OUTPUT;
     SDL_AudioFormat format = 0;
     audio_info_t info;
-    audio_prinfo *prinfo = iscapture ? &info.play : &info.record;
+    struct audio_prinfo *prinfo = iscapture ? &info.record : &info.play;
 
     /* We don't care what the devname is...we'll try to open anything. */
     /*  ...but default to first name in the list... */
@@ -294,25 +226,16 @@ NETBSDAUDIO_OpenDevice(_THIS, void *hand
     SDL_zerop(this->hidden);
 
     /* Open the audio device */
-    this->hidden->audio_fd = open(devname, flags, 0);
+    this->hidden->audio_fd = open(devname, iscapture ? O_RDONLY : O_WRONLY);
     if (this->hidden->audio_fd < 0) {
         return SDL_SetError("Couldn't open %s: %s", devname, strerror(errno));
     }
 
     AUDIO_INITINFO(&info);
 
-    /* Calculate the final parameters for this audio specification */
-    SDL_CalculateAudioSpec(&this->spec);
-
-    /* Set to play mode */
-    info.mode = iscapture ? AUMODE_RECORD : AUMODE_PLAY;
-    if (ioctl(this->hidden->audio_fd, AUDIO_SETINFO, &info) < 0) {
-        return SDL_SetError("Couldn't put device into play mode");
-    }
+    prinfo->encoding = AUDIO_ENCODING_NONE;
 
-    AUDIO_INITINFO(&info);
-    for (format = SDL_FirstAudioFormat(this->spec.format);
-         format; format = SDL_NextAudioFormat()) {
+    for (format = SDL_FirstAudioFormat(this->spec.format); format;) {
         switch (format) {
         case AUDIO_U8:
             prinfo->encoding = AUDIO_ENCODING_ULINEAR;
@@ -338,34 +261,33 @@ NETBSDAUDIO_OpenDevice(_THIS, void *hand
             prinfo->encoding = AUDIO_ENCODING_ULINEAR_BE;
             prinfo->precision = 16;
             break;
-        default:
-            continue;
         }
-
-        if (ioctl(this->hidden->audio_fd, AUDIO_SETINFO, &info) == 0) {
+        if (prinfo->encoding != AUDIO_ENCODING_NONE) {
             break;
         }
+        format = SDL_NextAudioFormat();
     }
 
-    if (!format) {
+    if (prinfo->encoding == AUDIO_ENCODING_NONE) {
         return SDL_SetError("No supported encoding for 0x%x", this->spec.format);
     }
 
     this->spec.format = format;
 
-    AUDIO_INITINFO(&info);
-    prinfo->channels = this->spec.channels;
-    if (ioctl(this->hidden->audio_fd, AUDIO_SETINFO, &info) == -1) {
-        this->spec.channels = 1;
-    }
-    AUDIO_INITINFO(&info);
-    prinfo->sample_rate = this->spec.freq;
+    /* Calculate spec parameters based on our chosen format */
+    SDL_CalculateAudioSpec(&this->spec);
+
+    info.mode = iscapture ? AUMODE_RECORD : AUMODE_PLAY;
     info.blocksize = this->spec.size;
     info.hiwat = 5;
     info.lowat = 3;
+    prinfo->sample_rate = this->spec.freq;
+    prinfo->channels = this->spec.channels;
     (void) ioctl(this->hidden->audio_fd, AUDIO_SETINFO, &info);
+
     (void) ioctl(this->hidden->audio_fd, AUDIO_GETINFO, &info);
     this->spec.freq = prinfo->sample_rate;
+    this->spec.channels = prinfo->channels;
 
     if (!iscapture) {
         /* Allocate mixing buffer */
@@ -390,7 +312,6 @@ NETBSDAUDIO_Init(SDL_AudioDriverImpl * i
     impl->DetectDevices = NETBSDAUDIO_DetectDevices;
     impl->OpenDevice = NETBSDAUDIO_OpenDevice;
     impl->PlayDevice = NETBSDAUDIO_PlayDevice;
-    impl->WaitDevice = NETBSDAUDIO_WaitDevice;
     impl->GetDeviceBuf = NETBSDAUDIO_GetDeviceBuf;
     impl->CloseDevice = NETBSDAUDIO_CloseDevice;
     impl->CaptureFromDevice = NETBSDAUDIO_CaptureFromDevice;
