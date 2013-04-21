$NetBSD: patch-src_window.c,v 1.1 2013/04/21 15:40:00 joerg Exp $

--- src/window.c.orig	1994-10-21 04:21:03.000000000 +0000
+++ src/window.c
@@ -34,6 +34,8 @@ the Free Software Foundation, 675 Mass A
 #include "disptab.h"
 #include "keyboard.h"
 
+static void change_window_height (int delta, int widthflag);
+
 Lisp_Object Qwindowp, Qwindow_live_p;
 
 Lisp_Object Fnext_window (), Fdelete_window (), Fselect_window ();
@@ -1583,10 +1585,7 @@ check_frame_size (frame, rows, cols)
    nodelete nonzero means do not do this.
    (The caller should check later and do so if appropriate)  */
 
-set_window_height (window, height, nodelete)
-     Lisp_Object window;
-     int height;
-     int nodelete;
+void set_window_height (Lisp_Object window, int height, int nodelete)
 {
   register struct window *w = XWINDOW (window);
   register struct window *c;
@@ -1648,10 +1647,7 @@ set_window_height (window, height, nodel
 
 /* Recursively set width of WINDOW and its inferiors. */
 
-set_window_width (window, width, nodelete)
-     Lisp_Object window;
-     int width;
-     int nodelete;
+void set_window_width (Lisp_Object window, int width, int nodelete)
 {
   register struct window *w = XWINDOW (window);
   register struct window *c;
@@ -2198,9 +2194,7 @@ window_width (window)
    also changes the heights of the siblings so as to
    keep everything consistent. */
 
-change_window_height (delta, widthflag)
-     register int delta;
-     int widthflag;
+static void change_window_height (int delta, int widthflag)
 {
   register Lisp_Object parent;
   Lisp_Object window;
