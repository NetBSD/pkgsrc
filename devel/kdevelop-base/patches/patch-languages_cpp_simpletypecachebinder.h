$NetBSD: patch-languages_cpp_simpletypecachebinder.h,v 1.1 2012/06/25 11:21:35 joerg Exp $

--- languages/cpp/simpletypecachebinder.h.orig	2012-06-18 23:20:34.000000000 +0000
+++ languages/cpp/simpletypecachebinder.h
@@ -37,7 +37,7 @@ class SimpleTypeCacheBinder : public Bas
   template <class InitType1, class InitType2>
   SimpleTypeCacheBinder( InitType1 t, InitType2 t2 ) : Base ( t, t2 ), m_haveBasesCache( false ), secondaryActive( true ), primaryActive( true ) {}
 
-  using Base::LocateMode;
+  using typename Base::LocateMode;
 
   struct LocateDesc {
    TypeDesc mname;
