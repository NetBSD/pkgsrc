$NetBSD: patch-usermove.c,v 1.1 2016/01/11 19:37:43 leot Exp $

Fix ctype(3) functions usage.

--- usermove.c.orig	2014-12-15 16:26:35.000000000 +0000
+++ usermove.c
@@ -878,7 +878,7 @@ user_dir_army(piece_info_t *obj, loc_t l
 	    ksend ("Your army marched dutifully into the sea and drowned.\n");
 	}
 	else { /* attack something at sea */
-	    enemy_killed = islower (user_map[loc].contents);
+	    enemy_killed = islower ((unsigned char)user_map[loc].contents);
 	    attack (obj, loc);
 	
 	    if (obj->hits > 0) /* ship won? */
@@ -894,7 +894,7 @@ user_dir_army(piece_info_t *obj, loc_t l
 	}
     }
 		
-    else if (isupper (user_map[loc].contents)
+    else if (isupper ((unsigned char)user_map[loc].contents)
 	     && user_map[loc].contents != 'X') { /* attacking self */
 	if (!getyn (
 		"Sir, those are our men!  Do you really want to attack them? "))
@@ -919,7 +919,7 @@ user_dir_fighter(piece_info_t *obj, loc_
 	       "That's never worked before, sir.  Do you really want to try? ",
 	       "Your fighter was shot down.");
 
-    else if (isupper (user_map[loc].contents)) {
+    else if (isupper ((unsigned char)user_map[loc].contents)) {
 	if (!getyn ("Sir, those are our men!  "
 		    "Do you really want to attack them? "))
 	    return;
@@ -959,7 +959,7 @@ user_dir_ship(piece_info_t *obj, loc_t l
 	    ksend ("Your %s broke up on shore.", piece_attr[obj->type].name);
 	}
 	else { /* attack something on shore */
-	    enemy_killed = islower (user_map[loc].contents);
+	    enemy_killed = islower ((unsigned char)user_map[loc].contents);
 	    attack (obj, loc);
 
 	    if (obj->hits > 0) /* ship won? */
@@ -975,7 +975,7 @@ user_dir_ship(piece_info_t *obj, loc_t l
 	}
     }
 		
-    else if (isupper (user_map[loc].contents)) { /* attacking self */
+    else if (isupper ((unsigned char)user_map[loc].contents)) { /* attacking self */
 	if (!getyn (
 		"Sir, those are our men!  Do you really want to attack them? "))
 	    return;
@@ -1062,7 +1062,7 @@ awake(piece_info_t *obj)
     for (i = 0; i < 8; i++) { /* for each surrounding cell */
 	char c = user_map[obj->loc+dir_offset[i]].contents;
 
-	if (islower (c) || c == MAP_CITY || c == 'X') {
+	if (islower ((unsigned char)c) || c == MAP_CITY || c == 'X') {
 	    if (obj->func < 0) obj->func = NOFUNC; /* awaken */
 	    return (true);
 	}
