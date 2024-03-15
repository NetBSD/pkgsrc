$NetBSD: patch-src_winio.c,v 1.1 2024/03/15 17:35:50 nia Exp $

NetBSD curses fix.

https://gnats.netbsd.org/57749

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
 
