$NetBSD: patch-tcpnice.c,v 1.1 2026/01/04 13:35:48 wiz Exp $

Avoid conflict with libpcap.

--- tcpnice.c.orig	2026-01-04 13:09:45.045453250 +0000
+++ tcpnice.c
@@ -159,7 +159,7 @@ main(int argc, char *argv[])
 
 	filter = copy_argv(argv);
 	
-	if ((pd = pcap_init(intf, filter, 128)) == NULL)
+	if ((pd = mypcap_init(intf, filter, 128)) == NULL)
 		errx(1, "couldn't initialize sniffing");
 
 	if ((pcap_off = pcap_dloff(pd)) < 0)
