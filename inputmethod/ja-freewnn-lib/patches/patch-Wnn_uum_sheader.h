$NetBSD: patch-Wnn_uum_sheader.h,v 1.1 2011/09/13 07:23:19 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/uum/sheader.h.orig	2003-05-11 18:29:24.000000000 +0000
+++ Wnn/uum/sheader.h
@@ -10,9 +10,9 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000, 2002-2003
+ * Copyright FreeWnn Project 1999, 2000, 2002, 2003, 2006
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -209,9 +209,22 @@ extern void uum_err (char *);
 extern void FPRINTF ();
 extern void PRINTF ();
 
+/* setutmp.c */
+extern int saveutmp (void);
+extern int resetutmp (int ttyFd);
+extern int setutmp (int ttyFd);
+
 /* ttyfdslot.c */
 extern int  ttyfdslot (int fd);
 
+#if HAVE_TERMINFO
+/* termio.c */
+extern int openTermData (void);
+#else
+/* termcap.c */
+extern int getTermData (void);
+#endif
+
 /* to be classified */
 extern void b_s_off_raw (void);
 extern void b_s_on_raw (void);
@@ -249,7 +262,6 @@ extern int find_entry (char *);
 extern void flushw_buf (void);
 extern int forward_char (void);
 extern int backward_char (void);
-extern int getTermData ();
 extern void get_end_of_history ();
 extern void getfname ();
 extern void h_r_off ();
@@ -310,11 +322,9 @@ extern int isconect_jserver ();
 extern int ren_henkan0 ();
 extern void reset_bold ();
 extern void reset_cursor_status ();
-extern int resetutmp ();
 extern void restore_cursor_raw ();
 extern void ring_bell ();
 extern void save_cursor_raw ();
-extern int saveutmp ();
 extern void scroll_up ();
 extern int select_jikouho1 ();
 extern int select_line_element ();
@@ -330,7 +340,6 @@ extern void set_screen_vars_default ();
 extern void set_keypad_on ();
 extern void set_keypad_off ();
 extern void set_scroll_region ();
-extern int setutmp ();
 extern int st_colum ();
 extern void t_cont_line_note_delete ();
 extern int t_delete_char ();
