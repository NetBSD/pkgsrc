$NetBSD: patch-pcap-libdlpi.c,v 1.2 2013/06/15 21:01:22 adam Exp $

* Fix compile on Solaris.

--- pcap-libdlpi.c.orig	2013-02-21 03:51:49.000000000 +0000
+++ pcap-libdlpi.c
@@ -235,7 +235,7 @@ bad:
 static int
 dlpromiscon(pcap_t *p, bpf_u_int32 level)
 {
-	int err;
+	int err, retv;
 
 	retv = dlpi_promiscon(p->dlpi_hd, level);
 	if (retv != DLPI_SUCCESS) {
