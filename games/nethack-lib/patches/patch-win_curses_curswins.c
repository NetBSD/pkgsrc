$NetBSD: patch-win_curses_curswins.c,v 1.1 2023/09/02 13:45:14 rhialto Exp $

NetBSD's curses crashes when status_window is NULL, which can happen
while #quit'ing.

--- win/curses/curswins.c.orig	2023-08-28 19:22:25.737331832 +0000
+++ win/curses/curswins.c
@@ -173,12 +173,18 @@ curses_refresh_nethack_windows()
         touchwin(stdscr);
         refresh();
     } else {
-        touchwin(status_window);
-        wnoutrefresh(status_window);
-        touchwin(map_window);
-        wnoutrefresh(map_window);
-        touchwin(message_window);
-        wnoutrefresh(message_window);
+        if (status_window) {
+            touchwin(status_window);
+            wnoutrefresh(status_window);
+        }
+        if (map_window) {
+            touchwin(map_window);
+            wnoutrefresh(map_window);
+        }
+        if (message_window) {
+            touchwin(message_window);
+            wnoutrefresh(message_window);
+        }
         if (inv_window) {
             touchwin(inv_window);
             wnoutrefresh(inv_window);
