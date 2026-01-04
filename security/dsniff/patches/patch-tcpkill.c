$NetBSD: patch-tcpkill.c,v 1.1 2026/01/04 13:35:48 wiz Exp $

Avoid conflict with libpcap.

--- tcpkill.c.orig	2026-01-04 13:09:30.753713754 +0000
+++ tcpkill.c
@@ -133,7 +133,7 @@ main(int argc, char *argv[])
 	
 	filter = copy_argv(argv);
 	
-	if ((pd = pcap_init(intf, filter, 128)) == NULL)
+	if ((pd = mypcap_init(intf, filter, 128)) == NULL)
 		errx(1, "couldn't initialize sniffing");
 
 	if ((pcap_off = pcap_dloff(pd)) < 0)
