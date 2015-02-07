$NetBSD: patch-src_iperf.h,v 1.1 2015/02/07 17:11:23 he Exp $

Add NetBSD support for tcp_info.

--- src/iperf.h.orig	2015-02-07 00:30:32.000000000 +0000
+++ src/iperf.h
@@ -55,7 +55,8 @@ struct iperf_interval_results
     int       cnt_error;
 
     int omitted;
-#if defined(linux) || defined(__FreeBSD__)
+#if (defined(linux) || defined(__FreeBSD__) || defined(__NetBSD__)) && \
+	defined(TCP_INFO)
     struct tcp_info tcpInfo;	/* getsockopt(TCP_INFO) for Linux and FreeBSD */
 #else
     /* Just placeholders, never accessed. */
