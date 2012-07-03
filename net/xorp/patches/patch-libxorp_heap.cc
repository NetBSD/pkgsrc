$NetBSD: patch-libxorp_heap.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- libxorp/heap.cc.orig	2009-01-05 18:30:57.000000000 +0000
+++ libxorp/heap.cc
@@ -257,10 +257,8 @@ Heap::heapify()
         push(i);
 }
 
-Heap::Heap(bool intrude)
+Heap::Heap(bool intrude) : _size(0), _elements(0), _intrude(intrude), _p(0)
 {
-    memset(this, 0, sizeof(*this));
-    _intrude = intrude;
     debug_msg("++ constructor for 0x%p\n", this);
 }
 
