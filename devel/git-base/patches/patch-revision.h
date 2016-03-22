$NetBSD: patch-revision.h,v 1.1.2.2 2016/03/22 18:55:23 bsiegert Exp $

CVE-2016-2324 via Debian
https://security-tracker.debian.org/tracker/CVE-2016-2324
https://github.com/git/git/commit/9831e92bfa833ee9c0ce464bbc2f941ae6c2698d

--- revision.h.orig	2016-03-10 22:11:15.000000000 +0000
+++ revision.h
@@ -257,16 +257,9 @@ extern void put_revision_mark(const stru
 extern void mark_parents_uninteresting(struct commit *commit);
 extern void mark_tree_uninteresting(struct tree *tree);
 
-struct name_path {
-	struct name_path *up;
-	int elem_len;
-	const char *elem;
-};
-
-char *path_name(const struct name_path *path, const char *name);
+char *path_name(struct strbuf *path, const char *name);
 
-extern void show_object_with_name(FILE *, struct object *,
-				  const struct name_path *, const char *);
+extern void show_object_with_name(FILE *, struct object *, const char *);
 
 extern void add_pending_object(struct rev_info *revs,
 			       struct object *obj, const char *name);
