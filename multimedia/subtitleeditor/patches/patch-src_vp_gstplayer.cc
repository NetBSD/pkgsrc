$NetBSD: patch-src_vp_gstplayer.cc,v 1.1 2020/05/14 19:30:42 joerg Exp $

--- src/vp/gstplayer.cc.orig	2020-05-13 22:35:58.988861353 +0000
+++ src/vp/gstplayer.cc
@@ -257,7 +257,7 @@ bool GstPlayer::seek(long start, long en
 	gint64 gend = end * Gst::MILLI_SECOND;
 
 	se_debug_message(SE_DEBUG_VIDEO_PLAYER,
-			"pipeline->seek(%" GST_TIME_FORMAT", %"GST_TIME_FORMAT")", 
+			"pipeline->seek(%" GST_TIME_FORMAT", %" GST_TIME_FORMAT ")",
 			GST_TIME_ARGS(gstart), GST_TIME_ARGS(gend));
 
 	bool ret = m_pipeline->seek(
