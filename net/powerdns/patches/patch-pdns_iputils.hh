$NetBSD: patch-pdns_iputils.hh,v 1.3 2018/01/02 12:18:15 fhajny Exp $

- Do not use IP_PKTINFO on NetBSD, the structure is not as expected.
- Backport fix for SunOS segfault problem, see:
  https://github.com/PowerDNS/pdns/pull/4877

--- pdns/iputils.hh.orig	2017-01-17 08:43:49.000000000 +0000
+++ pdns/iputils.hh
@@ -40,6 +40,10 @@
 
 #include "namespaces.hh"
 
+#if defined(__NetBSD__) && defined(IP_PKTINFO)
+#undef IP_PKTINFO
+#endif
+
 #ifdef __APPLE__
 #include <libkern/OSByteOrder.h>
 
