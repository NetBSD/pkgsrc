$NetBSD: patch-more.c,v 1.1 2017/12/29 11:59:13 plunky Exp $

-Wset-but-unused

--- more.c.orig	2014-12-30 15:00:06.000000000 +0000
+++ more.c
@@ -37,7 +37,7 @@
 static void
 print_page(WINDOW *win, char **page, int maxlines, int maxcols, int y, int x)
 {
-	int i, j, len;
+	int i, j;
 	char buf[MAXLEN], *c;
 	
 	for (i = 0; (page[i] != NULL) && (i < maxlines); i++) {
@@ -49,7 +49,6 @@ print_page(WINDOW *win, char **page, int
 		wprintw(win, "%s", buf);
 
 		/* print entry */
-		len = strlen(page[i]);
 		snprintf(buf, MAXLEN, "%s", page[i]);
 
 		/* 5 = 2 borders + 2 lines + 1 */
