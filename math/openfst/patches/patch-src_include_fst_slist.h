$NetBSD: patch-src_include_fst_slist.h,v 1.1 2013/05/06 14:53:17 joerg Exp $

--- src/include/fst/slist.h.orig	2013-05-03 17:49:34.000000000 +0000
+++ src/include/fst/slist.h
@@ -47,7 +47,7 @@ template <typename T> class slist : publ
 
   iterator erase_after(iterator pos) {
     iterator npos = pos;
-    erase(++npos);
+    this->erase(++npos);
     return pos;
   }
 };
