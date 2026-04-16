$NetBSD: patch-object.c,v 1.3 2026/04/16 12:34:46 wiz Exp $

Fix ctype(3) functions usage.
https://gitlab.com/esr/vms-empire/-/work_items/6

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
