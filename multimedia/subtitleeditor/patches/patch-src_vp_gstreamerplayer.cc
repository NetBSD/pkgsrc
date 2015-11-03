$NetBSD: patch-src_vp_gstreamerplayer.cc,v 1.1 2015/11/03 19:04:57 joerg Exp $

--- src/vp/gstreamerplayer.cc.orig	2015-11-03 12:01:20.000000000 +0000
+++ src/vp/gstreamerplayer.cc
@@ -513,7 +513,7 @@ GstElement* GStreamerPlayer::create_elem
 		return el;
 
 	// Error. Could not create element
-	GST_ELEMENT_ERROR(m_pipeline, RESOURCE, NOT_FOUND, (msg_error.c_str()), (NULL));
+	GST_ELEMENT_ERROR(m_pipeline, RESOURCE, NOT_FOUND, ("%s", msg_error.c_str()), (NULL));
 	
 	return NULL;
 }
@@ -941,7 +941,7 @@ void GStreamerPlayer::on_bus_message_seg
 
 			gst_message_parse_segment_done(msg, &fmt, &position);
 
-			se_debug_message(SE_DEBUG_VIDEO_PLAYER, "end of segment at %"GST_TIME_FORMAT, GST_TIME_ARGS(position));
+			se_debug_message(SE_DEBUG_VIDEO_PLAYER, "end of segment at %" GST_TIME_FORMAT, GST_TIME_ARGS(position));
 		}
 
 		// subtitle times
