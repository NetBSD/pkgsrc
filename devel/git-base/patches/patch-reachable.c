$NetBSD: patch-reachable.c,v 1.1.2.2 2016/03/22 18:55:23 bsiegert Exp $

CVE-2016-2324 via Debian
https://security-tracker.debian.org/tracker/CVE-2016-2324
https://github.com/git/git/commit/9831e92bfa833ee9c0ce464bbc2f941ae6c2698d

--- reachable.c.orig	2016-03-10 22:11:15.000000000 +0000
+++ reachable.c
@@ -43,15 +43,14 @@ static int add_one_ref(const char *path,
  * The traversal will have already marked us as SEEN, so we
  * only need to handle any progress reporting here.
  */
-static void mark_object(struct object *obj, const struct name_path *path,
-			const char *name, void *data)
+static void mark_object(struct object *obj, const char *name, void *data)
 {
 	update_progress(data);
 }
 
 static void mark_commit(struct commit *c, void *data)
 {
-	mark_object(&c->object, NULL, NULL, data);
+	mark_object(&c->object, NULL, data);
 }
 
 struct recent_data {
