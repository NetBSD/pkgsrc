$NetBSD: patch-src_av__mpeg4__part2.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/av_mpeg4_part2.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/av_mpeg4_part2.c
@@ -42,13 +42,13 @@ static const struct {
   int codec_id;
   mpeg4_vcodec_type_t type;
 } avf_vcodec_mapping[] = {
-  { CODEC_ID_H263,                      MPEG4_VCODEC_H263 },
-  { CODEC_ID_H263I,                     MPEG4_VCODEC_H263 },
-  { CODEC_ID_H263P,                     MPEG4_VCODEC_H263 },
-  { CODEC_ID_MPEG4,                     MPEG4_VCODEC_P2 },
-  { CODEC_ID_MSMPEG4V1,                 MPEG4_VCODEC_P2 },
-  { CODEC_ID_MSMPEG4V2,                 MPEG4_VCODEC_P2 },
-  { CODEC_ID_MSMPEG4V3,                 MPEG4_VCODEC_P2 },
+  { AV_CODEC_ID_H263,                      MPEG4_VCODEC_H263 },
+  { AV_CODEC_ID_H263I,                     MPEG4_VCODEC_H263 },
+  { AV_CODEC_ID_H263P,                     MPEG4_VCODEC_H263 },
+  { AV_CODEC_ID_MPEG4,                     MPEG4_VCODEC_P2 },
+  { AV_CODEC_ID_MSMPEG4V1,                 MPEG4_VCODEC_P2 },
+  { AV_CODEC_ID_MSMPEG4V2,                 MPEG4_VCODEC_P2 },
+  { AV_CODEC_ID_MSMPEG4V3,                 MPEG4_VCODEC_P2 },
   { -1, 0 }
 };
    
