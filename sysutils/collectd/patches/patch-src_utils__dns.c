$NetBSD: patch-src_utils__dns.c,v 1.2 2016/12/07 17:28:39 fhajny Exp $

Resolve conflict with pkgsrc PCAP on NetBSD 7.
--- src/utils_dns.c.orig	2016-11-30 08:52:01.328910078 +0000
+++ src/utils_dns.c
@@ -91,6 +91,9 @@
 #endif
 
 #if HAVE_PCAP_H
+# if defined(DLT_MATCHING_MAX)
+#  undef DLT_MATCHING_MAX
+# endif
 #include <pcap.h>
 #endif
 
