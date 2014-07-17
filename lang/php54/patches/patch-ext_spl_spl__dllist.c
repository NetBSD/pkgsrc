$NetBSD: patch-ext_spl_spl__dllist.c,v 1.1.2.2 2014/07/17 18:46:37 tron Exp $

Fix for CVE-2014-4670.

--- ext/spl/spl_dllist.c.orig	2014-06-25 22:53:57.000000000 +0000
+++ ext/spl/spl_dllist.c
@@ -916,6 +916,11 @@ SPL_METHOD(SplDoublyLinkedList, offsetUn
 			llist->dtor(element TSRMLS_CC);
 		}
 
+		if (intern->traverse_pointer == element) {
+			SPL_LLIST_DELREF(element);
+			intern->traverse_pointer = NULL;
+		}
+
 		zval_ptr_dtor((zval **)&element->data);
 		element->data = NULL;
 
