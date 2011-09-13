$NetBSD: patch-Wnn_jserver_de__header.h,v 1.1 2011/09/13 07:23:17 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/jserver/de_header.h.orig	2004-12-29 17:45:32.000000000 +0000
+++ Wnn/jserver/de_header.h
@@ -10,9 +10,10 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000, 2001, 2002, 2003, 2004
+ * Copyright FreeWnn Project
+ *                 1999, 2000, 2001, 2002, 2003, 2004, 2010, 2011
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -218,13 +219,13 @@ extern int b_index_add (struct JT *jt, w
 extern void b_index_delete (struct JT *jt, int serial);
 #endif
 /* bnsetu_kai.c */
-extern int sbn_kai ();
-extern int j_max ();
-extern int getgiji ();
-extern int is_g_eisuu ();
-extern int getgiji_f ();
-extern int check_bar_katakana ();
-extern int kan_ckvt ();
+extern int sbn_kai (int, int, int, int, struct SYO_BNSETSU **, int, struct SYO_BNSETSU *);
+extern int j_max (struct ICHBNP *, int);
+extern int getgiji (int, int, struct SYO_BNSETSU *, struct ICHBNP *, int, int);
+extern int is_g_eisuu (w_char);
+extern int getgiji_f (int,  struct SYO_BNSETSU *);
+extern int check_bar_katakana (int, int);
+extern int kan_ckvt (unsigned short, int);
 /* daibn_kai.c */
 extern int dbn_kai ();
 extern int get_status ();
@@ -512,7 +513,7 @@ extern int fread_cur ();
 extern int xgetc_cur ();
 extern void xungetc_cur ();
 extern void fwrite_cur ();
-extern void xputc_cur ();
+extern void xputc_cur (unsigned char);
 extern void fclose_cur ();
 /* w_string.c */
 extern void Sreverse ();
@@ -534,27 +535,27 @@ extern char *wnn_get_hinsi_name ();
 extern int wnn_get_fukugou_component_body ();
 extern int wnn_get_fukugou_component ();
 /* bdic.c */
-extern void check_backup ();
-extern void delete_tmp_file ();
-extern char *make_backup_file ();
-extern char *make_tmp_file ();
-extern void move_tmp_to_org ();
-extern int output_file_header ();
-extern int input_file_header ();
-extern int output_file_uniq (struct wnn_file_uniq* funiq, FILE* ofpter);
-extern int check_inode ();
-extern int change_file_uniq ();
-extern int f_uniq_cmp ();
-extern void Get_knj2 ();
-extern void get_kanji_str ();
-extern void Get_kanji_str_r ();
-extern unsigned char *kanjiaddr ();
-extern int create_null_dic ();
-extern int create_hindo_file ();
-extern int input_header_jt ();
-extern int output_header_jt ();
-extern int input_header_hjt ();
-extern int output_header_hjt ();
+extern void check_backup (char*);
+extern void delete_tmp_file (char*);
+extern char *make_backup_file (char*);
+extern char *make_tmp_file (char*, int, FILE**);
+extern void move_tmp_to_org (char*, char*, int);
+extern int output_file_header (FILE*, struct wnn_file_head*);
+extern int input_file_header  (FILE*, struct wnn_file_head*);
+extern int output_file_uniq (struct wnn_file_uniq*, FILE*);
+extern int check_inode (FILE*, struct wnn_file_head*);
+extern int change_file_uniq (struct wnn_file_head*, char*);
+extern int f_uniq_cmp (struct wnn_file_uniq*, struct wnn_file_uniq*);
+extern void Get_knj2 (unsigned char*, int, w_char*, w_char*, w_char*);
+extern void get_kanji_str (unsigned char*, w_char*, w_char*, w_char*);
+extern void Get_kanji_str_r (unsigned char*, w_char**, w_char**, w_char**);
+extern unsigned char kanjiaddr (unsigned char*, w_char*, w_char*, w_char*);
+extern int create_null_dic (char*, w_char*, char*, char*, int);
+extern int create_hindo_file (struct wnn_file_uniq*, char*, w_char*, char*, int);
+extern int input_header_jt  (FILE*, struct JT*);
+extern int output_header_jt (FILE*, struct JT*);
+extern int input_header_hjt  (FILE*, struct HJT*);
+extern int output_header_hjt (FILE*, struct HJT*);
 /* dic_atojis.c */
 extern void Get_kanji ();
 extern void Get_knj1 ();
@@ -565,8 +566,8 @@ extern int revdic ();
 extern int asshuku ();
 extern int motoni2 ();
 /* pwd.c */
-extern int new_pwd ();
-extern int check_pwd ();
+extern void new_pwd  (char*, char*);
+extern int check_pwd (char*, char*);
 
 #endif /* JSERVER_DE_HEADER_H */
 
