$NetBSD: patch-game.c,v 1.3 2026/04/16 12:34:46 wiz Exp $

Fix ctype(3) functions usage.
https://gitlab.com/esr/vms-empire/-/work_items/6

--- game.c.orig	2024-09-23 21:39:24.000000000 +0000
+++ game.c
@@ -783,7 +783,7 @@ void save_movie_screen(void) {
 			} else if (p->owner == USER) {
 				mapbuf[i] = piece_attr[p->type].sname;
 			} else {
-				mapbuf[i] = tolower(piece_attr[p->type].sname);
+				mapbuf[i] = tolower((unsigned char)piece_attr[p->type].sname);
 			}
 		}
 	}
