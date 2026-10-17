$NetBSD: patch-gcc_fibonacci_heap.h,v 1.1 2026/10/17 12:45:39 js Exp $

--- gcc/fibonacci_heap.h.orig	2026-10-17 12:22:12.133505610 +0000
+++ gcc/fibonacci_heap.h
@@ -478,7 +478,7 @@ fibonacci_heap<K,V>::union_with (fibonac
   heapa->m_nodes += heapb->m_nodes;
 
   /* And set the new minimum, if it's changed.  */
-  if (heapb->min->compare (heapa->min) < 0)
+  if (heapb->m_min->compare (heapa->m_min) < 0)
     heapa->m_min = heapb->m_min;
 
   delete (heapb);
