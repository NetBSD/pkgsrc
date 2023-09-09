$NetBSD: patch-trafshow.c,v 1.2 2023/09/09 13:27:28 wiz Exp $

* Avoid buffering on Solaris.
* Rename pcap_init() to avoid conflict with the one in pcap.h.

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
@@ -58,7 +61,7 @@ char copyright[] = "Copyright (c) 1993-2
 static void vers();
 static void usage();
 static pcap_if_t *pcap_matchdev(pcap_if_t *dp, const char *name);
-static int pcap_init(PCAP_HANDLER **ph_list, pcap_if_t *dp);
+static int trafshow_pcap_init(PCAP_HANDLER **ph_list, pcap_if_t *dp);
 static void *pcap_feed(void *arg); /* PCAP_HANDLER *ph */
 #ifdef	HAVE_PCAP_GET_SELECTABLE_FD
 static void *pcap_feed2(void *arg); /* PCAP_HANDLER *ph */
@@ -172,7 +175,7 @@ main(argc, argv)
 	}
 
 	/* initialize list of pcap handlers */
-	if ((op = pcap_init(&ph_list, dev_list)) < 1) {
+	if ((op = trafshow_pcap_init(&ph_list, dev_list)) < 1) {
 		fprintf(stderr, "No packet capture device available (no permission?)\n");
 		exit(1);
 	}
@@ -298,7 +301,7 @@ pcap_matchdev(dp, name)
 }
 
 static int
-pcap_init(ph_list, dp)
+trafshow_pcap_init(ph_list, dp)
 	PCAP_HANDLER **ph_list;
 	pcap_if_t *dp;
 {
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
