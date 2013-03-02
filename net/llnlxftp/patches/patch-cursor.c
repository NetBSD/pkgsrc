$NetBSD: patch-cursor.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- cursor.c.orig	1995-10-19 15:20:20.000000000 +0000
+++ cursor.c
@@ -79,8 +79,7 @@ static struct dialog_list_st *dialog_lis
  *                 used cursor.  Every dialog in use has to indivually
  *                 have its cursor changed.
  */
-change_cursor(shape)
-int shape;
+void change_cursor(int shape)
 {
 	struct cursor_stack_st *cptr;
 	struct dialog_list_st *dptr;
@@ -128,7 +127,7 @@ use_normal_cursor()
 /*
  * restore_prev_cursor - Restore cursor to the previously used shape.
  */
-restore_prev_cursor()
+void restore_prev_cursor(void)
 {
 	struct cursor_stack_st *current;
 	struct dialog_list_st *dptr;
@@ -178,8 +177,7 @@ restore_prev_cursor()
  *                      by change_cursor() so that it can change the
  *                      cursor for all existing dialogs.
  */
-add_dialog_to_list(w_dialog)
-Widget w_dialog;
+void add_dialog_to_list(Widget w_dialog)
 {
 	struct dialog_list_st *dptr;
 
@@ -214,8 +212,7 @@ Widget w_dialog;
  *                           by change_cursor() so that it can change the
  *                           cursor for all existing dialogs.
  */
-remove_dialog_from_list(w_dialog)
-Widget w_dialog;
+void remove_dialog_from_list(Widget w_dialog)
 {
 	struct dialog_list_st *dptr;
 
