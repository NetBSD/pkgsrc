$NetBSD: patch-rib_rt__tab__pol__conn.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- rib/rt_tab_pol_conn.cc.orig	2009-01-05 18:31:07.000000000 +0000
+++ rib/rt_tab_pol_conn.cc
@@ -45,7 +45,7 @@ PolicyConnectedTable<A>::PolicyConnected
     : RouteTable<A>(table_name), _parent(parent), _policy_filters(pfs)
 {
     if (_parent->next_table()) {
-	set_next_table(_parent->next_table());
+	this->set_next_table(_parent->next_table());
 
 	this->next_table()->replumb(_parent, this);
     }
