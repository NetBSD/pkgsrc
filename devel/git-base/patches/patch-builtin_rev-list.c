$NetBSD: patch-builtin_rev-list.c,v 1.1 2016/03/16 19:38:52 sevan Exp $

CVE-2016-2324 via Debian
https://security-tracker.debian.org/tracker/CVE-2016-2324
https://github.com/git/git/commit/9831e92bfa833ee9c0ce464bbc2f941ae6c2698d

--- builtin/rev-list.c.orig	2016-03-10 22:11:15.000000000 +0000
+++ builtin/rev-list.c
@@ -177,9 +177,7 @@ static void finish_commit(struct commit 
 	free_commit_buffer(commit);
 }
 
-static void finish_object(struct object *obj,
-			  const struct name_path *path, const char *name,
-			  void *cb_data)
+static void finish_object(struct object *obj, const char *name, void *cb_data)
 {
 	struct rev_list_info *info = cb_data;
 	if (obj->type == OBJ_BLOB && !has_object_file(&obj->oid))
@@ -188,15 +186,13 @@ static void finish_object(struct object 
 		parse_object(obj->oid.hash);
 }
 
-static void show_object(struct object *obj,
-			const struct name_path *path, const char *component,
-			void *cb_data)
+static void show_object(struct object *obj, const char *name, void *cb_data)
 {
 	struct rev_list_info *info = cb_data;
-	finish_object(obj, path, component, cb_data);
+	finish_object(obj, name, cb_data);
 	if (info->flags & REV_LIST_QUIET)
 		return;
-	show_object_with_name(stdout, obj, path, component);
+	show_object_with_name(stdout, obj, name);
 }
 
 static void show_edge(struct commit *commit)
