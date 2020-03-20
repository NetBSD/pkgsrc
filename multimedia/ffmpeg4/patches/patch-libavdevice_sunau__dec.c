$NetBSD: patch-libavdevice_sunau__dec.c,v 1.1 2020/03/20 21:19:54 nia Exp $

Sun audio support.

--- libavdevice/sunau_dec.c.orig	2020-03-20 20:53:01.607986932 +0000
+++ libavdevice/sunau_dec.c
@@ -0,0 +1,138 @@
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
+#include <stdint.h>
+
+#include <unistd.h>
+#include <fcntl.h>
+#include <poll.h>
+#include <sys/audioio.h>
+#include <sys/ioctl.h>
+
+#include "libavutil/internal.h"
+#include "libavutil/opt.h"
+#include "libavutil/time.h"
+
+#include "libavcodec/avcodec.h"
+
+#include "avdevice.h"
+#include "libavformat/internal.h"
+
+#include "sunau.h"
+
+static int audio_read_header(AVFormatContext *s1)
+{
+    SunAudioData *s = s1->priv_data;
+    AVStream *st;
+
+    st = avformat_new_stream(s1, NULL);
+    if (!st) {
+        return AVERROR(ENOMEM);
+    }
+
+    if (ff_sunau_audio_open(s1, 0, s1->url) < 0) {
+        return AVERROR(EIO);
+    }
+
+    /* take real parameters */
+    st->codecpar->codec_type = AVMEDIA_TYPE_AUDIO;
+    st->codecpar->codec_id = s->codec_id;
+    st->codecpar->sample_rate = s->sample_rate;
+    st->codecpar->channels = s->channels;
+
+    avpriv_set_pts_info(st, 64, 1, 1000000);  /* 64 bits pts in us */
+
+    return 0;
+}
+
+static int audio_read_packet(AVFormatContext *s1, AVPacket *pkt)
+{
+    SunAudioData *s = s1->priv_data;
+    struct audio_info info;
+    int ret;
+    long bdelay;
+    int64_t cur_time;
+
+    if ((ret = av_new_packet(pkt, s->blocksize)) < 0)
+        return ret;
+
+    ret = read(s->fd, pkt->data, pkt->size);
+    if (ret <= 0) {
+        av_packet_unref(pkt);
+        pkt->size = 0;
+        return ret < 0 ? AVERROR(errno) : AVERROR_EOF;
+    }
+
+    /* compute pts of the start of the packet */
+    cur_time = av_gettime();
+    bdelay = ret;
+
+#ifdef AUDIO_GETBUFINFO /* BSD extension */
+    if (ioctl(s->fd, AUDIO_GETBUFINFO, &info) == 0) {
+        bdelay += info.record.seek;
+    }
+#endif
+
+    /* subtract time represented by the number of bytes in the audio fifo */
+    cur_time -= (bdelay * 1000000LL) / (s->sample_rate * s->channels * s->precision);
+
+    /* convert to wanted units */
+    pkt->pts = cur_time;
+
+    return 0;
+}
+
+static int audio_read_close(AVFormatContext *s1)
+{
+    SunAudioData *s = s1->priv_data;
+
+    ff_sunau_audio_close(s);
+    return 0;
+}
+
+static const AVOption options[] = {
+    { "buffer_samples", "", offsetof(SunAudioData, buffer_samples), AV_OPT_TYPE_INT, {.i64 = 32},    1,     INT_MAX, AV_OPT_FLAG_DECODING_PARAM },
+    { "sample_rate",    "", offsetof(SunAudioData, sample_rate),    AV_OPT_TYPE_INT, {.i64 = 48000}, 1000,  192000,  AV_OPT_FLAG_DECODING_PARAM },
+    { "channels",       "", offsetof(SunAudioData, channels),       AV_OPT_TYPE_INT, {.i64 = 2},     1,     12,      AV_OPT_FLAG_DECODING_PARAM },
+    { NULL },
+};
+
+static const AVClass sunau_demuxer_class = {
+    .class_name     = "Sun/NetBSD audio demuxer",
+    .item_name      = av_default_item_name,
+    .option         = options,
+    .version        = LIBAVUTIL_VERSION_INT,
+    .category       = AV_CLASS_CATEGORY_DEVICE_AUDIO_INPUT,
+};
+
+AVInputFormat ff_sunau_demuxer = {
+    .name           = "sunau",
+    .long_name      = NULL_IF_CONFIG_SMALL("Sun/NetBSD audio capture"),
+    .priv_data_size = sizeof(SunAudioData),
+    .read_header    = audio_read_header,
+    .read_packet    = audio_read_packet,
+    .read_close     = audio_read_close,
+    .flags          = AVFMT_NOFILE,
+    .priv_class     = &sunau_demuxer_class,
+};
