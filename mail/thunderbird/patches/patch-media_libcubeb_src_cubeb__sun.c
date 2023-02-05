$NetBSD: patch-media_libcubeb_src_cubeb__sun.c,v 1.2 2023/02/05 09:05:29 he Exp $

--- media/libcubeb/src/cubeb_sun.c.orig	2020-09-02 21:41:01.178547066 +0000
+++ media/libcubeb/src/cubeb_sun.c
@@ -1,5 +1,5 @@
 /*
- * Copyright © 2019 Nia Alarie
+ * Copyright © 2019-2020 Nia Alarie <nia@NetBSD.org>
  *
  * This program is made available under an ISC-style license.  See the
  * accompanying file LICENSE for details.
@@ -9,19 +9,14 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <pthread.h>
+#include <stdbool.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
-#include <math.h>
+#include <limits.h>
 #include "cubeb/cubeb.h"
 #include "cubeb-internal.h"
 
-#define BYTES_TO_FRAMES(bytes, channels) \
-  (bytes / (channels * sizeof(int16_t)))
-
-#define FRAMES_TO_BYTES(frames, channels) \
-  (frames * (channels * sizeof(int16_t)))
-
 /* Default to 4 + 1 for the default device. */
 #ifndef SUN_DEVICE_COUNT
 #define SUN_DEVICE_COUNT (5)
@@ -41,10 +36,6 @@
 #define SUN_DEFAULT_DEVICE "/dev/audio"
 #endif
 
-#ifndef SUN_POLL_TIMEOUT
-#define SUN_POLL_TIMEOUT (1000)
-#endif
-
 #ifndef SUN_BUFFER_FRAMES
 #define SUN_BUFFER_FRAMES (32)
 #endif
@@ -75,26 +66,26 @@ struct cubeb {
   struct cubeb_ops const * ops;
 };
 
+struct sun_stream {
+  char name[32];
+  int fd;
+  void * buf;
+  struct audio_info info;
+  unsigned frame_size; /* precision in bytes * channels */
+  bool floating;
+};
+
 struct cubeb_stream {
   struct cubeb * context;
   void * user_ptr;
   pthread_t thread;
   pthread_mutex_t mutex; /* protects running, volume, frames_written */
-  int floating;
-  int running;
-  int play_fd;
-  int record_fd;
+  bool running;
   float volume;
-  struct audio_info p_info; /* info for the play fd */
-  struct audio_info r_info; /* info for the record fd */
+  struct sun_stream play;
+  struct sun_stream record;
   cubeb_data_callback data_cb;
   cubeb_state_callback state_cb;
-  int16_t * play_buf;
-  int16_t * record_buf;
-  float * f_play_buf;
-  float * f_record_buf;
-  char input_name[32];
-  char output_name[32];
   uint64_t frames_written;
   uint64_t blocks_written;
 };
@@ -312,18 +303,19 @@ sun_copy_params(int fd, cubeb_stream * s
 {
   prinfo->channels = params->channels;
   prinfo->sample_rate = params->rate;
-  prinfo->precision = 16;
 #ifdef AUDIO_ENCODING_SLINEAR_LE
   switch (params->format) {
   case CUBEB_SAMPLE_S16LE:
     prinfo->encoding = AUDIO_ENCODING_SLINEAR_LE;
+    prinfo->precision = 16;
     break;
   case CUBEB_SAMPLE_S16BE:
     prinfo->encoding = AUDIO_ENCODING_SLINEAR_BE;
+    prinfo->precision = 16;
     break;
   case CUBEB_SAMPLE_FLOAT32NE:
-    stream->floating = 1;
     prinfo->encoding = AUDIO_ENCODING_SLINEAR;
+    prinfo->precision = 32;
     break;
   default:
     LOG("Unsupported format");
@@ -333,10 +325,11 @@ sun_copy_params(int fd, cubeb_stream * s
   switch (params->format) {
   case CUBEB_SAMPLE_S16NE:
     prinfo->encoding = AUDIO_ENCODING_LINEAR;
+    prinfo->precision = 16;
     break;
   case CUBEB_SAMPLE_FLOAT32NE:
-    stream->floating = 1;
     prinfo->encoding = AUDIO_ENCODING_LINEAR;
+    prinfo->precision = 32;
     break;
   default:
     LOG("Unsupported format");
@@ -357,7 +350,7 @@ sun_stream_stop(cubeb_stream * s)
 {
   pthread_mutex_lock(&s->mutex);
   if (s->running) {
-    s->running = 0;
+    s->running = false;
     pthread_mutex_unlock(&s->mutex);
     pthread_join(s->thread, NULL);
   } else {
@@ -371,53 +364,50 @@ sun_stream_destroy(cubeb_stream * s)
 {
   pthread_mutex_destroy(&s->mutex);
   sun_stream_stop(s);
-  if (s->play_fd != -1) {
-    close(s->play_fd);
+  if (s->play.fd != -1) {
+    close(s->play.fd);
   }
-  if (s->record_fd != -1) {
-    close(s->record_fd);
+  if (s->record.fd != -1) {
+    close(s->record.fd);
   }
-  free(s->f_play_buf);
-  free(s->f_record_buf);
-  free(s->play_buf);
-  free(s->record_buf);
+  free(s->play.buf);
+  free(s->record.buf);
   free(s);
 }
 
 static void
-sun_float_to_linear(float * in, int16_t * out,
-                    unsigned channels, long frames, float vol)
+sun_float_to_linear32(void * buf, unsigned sample_count, float vol)
 {
-  unsigned i, sample_count = frames * channels;
-  float multiplier = vol * 0x8000;
-
-  for (i = 0; i < sample_count; ++i) {
-    int32_t sample = lrintf(in[i] * multiplier);
-    if (sample < -0x8000) {
-      out[i] = -0x8000;
-    } else if (sample > 0x7fff) {
-      out[i] = 0x7fff;
-    } else {
-      out[i] = sample;
-    }
+  float * in = buf;
+  int32_t * out = buf;
+  int32_t * tail = out + sample_count;
+
+  while (out < tail) {
+    float f = *(in++) * vol;
+    if (f < -1.0)
+      f = -1.0;
+    else if (f > 1.0)
+      f = 1.0;
+    *(out++) = f * (float)INT32_MAX;
   }
 }
 
 static void
-sun_linear_to_float(int16_t * in, float * out,
-                    unsigned channels, long frames)
+sun_linear32_to_float(void * buf, unsigned sample_count) 
 {
-  unsigned i, sample_count = frames * channels;
+  int32_t * in = buf;
+  float * out = buf;
+  float * tail = out + sample_count;
 
-  for (i = 0; i < sample_count; ++i) {
-    out[i] = (1.0 / 0x8000) * in[i];
+  while (out < tail) {
+    *(out++) = (1.0 / 0x80000000) * *(in++);
   }
 }
 
 static void
-sun_linear_set_vol(int16_t * buf, unsigned channels, long frames, float vol)
+sun_linear16_set_vol(int16_t * buf, unsigned sample_count, float vol)
 {
-  unsigned i, sample_count = frames * channels;
+  unsigned i;
   int32_t multiplier = vol * 0x8000;
 
   for (i = 0; i < sample_count; ++i) {
@@ -445,41 +435,36 @@ sun_io_routine(void * arg)
       break;
     }
     pthread_mutex_unlock(&s->mutex);
-    if (s->floating) {
-      if (s->record_fd != -1) {
-        sun_linear_to_float(s->record_buf, s->f_record_buf,
-                            s->r_info.record.channels, SUN_BUFFER_FRAMES);
-      }
-      to_write = s->data_cb(s, s->user_ptr,
-                            s->f_record_buf, s->f_play_buf, SUN_BUFFER_FRAMES);
-      if (to_write == CUBEB_ERROR) {
-        state = CUBEB_STATE_ERROR;
-        break;
-      }
-      if (s->play_fd != -1) {
-        pthread_mutex_lock(&s->mutex);
-        sun_float_to_linear(s->f_play_buf, s->play_buf,
-                            s->p_info.play.channels, to_write, s->volume);
-        pthread_mutex_unlock(&s->mutex);
-      }
-    } else {
-      to_write = s->data_cb(s, s->user_ptr,
-                            s->record_buf, s->play_buf, SUN_BUFFER_FRAMES);
-      if (to_write == CUBEB_ERROR) {
-        state = CUBEB_STATE_ERROR;
-        break;
-      }
-      if (s->play_fd != -1) {
-        pthread_mutex_lock(&s->mutex);
-        sun_linear_set_vol(s->play_buf, s->p_info.play.channels, to_write, s->volume);
-        pthread_mutex_unlock(&s->mutex);
+    if (s->record.fd != -1 && s->record.floating) {
+      sun_linear32_to_float(s->record.buf,
+                            s->record.info.record.channels * SUN_BUFFER_FRAMES);
+    }
+    to_write = s->data_cb(s, s->user_ptr,
+                          s->record.buf, s->play.buf, SUN_BUFFER_FRAMES);
+    if (to_write == CUBEB_ERROR) {
+      state = CUBEB_STATE_ERROR;
+      break;
+    }
+    if (s->play.fd != -1) {
+      float vol;
+
+      pthread_mutex_lock(&s->mutex);
+      vol = s->volume;
+      pthread_mutex_unlock(&s->mutex);
+
+      if (s->play.floating) {
+        sun_float_to_linear32(s->play.buf,
+                              s->play.info.play.channels * to_write, vol);
+      } else {
+        sun_linear16_set_vol(s->play.buf,
+                             s->play.info.play.channels * to_write, vol);
       }
     }
     if (to_write < SUN_BUFFER_FRAMES) {
       drain = 1;
     }
-    to_write = s->play_fd != -1 ? to_write : 0;
-    to_read = s->record_fd != -1 ? SUN_BUFFER_FRAMES : 0;
+    to_write = s->play.fd != -1 ? to_write : 0;
+    to_read = s->record.fd != -1 ? SUN_BUFFER_FRAMES : 0;
     write_ofs = 0;
     read_ofs = 0;
     while (to_write > 0 || to_read > 0) {
@@ -487,27 +472,27 @@ sun_io_routine(void * arg)
       ssize_t n, frames;
 
       if (to_write > 0) {
-        bytes = FRAMES_TO_BYTES(to_write, s->p_info.play.channels);
-        if ((n = write(s->play_fd, s->play_buf + write_ofs, bytes)) < 0) {
+        bytes = to_write * s->play.frame_size;
+        if ((n = write(s->play.fd, (uint8_t *)s->play.buf + write_ofs, bytes)) < 0) {
           state = CUBEB_STATE_ERROR;
           break;
         }
-        frames = BYTES_TO_FRAMES(n, s->p_info.play.channels);
+        frames = n / s->play.frame_size;
         pthread_mutex_lock(&s->mutex);
         s->frames_written += frames;
         pthread_mutex_unlock(&s->mutex);
         to_write -= frames;
-        write_ofs += frames;
+        write_ofs += n;
       }
       if (to_read > 0) {
-        bytes = FRAMES_TO_BYTES(to_read, s->r_info.record.channels);
-        if ((n = read(s->record_fd, s->record_buf + read_ofs, bytes)) < 0) {
+        bytes = to_read * s->record.frame_size;
+        if ((n = read(s->record.fd, (uint8_t *)s->record.buf + read_ofs, bytes)) < 0) {
           state = CUBEB_STATE_ERROR;
           break;
         }
-        frames = BYTES_TO_FRAMES(n, s->r_info.record.channels);
+        frames = n / s->record.frame_size;
         to_read -= frames;
-        read_ofs += frames;
+        read_ofs += n;
       }
     }
     if (drain && state != CUBEB_STATE_ERROR) {
@@ -536,23 +521,24 @@ sun_stream_init(cubeb * context,
   cubeb_stream *s = NULL;
 
   (void)stream_name;
+  (void)latency_frames;
   if ((s = calloc(1, sizeof(cubeb_stream))) == NULL) {
     ret = CUBEB_ERROR;
     goto error;
   }
-  s->record_fd = -1;
-  s->play_fd = -1;
+  s->record.fd = -1;
+  s->play.fd = -1;
   if (input_device != 0) {
-    snprintf(s->input_name, sizeof(s->input_name),
+    snprintf(s->record.name, sizeof(s->record.name),
       "/dev/audio%zu", (uintptr_t)input_device - 1);
   } else {
-    snprintf(s->input_name, sizeof(s->input_name), "%s", SUN_DEFAULT_DEVICE);
+    snprintf(s->record.name, sizeof(s->record.name), "%s", SUN_DEFAULT_DEVICE);
   }
   if (output_device != 0) {
-    snprintf(s->output_name, sizeof(s->output_name),
+    snprintf(s->play.name, sizeof(s->play.name),
       "/dev/audio%zu", (uintptr_t)output_device - 1);
   } else {
-    snprintf(s->output_name, sizeof(s->output_name), "%s", SUN_DEFAULT_DEVICE);
+    snprintf(s->play.name, sizeof(s->play.name), "%s", SUN_DEFAULT_DEVICE);
   }
   if (input_stream_params != NULL) {
     if (input_stream_params->prefs & CUBEB_STREAM_PREF_LOOPBACK) {
@@ -560,22 +546,23 @@ sun_stream_init(cubeb * context,
       ret = CUBEB_ERROR_NOT_SUPPORTED;
       goto error;
     }
-    if (s->record_fd == -1) {
-      if ((s->record_fd = open(s->input_name, O_RDONLY)) == -1) {
-        LOG("Audio device cannot be opened as read-only");
+    if (s->record.fd == -1) {
+      if ((s->record.fd = open(s->record.name, O_RDONLY)) == -1) {
+        LOG("Audio device could not be opened as read-only");
         ret = CUBEB_ERROR_DEVICE_UNAVAILABLE;
         goto error;
       }
     }
-    AUDIO_INITINFO(&s->r_info);
+    AUDIO_INITINFO(&s->record.info);
 #ifdef AUMODE_RECORD
-    s->r_info.mode = AUMODE_RECORD;
+    s->record.info.mode = AUMODE_RECORD;
 #endif
-    if ((ret = sun_copy_params(s->record_fd, s, input_stream_params,
-                               &s->r_info, &s->r_info.record)) != CUBEB_OK) {
+    if ((ret = sun_copy_params(s->record.fd, s, input_stream_params,
+                               &s->record.info, &s->record.info.record)) != CUBEB_OK) {
       LOG("Setting record params failed");
       goto error;
     }
+    s->record.floating = (input_stream_params->format == CUBEB_SAMPLE_FLOAT32NE);
   }
   if (output_stream_params != NULL) {
     if (output_stream_params->prefs & CUBEB_STREAM_PREF_LOOPBACK) {
@@ -583,22 +570,23 @@ sun_stream_init(cubeb * context,
       ret = CUBEB_ERROR_NOT_SUPPORTED;
       goto error;
     }
-    if (s->play_fd == -1) {
-      if ((s->play_fd = open(s->output_name, O_WRONLY)) == -1) {
-        LOG("Audio device cannot be opened as write-only");
+    if (s->play.fd == -1) {
+      if ((s->play.fd = open(s->play.name, O_WRONLY)) == -1) {
+        LOG("Audio device could not be opened as write-only");
         ret = CUBEB_ERROR_DEVICE_UNAVAILABLE;
         goto error;
       }
     }
-    AUDIO_INITINFO(&s->p_info);
+    AUDIO_INITINFO(&s->play.info);
 #ifdef AUMODE_PLAY
-    s->p_info.mode = AUMODE_PLAY;
+    s->play.info.mode = AUMODE_PLAY;
 #endif
-    if ((ret = sun_copy_params(s->play_fd, s, output_stream_params,
-                               &s->p_info, &s->p_info.play)) != CUBEB_OK) {
+    if ((ret = sun_copy_params(s->play.fd, s, output_stream_params,
+                               &s->play.info, &s->play.info.play)) != CUBEB_OK) {
       LOG("Setting play params failed");
       goto error;
     }
+    s->play.floating = (output_stream_params->format == CUBEB_SAMPLE_FLOAT32NE);
   }
   s->context = context;
   s->volume = 1.0;
@@ -609,28 +597,20 @@ sun_stream_init(cubeb * context,
     LOG("Failed to create mutex");
     goto error;
   }
-  if (s->play_fd != -1 && (s->play_buf = calloc(SUN_BUFFER_FRAMES,
-      s->p_info.play.channels * sizeof(int16_t))) == NULL) {
+  s->play.frame_size = s->play.info.play.channels *
+                      (s->play.info.play.precision / 8);
+  if (s->play.fd != -1 &&
+     (s->play.buf = calloc(SUN_BUFFER_FRAMES, s->play.frame_size)) == NULL) {
     ret = CUBEB_ERROR;
     goto error;
   }
-  if (s->record_fd != -1 && (s->record_buf = calloc(SUN_BUFFER_FRAMES,
-      s->r_info.record.channels * sizeof(int16_t))) == NULL) {
+  s->record.frame_size = s->record.info.record.channels *
+                        (s->record.info.record.precision / 8);
+  if (s->record.fd != -1 &&
+     (s->record.buf = calloc(SUN_BUFFER_FRAMES, s->record.frame_size)) == NULL) {
     ret = CUBEB_ERROR;
     goto error;
   }
-  if (s->floating) {
-    if (s->play_fd != -1 && (s->f_play_buf = calloc(SUN_BUFFER_FRAMES,
-        s->p_info.play.channels * sizeof(float))) == NULL) {
-      ret = CUBEB_ERROR;
-      goto error;
-    }
-    if (s->record_fd != -1 && (s->f_record_buf = calloc(SUN_BUFFER_FRAMES,
-        s->r_info.record.channels * sizeof(float))) == NULL) {
-      ret = CUBEB_ERROR;
-      goto error;
-    }
-  }
   *stream = s;
   return CUBEB_OK;
 error:
@@ -643,7 +623,7 @@ error:
 static int
 sun_stream_start(cubeb_stream * s)
 {
-  s->running = 1;
+  s->running = true;
   if (pthread_create(&s->thread, NULL, sun_io_routine, s) != 0) {
     LOG("Couldn't create thread");
     return CUBEB_ERROR;
@@ -657,12 +637,11 @@ sun_stream_get_position(cubeb_stream * s
 #ifdef AUDIO_GETOOFFS
   struct audio_offset offset;
 
-  if (ioctl(s->play_fd, AUDIO_GETOOFFS, &offset) == -1) {
+  if (ioctl(s->play.fd, AUDIO_GETOOFFS, &offset) == -1) {
     return CUBEB_ERROR;
   }
   s->blocks_written += offset.deltablks;
-  *position = BYTES_TO_FRAMES(s->blocks_written * s->p_info.blocksize,
-                              s->p_info.play.channels);
+  *position = (s->blocks_written * s->play.info.blocksize) / s->play.frame_size;
   return CUBEB_OK;
 #else
   pthread_mutex_lock(&s->mutex);
@@ -673,22 +652,21 @@ sun_stream_get_position(cubeb_stream * s
 }
 
 static int
-sun_stream_get_latency(cubeb_stream * stream, uint32_t * latency)
+sun_stream_get_latency(cubeb_stream * s, uint32_t * latency)
 {
 #ifdef AUDIO_GETBUFINFO
   struct audio_info info;
 
-  if (ioctl(stream->play_fd, AUDIO_GETBUFINFO, &info) == -1) {
+  if (ioctl(s->play.fd, AUDIO_GETBUFINFO, &info) == -1) {
     return CUBEB_ERROR;
   }
 
-  *latency = BYTES_TO_FRAMES(info.play.seek + info.blocksize / 2,
-                             info.play.channels);
+  *latency = (info.play.seek + info.blocksize) / s->play.frame_size;
   return CUBEB_OK;
 #else
   cubeb_stream_params params;
 
-  params.rate = stream->p_info.play.sample_rate;
+  params.rate = stream->play.info.play.sample_rate;
 
   return sun_get_min_latency(NULL, params, latency);
 #endif
@@ -710,10 +688,10 @@ sun_get_current_device(cubeb_stream * st
   if (*device == NULL) {
     return CUBEB_ERROR;
   }
-  (*device)->input_name = stream->record_fd != -1 ?
-    strdup(stream->input_name) : NULL;
-  (*device)->output_name = stream->play_fd != -1 ?
-    strdup(stream->output_name) : NULL;
+  (*device)->input_name = stream->record.fd != -1 ?
+    strdup(stream->record.name) : NULL;
+  (*device)->output_name = stream->play.fd != -1 ?
+    strdup(stream->play.name) : NULL;
   return CUBEB_OK;
 }
 
@@ -743,8 +721,8 @@ static struct cubeb_ops const sun_ops = 
 //  .stream_reset_default_device = NULL,
   .stream_get_position = sun_stream_get_position,
   .stream_get_latency = sun_stream_get_latency,
+  .stream_get_input_latency = NULL,
   .stream_set_volume = sun_stream_set_volume,
-  .stream_set_panning = NULL,
   .stream_get_current_device = sun_get_current_device,
   .stream_device_destroy = sun_stream_device_destroy,
   .stream_register_device_changed_callback = NULL,
