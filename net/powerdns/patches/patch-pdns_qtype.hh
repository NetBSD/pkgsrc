$NetBSD: patch-pdns_qtype.hh,v 1.2 2022/09/29 13:49:50 jperkin Exp $

Avoid symbol pollution on SunOS.

--- pdns/qtype.hh.orig	2022-07-11 13:54:25.000000000 +0000
+++ pdns/qtype.hh
@@ -22,6 +22,10 @@
 #pragma once
 #include "namespaces.hh"
 
+#if defined(__sun) && defined(DS)
+#undef DS
+#endif
+
 /** The QType class is meant to deal easily with the different kind of resource types, like 'A', 'NS',
  *  'CNAME' etcetera. These types have both a name and a number. This class can seamlessly move between
  *   them. Use it like this:
