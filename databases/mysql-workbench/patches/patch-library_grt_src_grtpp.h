$NetBSD: patch-library_grt_src_grtpp.h,v 1.1 2015/07/07 11:45:52 joerg Exp $

--- library/grt/src/grtpp.h.orig	2015-06-28 17:13:25.000000000 +0000
+++ library/grt/src/grtpp.h
@@ -855,8 +855,6 @@ namespace grt {
 
     IterType iter;
     
-    TypedListConstIterator() : iter(0) {}
-
     TypedListConstIterator(const TypedListConstIterator &content) : iter(content.iter) {}
     
     TypedListConstIterator(const IterType &content)
@@ -895,6 +893,9 @@ namespace grt {
       ++iter;
       return temp;
     }
+
+    private:
+      TypedListConstIterator() {}
   };
 
   template<class C>
@@ -909,8 +910,6 @@ namespace grt {
     
     IterType iter;
     
-    TypedListConstReverseIterator() {}
-    
     TypedListConstReverseIterator(const TypedListConstReverseIterator &content) : iter(content.iter) {}
     
     TypedListConstReverseIterator(const IterType &content)
@@ -949,6 +948,9 @@ namespace grt {
       ++iter;
       return temp;
     }
+
+    private:
+      TypedListConstReverseIterator() {}
   };
   
   
