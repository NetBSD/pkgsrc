$NetBSD: patch-boost_range_detail_any__iterator__interface.hpp,v 1.1 2025/09/27 06:54:04 adam Exp $

https://bugs.gentoo.org/955526

--- boost/range/detail/any_iterator_interface.hpp.orig	2025-09-25 16:58:41.016441197 +0000
+++ boost/range/detail/any_iterator_interface.hpp
@@ -13,6 +13,7 @@
 #include <boost/mpl/if.hpp>
 #include <boost/range/detail/any_iterator_buffer.hpp>
 #include <boost/iterator/iterator_categories.hpp>
+#include <boost/type_traits/add_const.hpp>
 #include <boost/type_traits/is_convertible.hpp>
 #include <boost/type_traits/is_reference.hpp>
 #include <boost/type_traits/remove_const.hpp>
