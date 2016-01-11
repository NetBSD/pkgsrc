$NetBSD: patch-game.c,v 1.1 2016/01/11 19:37:43 leot Exp $

Fix ctype(3) functions usage.

--- game.c.orig	2014-12-15 16:36:24.000000000 +0000
+++ game.c
@@ -745,7 +745,7 @@ save_movie_screen(void)
 	    if (!p) mapbuf[i] = map[i].contents;
 	    else if (p->owner == USER)
 		mapbuf[i] = piece_attr[p->type].sname;
-	    else mapbuf[i] = tolower (piece_attr[p->type].sname);
+	    else mapbuf[i] = tolower ((unsigned char)piece_attr[p->type].sname);
 	}
     }
     wbuf (mapbuf);
