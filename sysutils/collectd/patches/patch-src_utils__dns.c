$NetBSD: patch-src_utils__dns.c,v 1.1 2015/04/07 13:20:41 fhajny Exp $

Resolve conflict with pkgsrc PCAP on NetBSD 7.
--- src/utils_dns.c.orig	2015-02-26 10:43:48.496180984 +0000
+++ src/utils_dns.c
@@ -96,6 +96,9 @@
 #endif
 
 #if HAVE_PCAP_H
+# if defined(DLT_MATCHING_MAX)
+#  undef DLT_MATCHING_MAX
+# endif
 # include <pcap.h>
 #endif
 
