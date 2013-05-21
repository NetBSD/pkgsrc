$NetBSD: patch-libcult-1.4.2_cult_containers_graph.txx,v 1.1 2013/05/21 16:36:22 joerg Exp $

--- libcult-1.4.2/cult/containers/graph.txx.orig	2013-05-14 20:04:32.000000000 +0000
+++ libcult-1.4.2/cult/containers/graph.txx
@@ -294,7 +294,7 @@ namespace Cult
     Void Graph<N, E>::
     delete_edge (Left& l, Right& r, T& edge)
     {
-      typename Edges::Iterator i (edges_.find (&edge));
+      typename Edges::ConstIterator i (edges_.find (&edge));
 
       if (i == edges_.end () ||
           nodes_.find (&l) == nodes_.end () ||
