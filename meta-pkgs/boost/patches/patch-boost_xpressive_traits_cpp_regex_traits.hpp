$NetBSD: patch-boost_xpressive_traits_cpp_regex_traits.hpp,v 1.1 2012/05/01 18:47:01 adam Exp $

Fix building with Clang.

--- boost/xpressive/traits/cpp_regex_traits.hpp.orig	2012-05-01 17:25:19.000000000 +0000
+++ boost/xpressive/traits/cpp_regex_traits.hpp
@@ -24,6 +24,7 @@
 #include <boost/assert.hpp>
 #include <boost/integer.hpp>
 #include <boost/mpl/assert.hpp>
+#include <boost/static_assert.hpp>
 #include <boost/detail/workaround.hpp>
 #include <boost/type_traits/is_same.hpp>
 #include <boost/xpressive/detail/detail_fwd.hpp>
@@ -89,7 +90,7 @@ namespace detail
     template<umaskex_t In, umaskex_t Out = highest_bit, bool Done = (0 == (Out & In))>
     struct unused_mask
     {
-        BOOST_MPL_ASSERT_RELATION(1, !=, Out);
+        BOOST_STATIC_ASSERT(1 != Out);
         BOOST_STATIC_CONSTANT(umaskex_t, value = (unused_mask<In, (Out >> 1)>::value));
     };
 
