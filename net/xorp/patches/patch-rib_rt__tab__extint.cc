$NetBSD: patch-rib_rt__tab__extint.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- rib/rt_tab_extint.cc.orig	2009-01-05 18:31:07.000000000 +0000
+++ rib/rt_tab_extint.cc
@@ -749,7 +749,7 @@ ExtIntTable<A>::replumb(RouteTable<A>* o
 	// Shouldn't be possible
 	XLOG_UNREACHABLE();
     }
-    set_tablename(make_extint_name(_ext_table, _int_table));
+    this->set_tablename(make_extint_name(_ext_table, _int_table));
     debug_msg("ExtIntTable: now called \"%s\"\n", this->tablename().c_str());
 }
 
