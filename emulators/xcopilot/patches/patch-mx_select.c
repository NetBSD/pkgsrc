$NetBSD: patch-mx_select.c,v 1.1 2021/08/27 03:41:41 ryoon Exp $

* Declare variables as int.

--- mx/select.c.orig	1998-04-25 17:50:15.000000000 +0000
+++ mx/select.c
@@ -27,7 +27,7 @@ Update History:   (most recent first)
 int mx_scroll_event(Display *display, int screen, XEvent *event,
 		    mx_scroll *scroll, int *done)
 {
-  static x, y, pick_x, pick_y;
+  static int x, y, pick_x, pick_y;
   static int pick_item, item;
   int cursor_range, item_range;
   switch(event->type) {
