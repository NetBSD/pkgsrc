$NetBSD: patch-src_video.c,v 1.1 2026/11/20 15:57:11 ktnb Exp $

unsigned long is being printed

--- src/video.c.orig	2026-11-20 14:27:35.687596322 +0000
+++ src/video.c
@@ -109,9 +109,9 @@ showscreen(char **message, unsigned long lines, unsign
 	mymvhline(maxy - 1, 0, ' ', maxx);
 	move(maxy - 1, 0);
 	if ((pos < lines - 1) &&(lines > pos + maxy - 2))
-		printw(_("Viewing line %d/%d, %d%%"), pos + maxy - 2, lines,((pos + maxy - 2) * 100) / lines);
+		printw(_("Viewing line %ld/%ld, %ld%%"), pos + maxy - 2, lines,((pos + maxy - 2) * 100) / lines);
 	else
-		printw(_("Viewing line %d/%d, 100%%"), lines, lines);
+		printw(_("Viewing line %ld/%ld, 100%%"), lines, lines);
 	info_add_highlights(pos, cursor, lines, column, message);
 	attrset(normal);
 	move(0, 0);
