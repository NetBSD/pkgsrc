$NetBSD: patch-libs_util_llist.c,v 1.1 2013/03/28 21:25:52 joerg Exp $

--- libs/util/llist.c.orig	2013-03-28 15:10:33.000000000 +0000
+++ libs/util/llist.c
@@ -215,7 +215,7 @@ llist_size (llist_t *llist)
 }
 
 void
-llist_iterate (llist_t *list, llist_iterator_t iterate)
+llist_iterate (llist_t *list, llist_iterator_t iterate, void *data)
 {
 	llist_node_t *node;
 
@@ -223,7 +223,7 @@ llist_iterate (llist_t *list, llist_iter
 		return;
 	for (node = list->start; node; node = list->iter) {
 		list->iter = node->next;
-		if (!iterate (node->data, node))
+		if (!iterate (data, node->data, node))
 			break;
 	}
 	list->iter = 0;
