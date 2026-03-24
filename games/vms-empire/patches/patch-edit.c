$NetBSD: patch-edit.c,v 1.3 2026/03/24 12:46:06 wiz Exp $

Fix ctype(3) functions usage.

--- edit.c.orig	2026-03-24 12:40:47.000000000 +0000
+++ edit.c
@@ -148,7 +148,7 @@ char e_cursor(loc_t *edit_cursor) {
 		e = getch();
 	}
 	(void)nocrmode(); /* reset terminal */
-	return toupper(e);
+	return toupper((unsigned char)e);
 }
 
 /*
@@ -306,7 +306,7 @@ void e_stasis(loc_t loc) {
 static char dirs[] = "WEDCXZAQ";
 
 void e_stasis(loc_t loc) {
-	if (!isupper(game.user_map[loc].contents)) {
+	if (!isupper((unsigned char)game.user_map[loc].contents)) {
 		huh(); /* no object here */
 	} else if (game.user_map[loc].contents == 'X') {
 		huh();
@@ -422,7 +422,7 @@ void e_move(loc_t *path_start, loc_t loc) {
 */
 
 void e_move(loc_t *path_start, loc_t loc) {
-	if (!isupper(game.user_map[loc].contents)) {
+	if (!isupper((unsigned char)game.user_map[loc].contents)) {
 		huh(); /* nothing there? */
 	} else if (game.user_map[loc].contents == 'X') {
 		huh(); /* enemy city? */
