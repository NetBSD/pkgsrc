$NetBSD: patch-Wnn_uum_header.c,v 1.1 2011/09/13 07:23:18 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/uum/header.c.orig	2001-09-16 11:42:58.000000000 +0000
+++ Wnn/uum/header.c
@@ -10,9 +10,10 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000
+ * Copyright FreeWnn Project 1999, 2000, 2006
+ * Copyright Canna Project 2002
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -131,7 +132,7 @@ FunctionTable *f_table = NULL;
 
 FuncDataBase function_db[] = {
 #ifdef JAPANESE
-  {"ja_JP",
+  {WNN_J_LANG,
    {NULL, NULL, call_t_redraw_move_normal,
     call_t_redraw_move_1_normal, call_t_redraw_move_2_normal,
     call_t_print_l_normal, NULL, char_len_normal, char_q_len_normal,
@@ -151,7 +152,7 @@ FuncDataBase function_db[] = {
    },
 #endif /* JAPANESE */
 #ifdef CHINESE
-  {"zh_CN",                     /* Simplified Chinese */
+  {WNN_C_LANG,				/* Simplified Chinese */
    {print_out_yincod, input_yincod, call_t_redraw_move_yincod,
     call_t_redraw_move_1_yincod, call_t_redraw_move_2_yincod,
     call_t_print_l_yincod, redraw_when_chmsig_yincod, char_len_yincod,
@@ -170,7 +171,7 @@ FuncDataBase function_db[] = {
    {
     NULL, NULL, NULL, NULL, NULL, NULL}
    },
-  {"zh_TW",                     /* Traditional Chinese */
+  {WNN_T_LANG,				/* Traditional Chinese */
    {print_out_yincod, input_yincod, call_t_redraw_move_yincod,
     call_t_redraw_move_1_yincod, call_t_redraw_move_2_yincod,
     call_t_print_l_yincod, redraw_when_chmsig_yincod, char_len_yincod,
@@ -191,7 +192,7 @@ FuncDataBase function_db[] = {
    },
 #endif /* CHINESE */
 #ifdef   KOREAN
-  {"ko_KR",
+  {WNN_K_LANG,
    {NULL, NULL, call_t_redraw_move_normal,
     call_t_redraw_move_1_normal, call_t_redraw_move_2_normal,
     call_t_print_l_normal, NULL, char_len_normal, char_q_len_normal,
