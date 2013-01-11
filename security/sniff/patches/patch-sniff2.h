$NetBSD: patch-sniff2.h,v 1.1 2013/01/11 00:05:54 joerg Exp $

--- sniff2.h.orig	2001-02-15 12:18:33.000000000 +0000
+++ sniff2.h
@@ -1,4 +1,6 @@
-
+#include <ctype.h>
+#include <stdlib.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/time.h>
@@ -48,7 +50,7 @@ struct victim
 
 
 void ifOpen(void);
-int readTCP(u_char *u, struct pcap_pkthdr *p, u_char *packet);
+void readTCP(u_char *u, const struct pcap_pkthdr *p, const u_char *packet);
 int sniffData(void);
 int printHeader(void);
 int printData(int, char *);
