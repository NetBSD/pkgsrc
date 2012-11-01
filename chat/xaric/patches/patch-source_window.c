$NetBSD: patch-source_window.c,v 1.1 2012/11/01 19:33:19 joerg Exp $

--- source/window.c.orig	2012-10-30 21:45:57.000000000 +0000
+++ source/window.c
@@ -1077,7 +1077,7 @@ show_window (Window * window)
 {
 	if (window->visible) {
 		set_current_window (window);
-		return;
+		return 0;
 	}
 	remove_from_invisible_list (window);
 	if (add_to_window_list (window)) {
