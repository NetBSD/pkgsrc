$NetBSD: patch-src_modules_bluetooth_module-bluetooth-device.c,v 1.1 2011/10/12 20:12:35 hans Exp $

--- src/modules/bluetooth/module-bluetooth-device.c.orig	Wed Nov 11 05:11:07 2009
+++ src/modules/bluetooth/module-bluetooth-device.c	Tue Oct 11 19:23:10 2011
@@ -781,9 +781,11 @@
     pa_make_fd_nonblock(u->stream_fd);
     pa_make_socket_low_delay(u->stream_fd);
 
+#ifdef SO_TIMESTAMP
     one = 1;
     if (setsockopt(u->stream_fd, SOL_SOCKET, SO_TIMESTAMP, &one, sizeof(one)) < 0)
         pa_log_warn("Failed to enable SO_TIMESTAMP: %s", pa_cstrerror(errno));
+#endif
 
     pa_log_debug("Stream properly set up, we're ready to roll!");
 
@@ -1104,6 +1106,7 @@
         memchunk.length = (size_t) l;
         u->read_index += (uint64_t) l;
 
+#ifdef SO_TIMESTAMP
         for (cm = CMSG_FIRSTHDR(&m); cm; cm = CMSG_NXTHDR(&m, cm))
             if (cm->cmsg_level == SOL_SOCKET && cm->cmsg_type == SO_TIMESTAMP) {
                 struct timeval *tv = (struct timeval*) CMSG_DATA(cm);
@@ -1117,6 +1120,9 @@
             pa_log_warn("Couldn't find SO_TIMESTAMP data in auxiliary recvmsg() data!");
             tstamp = pa_rtclock_now();
         }
+#else
+	tstamp = pa_rtclock_now();
+#endif
 
         pa_smoother_put(u->read_smoother, tstamp, pa_bytes_to_usec(u->read_index, &u->sample_spec));
         pa_smoother_resume(u->read_smoother, tstamp, TRUE);
