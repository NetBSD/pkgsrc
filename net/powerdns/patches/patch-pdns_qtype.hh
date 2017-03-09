$NetBSD: patch-pdns_qtype.hh,v 1.1 2017/03/09 13:32:54 fhajny Exp $

Avoid symbol pollution on SunOS.

--- pdns/qtype.hh.orig	2017-01-17 08:43:49.000000000 +0000
+++ pdns/qtype.hh
@@ -26,6 +26,10 @@
 #include <vector>
 #include "namespaces.hh"
 
+#if defined(__sun) && defined(DS)
+#undef DS
+#endif
+
 /** The QType class is meant to deal easily with the different kind of resource types, like 'A', 'NS',
  *  'CNAME' etcetera. These types have both a name and a number. This class can seamlessly move between
  *   them. Use it like this:
