$NetBSD: patch-boost_math_tools_promotion.hpp,v 1.4 2024/12/29 14:53:14 adam Exp $

Remove the guard; long double should be allowed as a type, even when
long double math functions are not present. Allows py-scipy to build.

--- boost/math/tools/promotion.hpp.orig	2024-12-05 00:53:33.000000000 +0000
+++ boost/math/tools/promotion.hpp
@@ -117,7 +117,7 @@ namespace boost
       template <class... Args>
       struct promote_args {
          using type = typename promote_args_permissive<Args...>::type;
-#if defined(BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
+#if 0
          //
          // Guard against use of long double if it's not supported:
          //
