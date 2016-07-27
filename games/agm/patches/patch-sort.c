$NetBSD: patch-sort.c,v 1.1 2016/07/27 20:37:27 kamil Exp $

Fix K&R code.

--- sort.c.orig	2016-07-27 20:12:55.361585478 +0000
+++ sort.c
@@ -14,9 +14,8 @@ char sort_RCSid[] = "Revision: 1.2 $";
 
 #include "agm.h"
 
-merge_sort (start, length)
-    struct wnode **start;
-    int length;
+void
+merge_sort (struct wnode **start, int length)
 {
   struct wnode *p, *q, *s1, *s2;
   int i, cmp;
