$NetBSD: patch-libcult-1.4.2_cult_mm_shptr.hxx,v 1.1 2013/03/24 16:58:28 joerg Exp $

--- libcult-1.4.2/cult/mm/shptr.hxx.orig	2013-03-23 19:44:25.000000000 +0000
+++ libcult-1.4.2/cult/mm/shptr.hxx
@@ -45,7 +45,7 @@ namespace Cult
       Shptr&
       operator= (Shptr const& ap)
       {
-        assign (ap);
+        this->assign (ap);
         return *this;
       }
 
@@ -53,7 +53,7 @@ namespace Cult
       Shptr&
       operator= (Shptr<Y> const& ap)
       {
-        assign (ap);
+        this->assign (ap);
         return *this;
       }
 
