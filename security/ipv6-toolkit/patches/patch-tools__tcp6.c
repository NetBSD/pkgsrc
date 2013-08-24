$NetBSD: patch-tools__tcp6.c,v 1.1 2013/08/24 16:12:24 agc Exp $

Avoid uninitialised warnings

--- tools/tcp6.c	2013/08/22 16:58:54	1.1
+++ tools/tcp6.c	2013/08/22 17:00:42
@@ -286,6 +286,9 @@
 	hoplimit=255;
 	init_iface_data(&idata);
 
+	pktinterval = 0;
+	memset(&lastprobe, 0x0, sizeof(lastprobe));
+
 	while((r=getopt_long(argc, argv, shortopts, longopts, NULL)) != -1) {
 		option= r;
 
