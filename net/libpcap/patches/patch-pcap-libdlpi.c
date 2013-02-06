$NetBSD: patch-pcap-libdlpi.c,v 1.1 2013/02/06 18:07:04 jperkin Exp $

* Fix compile on Solaris.

--- pcap-libdlpi.c.orig	2012-03-29 12:57:32.000000000 +0000
+++ pcap-libdlpi.c
@@ -235,9 +235,9 @@ bad:
 static int
 dlpromiscon(pcap_t *p, bpf_u_int32 level)
 {
-	int err;
+	int err, retv;
 
-	retv = dlpi_promiscon(p->hd, level);
+	retv = dlpi_promiscon(p->dlpi_hd, level);
 	if (retv != DLPI_SUCCESS) {
 		if (retv == DL_SYSERR &&
 		    (errno == EPERM || errno == EACCES))
