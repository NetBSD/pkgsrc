$NetBSD: patch-http-push.c,v 1.1 2016/03/16 19:38:52 sevan Exp $

CVE-2016-2324 via Debian
https://security-tracker.debian.org/tracker/CVE-2016-2324
https://github.com/git/git/commit/9831e92bfa833ee9c0ce464bbc2f941ae6c2698d

--- http-push.c.orig	2016-03-10 22:11:15.000000000 +0000
+++ http-push.c
@@ -1277,9 +1277,7 @@ static struct object_list **add_one_obje
 }
 
 static struct object_list **process_blob(struct blob *blob,
-					 struct object_list **p,
-					 struct name_path *path,
-					 const char *name)
+					 struct object_list **p)
 {
 	struct object *obj = &blob->object;
 
@@ -1293,14 +1291,11 @@ static struct object_list **process_blob
 }
 
 static struct object_list **process_tree(struct tree *tree,
-					 struct object_list **p,
-					 struct name_path *path,
-					 const char *name)
+					 struct object_list **p)
 {
 	struct object *obj = &tree->object;
 	struct tree_desc desc;
 	struct name_entry entry;
-	struct name_path me;
 
 	obj->flags |= LOCAL;
 
@@ -1310,21 +1305,17 @@ static struct object_list **process_tree
 		die("bad tree object %s", oid_to_hex(&obj->oid));
 
 	obj->flags |= SEEN;
-	name = xstrdup(name);
 	p = add_one_object(obj, p);
-	me.up = path;
-	me.elem = name;
-	me.elem_len = strlen(name);
 
 	init_tree_desc(&desc, tree->buffer, tree->size);
 
 	while (tree_entry(&desc, &entry))
 		switch (object_type(entry.mode)) {
 		case OBJ_TREE:
-			p = process_tree(lookup_tree(entry.sha1), p, &me, name);
+			p = process_tree(lookup_tree(entry.sha1), p);
 			break;
 		case OBJ_BLOB:
-			p = process_blob(lookup_blob(entry.sha1), p, &me, name);
+			p = process_blob(lookup_blob(entry.sha1), p);
 			break;
 		default:
 			/* Subproject commit - not in this repository */
@@ -1343,7 +1334,7 @@ static int get_delta(struct rev_info *re
 	int count = 0;
 
 	while ((commit = get_revision(revs)) != NULL) {
-		p = process_tree(commit->tree, p, NULL, "");
+		p = process_tree(commit->tree, p);
 		commit->object.flags |= LOCAL;
 		if (!(commit->object.flags & UNINTERESTING))
 			count += add_send_request(&commit->object, lock);
@@ -1362,11 +1353,11 @@ static int get_delta(struct rev_info *re
 			continue;
 		}
 		if (obj->type == OBJ_TREE) {
-			p = process_tree((struct tree *)obj, p, NULL, name);
+			p = process_tree((struct tree *)obj, p);
 			continue;
 		}
 		if (obj->type == OBJ_BLOB) {
-			p = process_blob((struct blob *)obj, p, NULL, name);
+			p = process_blob((struct blob *)obj, p);
 			continue;
 		}
 		die("unknown pending object %s (%s)", oid_to_hex(&obj->oid), name);
