$NetBSD: patch-ui.cc,v 1.1 2018/10/04 15:46:48 roy Exp $

Support NetBSD curses.
Don't assume that stdscr is at y 0.

diff --git a/ui.cc b/ui.cc
index c8e7bb4..564e964 100644
--- ui.cc
+++ ui.cc
@@ -133,6 +133,11 @@ void Ui::init() {
     signal (SIGINT, end_sig);
     signal (SIGSEGV, end_sig);
 
+    ripoffline(1, createMessageWin);
+    ripoffline(-1, createStatusWin);
+    initscr();
+    keypad(stdscr, TRUE);
+
     _viewport = 0;
     _lines = 0;
     _cols  = 0;
@@ -158,11 +163,6 @@ void Ui::init() {
     _keybindings['n']               = &Game::move_downright;
     _keybindings[KEY_RESIZE]        = &Game::resize;
 
-    ripoffline(1, createMessageWin);
-    ripoffline(-1, createStatusWin);
-    initscr();
-    keypad(stdscr, TRUE);
-
     if (has_colors()) {
         start_color();
         init_pair(1, COLOR_BLACK, COLOR_WHITE);
@@ -215,7 +215,9 @@ void Ui::resize() {
     wbkgd(stdscr, ' ');
 
     if (!_viewport) {
-        _viewport = subwin(stdscr, _lines, _cols, 0, 0);
+        int begy, begx;
+        getbegyx(stdscr, begy, begx);
+        _viewport = subwin(stdscr, _lines, _cols, begy, begx);
     }
     else {
         wresize(_viewport, _lines, _cols);
