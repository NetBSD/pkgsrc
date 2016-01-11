$NetBSD: patch-edit.c,v 1.1 2016/01/11 19:37:43 leot Exp $

Fix ctype(3) functions usage.

--- edit.c.orig	2014-12-15 00:46:31.000000000 +0000
+++ edit.c
@@ -316,7 +316,7 @@ static char dirs[] = "WEDCXZAQ";
 void
 e_stasis(loc_t loc)
 {
-    if (!isupper (user_map[loc].contents))
+    if (!isupper ((unsigned char)user_map[loc].contents))
 	huh (); /* no object here */
     else if (user_map[loc].contents == 'X')
 	huh ();
@@ -437,7 +437,7 @@ Beginning of move to location.
 void
 e_move(loc_t *path_start, loc_t loc)
 {
-    if (!isupper(user_map[loc].contents)) huh (); /* nothing there? */
+    if (!isupper((unsigned char)user_map[loc].contents)) huh (); /* nothing there? */
     else if (user_map[loc].contents == 'X') huh (); /* enemy city? */
     else *path_start = loc;
 }
@@ -509,7 +509,7 @@ e_piece_info(loc_t edit_cursor, char ab)
     int type;
     char *p;
 
-    ab = toupper (ab);
+    ab = toupper ((unsigned char)ab);
     p = strchr (type_chars, ab);
     type = p - type_chars;
 
