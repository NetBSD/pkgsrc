$NetBSD: patch-src_winio.c,v 1.2 2024/03/15 17:44:36 nia Exp $

NetBSD curses fix.

https://gnats.netbsd.org/57749
https://savannah.gnu.org/patch/index.php?10438

--- src/winio.c.orig	2024-03-15 17:30:32.969607523 +0000
+++ src/winio.c
@@ -2502,10 +2502,11 @@ void place_the_cursor(void)
 		column -= get_page_start(column);
 	}
 
-	if (row < editwinrows)
+	if (row < editwinrows) {
 		wmove(midwin, row, margin + column);
+		wnoutrefresh(midwin);
 #ifndef NANO_TINY
-	else
+	} else
 		statusline(ALERT, "Misplaced cursor -- please report a bug");
 #endif
 
