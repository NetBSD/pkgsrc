$NetBSD: patch-usermove.c,v 1.2 2025/02/08 10:49:45 triaxx Exp $

Fix ctype(3) functions usage.

--- usermove.c.orig	2024-02-11 16:53:28.000000000 +0000
+++ usermove.c
@@ -997,7 +997,7 @@ void user_dir_army(piece_info_t *obj, lo
 			ksend("Your army marched dutifully into the sea and "
 			      "drowned.\n");
 		} else { /* attack something at sea */
-			enemy_killed = islower(game.user_map[loc].contents);
+			enemy_killed = islower((unsigned char)game.user_map[loc].contents);
 			attack(obj, loc);
 
 			if (obj->hits > 0) /* ship won? */
@@ -1016,7 +1016,7 @@ void user_dir_army(piece_info_t *obj, lo
 		}
 	}
 
-	else if (isupper(game.user_map[loc].contents) &&
+	else if (isupper((unsigned char)game.user_map[loc].contents) &&
 	         game.user_map[loc].contents != 'X') { /* attacking self */
 		if (!getyn("Sir, those are our men!  Do you really want to "
 		           "attack them? ")) {
@@ -1044,7 +1044,7 @@ void user_dir_fighter(piece_info_t *obj,
 		      "Your fighter was shot down.");
 	}
 
-	else if (isupper(game.user_map[loc].contents)) {
+	else if (isupper((unsigned char)game.user_map[loc].contents)) {
 		if (!getyn("Sir, those are our men!  "
 		           "Do you really want to attack them? ")) {
 			return;
@@ -1089,7 +1089,7 @@ void user_dir_ship(piece_info_t *obj, lo
 			ksend("Your %s broke up on shore.",
 			      piece_attr[obj->type].name);
 		} else { /* attack something on shore */
-			enemy_killed = islower(game.user_map[loc].contents);
+			enemy_killed = islower((unsigned char)game.user_map[loc].contents);
 			attack(obj, loc);
 
 			if (obj->hits > 0) /* ship won? */
@@ -1110,7 +1110,7 @@ void user_dir_ship(piece_info_t *obj, lo
 		}
 	}
 
-	else if (isupper(game.user_map[loc].contents)) { /* attacking self */
+	else if (isupper((unsigned char)game.user_map[loc].contents)) { /* attacking self */
 		if (!getyn("Sir, those are our men!  Do you really want to "
 		           "attack them? ")) {
 			return;
@@ -1196,7 +1196,7 @@ bool awake(piece_info_t *obj) {
 	for (i = 0; i < 8; i++) { /* for each surrounding cell */
 		char c = game.user_map[obj->loc + dir_offset[i]].contents;
 
-		if (islower(c) || c == MAP_CITY || c == 'X') {
+		if (islower((unsigned char)c) || c == MAP_CITY || c == 'X') {
 			if (obj->func < 0) {
 				obj->func = NOFUNC; /* awaken */
 			}
