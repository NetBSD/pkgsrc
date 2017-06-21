$NetBSD: patch-libpcap__stuff.c,v 1.1.2.2 2017/06/21 18:20:04 bsiegert Exp $

Fix include ordering to avoid redefined bpf_* symbols.

--- libpcap_stuff.c.orig	2004-04-09 23:38:56.000000000 +0000
+++ libpcap_stuff.c
@@ -16,8 +16,8 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/ioctl.h>
-#include <pcap.h>
 #include <net/bpf.h>
+#include <pcap.h>
 
 #include "globals.h"
 
