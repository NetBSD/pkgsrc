$NetBSD: patch-iputils.hh,v 1.2 2017/03/09 13:43:49 fhajny Exp $

IP_PKTINFO structure different on NetBSD than expected.

--- iputils.hh.orig	2017-01-13 08:55:55.000000000 +0000
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
