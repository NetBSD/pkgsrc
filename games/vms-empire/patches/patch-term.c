$NetBSD: patch-term.c,v 1.3 2026/04/16 12:34:46 wiz Exp $

Fix ctype(3) functions usage.
https://gitlab.com/esr/vms-empire/-/work_items/6

--- term.c.orig	2024-02-11 16:53:28.000000000 +0000
+++ term.c
@@ -219,8 +219,8 @@ char get_chx(void) {
 
 	c = get_cq();
 
-	if (islower(c)) {
-		return (toupper(c));
+	if (islower((unsigned char)c)) {
+		return (toupper((unsigned char)c));
 	} else {
 		return (c);
 	}
@@ -362,7 +362,7 @@ void help(char **text, int nlines) {
 		}
 		pos_str(r + text_lines + NUMTOPS + 3, c,
 		        "%-12s%c     %c%6d%5d%6d", piece_attr[i].nickname,
-		        piece_attr[i].sname, tolower(piece_attr[i].sname),
+		        piece_attr[i].sname, tolower((unsigned char)piece_attr[i].sname),
 		        piece_attr[i].speed, piece_attr[i].max_hits,
 		        piece_attr[i].build_time, 0, 0); // FLAG
 	}
