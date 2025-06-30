$NetBSD: patch-pdns_qtype.hh,v 1.3 2025/06/30 11:00:50 jperkin Exp $

Avoid symbol pollution on SunOS.

--- pdns/qtype.hh.orig	2025-06-20 14:11:31.859917271 +0000
+++ pdns/qtype.hh
@@ -26,6 +26,10 @@
 
 #include "namespaces.hh"
 
+#if defined(__sun) && defined(DS)
+#undef DS
+#endif
+
 /** The QType class is meant to deal easily with the different kind of resource types, like 'A', 'NS',
  *  'CNAME' etcetera. These types have both a name and a number. This class can seamlessly move between
  *   them. Use it like this:
