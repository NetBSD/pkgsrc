$NetBSD: patch-src_init2.c,v 1.1 2020/01/24 13:33:33 pho Exp $

Directories that contain things like score files have to be placed
under ${VARBASE}, because ${PREFIX}/libdata is meant to be
read-only. This is pkgsrc-specific.

--- src/init2.c.orig	2020-01-23 15:49:35.185187295 +0000
+++ src/init2.c
@@ -139,16 +139,13 @@ void init_file_paths(char *path)
 	/*** Build the sub-directory names ***/
 
 	/* Build a path name */
-	strcpy(tail, "apex");
-	ANGBAND_DIR_APEX = string_make(path);
+	ANGBAND_DIR_APEX = string_make("@HENGBAND_VARDIR@/apex");
 
 	/* Build a path name */
-	strcpy(tail, "bone");
-	ANGBAND_DIR_BONE = string_make(path);
+	ANGBAND_DIR_BONE = string_make("@HENGBAND_VARDIR@/bone");
 
 	/* Build a path name */
-	strcpy(tail, "data");
-	ANGBAND_DIR_DATA = string_make(path);
+	ANGBAND_DIR_DATA = string_make("@HENGBAND_VARDIR@/data");
 
 	/* Build a path name */
 	strcpy(tail, "edit");
@@ -175,8 +172,7 @@ void init_file_paths(char *path)
 	ANGBAND_DIR_PREF = string_make(path);
 
 	/* Build a path name */
-	strcpy(tail, "save");
-	ANGBAND_DIR_SAVE = string_make(path);
+	ANGBAND_DIR_SAVE = string_make("@HENGBAND_VARDIR@/save");
 
 #ifdef PRIVATE_USER_PATH
 
