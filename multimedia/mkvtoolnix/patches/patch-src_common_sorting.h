$NetBSD: patch-src_common_sorting.h,v 1.1 2024/04/30 09:07:29 adam Exp $

Fix build: std::result_of is deprecated in c++17 and removed in c++20.
https://gitlab.com/mbunkus/mkvtoolnix/-/issues/3695

--- src/common/sorting.h.orig	2024-04-30 06:42:03.310422049 +0000
+++ src/common/sorting.h
@@ -27,7 +27,7 @@ namespace mtx::sort {
 
 template<  typename Titer
          , typename Tcriterion_maker
-         , typename Tcriterion = typename std::result_of< Tcriterion_maker(typename std::iterator_traits<Titer>::value_type) >::type
+         , typename Tcriterion = typename boost::result_of< Tcriterion_maker(typename std::iterator_traits<Titer>::value_type) >::type
          , typename Tcomparator = std::less<Tcriterion>
          >
 void
