$NetBSD: patch-cmd_ossplay_ossplay.h,v 1.1 2021/05/09 09:06:59 nia Exp $

Missing features in libossaudio...

--- cmd/ossplay/ossplay.h.orig	2014-02-14 22:59:55.000000000 +0000
+++ cmd/ossplay/ossplay.h
@@ -105,6 +105,23 @@ enum {
  AFMT_DOUBLE64_BE,
  AFMT_DOUBLE64_LE
 };
+
+#ifndef AFMT_S24_PACKED
+#define AFMT_S24_PACKED	(-300)
+#endif
+
+#ifndef AFMT_FLOAT
+#define AFMT_FLOAT	(-301)
+#endif
+
+#ifndef AFMT_VORBIS
+#define AFMT_VORBIS	(-302)
+#endif
+
+#ifndef AFMT_SPDIF_RAW
+#define AFMT_SPDIF_RAW	(-303)
+#endif
+
 #define AFMT_S24_PACKED_LE	AFMT_S24_PACKED
 
 typedef struct {
