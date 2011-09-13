$NetBSD: patch-Wnn_jutil_ujisf.c,v 1.1 2011/09/13 07:23:17 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/jutil/ujisf.c.orig	2002-07-14 04:26:57.000000000 +0000
+++ Wnn/jutil/ujisf.c
@@ -10,9 +10,9 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000, 2002
+ * Copyright FreeWnn Project 1999, 2000, 2002, 2010
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -68,8 +68,10 @@ static void sisheng_num (), read_kanji_s
 #define max(a, b) ((a < b)? b:a)
 #endif
 
-extern unsigned char kanjiaddr ();
-extern void Print_entry ();
+extern unsigned char kanjiaddr (unsigned char *d0, w_char* kanji, w_char* yomi, w_char* comment);
+extern void Print_entry (w_char* yomi, w_char* kstr, w_char* cstr,
+		int hindo, int ima, int hinsi, int serial,
+		FILE* ofpter, int esc_exp);
 extern int wnn_find_hinsi_by_name ();
 #ifdef CHINESE
 extern void cwnn_zy_str_analysis (), cwnn_py_str_analysis ();
