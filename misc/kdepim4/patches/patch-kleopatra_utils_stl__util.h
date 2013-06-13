$NetBSD: patch-kleopatra_utils_stl__util.h,v 1.1 2013/06/13 14:29:37 joerg Exp $

--- kleopatra/utils/stl_util.h.orig	2013-06-12 20:35:45.000000000 +0000
+++ kleopatra/utils/stl_util.h
@@ -347,7 +347,7 @@ namespace kdtools {
     template <typename O, typename I, typename P>
     O copy_if( const I & i, P p ) {
         O o;
-        copy_if( boost::begin( i ), boost::end( i ), std::back_inserter( o ), p );
+        kdtools::copy_if( boost::begin( i ), boost::end( i ), std::back_inserter( o ), p );
         return o;
     }
 
@@ -390,7 +390,7 @@ namespace kdtools {
 
     template <typename C, typename P>
     bool none_of( const C & c, P p ) {
-        return none_of( boost::begin( c ), boost::end( c ), p );
+        return kdtools::none_of( boost::begin( c ), boost::end( c ), p );
     }
 
     template <typename C, typename B>
