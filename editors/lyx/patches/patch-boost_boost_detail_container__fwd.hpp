$NetBSD: patch-boost_boost_detail_container__fwd.hpp,v 1.1 2013/05/09 13:56:58 joerg Exp $

--- boost/boost/detail/container_fwd.hpp.orig	2013-05-09 11:28:09.000000000 +0000
+++ boost/boost/detail/container_fwd.hpp
@@ -16,7 +16,8 @@
 #if ((defined(__GLIBCPP__) || defined(__GLIBCXX__)) && defined(_GLIBCXX_DEBUG)) \
     || BOOST_WORKAROUND(__BORLANDC__, > 0x551) \
     || BOOST_WORKAROUND(__DMC__, BOOST_TESTED_AT(0x842)) \
-    || (defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION))
+    || (defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)) \
+    || defined(_LIBCPP_VERSION)
 
 #include <deque>
 #include <list>
