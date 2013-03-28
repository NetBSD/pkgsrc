$NetBSD: patch-include_QF_llist.h,v 1.1 2013/03/28 21:25:52 joerg Exp $

--- include/QF/llist.h.orig	2013-03-28 15:10:12.000000000 +0000
+++ include/QF/llist.h
@@ -44,7 +44,7 @@ typedef struct llist_s {
 	void *userdata;
 } llist_t;
 
-typedef qboolean (*llist_iterator_t)(void *element, llist_node_t *node);
+typedef qboolean (*llist_iterator_t)(void *data, void *element, llist_node_t *node);
 
 #define LLIST_ICAST(x) (llist_iterator_t)(x)
 #define LLIST_DATA(node, type) ((type *)((node)->data))
@@ -59,7 +59,7 @@ llist_node_t *llist_insertafter (llist_n
 llist_node_t *llist_insertbefore (llist_node_t *ref, void *element);
 void *llist_remove (llist_node_t *ref);
 unsigned int llist_size (llist_t *llist);
-void llist_iterate (llist_t *list, llist_iterator_t iterate);
+void llist_iterate (llist_t *list, llist_iterator_t iterate, void *data);
 void *llist_find (llist_t *list, void *comparison);
 llist_node_t *llist_findnode (llist_t *list, void *comparison);
 void *llist_createarray (llist_t *list, size_t esize);
