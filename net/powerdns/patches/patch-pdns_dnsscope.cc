$NetBSD: patch-pdns_dnsscope.cc,v 1.2 2015/03/27 23:37:52 rodent Exp $

IP_OFFMASK not defined on SunOS.
--- pdns/dnsscope.cc.orig	2015-03-02 13:17:10.000000000 +0000
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
 
