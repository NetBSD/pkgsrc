$NetBSD: patch-mozilla_media_webrtc_signaling_src_sipcc_cpr_darwin_cpr__darwin__ipc.c,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/media/webrtc/signaling/src/sipcc/cpr/darwin/cpr_darwin_ipc.c.orig	2013-10-23 22:09:12.000000000 +0000
+++ mozilla/media/webrtc/signaling/src/sipcc/cpr/darwin/cpr_darwin_ipc.c
@@ -321,11 +321,15 @@ cprGetMessage (cprMsgQueue_t msgQueue, b
     cpr_msgq_node_t *node;
 	struct timespec timeout;
 	struct timeval tv;
+#ifndef __APPLE__
+	struct timezone tz;
+#else
 	// On the iPhone, there is a DarwinAlias problem with "timezone"
 	struct _timezone {
 		int     tz_minuteswest; /* of Greenwich */
 		int     tz_dsttime;     /* type of dst correction to apply */
 	} tz;
+#endif
 
     /* Initialize ppUserData */
     if (ppUserData) {
