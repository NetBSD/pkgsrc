$NetBSD: patch-tcpdump.c,v 1.1 2015/01/20 00:04:58 enami Exp $

--- tcpdump.c.orig	2004-10-07 20:07:30.000000000 +0000
+++ tcpdump.c
@@ -420,7 +420,14 @@ PcapSavePacket(
     void *plast)
 {
     static MFILE *f_savefile = NULL;
-    struct pcap_pkthdr phdr;
+    struct {
+	struct {
+	    tt_int32 tv_sec;
+	    tt_int32 tv_usec;
+	} ts;
+	tt_uint32 caplen;
+	tt_uint32 len;
+    } phdr;
     int wlen;
 
     if (f_savefile == NULL) {
