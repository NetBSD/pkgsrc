$NetBSD: patch-include_hashtables.h,v 1.1 2014/02/21 20:17:03 joerg Exp $

--- include/hashtables.h.orig	2014-02-21 00:47:35.000000000 +0000
+++ include/hashtables.h
@@ -50,7 +50,7 @@ typedef std::unordered_map< std::string,
 #elif 1     // boost::unordered_map
 
 // fix a compile bug at line 97 of boost/detail/container_fwd.hpp
-#define BOOST_DETAIL_TEST_FORCE_CONTAINER_FWD
+//#define BOOST_DETAIL_TEST_FORCE_CONTAINER_FWD
 
 #include <boost/unordered_map.hpp>
 
