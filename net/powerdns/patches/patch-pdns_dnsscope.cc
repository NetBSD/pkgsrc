$NetBSD: patch-pdns_dnsscope.cc,v 1.4 2025/06/30 11:00:50 jperkin Exp $

Support IP_OFFMASK on illumos.

--- pdns/dnsscope.cc.orig	2025-06-20 13:58:07.364067810 +0000
+++ pdns/dnsscope.cc
@@ -45,6 +45,14 @@
 #include "dnsrecords.hh"
 #include "statnode.hh"
 
+/*
+ * illumos defines this in netinet/ip_compat.h but that introduces many more
+ * complications so just define exactly what we need.
+ */
+#if defined(__illumos__) && !defined(IP_OFFMASK)
+#define IP_OFFMASK 0x1fff
+#endif
+
 namespace po = boost::program_options;
 po::variables_map g_vm;
 
