$NetBSD: patch-dns.h,v 1.1 2018/10/27 12:04:33 tron Exp $

Fix build with BIND 9.12.3 and newer

--- dns.h.orig	2015-12-16 00:46:50.000000000 +0000
+++ dns.h	2018-10-27 12:58:23.298408393 +0100
@@ -33,6 +33,8 @@
  */
 
 #include <isc/types.h>
+#include <isc/boolean.h>
+#include <isc/int.h>
 
 #ifndef PERF_DNS_H
 #define PERF_DNS_H 1
