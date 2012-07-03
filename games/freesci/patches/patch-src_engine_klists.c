$NetBSD: patch-src_engine_klists.c,v 1.1 2012/07/03 18:41:58 joerg Exp $

--- src/engine/klists.c.orig	2012-07-03 15:42:02.000000000 +0000
+++ src/engine/klists.c
@@ -98,7 +98,7 @@ kNewList(state_t *s, int funct_nr, int a
 }
 
 
-inline heap_ptr
+static inline heap_ptr
 _k_new_node(state_t *s, int value, int key)
 {
 	heap_ptr nodebase = heap_allocate(s->_heap, 8);
@@ -127,7 +127,7 @@ kNewNode(state_t *s, int funct_nr, int a
 }
 
 
-inline void
+static inline void
 _k_add_to_end(state_t *s, heap_ptr listbase, heap_ptr nodebase)
 {
 	heap_ptr old_lastnode = GET_HEAP(listbase + LIST_LAST_NODE);
