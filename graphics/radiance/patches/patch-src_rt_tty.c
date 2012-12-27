$NetBSD: patch-src_rt_tty.c,v 1.1 2012/12/27 00:23:21 dholland Exp $

Pass around input buffer lengths.

--- src/rt/tty.c~	2004-04-10 02:54:10.000000000 +0000
+++ src/rt/tty.c
@@ -85,13 +85,14 @@ getch(void)					/* get a character in ra
 static void
 ttyin(			/* read a line in raw mode */
 	char  *buf,
+	size_t max,
 	char  *prompt
 )
 {
 
 	if (prompt != NULL)
 		(*ttydev->comout)(prompt);
-	editline(buf, getch, ttydev->comout);
+	editline(buf, max, getch, ttydev->comout);
 }
 
 
