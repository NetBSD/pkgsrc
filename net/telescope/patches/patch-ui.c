$NetBSD: patch-ui.c,v 1.3 2025/10/12 10:07:00 vins Exp $

Use printf instead of dprintf, for SunOS compat.

--- ui.c.orig	2024-12-30 09:09:40.000000000 +0000
+++ ui.c
@@ -1072,9 +1072,11 @@ redraw_tab(struct tab *tab)
 
 	doupdate();
 
-	if (set_title)
-		dprintf(1, "\033]2;%s - Telescope\a",
+	if (set_title) {
+		printf("\033]2;%s - Telescope\a",
 		    current_tab->buffer.title);
+		fflush(stdout);
+	}
 }
 
 void
