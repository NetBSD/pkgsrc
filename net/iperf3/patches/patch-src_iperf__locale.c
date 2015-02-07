$NetBSD: patch-src_iperf__locale.c,v 1.1 2015/02/07 17:11:23 he Exp $

Add NetBSD support for tcp_info.

--- src/iperf_locale.c.orig	2015-01-09 17:44:11.000000000 +0000
+++ src/iperf_locale.c
@@ -355,7 +355,10 @@ const char report_tcpInfo[] =
 const char report_tcpInfo[] =
 "event=TCP_Info CWND=%u RCV_WIND=%u SND_SSTHRESH=%u RTT=%u\n";
 #endif
-
+#if defined(__NetBSD__)
+const char report_tcpInfo[] =
+"event=TCP_Info CWND=%u RCV_WIND=%u SND_SSTHRESH=%u RTT=%u\n";
+#endif
 
 #ifdef HAVE_QUAD_SUPPORT
 #ifdef HAVE_PRINTF_QD
