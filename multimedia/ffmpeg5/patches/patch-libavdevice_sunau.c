$NetBSD: patch-libavdevice_sunau.c,v 1.1 2022/01/31 23:16:41 ryoon Exp $

Sun audio support.

--- libavdevice/sunau.c.orig	2020-03-20 20:53:01.554485424 +0000
+++ libavdevice/sunau.c
@@ -0,0 +1,102 @@
+/*
+ * Solaris/NetBSD play and grab interface
+ * Copyright (c) 2020 Yorick Hardy
+ * Copyright (c) 2020 Nia Alarie <nia@NetBSD.org>
+ *
+ * This file is part of FFmpeg.
+ *
+ * FFmpeg is free software; you can redistribute it and/or
+ * modify it under the terms of the GNU Lesser General Public
+ * License as published by the Free Software Foundation; either
+ * version 2.1 of the License, or (at your option) any later version.
+ *
+ * FFmpeg is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * Lesser General Public License for more details.
+ *
+ * You should have received a copy of the GNU Lesser General Public
+ * License along with FFmpeg; if not, write to the Free Software
+ * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
+ */
+
+#include "config.h"
+
+#include <string.h>
+
+#include <unistd.h>
+#include <fcntl.h>
+#include <sys/audioio.h>
+#include <sys/ioctl.h>
+
+#include "libavutil/log.h"
+
+#include "libavcodec/avcodec.h"
+#include "avdevice.h"
+
+#include "sunau.h"
+
+int ff_sunau_audio_open(AVFormatContext *s1, int is_output,
+                          const char *audio_device)
+{
+    SunAudioData *s = s1->priv_data;
+    struct audio_info info;
+    struct audio_prinfo *prinfo;
+    int audio_fd, err;
+
+    audio_fd = avpriv_open(audio_device, is_output ? O_WRONLY : O_RDONLY);
+    if (audio_fd < 0) {
+        av_log(s1, AV_LOG_ERROR, "%s: %s\n", audio_device, av_err2str(AVERROR(errno)));
+        return AVERROR(EIO);
+    }
+
+    AUDIO_INITINFO(&info);
+
+#ifdef AUMODE_PLAY /* BSD extension */
+    info.mode = is_output ? AUMODE_PLAY : AUMODE_RECORD;
+#endif
+
+    prinfo = is_output ? &info.play : &info.record;
+
+    prinfo->encoding = AUDIO_ENCODING_LINEAR;
+    prinfo->precision = 16;
+    prinfo->sample_rate = s->sample_rate;
+    prinfo->channels = s->channels;
+
+    if ((err = ioctl(audio_fd, AUDIO_SETINFO, &info)) < 0) {
+        av_log(s1, AV_LOG_ERROR, "AUDIO_SETINFO: %s\n", av_err2str(AVERROR(errno)));
+        goto fail;
+    }
+
+    if ((err = ioctl(audio_fd, AUDIO_GETINFO, &info)) < 0) {
+        av_log(s1, AV_LOG_ERROR, "AUDIO_GETINFO: %s\n", av_err2str(AVERROR(errno)));
+        goto fail;
+    }
+
+    s->fd = audio_fd;
+#if HAVE_BIGENDIAN
+    s->codec_id = AV_CODEC_ID_PCM_S16BE;
+#else
+    s->codec_id = AV_CODEC_ID_PCM_S16LE;
+#endif
+    s->precision = prinfo->precision;
+    s->sample_rate = prinfo->sample_rate;
+    s->channels = prinfo->channels;
+    s->blocksize = s->buffer_samples * prinfo->precision * prinfo->channels;
+
+    if ((s->buffer = malloc(s->blocksize)) == NULL) {
+        av_log(s1, AV_LOG_ERROR, "malloc: %s\n", av_err2str(AVERROR(errno)));
+        goto fail;
+    }
+
+    return 0;
+ fail:
+    close(audio_fd);
+    return AVERROR(EIO);
+}
+
+int ff_sunau_audio_close(SunAudioData *s)
+{
+    close(s->fd);
+    return 0;
+}
