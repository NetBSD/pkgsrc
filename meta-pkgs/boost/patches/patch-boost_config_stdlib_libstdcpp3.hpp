$NetBSD: patch-boost_config_stdlib_libstdcpp3.hpp,v 1.2 2015/04/17 14:04:47 adam Exp $

* Fix build under NetBSD with GCC 4.8.3 in base.
  GCC 4.8.3 does not define _GLIBCXX_HAVE_GTHR_DEFAULT
  in /usr/include/g++/bits/c++config.h.

--- boost/config/stdlib/libstdcpp3.hpp.orig	2015-03-24 18:27:48.000000000 +0000
+++ boost/config/stdlib/libstdcpp3.hpp
@@ -37,6 +37,7 @@
         || defined(_GLIBCXX_HAS_GTHREADS) \
         || defined(_WIN32) \
         || defined(_AIX) \
+        || defined(__NetBSD__) \
         || defined(__HAIKU__)
       //
       // If the std lib has thread support turned on, then turn it on in Boost
