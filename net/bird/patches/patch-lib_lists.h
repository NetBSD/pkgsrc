$NetBSD: patch-lib_lists.h,v 1.3 2015/02/04 20:50:50 joerg Exp $

date: 2012-06-29 21:37:45 +0900;  author: joerg;  state: Exp;
Fix inline usage.

--- lib/lists.h.orig	2014-04-01 18:24:10.000000000 +0900
+++ lib/lists.h	2015-02-03 22:46:25.000000000 +0900
@@ -50,6 +50,14 @@ typedef struct list {			/* In fact two o
 
 #define EMPTY_LIST(list) (!(list).head->next)
 
+
+#ifndef _BIRD_LISTS_C_
+#define LIST_INLINE static inline
+#include "lib/lists.c"
+#undef LIST_INLINE
+#else
+#define LIST_INLINE
+
 void add_tail(list *, node *);
 void add_head(list *, node *);
 void rem_node(node *);
@@ -57,13 +64,6 @@ void rem2_node(node *);
 void add_tail_list(list *, list *);
 void init_list(list *);
 void insert_node(node *, node *);
-
-#ifndef _BIRD_LISTS_C_
-#define LIST_INLINE extern inline
-#include "lib/lists.c"
-#undef LIST_INLINE
-#else
-#define LIST_INLINE
 #endif
 
 #endif
