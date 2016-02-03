$NetBSD: patch-include_hashtables.h,v 1.2 2016/02/03 19:34:33 bouyer Exp $

--- include/hashtables.h.orig	2015-12-11 17:59:12.000000000 +0100
+++ include/hashtables.h	2015-12-11 17:59:18.000000000 +0100
@@ -48,7 +48,7 @@
 #elif 1     // boost::unordered_map
 
 // fix a compile bug at line 97 of boost/detail/container_fwd.hpp
-#define BOOST_DETAIL_TEST_FORCE_CONTAINER_FWD
+// #define BOOST_DETAIL_TEST_FORCE_CONTAINER_FWD
 
 #include <boost/unordered_map.hpp>
 
