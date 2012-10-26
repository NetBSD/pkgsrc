$NetBSD: patch-rtsp_rtsp__get__rtp__queue.c,v 1.1 2012/10/26 20:41:45 joerg Exp $

--- rtsp/rtsp_get_rtp_queue.c.orig	2012-10-26 16:07:42.000000000 +0000
+++ rtsp/rtsp_get_rtp_queue.c
@@ -28,7 +28,7 @@
 
 #include <nemesi/rtsp.h>
 
-inline rtp_session *rtsp_get_rtp_queue(rtsp_ctrl * rtsp_ctl)
+rtp_session *rtsp_get_rtp_queue(rtsp_ctrl * rtsp_ctl)
 {
 	return ((rtsp_thread *) rtsp_ctl)->rtp_th->rtp_sess_head;
 }
