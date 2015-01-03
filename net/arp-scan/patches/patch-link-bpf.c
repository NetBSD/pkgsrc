$NetBSD: patch-link-bpf.c,v 1.2 2015/01/03 14:44:36 schwarz Exp $

--- link-bpf.c.orig	2013-04-27 10:39:08.000000000 +0200
+++ link-bpf.c	2015-01-03 15:34:53.000000000 +0100
@@ -32,6 +32,9 @@
  *
  */
 
+#ifdef __DragonFly__
+#define PCAP_DONT_INCLUDE_PCAP_BPF_H
+#endif
 #include "arp-scan.h"
 
 #ifdef HAVE_NET_IF_H
