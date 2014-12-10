$NetBSD: patch-pdns_dnsscope.cc,v 1.1 2014/12/10 14:50:09 fhajny Exp $

IP_OFFMASK not defined on SunOS.
--- pdns/dnsscope.cc.orig	2014-06-26 11:22:02.000000000 +0000
+++ pdns/dnsscope.cc
@@ -16,6 +16,10 @@
 #include "namespaces.hh"
 #include <deque>
 
+#ifndef IP_OFFMASK
+# define        IP_OFFMASK      0x1fff
+#endif
+
 namespace po = boost::program_options;
 po::variables_map g_vm;
 
