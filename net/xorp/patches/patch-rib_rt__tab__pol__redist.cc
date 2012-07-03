$NetBSD: patch-rib_rt__tab__pol__redist.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- rib/rt_tab_pol_redist.cc.orig	2009-01-05 18:31:07.000000000 +0000
+++ rib/rt_tab_pol_redist.cc
@@ -50,7 +50,7 @@ PolicyRedistTable<A>::PolicyRedistTable(
       _multicast(multicast)
 {
     if (_parent->next_table() != NULL) {
-        set_next_table(_parent->next_table());
+        this->set_next_table(_parent->next_table());
 
         this->next_table()->replumb(_parent, this);
     }
