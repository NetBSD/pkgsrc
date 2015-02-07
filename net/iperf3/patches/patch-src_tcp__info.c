$NetBSD: patch-src_tcp__info.c,v 1.1 2015/02/07 17:11:23 he Exp $

Add NetBSD support, conditional on TCP_INFO.

--- src/tcp_info.c.orig	2015-01-09 17:44:11.000000000 +0000
+++ src/tcp_info.c
@@ -62,7 +62,8 @@
 int
 has_tcpinfo(void)
 {
-#if defined(linux) || defined(__FreeBSD__)
+#if (defined(linux) || defined(__FreeBSD__) || defined(__NetBSD__)) \
+	&& defined(TCP_INFO)
     return 1;
 #else
     return 0;
@@ -82,8 +83,9 @@ has_tcpinfo_retransmits(void)
     return 1;
 #else
 #if defined(__FreeBSD__) && __FreeBSD_version >= 600000
-    /* return 1; */
-    return 0;	/* FreeBSD retransmit reporting doesn't actually work yet */
+    return 1; /* Should work now */
+#elif defined(__NetBSD__) && defined(TCP_INFO)
+    return 1;
 #else
     return 0;
 #endif
@@ -94,15 +96,17 @@ has_tcpinfo_retransmits(void)
 void
 save_tcpinfo(struct iperf_stream *sp, struct iperf_interval_results *irp)
 {
-#if defined(linux) || defined(__FreeBSD__)
+#if (defined(linux) || defined(__FreeBSD__) || defined(__NetBSD__)) \
+	&& defined(TCP_INFO)
     socklen_t tcp_info_length = sizeof(struct tcp_info);
 
     if (getsockopt(sp->socket, IPPROTO_TCP, TCP_INFO, (void *)&irp->tcpInfo, &tcp_info_length) < 0)
 	iperf_err(sp->test, "getsockopt - %s", strerror(errno));
 
     if (sp->test->debug) {
-	printf("tcpi_snd_cwnd %u tcpi_snd_mss %u\n",
-	       irp->tcpInfo.tcpi_snd_cwnd, irp->tcpInfo.tcpi_snd_mss);
+	printf("tcpi_snd_cwnd %u tcpi_snd_mss %u tcpi_snd_rexmitpack %u\n",
+	       irp->tcpInfo.tcpi_snd_cwnd, irp->tcpInfo.tcpi_snd_mss,
+		irp->tcpInfo.tcpi_snd_rexmitpack);
     }
 
 #endif
@@ -114,13 +118,13 @@ get_total_retransmits(struct iperf_inter
 {
 #if defined(linux) && defined(TCP_MD5SIG)
     return irp->tcpInfo.tcpi_total_retrans;
-#else
-#if defined(__FreeBSD__) && __FreeBSD_version >= 600000
-    return irp->tcpInfo.__tcpi_retransmits;
+#elif defined(__FreeBSD__) && __FreeBSD_version >= 600000
+    return irp->tcpInfo.tcpi_snd_rexmitpack;
+#elif defined(__NetBSD__) && defined(TCP_INFO)
+    return irp->tcpInfo.tcpi_snd_rexmitpack;
 #else
     return -1;
 #endif
-#endif
 }
 
 /*************************************************************/
@@ -132,13 +136,13 @@ get_snd_cwnd(struct iperf_interval_resul
 {
 #if defined(linux) && defined(TCP_MD5SIG)
     return irp->tcpInfo.tcpi_snd_cwnd * irp->tcpInfo.tcpi_snd_mss;
-#else
-#if defined(__FreeBSD__) && __FreeBSD_version >= 600000
+#elif defined(__FreeBSD__) && __FreeBSD_version >= 600000
+    return irp->tcpInfo.tcpi_snd_cwnd * irp->tcpInfo.tcpi_snd_mss;
+#elif defined(__NetBSD__) && defined(TCP_INFO)
     return irp->tcpInfo.tcpi_snd_cwnd * irp->tcpInfo.tcpi_snd_mss;
 #else
     return -1;
 #endif
-#endif
 }
 
 #ifdef notdef
@@ -187,4 +191,8 @@ build_tcpinfo_message(struct iperf_inter
     sprintf(message, report_tcpInfo, r->tcpInfo.tcpi_snd_cwnd,
 	    r->tcpInfo.tcpi_rcv_space, r->tcpInfo.tcpi_snd_ssthresh, r->tcpInfo.tcpi_rtt);
 #endif
+#if defined(__NetBSD__) && defined(TCP_INFO)
+    sprintf(message, report_tcpInfo, r->tcpInfo.tcpi_snd_cwnd,
+	    r->tcpInfo.tcpi_rcv_space, r->tcpInfo.tcpi_snd_ssthresh, r->tcpInfo.tcpi_rtt);
+#endif
 }
