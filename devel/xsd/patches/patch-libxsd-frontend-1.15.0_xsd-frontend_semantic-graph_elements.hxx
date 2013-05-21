$NetBSD: patch-libxsd-frontend-1.15.0_xsd-frontend_semantic-graph_elements.hxx,v 1.1 2013/05/21 16:36:22 joerg Exp $

--- libxsd-frontend-1.15.0/xsd-frontend/semantic-graph/elements.hxx.orig	2013-05-14 19:59:19.000000000 +0000
+++ libxsd-frontend-1.15.0/xsd-frontend/semantic-graph/elements.hxx
@@ -577,7 +577,7 @@ namespace XSDFrontend
       Void
       remove_edge_left (Names& e)
       {
-        ListIteratorMap::Iterator i (iterator_map_.find (&e));
+        ListIteratorMap::ConstIterator i (iterator_map_.find (&e));
         assert (i != iterator_map_.end ());
 
         names_.erase (i->second);
