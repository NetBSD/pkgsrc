$NetBSD: patch-libsafeptr_sp__gc.h,v 1.1 2013/10/20 18:16:34 joerg Exp $

--- libsafeptr/sp_gc.h.orig	2013-10-15 15:29:52.000000000 +0000
+++ libsafeptr/sp_gc.h
@@ -382,8 +382,8 @@ namespace gc {
       return ret;
     }
 
-    aptr<T,V,G> operator++ (size_t s) { return (*this) += 1; }
-    aptr<T,V,G> operator-- (size_t s) { return (*this) -= 1; }
+    aptr<T,V,G> operator++ (int s) { return (*this) += 1; }
+    aptr<T,V,G> operator-- (int s) { return (*this) -= 1; }
 
     aptr<T,V,G> &operator+= (size_t s) 
     {
