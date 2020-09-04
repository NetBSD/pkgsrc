$NetBSD: patch-src_ui_window.c,v 1.1 2020/09/04 10:15:17 nia Exp $

Prevent NetBSD libcurses from dereferencing a null pointer.

--- src/ui/window.c.orig	2020-07-01 16:49:19.000000000 +0000
+++ src/ui/window.c
@@ -1858,7 +1858,12 @@ win_sub_print(WINDOW *win, char *msg, gb
 void
 win_sub_newline_lazy(WINDOW *win)
 {
-    int curx = getcurx(win);
+    int curx;
+
+    if (win == NULL) {
+        return;
+    }
+    curx = getcurx(win);
     if (curx > 0) {
         int cury = getcury(win);
         wmove(win, cury+1, 0);
