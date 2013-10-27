$NetBSD: patch-boost_archive_iterators_transform__width.hpp,v 1.1 2013/10/27 20:31:58 joerg Exp $

--- boost/archive/iterators/transform_width.hpp.orig	2013-10-27 13:52:06.000000000 +0000
+++ boost/archive/iterators/transform_width.hpp
@@ -30,6 +30,8 @@
 #include <boost/iterator/iterator_adaptor.hpp>
 #include <boost/iterator/iterator_traits.hpp>
 
+#include <algorithm> // std::min
+
 namespace boost { 
 namespace archive {
 namespace iterators {
