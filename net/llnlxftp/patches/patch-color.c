$NetBSD: patch-color.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- color.c.orig	1995-10-19 15:20:20.000000000 +0000
+++ color.c
@@ -78,8 +78,7 @@ color_display()
  * fix_list_color - Set background of scrolled list to match its
  *                  scrollbar's trough color.
  */
-fix_list_color(widget)
-Widget widget;
+void fix_list_color(Widget widget)
 {
 	Pixel	sb_trough_color;
 	Widget	w_vertical_sb;
@@ -108,9 +107,7 @@ Widget widget;
  *                             of certain types of widgets (e.g., text
  *                             and textfield widgets).
  */
-set_bg_to_sb_trough_color(widget, w_sb)
-Widget widget;
-Widget w_sb;
+void set_bg_to_sb_trough_color(Widget widget, Widget w_sb)
 {
 	Pixel sb_trough_color;
 
