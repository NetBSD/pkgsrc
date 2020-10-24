$NetBSD: patch-src_utils_dns_dns.c,v 1.1 2020/10/24 22:39:45 wiz Exp $

Resolve conflict with pkgsrc PCAP on NetBSD 7 and 8.

--- src/utils/dns/dns.c.orig	2020-03-08 16:57:09.000000000 +0100
+++ src/utils/dns/dns.c	2020-07-20 12:55:29.000000000 +0200
@@ -85,6 +85,12 @@
 #endif
 
 #if HAVE_PCAP_H
+# if defined(DLT_MATCHING_MAX)
+#  undef DLT_MATCHING_MAX
+# endif
+# if defined(DLT_IEEE802_15_4)
+#  undef DLT_IEEE802_15_4
+# endif
 #include <pcap.h>
 #endif
 
