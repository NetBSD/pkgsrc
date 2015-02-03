$NetBSD: patch-lib_lists.h,v 1.2 2015/02/03 13:58:32 mef Exp $

date: 2012-06-29 21:37:45 +0900;  author: joerg;  state: Exp;
Fix inline usage.

--- lib/lists.h.orig	2014-04-01 18:24:10.000000000 +0900
+++ lib/lists.h	2015-02-03 22:46:25.000000000 +0900
@@ -50,13 +50,6 @@ typedef struct list {			/* In fact two o
 
 #define EMPTY_LIST(list) (!(list).head->next)
 
-void add_tail(list *, node *);
-void add_head(list *, node *);
-void rem_node(node *);
-void rem2_node(node *);
-void add_tail_list(list *, list *);
-void init_list(list *);
-void insert_node(node *, node *);
 
 #ifndef _BIRD_LISTS_C_
 #define LIST_INLINE extern inline
@@ -66,4 +59,12 @@ void insert_node(node *, node *);
 #define LIST_INLINE
 #endif
 
+void add_tail(list *, node *);
+void add_head(list *, node *);
+void rem_node(node *);
+void rem2_node(node *);
+void add_tail_list(list *, list *);
+void init_list(list *);
+void insert_node(node *, node *);
+
 #endif
