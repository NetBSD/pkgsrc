$NetBSD: patch-object.c,v 1.2 2025/02/08 10:49:45 triaxx Exp $

Fix ctype(3) functions usage.

--- object.c.orig	2024-02-11 15:57:48.000000000 +0000
+++ object.c
@@ -552,7 +552,7 @@ void update(view_map_t vmap[], loc_t loc
 		else if (p->owner == USER)
 			vmap[loc].contents = piece_attr[p->type].sname;
 		else
-			vmap[loc].contents = tolower(piece_attr[p->type].sname);
+			vmap[loc].contents = tolower((unsigned char)piece_attr[p->type].sname);
 	}
 	if (vmap == game.comp_map)
 		display_locx(COMP, game.comp_map, loc);
