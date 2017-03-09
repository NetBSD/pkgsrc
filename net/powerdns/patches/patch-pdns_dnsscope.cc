$NetBSD: patch-pdns_dnsscope.cc,v 1.3 2017/03/09 13:32:54 fhajny Exp $

IP_OFFMASK not defined on SunOS.

--- pdns/dnsscope.cc.orig	2017-01-17 08:43:49.000000000 +0000
+++ pdns/dnsscope.cc
@@ -43,6 +43,10 @@
 #include "dnsrecords.hh"
 #include "statnode.hh"
 
+#ifndef IP_OFFMASK
+# define        IP_OFFMASK      0x1fff
+#endif
+
 namespace po = boost::program_options;
 po::variables_map g_vm;
 
