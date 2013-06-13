$NetBSD: patch-bgp_route__table__fanout.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- bgp/route_table_fanout.hh.orig	2013-06-13 19:01:39.000000000 +0000
+++ bgp/route_table_fanout.hh
@@ -45,6 +45,9 @@ public:
     bool operator==(const NextTableMapIterator& them) const {
 	return _iter == them._iter;
     }
+    bool operator!=(const NextTableMapIterator& them) const {
+	return _iter != them._iter;
+    }
 private:
     typename multimap <uint32_t, PeerTableInfo<A>*>::iterator _iter;
 };
