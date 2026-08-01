$NetBSD: patch-src_winio.c,v 1.5 2026/08/01 22:05:31 schwarz Exp $

NetBSD curses fix.

https://gnats.netbsd.org/57749
https://savannah.gnu.org/patch/index.php?10438

--- src/winio.c.orig	2026-07-25 10:51:54.000000000 +0200
+++ src/winio.c	2026-08-01 23:45:43.000000000 +0200
@@ -2528,10 +2528,11 @@
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
 
