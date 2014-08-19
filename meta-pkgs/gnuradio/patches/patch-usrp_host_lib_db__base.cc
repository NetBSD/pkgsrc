$NetBSD: patch-usrp_host_lib_db__base.cc,v 1.1 2014/08/19 13:38:49 joerg Exp $

--- usrp/host/lib/db_base.cc.orig	2014-08-18 14:44:41.000000000 +0000
+++ usrp/host/lib/db_base.cc
@@ -25,6 +25,7 @@
 
 #include <usrp/db_base.h>
 #include <db_base_impl.h>
+#include <ostream>
 
 #if 0
 tune_result::tune_result(double baseband, double dxc, double residual, bool inv)
