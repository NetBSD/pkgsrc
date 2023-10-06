$NetBSD: patch-src_cinnabar-fast-import.c,v 1.1 2023/10/06 10:20:19 riastradh Exp $

https://github.com/glandium/git-cinnabar/issues/315
https://github.com/glandium/git-cinnabar/commit/d81234ae36a090477ce298342a871c8f341e8b7a

--- src/cinnabar-fast-import.c.orig	2023-07-09 20:08:20.000000000 +0000
+++ src/cinnabar-fast-import.c
@@ -1014,7 +1014,7 @@ const struct object_id *ensure_empty_tre
 	if (!oe) {
 		struct object_id hash;
 		struct strbuf buf = STRBUF_INIT;
-		store_object(OBJ_BLOB, &buf, NULL, &hash, 0);
+		store_object(OBJ_TREE, &buf, NULL, &hash, 0);
 		assert(oidcmp(&hash, &empty_tree) == 0);
 	}
 	return &empty_tree;
