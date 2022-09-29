$NetBSD: patch-qtype.hh,v 1.2 2022/09/29 12:47:31 jperkin Exp $

Avoid symbol pollution on SunOS.

--- qtype.hh.orig	2022-09-19 10:31:34.000000000 +0000
+++ qtype.hh
@@ -26,6 +26,10 @@
 
 #include "namespaces.hh"
 
+#if defined(__sun) && defined(DS)
+#undef DS
+#endif
+
 /** The QType class is meant to deal easily with the different kind of resource types, like 'A', 'NS',
  *  'CNAME' etcetera. These types have both a name and a number. This class can seamlessly move between
  *   them. Use it like this:
