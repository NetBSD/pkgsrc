$NetBSD: patch-libavdevice_sunau__enc.c,v 1.1 2020/03/20 21:19:54 nia Exp $

Sun audio support.

--- libavdevice/sunau_enc.c.orig	2020-03-20 20:53:01.636938971 +0000
+++ libavdevice/sunau_enc.c
@@ -0,0 +1,114 @@
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
+#include <unistd.h>
+#include <fcntl.h>
+#include <sys/audioio.h>
+#include <sys/ioctl.h>
+
+#include "libavutil/internal.h"
+
+#include "libavcodec/avcodec.h"
+
+#include "avdevice.h"
+#include "libavformat/internal.h"
+
+#include "sunau.h"
+
+static int audio_write_header(AVFormatContext *s1)
+{
+    SunAudioData *s = s1->priv_data;
+    AVStream *st;
+
+    st = s1->streams[0];
+    s->sample_rate = st->codecpar->sample_rate;
+    s->channels = st->codecpar->channels;
+    s->codec_id = st->codecpar->codec_id;
+    return ff_sunau_audio_open(s1, 1, s1->url) < 0 ? AVERROR(EIO) : 0;
+}
+
+static int audio_write_packet(AVFormatContext *s1, AVPacket *pkt)
+{
+    SunAudioData *s = s1->priv_data;
+    unsigned int len, size = pkt->size;
+    uint8_t *buf = pkt->data;
+    int ret;
+
+    while (size > 0) {
+        len = FFMIN(s->blocksize - s->buffer_ptr, size);
+        memcpy(s->buffer + s->buffer_ptr, buf, len);
+        s->buffer_ptr += len;
+        if (s->buffer_ptr >= s->blocksize) {
+            for (;;) {
+                ret = write(s->fd, s->buffer, s->blocksize);
+                if (ret > 0)
+                    break;
+                if (ret < 0 && (errno != EAGAIN && errno != EINTR))
+                    return AVERROR(EIO);
+            }
+            s->buffer_ptr = 0;
+        }
+        buf += len;
+        size -= len;
+    }
+    return 0;
+}
+
+static int audio_write_trailer(AVFormatContext *s1)
+{
+    SunAudioData *s = s1->priv_data;
+
+    ff_sunau_audio_close(s);
+    return 0;
+}
+
+static const AVOption options[] = {
+    { "buffer_samples", "", offsetof(SunAudioData, buffer_samples), AV_OPT_TYPE_INT, {.i64 = 32}, 1, 192000, AV_OPT_FLAG_DECODING_PARAM },
+    { NULL },
+};
+
+static const AVClass sunau_muxer_class = {
+    .class_name     = "Sun/NetBSD audio muxer",
+    .item_name      = av_default_item_name,
+    .option         = options,
+    .version        = LIBAVUTIL_VERSION_INT,
+    .category       = AV_CLASS_CATEGORY_DEVICE_AUDIO_OUTPUT,
+};
+
+AVOutputFormat ff_sunau_muxer = {
+    .name           = "sunau",
+    .long_name      = NULL_IF_CONFIG_SMALL("Sun/NetBSD audio playback"),
+    .priv_data_size = sizeof(SunAudioData),
+    /* XXX: we may need to support higher precisions in the future, but
+       right now this is what the kernel can handle natively */
+    /* XXX: find better solution with "preinit" method, needed also in
+       other formats */
+    .audio_codec    = AV_NE(AV_CODEC_ID_PCM_S16BE, AV_CODEC_ID_PCM_S16LE),
+    .video_codec    = AV_CODEC_ID_NONE,
+    .write_header   = audio_write_header,
+    .write_packet   = audio_write_packet,
+    .write_trailer  = audio_write_trailer,
+    .flags          = AVFMT_NOFILE,
+    .priv_class     = &sunau_muxer_class,
+};
