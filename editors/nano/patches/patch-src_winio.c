$NetBSD: patch-src_winio.c,v 1.3 2024/05/11 20:14:27 schwarz Exp $

NetBSD curses fix.

https://gnats.netbsd.org/57749
https://savannah.gnu.org/patch/index.php?10438

--- src/winio.c.orig	2024-05-01 10:25:05.000000000 +0200
+++ src/winio.c	2024-05-11 22:01:46.000000000 +0200
@@ -2534,10 +2534,11 @@
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
 
