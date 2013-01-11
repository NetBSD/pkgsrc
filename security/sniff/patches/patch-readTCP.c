$NetBSD: patch-readTCP.c,v 1.1 2013/01/11 00:05:54 joerg Exp $

--- readTCP.c.orig	2001-02-15 12:20:31.000000000 +0000
+++ readTCP.c
@@ -4,17 +4,17 @@ extern struct etherpacket ep;
 extern struct victim vittima;
 extern struct iphdr  *ip;
 
-int readTCP(u_char *u, struct pcap_pkthdr *p, u_char *packet)
+void readTCP(u_char *u, const struct pcap_pkthdr *p, const u_char *packet)
 {
    int i;
-	memcpy(&ep,(unsigned char *)packet,p->caplen);
+	memcpy(&ep,(const unsigned char *)packet,p->caplen);
 	i=p->caplen;
       if (i <= 0)
-        return -1;
+        return;
       if(i > 1) 
       {
 	if(!sniffData()) 
-	  return 0;
+	  return;
 	i=i-54;
 	if(i < 1) 
 	  return;
