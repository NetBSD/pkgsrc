$NetBSD: patch-src_gui_curses_gui-curses-main.c,v 1.1 2017/02/07 12:30:29 roy Exp $

Upstream commit d6977490d0c91b3417a383dd3d1a844657c09f84

core: fix delayed refresh when the signal SIGWINCH is received (terminal resized)

--- src/gui/curses/gui-curses-main.c.orig	2017-02-07 10:57:15.926377533 +0000
+++ src/gui/curses/gui-curses-main.c
@@ -451,10 +451,6 @@ gui_main_loop ()
             gui_color_pairs_auto_reset_pending = 1;
         }
 
-        gui_main_refreshs ();
-        if (gui_window_refresh_needed && !gui_window_bare_display)
-            gui_main_refreshs ();
-
         if (gui_signal_sigwinch_received)
         {
             (void) hook_signal_send ("signal_sigwinch",
@@ -463,6 +459,10 @@ gui_main_loop ()
             gui_window_ask_refresh (2);
         }
 
+        gui_main_refreshs ();
+        if (gui_window_refresh_needed && !gui_window_bare_display)
+            gui_main_refreshs ();
+
         gui_color_pairs_auto_reset_pending = 0;
 
         /* execute fd hooks */
