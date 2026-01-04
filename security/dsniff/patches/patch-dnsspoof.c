$NetBSD: patch-dnsspoof.c,v 1.1 2026/01/04 13:35:48 wiz Exp $

Avoid conflict with libpcap.

--- dnsspoof.c.orig	2026-01-04 13:09:00.453429317 +0000
+++ dnsspoof.c
@@ -304,7 +304,7 @@ main(int argc, char *argv[])
 	else snprintf(buf, sizeof(buf), "udp dst port 53 and not src %s",
 		      libnet_host_lookup(lnet_ip, 0));
 	
-	if ((pcap_pd = pcap_init(dev, buf, 128)) == NULL)
+	if ((pcap_pd = mypcap_init(dev, buf, 128)) == NULL)
 		errx(1, "couldn't initialize sniffing");
 
 	if ((pcap_off = pcap_dloff(pcap_pd)) < 0)
