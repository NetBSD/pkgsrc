$NetBSD: patch-memo.c,v 1.2 2015/12/29 04:04:27 dholland Exp $

Only sort memos alphabetically when enabled in the app_info.

--- memo.c.orig	2014-05-25 03:25:20.000000000 +0000
+++ memo.c	2015-05-19 10:51:57.000000000 +0000
@@ -262,7 +262,7 @@
 
 static int memo_sort(MemoList **memol, int sort_order)
 {
-   /* struct MemoAppInfo memo_ai; */
+   struct MemoAppInfo memo_ai;
    MemoList *temp_memol;
    MemoList **sort_memol;
    int count, i;
@@ -291,13 +291,10 @@
       sort_memol[i] = temp_memol;
    }
 
-   /* TODO: Restore code when syncing of AppInfo blocks is implemented
    get_memo_app_info(&memo_ai);
    if (memo_ai.sortByAlpha==1) {
       qsort(sort_memol, count, sizeof(MemoList *), memo_compare);
    }
-   */
-   qsort(sort_memol, count, sizeof(MemoList *), memo_compare);
 
    /* Put the linked list in the order of the array */
    if (sort_order==SORT_ASCENDING) {
