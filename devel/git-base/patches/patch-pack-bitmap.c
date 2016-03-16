$NetBSD: patch-pack-bitmap.c,v 1.1 2016/03/16 19:38:52 sevan Exp $

CVE-2016-2324 via Debian
https://security-tracker.debian.org/tracker/CVE-2016-2324
https://github.com/git/git/commit/9831e92bfa833ee9c0ce464bbc2f941ae6c2698d

--- pack-bitmap.c.orig	2016-03-10 22:11:15.000000000 +0000
+++ pack-bitmap.c
@@ -417,19 +417,15 @@ static int ext_index_add_object(struct o
 	return bitmap_pos + bitmap_git.pack->num_objects;
 }
 
-static void show_object(struct object *object, const struct name_path *path,
-			const char *last, void *data)
+static void show_object(struct object *object, const char *name, void *data)
 {
 	struct bitmap *base = data;
 	int bitmap_pos;
 
 	bitmap_pos = bitmap_position(object->oid.hash);
 
-	if (bitmap_pos < 0) {
-		char *name = path_name(path, last);
+	if (bitmap_pos < 0)
 		bitmap_pos = ext_index_add_object(object, name);
-		free(name);
-	}
 
 	bitmap_set(base, bitmap_pos);
 }
@@ -897,9 +893,8 @@ struct bitmap_test_data {
 	size_t seen;
 };
 
-static void test_show_object(struct object *object,
-			     const struct name_path *path,
-			     const char *last, void *data)
+static void test_show_object(struct object *object, const char *name,
+			     void *data)
 {
 	struct bitmap_test_data *tdata = data;
 	int bitmap_pos;
