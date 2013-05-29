$NetBSD: patch-src_Dictionary.cpp,v 1.1 2013/05/29 13:20:22 joerg Exp $

What is the intention here?

--- src/Dictionary.cpp.orig	2013-04-28 13:27:28.000000000 +0000
+++ src/Dictionary.cpp
@@ -151,7 +151,7 @@ Dictionary::iterator Dictionary::Insert(
         _map[key] = clone;
         return _map.find(key);
     }
-    return iterator(NULL);
+    return _map.end();
 }
 
 void Dictionary::Remove(Node* node)
