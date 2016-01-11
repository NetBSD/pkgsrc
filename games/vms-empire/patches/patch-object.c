$NetBSD: patch-object.c,v 1.1 2016/01/11 19:37:43 leot Exp $

Fix ctype(3) functions usage.

--- object.c.orig	2014-12-15 00:57:48.000000000 +0000
+++ object.c
@@ -568,7 +568,7 @@ update(view_map_t vmap[], loc_t loc)
 	else if (p->owner == USER)
 	    vmap[loc].contents = piece_attr[p->type].sname;
 	else
-	    vmap[loc].contents = tolower (piece_attr[p->type].sname);
+	    vmap[loc].contents = tolower ((unsigned char)piece_attr[p->type].sname);
     }
     if (vmap == comp_map)
 	display_locx (COMP, comp_map, loc);
