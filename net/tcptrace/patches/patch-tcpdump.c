$NetBSD: patch-tcpdump.c,v 1.2 2025/12/13 16:42:03 vins Exp $

--- tcpdump.c.orig	2004-10-07 20:07:30.000000000 +0000
+++ tcpdump.c
@@ -68,9 +68,6 @@ static char const GCC_UNUSED rcsid[] =
 
 
 
-/* external ref, in case missing in older version */
-extern int pcap_offline_read(void *, int, pcap_handler, u_char *);
-
 /* global pointer, the pcap info header */
 static pcap_t *pcap;
 
@@ -248,7 +245,7 @@ pread_tcpdump(
     int ret;
 
     while (1) {
-	if ((ret = pcap_offline_read(pcap,1,(pcap_handler)callback,0)) != 1) {
+	if ((ret = pcap_dispatch(pcap,1,(pcap_handler)callback,0)) != 1) {
 	    /* prob EOF */
 
 	    if (ret == -1) {
@@ -420,7 +417,14 @@ PcapSavePacket(
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
