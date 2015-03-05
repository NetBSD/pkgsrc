$NetBSD: patch-sapi_fpm_fpm_fpm__sockets.c,v 1.1 2015/03/05 11:16:28 he Exp $

Use the "right" fields in tcp_info struct for FreeBSD and NetBSD.

--- sapi/fpm/fpm/fpm_sockets.c.orig	2014-08-13 19:22:50.000000000 +0000
+++ sapi/fpm/fpm/fpm_sockets.c
@@ -406,6 +406,19 @@ int fpm_socket_get_listening_queue(int s
 		return -1;
 	}
 
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+	if (info.__tcpi_sacked == 0) {
+		return -1;
+	}
+
+	if (cur_lq) {
+		*cur_lq = info.__tcpi_unacked;
+	}
+
+	if (max_lq) {
+		*max_lq = info.__tcpi_sacked;
+	}
+#else
 	/* kernel >= 2.6.24 return non-zero here, that means operation is supported */
 	if (info.tcpi_sacked == 0) {
 		return -1;
@@ -418,6 +431,7 @@ int fpm_socket_get_listening_queue(int s
 	if (max_lq) {
 		*max_lq = info.tcpi_sacked;
 	}
+#endif
 
 	return 0;
 }
