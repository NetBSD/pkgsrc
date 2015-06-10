$NetBSD: patch-iputils.hh,v 1.1 2015/06/10 14:22:29 fhajny Exp $

IP_PKTINFO structure different on NetBSD than expected.

--- iputils.hh.orig	2015-04-21 13:02:57.000000000 +0000
+++ iputils.hh
@@ -38,6 +38,10 @@
 #include <boost/tuple/tuple_comparison.hpp>
 #include <boost/lexical_cast.hpp>
 
+#if defined(IP_PKTINFO) && defined(__NetBSD__)
+#undef IP_PKTINFO
+#endif
+
 #include "namespaces.hh"
 
 union ComboAddress {
