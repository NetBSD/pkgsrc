$NetBSD: patch-rib_rt__tab__deletion.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- rib/rt_tab_deletion.cc.orig	2009-01-05 18:31:07.000000000 +0000
+++ rib/rt_tab_deletion.cc
@@ -43,7 +43,7 @@ DeletionTable<A>::DeletionTable(const st
       _ip_route_table(ip_route_trie)
 {
     XLOG_ASSERT(_parent != NULL);
-    set_next_table(_parent->next_table());
+    this->set_next_table(_parent->next_table());
     this->next_table()->replumb(parent, this);
     parent->set_next_table(this);
 
