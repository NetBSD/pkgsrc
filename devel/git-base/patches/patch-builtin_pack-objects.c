$NetBSD: patch-builtin_pack-objects.c,v 1.1.2.2 2016/03/22 18:55:23 bsiegert Exp $

CVE-2016-2324 via Debian
https://security-tracker.debian.org/tracker/CVE-2016-2324
https://github.com/git/git/commit/9831e92bfa833ee9c0ce464bbc2f941ae6c2698d

--- builtin/pack-objects.c.orig	2016-03-10 22:11:15.000000000 +0000
+++ builtin/pack-objects.c
@@ -2285,21 +2285,11 @@ static void show_commit(struct commit *c
 		index_commit_for_bitmap(commit);
 }
 
-static void show_object(struct object *obj,
-			const struct name_path *path, const char *last,
-			void *data)
+static void show_object(struct object *obj, const char *name, void *data)
 {
-	char *name = path_name(path, last);
-
 	add_preferred_base_object(name);
 	add_object_entry(obj->oid.hash, obj->type, name, 0);
 	obj->flags |= OBJECT_ADDED;
-
-	/*
-	 * We will have generated the hash from the name,
-	 * but not saved a pointer to it - we can free it
-	 */
-	free((char *)name);
 }
 
 static void show_edge(struct commit *commit)
@@ -2481,8 +2471,7 @@ static int get_object_list_from_bitmap(s
 }
 
 static void record_recent_object(struct object *obj,
-				 const struct name_path *path,
-				 const char *last,
+				 const char *name,
 				 void *data)
 {
 	sha1_array_append(&recent_objects, obj->oid.hash);
