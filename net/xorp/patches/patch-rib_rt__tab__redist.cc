$NetBSD: patch-rib_rt__tab__redist.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- rib/rt_tab_redist.cc.orig	2009-01-05 18:31:07.000000000 +0000
+++ rib/rt_tab_redist.cc
@@ -340,7 +340,7 @@ RedistTable<A>::RedistTable(const string
     : RouteTable<A>(tablename), _parent(parent)
 {
     if (_parent->next_table()) {
-	set_next_table(_parent->next_table());
+	this->set_next_table(_parent->next_table());
 	this->next_table()->replumb(_parent, this);
     }
     _parent->set_next_table(this);
