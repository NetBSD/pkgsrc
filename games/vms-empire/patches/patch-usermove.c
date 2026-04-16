$NetBSD: patch-usermove.c,v 1.4 2026/04/16 12:34:46 wiz Exp $

Fix ctype(3) functions usage.
https://gitlab.com/esr/vms-empire/-/work_items/6

--- usermove.c.orig	2026-04-16 12:16:09.000000000 +0000
+++ usermove.c
@@ -997,7 +997,7 @@ void user_dir_army(piece_info_t *obj, loc_t loc) {
 			ksend("Your army marched dutifully into the sea and "
 			      "drowned.\n");
 		} else { /* attack something at sea */
-			enemy_killed = islower(game.user_map[loc].contents);
+			enemy_killed = islower((unsigned char)game.user_map[loc].contents);
 			attack(obj, loc);
 
 			if (obj->hits > 0) /* ship won? */
@@ -1016,7 +1016,7 @@ void user_dir_army(piece_info_t *obj, loc_t loc) {
 		}
 	}
 
-	else if (isupper(game.user_map[loc].contents) &&
+	else if (isupper((unsigned char)game.user_map[loc].contents) &&
 	         game.user_map[loc].contents != 'X') { /* attacking self */
 		if (!getyn("Sir, those are our men!  Do you really want to "
 		           "attack them? ")) {
@@ -1044,7 +1044,7 @@ void user_dir_fighter(piece_info_t *obj, loc_t loc) {
 		      "Your fighter was shot down.");
 	}
 
-	else if (isupper(game.user_map[loc].contents)) {
+	else if (isupper((unsigned char)game.user_map[loc].contents)) {
 		if (!getyn("Sir, those are our men!  "
 		           "Do you really want to attack them? ")) {
 			return;
@@ -1092,7 +1092,7 @@ void user_dir_ship(piece_info_t *obj, loc_t loc) {
 			ksend("Your %s broke up on shore.",
 			      piece_attr[obj->type].name);
 		} else { /* attack something on shore */
-			enemy_killed = islower(game.user_map[loc].contents);
+			enemy_killed = islower((unsigned char)game.user_map[loc].contents);
 			attack(obj, loc);
 
 			if (obj->hits > 0) /* ship won? */
@@ -1113,7 +1113,7 @@ void user_dir_ship(piece_info_t *obj, loc_t loc) {
 		}
 	}
 
-	else if (isupper(game.user_map[loc].contents)) { /* attacking self */
+	else if (isupper((unsigned char)game.user_map[loc].contents)) { /* attacking self */
 		if (!getyn("Sir, those are our men!  Do you really want to "
 		           "attack them? ")) {
 			return;
@@ -1201,7 +1201,7 @@ bool awake(piece_info_t *obj) {
 		char c = game.user_map[loc].contents;
 		const piece_info_t *enemy = find_obj_at_loc(loc);
 
-		if ((islower(c) && (enemy == NULL || enemy->type != SATELLITE)) ||
+		if ((islower((unsigned char)c) && (enemy == NULL || enemy->type != SATELLITE)) ||
 		    c == MAP_CITY || c == 'X') {
 			if (obj->func < 0) {
 				obj->func = NOFUNC; /* awaken */
