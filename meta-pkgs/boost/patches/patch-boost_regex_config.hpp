$NetBSD: patch-boost_regex_config.hpp,v 1.1 2014/05/13 18:48:49 ryoon Exp $

* Fix OpenBSD build

--- boost/regex/config.hpp.orig	2012-07-16 08:38:23.000000000 +0000
+++ boost/regex/config.hpp
@@ -75,7 +75,7 @@
  * std::use_facet<std::ctype<wchar_t> >.is(std::ctype_base::lower|std::ctype_base::upper, L'a');
  * returns *false*.
  */
-#ifdef __GLIBCPP__
+#if defined(__GLIBCPP__) && !defined(__OpenBSD__)
 #  define BOOST_REGEX_BUGGY_CTYPE_FACET
 #endif
 
