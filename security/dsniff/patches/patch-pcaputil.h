$NetBSD: patch-pcaputil.h,v 1.1 2026/01/04 13:35:48 wiz Exp $

Avoid conflict with libpcap.

--- pcaputil.h.orig	2026-01-04 13:08:21.258572195 +0000
+++ pcaputil.h
@@ -11,7 +11,7 @@
 #ifndef PCAPUTIL_H
 #define PCAPUTIL_H
 
-pcap_t *pcap_init(char *intf, char *filter, int snaplen);
+pcap_t *mypcap_init(char *intf, char *filter, int snaplen);
 
 int	pcap_dloff(pcap_t *pd);
 
