$NetBSD: patch-src_includes_Ref.h,v 1.1 2012/12/20 21:48:15 joerg Exp $

--- src/includes/Ref.h.orig	2012-12-20 17:44:52.000000000 +0000
+++ src/includes/Ref.h
@@ -189,7 +189,7 @@ public:
 
   CRef<T> &operator=(const CRef<T> &other)
   {
-    assign(other);
+    this->assign(other);
     return *this;
   }
 
@@ -245,7 +245,7 @@ public:
 
   Ref<T> &operator=(const Ref<T> &other)
   {
-    assign(other);
+    this->assign(other);
     return *this;
   }
 
