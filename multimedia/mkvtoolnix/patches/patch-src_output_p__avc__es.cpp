$NetBSD: patch-src_output_p__avc__es.cpp,v 1.1 2018/12/13 19:52:14 adam Exp $

Fix for boost-1.69.0.

--- src/output/p_avc_es.cpp.orig	2018-12-13 12:02:54.000000000 +0000
+++ src/output/p_avc_es.cpp
@@ -46,7 +46,7 @@ avc_es_video_packetizer_c(generic_reader
   set_codec_id(MKV_V_MPEG4_AVC);
 
   m_parser.set_keep_ar_info(false);
-  m_parser.set_fix_bitstream_frame_rate(m_ti.m_fix_bitstream_frame_rate);
+  m_parser.set_fix_bitstream_frame_rate(m_ti.m_fix_bitstream_frame_rate ? true : false);
 
   // If no external timestamp file has been specified then mkvmerge
   // might have created a factory due to the --default-duration
