$NetBSD: patch-iputils.hh,v 1.4 2017/06/15 07:15:57 fhajny Exp $

- IP_PKTINFO structure different on NetBSD than expected.

--- iputils.hh.orig	2017-06-13 09:58:51.000000000 +0000
+++ iputils.hh
@@ -38,6 +38,10 @@
 #include <boost/tuple/tuple.hpp>
 #include <boost/tuple/tuple_comparison.hpp>
 
+#if defined(IP_PKTINFO) && defined(__NetBSD__)
+#undef IP_PKTINFO
+#endif
+
 #include "namespaces.hh"
 
 #ifdef __APPLE__
