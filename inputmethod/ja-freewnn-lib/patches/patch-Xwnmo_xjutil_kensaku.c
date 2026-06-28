$NetBSD: patch-Xwnmo_xjutil_kensaku.c,v 1.1 2026/06/28 06:16:28 tsutsui Exp $

- Fix build with -std=gnu23 (i.e. gcc14 and later)

--- Xwnmo/xjutil/kensaku.c.orig	2026-06-25 14:34:37.374657174 +0000
+++ Xwnmo/xjutil/kensaku.c
@@ -57,17 +57,19 @@ int del_point, ima_point, hindo_point, c
 
 static int
 sort_func_ws (a, b)
-     register char *a, *b;
+     const void *a, *b;
 {
   int ah, bh, ai, bi, iah, ibh, iai, ibi;
-  ah = ((struct wnn_jdata *) a)->hindo;
-  bh = ((struct wnn_jdata *) b)->hindo;
-  iah = ((struct wnn_jdata *) a)->int_hindo;
-  ibh = ((struct wnn_jdata *) b)->int_hindo;
-  ai = ((struct wnn_jdata *) a)->ima;
-  bi = ((struct wnn_jdata *) b)->ima;
-  iai = ((struct wnn_jdata *) a)->int_ima;
-  ibi = ((struct wnn_jdata *) b)->int_ima;
+  const struct wnn_jdata *ja = a;
+  const struct wnn_jdata *jb = b;
+  ah = ja->hindo;
+  bh = jb->hindo;
+  iah = ja->int_hindo;
+  ibh = jb->int_hindo;
+  ai = ja->ima;
+  bi = jb->ima;
+  iai = ja->int_ima;
+  ibi = jb->int_ima;
 
   if (ai == WNN_IMA_OFF && ah == WNN_ENTRY_NO_USE)
     return (1);
@@ -160,7 +162,7 @@ retry:
       return (NULL);
     }
   word_searched = (struct wnn_jdata *) wordrb.buf;
-  qsort ((char *) word_searched, cnt, sizeof (struct wnn_jdata), sort_func_ws);
+  qsort (word_searched, cnt, sizeof (struct wnn_jdata), sort_func_ws);
 
   update_dic_list ();
 
