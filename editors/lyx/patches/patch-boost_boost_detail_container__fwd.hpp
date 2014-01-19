$NetBSD: patch-boost_boost_detail_container__fwd.hpp,v 1.2 2014/01/19 14:04:39 rumko Exp $

--- boost/boost/detail/container_fwd.hpp.orig	2013-04-29 15:58:30.000000000 +0000
+++ boost/boost/detail/container_fwd.hpp
@@ -18,7 +18,8 @@
         && (defined(_GLIBCXX_DEBUG) || defined(_GLIBCXX_PARALLEL))) \
     || BOOST_WORKAROUND(__BORLANDC__, > 0x551) \
     || BOOST_WORKAROUND(__DMC__, BOOST_TESTED_AT(0x842)) \
-    || (defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION))
+    || (defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)) \
+    || defined(_LIBCPP_VERSION)
 
 #include <deque>
 #include <list>
