$NetBSD: patch-syswatch.c,v 1.1 2025/11/13 01:33:13 mef Exp $

Avoid error with gcc-14.3.0  (Thanks @tristelo) 
+----------------------
| syswatch.c:799:84: error: passing argument 4 of 'qsort' from incompatible pointer type [-Wincompatible-pointer-types]
|   799 |                         qsort(queue_list, numele, sizeof(struct graph_elements *), q_time_cmp);
|       |                                                                                    ^~~~~~~~~~
|       |                                                                                    |
|       |                                                                                    int (*)(void **, void **)
| In file included from config.h:10,
|                  from syswatch.c:2:
| | usr/include/stdlib.h:117:40: note: expected 'int (*)(const void *, const void *)' but argument is of type 'int (*)(void **, void **)'
|  117 | void     qsort(void *, size_t, size_t, int (*)(const void *, const void *));
|      |                                        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
| *** [syswatch.o] Error code 1
+----------------------

--- src/syswatch.c.orig	2014-07-10 01:29:39.000000000 +0900
+++ src/syswatch.c	2025-11-13 10:12:50.302148951 +0900
@@ -681,12 +681,12 @@ void walk_queue_checks(struct graph_elem
 /*
  * time comparison function for qsort
  */
-int q_time_cmp(void **arg_a, void **arg_b)
+int q_time_cmp(const void *arg_a, const void *arg_b)
 {
         struct graph_elements *sort_a, *sort_b;
 
-        sort_a = *arg_a;
-        sort_b = *arg_b;
+        sort_a = *(struct graph_elements **)arg_a ;
+        sort_b = *(struct graph_elements **)arg_b;
 
 	/* if they're both null, then they're equal */
 	if ((sort_a == NULL) && (sort_b == NULL))
