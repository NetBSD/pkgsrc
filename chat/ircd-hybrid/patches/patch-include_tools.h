$NetBSD: patch-include_tools.h,v 1.1 2012/12/20 22:01:22 joerg Exp $

--- include/tools.h.orig	2007-02-28 04:17:43.000000000 +0000
+++ include/tools.h
@@ -98,7 +98,7 @@ void mem_frob(void *data, int len);
  * which is mine.
  *   -- adrian
  */
-extern inline void
+extern inline __attribute__((__gnu_inline__)) void
 dlinkAdd(void *data, dlink_node * m, dlink_list * list)
 {
  m->data = data;
@@ -113,7 +113,7 @@ dlinkAdd(void *data, dlink_node * m, dli
  list->length++;
 }
 
-extern inline void
+extern inline __attribute__((__gnu_inline__))  void
 dlinkAddBefore(dlink_node *b, void *data, dlink_node *m, dlink_list *list)
 {
     /* Shortcut - if its the first one, call dlinkAdd only */
@@ -129,7 +129,7 @@ dlinkAddBefore(dlink_node *b, void *data
     }
 }
 
-extern inline void
+extern inline __attribute__((__gnu_inline__))  void
 dlinkAddTail(void *data, dlink_node *m, dlink_list *list)
 {
  m->data = data;
@@ -147,7 +147,7 @@ dlinkAddTail(void *data, dlink_node *m, 
 /* Execution profiles show that this function is called the most
  * often of all non-spontaneous functions. So it had better be
  * efficient. */
-extern inline void
+extern inline __attribute__((__gnu_inline__))  void
 dlinkDelete(dlink_node *m, dlink_list *list)
 {
  /* Assumption: If m->next == NULL, then list->tail == m
@@ -177,7 +177,7 @@ dlinkDelete(dlink_node *m, dlink_list *l
  * output	- pointer to link or NULL if not found
  * side effects	- Look for ptr in the linked listed pointed to by link.
  */
-extern inline dlink_node *
+extern inline __attribute__((__gnu_inline__))  dlink_node *
 dlinkFind(dlink_list *list, void *data)
 {
   dlink_node *ptr;
@@ -191,7 +191,7 @@ dlinkFind(dlink_list *list, void *data)
   return(NULL);
 }
 
-extern inline void
+extern inline __attribute__((__gnu_inline__))  void
 dlinkMoveList(dlink_list *from, dlink_list *to)
 {
   /* There are three cases */
@@ -226,7 +226,7 @@ dlinkMoveList(dlink_list *from, dlink_li
   /* I think I got that right */
 }
 
-extern inline dlink_node *
+extern inline __attribute__((__gnu_inline__))  dlink_node *
 dlinkFindDelete(dlink_list *list, void *data)
 {
   dlink_node *m;
