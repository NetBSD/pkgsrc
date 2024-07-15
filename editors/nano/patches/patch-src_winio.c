$NetBSD: patch-src_winio.c,v 1.4 2024/07/15 21:14:50 schwarz Exp $

NetBSD curses fix.

https://gnats.netbsd.org/57749
https://savannah.gnu.org/patch/index.php?10438

--- src/winio.c.orig	2024-07-01 11:15:11.000000000 +0200
+++ src/winio.c	2024-07-15 23:03:13.000000000 +0200
@@ -2531,10 +2531,11 @@
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
 
