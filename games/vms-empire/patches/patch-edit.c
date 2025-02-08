$NetBSD: patch-edit.c,v 1.2 2025/02/08 10:49:45 triaxx Exp $

Fix ctype(3) functions usage.

--- edit.c.orig	2024-02-11 16:53:28.000000000 +0000
+++ edit.c
@@ -305,7 +305,7 @@ Set object to move in a direction.
 static char dirs[] = "WEDCXZAQ";
 
 void e_stasis(loc_t loc) {
-	if (!isupper(game.user_map[loc].contents)) {
+	if (!isupper((unsigned char)game.user_map[loc].contents)) {
 		huh(); /* no object here */
 	} else if (game.user_map[loc].contents == 'X') {
 		huh();
@@ -421,7 +421,7 @@ Beginning of move to location.
 */
 
 void e_move(loc_t *path_start, loc_t loc) {
-	if (!isupper(game.user_map[loc].contents)) {
+	if (!isupper((unsigned char)game.user_map[loc].contents)) {
 		huh(); /* nothing there? */
 	} else if (game.user_map[loc].contents == 'X') {
 		huh(); /* enemy city? */
@@ -493,7 +493,7 @@ void e_piece_info(loc_t edit_cursor, cha
 	int type;
 	char *p;
 
-	ab = toupper(ab);
+	ab = toupper((unsigned char)ab);
 	p = strchr(type_chars, ab);
 	type = p - type_chars;
 
