$NetBSD: patch-Wnn_jutil_atorev.c,v 1.1 2026/06/28 06:16:28 tsutsui Exp $

- Fix build with -std=gnu23 (i.e. gcc14 and later)

--- Wnn/jutil/atorev.c.orig	2026-06-23 14:01:43.991289584 +0000
+++ Wnn/jutil/atorev.c
@@ -64,9 +64,6 @@ static void make_ri2 FRWNN_PARAMS((void)
 static void make_ri1 FRWNN_PARAMS((int));
 static void set_rpter1 FRWNN_PARAMS((int));
 
-extern int sort_func_je ();
-extern void sort_kanji ();
-
 struct je **ptmp;
 
 void
