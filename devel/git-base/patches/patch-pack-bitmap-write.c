$NetBSD: patch-pack-bitmap-write.c,v 1.1 2016/03/16 19:38:52 sevan Exp $

CVE-2016-2324 via Debian
https://security-tracker.debian.org/tracker/CVE-2016-2324
https://github.com/git/git/commit/9831e92bfa833ee9c0ce464bbc2f941ae6c2698d

--- pack-bitmap-write.c.orig	2016-03-10 22:11:15.000000000 +0000
+++ pack-bitmap-write.c
@@ -148,8 +148,7 @@ static uint32_t find_object_pos(const un
 	return entry->in_pack_pos;
 }
 
-static void show_object(struct object *object, const struct name_path *path,
-			const char *last, void *data)
+static void show_object(struct object *object, const char *name, void *data)
 {
 	struct bitmap *base = data;
 	bitmap_set(base, find_object_pos(object->oid.hash));
