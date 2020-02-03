$NetBSD: patch-src_utils__dns.c,v 1.3 2020/02/03 09:12:32 triaxx Exp $

Resolve conflict with pkgsrc PCAP on NetBSD 7 and 8.

--- src/utils_dns.c.orig	2017-11-18 09:03:27.370749644 +0000
+++ src/utils_dns.c
@@ -91,6 +91,12 @@
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
 
