$NetBSD: patch-plugins_video_common_dyna.cxx,v 1.1 2011/12/04 22:06:04 marino Exp $

--- plugins/video/common/dyna.cxx.orig	2009-09-22 00:57:52.000000000 +0000
+++ plugins/video/common/dyna.cxx
@@ -236,36 +236,36 @@ bool FFMPEGLibrary::Load(int ver)
   }
 
   if (_codec==CODEC_ID_H264) {
-    if (!libAvcodec.GetFunction("h264_decoder", (DynaLink::Function &)Favcodec_h264_decoder)) {
+    if (!libAvcodec.GetFunction("ff_h264_decoder", (DynaLink::Function &)Favcodec_h264_decoder)) {
       TRACE (1, _codecString << "\tDYNA\tFailed to load h264_decoder");
       return false;
     }
   }
   
   if (_codec==CODEC_ID_H263P) {
-    if (!libAvcodec.GetFunction("h263_encoder", (DynaLink::Function &)Favcodec_h263_encoder)) {
+    if (!libAvcodec.GetFunction("ff_h263_encoder", (DynaLink::Function &)Favcodec_h263_encoder)) {
       TRACE (1, _codecString << "\tDYNA\tFailed to load h263_encoder" );
       return false;
     }
   
-    if (!libAvcodec.GetFunction("h263p_encoder", (DynaLink::Function &)Favcodec_h263p_encoder)) {
+    if (!libAvcodec.GetFunction("ff_h263p_encoder", (DynaLink::Function &)Favcodec_h263p_encoder)) {
       TRACE (1, _codecString << "\tDYNA\tFailed to load h263p_encoder" );
       return false;
     }
 
-    if (!libAvcodec.GetFunction("h263_decoder", (DynaLink::Function &)Favcodec_h263_decoder)) {
+    if (!libAvcodec.GetFunction("ff_h263_decoder", (DynaLink::Function &)Favcodec_h263_decoder)) {
       TRACE (1, _codecString << "\tDYNA\tFailed to load h263_decoder" );
       return false;
     }
   }
 
   if (_codec==CODEC_ID_MPEG4) {
-    if (!libAvcodec.GetFunction("mpeg4_encoder", (DynaLink::Function &)mpeg4_encoder)) {
+    if (!libAvcodec.GetFunction("ff_mpeg4_encoder", (DynaLink::Function &)mpeg4_encoder)) {
       TRACE (1, _codecString << "\tDYNA\tFailed to load mpeg4_encoder");
       return false;
     }
 
-    if (!libAvcodec.GetFunction("mpeg4_decoder", (DynaLink::Function &)mpeg4_decoder)) {
+    if (!libAvcodec.GetFunction("ff_mpeg4_decoder", (DynaLink::Function &)mpeg4_decoder)) {
       TRACE (1, _codecString << "\tDYNA\tFailed to load mpeg4_decoder");
       return false;
     }
