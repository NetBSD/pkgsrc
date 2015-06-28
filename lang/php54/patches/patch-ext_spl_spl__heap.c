$NetBSD: patch-ext_spl_spl__heap.c,v 1.1 2015/06/28 15:34:16 taca Exp $

Fix Bug #69737 	Segfault when SplMinHeap::compare produces fatal error.

--- ext/spl/spl_heap.c.orig	2015-06-10 05:11:55.000000000 +0000
+++ ext/spl/spl_heap.c
@@ -249,9 +249,10 @@ static void spl_ptr_heap_insert(spl_ptr_
 	heap->ctor(elem TSRMLS_CC);
 
 	/* sifting up */
-	for(i = heap->count++; i > 0 && heap->cmp(heap->elements[(i-1)/2], elem, cmp_userdata TSRMLS_CC) < 0; i = (i-1)/2) {
+	for(i = heap->count; i > 0 && heap->cmp(heap->elements[(i-1)/2], elem, cmp_userdata TSRMLS_CC) < 0; i = (i-1)/2) {
 		heap->elements[i] = heap->elements[(i-1)/2];
 	}
+	heap->count++;
 
 	if (EG(exception)) {
 		/* exception thrown during comparison */
