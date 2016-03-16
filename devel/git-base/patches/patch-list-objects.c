$NetBSD: patch-list-objects.c,v 1.1 2016/03/16 19:38:52 sevan Exp $

CVE-2016-2324 via Debian
https://security-tracker.debian.org/tracker/CVE-2016-2324
https://github.com/git/git/commit/9831e92bfa833ee9c0ce464bbc2f941ae6c2698d

--- list-objects.c.orig	2016-03-10 22:11:15.000000000 +0000
+++ list-objects.c
@@ -11,11 +11,12 @@
 static void process_blob(struct rev_info *revs,
 			 struct blob *blob,
 			 show_object_fn show,
-			 struct name_path *path,
+			 struct strbuf *path,
 			 const char *name,
 			 void *cb_data)
 {
 	struct object *obj = &blob->object;
+	size_t pathlen;
 
 	if (!revs->blob_objects)
 		return;
@@ -24,7 +25,11 @@ static void process_blob(struct rev_info
 	if (obj->flags & (UNINTERESTING | SEEN))
 		return;
 	obj->flags |= SEEN;
-	show(obj, path, name, cb_data);
+
+	pathlen = path->len;
+	strbuf_addstr(path, name);
+	show(obj, path->buf, cb_data);
+	strbuf_setlen(path, pathlen);
 }
 
 /*
@@ -52,7 +57,7 @@ static void process_blob(struct rev_info
 static void process_gitlink(struct rev_info *revs,
 			    const unsigned char *sha1,
 			    show_object_fn show,
-			    struct name_path *path,
+			    struct strbuf *path,
 			    const char *name,
 			    void *cb_data)
 {
@@ -62,7 +67,6 @@ static void process_gitlink(struct rev_i
 static void process_tree(struct rev_info *revs,
 			 struct tree *tree,
 			 show_object_fn show,
-			 struct name_path *path,
 			 struct strbuf *base,
 			 const char *name,
 			 void *cb_data)
@@ -70,7 +74,6 @@ static void process_tree(struct rev_info
 	struct object *obj = &tree->object;
 	struct tree_desc desc;
 	struct name_entry entry;
-	struct name_path me;
 	enum interesting match = revs->diffopt.pathspec.nr == 0 ?
 		all_entries_interesting: entry_not_interesting;
 	int baselen = base->len;
@@ -86,17 +89,12 @@ static void process_tree(struct rev_info
 			return;
 		die("bad tree object %s", oid_to_hex(&obj->oid));
 	}
+
 	obj->flags |= SEEN;
-	show(obj, path, name, cb_data);
-	me.up = path;
-	me.elem = name;
-	me.elem_len = strlen(name);
-
-	if (!match) {
-		strbuf_addstr(base, name);
-		if (base->len)
-			strbuf_addch(base, '/');
-	}
+	strbuf_addstr(base, name);
+	show(obj, base->buf, cb_data);
+	if (base->len)
+		strbuf_addch(base, '/');
 
 	init_tree_desc(&desc, tree->buffer, tree->size);
 
@@ -113,16 +111,16 @@ static void process_tree(struct rev_info
 		if (S_ISDIR(entry.mode))
 			process_tree(revs,
 				     lookup_tree(entry.sha1),
-				     show, &me, base, entry.path,
+				     show, base, entry.path,
 				     cb_data);
 		else if (S_ISGITLINK(entry.mode))
 			process_gitlink(revs, entry.sha1,
-					show, &me, entry.path,
+					show, base, entry.path,
 					cb_data);
 		else
 			process_blob(revs,
 				     lookup_blob(entry.sha1),
-				     show, &me, entry.path,
+				     show, base, entry.path,
 				     cb_data);
 	}
 	strbuf_setlen(base, baselen);
@@ -213,19 +211,19 @@ void traverse_commit_list(struct rev_inf
 			continue;
 		if (obj->type == OBJ_TAG) {
 			obj->flags |= SEEN;
-			show_object(obj, NULL, name, data);
+			show_object(obj, name, data);
 			continue;
 		}
 		if (!path)
 			path = "";
 		if (obj->type == OBJ_TREE) {
 			process_tree(revs, (struct tree *)obj, show_object,
-				     NULL, &base, path, data);
+				     &base, path, data);
 			continue;
 		}
 		if (obj->type == OBJ_BLOB) {
 			process_blob(revs, (struct blob *)obj, show_object,
-				     NULL, path, data);
+				     &base, path, data);
 			continue;
 		}
 		die("unknown pending object %s (%s)",
