$NetBSD: patch-list-objects.h,v 1.1.2.2 2016/03/22 18:55:23 bsiegert Exp $

CVE-2016-2324 via Debian
https://security-tracker.debian.org/tracker/CVE-2016-2324
https://github.com/git/git/commit/9831e92bfa833ee9c0ce464bbc2f941ae6c2698d

--- list-objects.h.orig	2016-03-10 22:11:15.000000000 +0000
+++ list-objects.h
@@ -2,7 +2,7 @@
 #define LIST_OBJECTS_H
 
 typedef void (*show_commit_fn)(struct commit *, void *);
-typedef void (*show_object_fn)(struct object *, const struct name_path *, const char *, void *);
+typedef void (*show_object_fn)(struct object *, const char *, void *);
 void traverse_commit_list(struct rev_info *, show_commit_fn, show_object_fn, void *);
 
 typedef void (*show_edge_fn)(struct commit *);
