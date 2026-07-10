$NetBSD: patch-Wnn_jutil_atorev.c,v 1.2 2026/07/10 23:32:37 tsutsui Exp $

- Remove unnecessary old-style function prototypes

--- Wnn/jutil/atorev.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jutil/atorev.c
@@ -58,15 +58,11 @@
 extern int kanjicount;
 extern struct JT jt;
 
-static void set_rpter1 ();
 static void r_alloc FRWNN_PARAMS((void));
 static void make_ri2 FRWNN_PARAMS((void));
 static void make_ri1 FRWNN_PARAMS((int));
 static void set_rpter1 FRWNN_PARAMS((int));
 
-extern int sort_func_je ();
-extern void sort_kanji ();
-
 struct je **ptmp;
 
 void
