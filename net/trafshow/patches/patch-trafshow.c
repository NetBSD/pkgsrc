$NetBSD: patch-trafshow.c,v 1.1 2013/02/06 20:32:17 jperkin Exp $

* Avoid buffering on Solaris.

--- trafshow.c.orig	2006-03-14 07:58:07.000000000 +0000
+++ trafshow.c
@@ -23,6 +23,9 @@
 #ifdef	HAVE_PCAP_GET_SELECTABLE_FD
 #include <sys/select.h>
 #endif
+#ifdef __sun
+#include <sys/bufmod.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
@@ -543,6 +546,9 @@ pcap_feed2(arg)
 	PCAP_HANDLER *ph, *ph_list = (PCAP_HANDLER *)arg;
 	int npkt = -1, ndev, op;
 	fd_set readfds;
+#ifdef __sun
+	struct timeval tv = {0, 0};
+#endif
 
 	for (;;) {
 #ifdef	notdef
@@ -555,6 +561,9 @@ pcap_feed2(arg)
 			if (!ph->pcap) /* skip non-pcap devices */
 				continue;
 			op = pcap_get_selectable_fd(ph->pcap);
+#ifdef __sun
+			ioctl(op, SBIOCSTIME, &tv);
+#endif
 			if (op < 0) /* should not happen */
 				continue;
 			if (op + 1 > ndev)
