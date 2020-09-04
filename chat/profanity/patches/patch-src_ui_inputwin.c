$NetBSD: patch-src_ui_inputwin.c,v 1.1 2020/09/04 10:15:17 nia Exp $

Prevent NetBSD libcurses from dereferencing a null pointer.

--- src/ui/inputwin.c.orig	2020-06-29 15:43:33.000000000 +0000
+++ src/ui/inputwin.c
@@ -307,7 +307,9 @@ _inp_win_update_virtual(void)
 {
     int wcols = getmaxx(stdscr);
     int row = screen_inputwin_row();
-    pnoutrefresh(inp_win, 0, pad_start, row, 0, row, wcols-2);
+    if (inp_win != NULL) {
+        pnoutrefresh(inp_win, 0, pad_start, row, 0, row, wcols-2);
+    }
 }
 
 static void
