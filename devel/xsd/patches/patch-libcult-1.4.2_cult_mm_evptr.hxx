$NetBSD: patch-libcult-1.4.2_cult_mm_evptr.hxx,v 1.1 2013/03/24 16:58:28 joerg Exp $

--- libcult-1.4.2/cult/mm/evptr.hxx.orig	2013-03-23 19:36:25.000000000 +0000
+++ libcult-1.4.2/cult/mm/evptr.hxx
@@ -70,7 +70,7 @@ namespace Cult
       Evptr&
       operator= (Evptr const& ep)
       {
-        assign (ep.cp_ ? ep.cp_ : ep.p_, ep.c_);
+        this->assign (ep.cp_ ? ep.cp_ : ep.p_, ep.c_);
 
         return *this;
       }
@@ -79,7 +79,7 @@ namespace Cult
       Evptr&
       operator= (Evptr<Y> const& ep)
       {
-        assign (ep.cp_ ? ep.cp_ : ep.p_, ep.c_);
+        this->assign (ep.cp_ ? ep.cp_ : ep.p_, ep.c_);
 
         return *this;
       }
