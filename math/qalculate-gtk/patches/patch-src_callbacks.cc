$NetBSD: patch-src_callbacks.cc,v 1.1 2013/05/12 19:16:01 joerg Exp $

--- src/callbacks.cc.orig	2013-05-12 18:04:10.000000000 +0000
+++ src/callbacks.cc
@@ -346,7 +346,7 @@ struct tree_struct {
 			it->sort();
 		}
 	}
-	bool operator < (tree_struct &s1) const {
+	bool operator < (const tree_struct &s1) const {
 		return item < s1.item;	
 	}	
 };
