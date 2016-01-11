$NetBSD: patch-term.c,v 1.1 2016/01/11 19:37:43 leot Exp $

Fix ctype(3) functions usage.

--- term.c.orig	2014-12-15 16:26:35.000000000 +0000
+++ term.c
@@ -249,8 +249,8 @@ get_chx(void)
 
     c = get_cq ();
 
-    if (islower(c))
-	return (toupper(c));
+    if (islower((unsigned char)c))
+	return (toupper((unsigned char)c));
     else
 	return (c);
 }
@@ -390,7 +390,7 @@ help(char **text, int nlines)
 	pos_str (r + text_lines + NUMTOPS + 3, c,"%-12s%c     %c%6d%5d%6d",
 		  piece_attr[i].nickname,
 		  piece_attr[i].sname,
-		  tolower (piece_attr[i].sname),
+		  tolower ((unsigned char)piece_attr[i].sname),
 		  piece_attr[i].speed,
 		  piece_attr[i].max_hits,
 		  piece_attr[i].build_time,0,0);		//FLAG
