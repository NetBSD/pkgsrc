$NetBSD: patch-libkleo_kleo_stl_util.h,v 1.1 2014/11/13 19:19:08 markd Exp $

Work around: Parse error at "BOOST_JOIN"

--- libkleo/kleo/stl_util.h.orig	2014-11-12 07:57:34.000000000 +0000
+++ libkleo/kleo/stl_util.h
@@ -22,7 +22,9 @@
 #ifndef __KDTOOLSCORE_STL_UTIL_H__
 #define __KDTOOLSCORE_STL_UTIL_H__
 
+#ifndef Q_MOC_RUN
 #include <boost/range.hpp>
+#endif
 #include <boost/iterator/filter_iterator.hpp>
 #include <boost/iterator/transform_iterator.hpp>
 #include <boost/call_traits.hpp>
