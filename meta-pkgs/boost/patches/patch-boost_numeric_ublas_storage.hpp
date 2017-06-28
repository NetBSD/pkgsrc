$NetBSD: patch-boost_numeric_ublas_storage.hpp,v 1.2 2017/06/28 08:27:00 joerg Exp $

--- boost/numeric/ublas/storage.hpp.orig	2017-06-27 09:07:20.588660202 +0000
+++ boost/numeric/ublas/storage.hpp
@@ -26,6 +26,8 @@
 #include <boost/numeric/ublas/traits.hpp>
 #include <boost/numeric/ublas/detail/iterator.hpp>
 
+#include <boost/serialization/array_wrapper.hpp>
+
 
 namespace boost { namespace numeric { namespace ublas {
 
