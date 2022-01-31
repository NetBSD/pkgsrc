$NetBSD: patch-libavdevice_sunau.h,v 1.1 2022/01/31 23:16:41 ryoon Exp $

Sun audio support.

--- libavdevice/sunau.h.orig	2020-03-20 20:53:01.579839153 +0000
+++ libavdevice/sunau.h
@@ -0,0 +1,48 @@
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
+#ifndef AVDEVICE_SUNAU_H
+#define AVDEVICE_SUNAU_H
+
+#include "libavcodec/avcodec.h"
+
+#include "libavformat/avformat.h"
+
+typedef struct SunAudioData {
+    AVClass *class;
+    int fd;
+    int buffer_samples;
+    unsigned int sample_rate;
+    unsigned int channels;
+    unsigned int precision;
+    size_t blocksize;
+    enum AVCodecID codec_id;
+    uint8_t *buffer;
+    size_t buffer_ptr;
+} SunAudioData;
+
+int ff_sunau_audio_open(AVFormatContext *s1, int is_output,
+                        const char *audio_device);
+
+int ff_sunau_audio_close(SunAudioData *s);
+
+#endif /* AVDEVICE_SUNAU_H */
