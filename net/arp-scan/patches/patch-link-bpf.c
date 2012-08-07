$NetBSD: patch-link-bpf.c,v 1.1 2012/08/07 18:21:30 marino Exp $

DragonFly's pcap.h includes pcap/bpf.h which clashes with net/bpf.h
pcap.h is included by arp-scan.h

--- link-bpf.c.orig	2011-01-09 10:37:09.000000000 +0000
+++ link-bpf.c
@@ -32,6 +32,9 @@
  *
  */
 
+#ifdef __DragonFly__
+#define PCAP_DONT_INCLUDE_PCAP_BPF_H
+#endif
 #include "arp-scan.h"
 
 #ifdef HAVE_FCNTL_H
