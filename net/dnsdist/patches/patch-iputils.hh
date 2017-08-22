$NetBSD: patch-iputils.hh,v 1.2 2017/08/22 17:00:35 fhajny Exp $

- Do not use IP_PKTINFO on NetBSD, the structure is not as expected.
- Backport fix for SunOS segfault problem, see:
  https://github.com/PowerDNS/pdns/pull/4877

--- iputils.hh.orig	2017-01-17 08:43:49.000000000 +0000
+++ iputils.hh
@@ -40,6 +40,10 @@
 
 #include "namespaces.hh"
 
+#if defined(__NetBSD__) && defined(IP_PKTINFO)
+#undef IP_PKTINFO
+#endif
+
 #ifdef __APPLE__
 #include <libkern/OSByteOrder.h>
 
