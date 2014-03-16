$NetBSD: patch-boost_config_stdlib_libstdcpp3.hpp,v 1.1 2014/03/16 04:40:25 ryoon Exp $

* Fix build under NetBSD with GCC 4.8.3 in base.
  GCC 4.8.3 does not define _GLIBCXX_HAVE_GTHR_DEFAULT
  in /usr/include/g++/bits/c++config.h.

--- boost/config/stdlib/libstdcpp3.hpp.orig	2014-03-08 14:33:38.000000000 +0000
+++ boost/config/stdlib/libstdcpp3.hpp
@@ -36,7 +36,8 @@
         || defined(_GLIBCXX__PTHREADS) \
         || defined(_GLIBCXX_HAS_GTHREADS) \
         || defined(_WIN32) \
-        || defined(_AIX)
+        || defined(_AIX) \
+	|| defined(__NetBSD__)
       //
       // If the std lib has thread support turned on, then turn it on in Boost
       // as well.  We do this because some gcc-3.4 std lib headers define _REENTANT
