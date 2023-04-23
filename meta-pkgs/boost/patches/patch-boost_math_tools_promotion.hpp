$NetBSD: patch-boost_math_tools_promotion.hpp,v 1.3 2023/04/23 14:03:08 adam Exp $

Remove the guard; long double should be allowed as a type, even when
long double math functions are not present. Allows py-scipy to build.

--- boost/math/tools/promotion.hpp.orig	2023-04-21 10:05:48.000000000 +0000
+++ boost/math/tools/promotion.hpp
@@ -132,13 +132,6 @@ namespace boost
                >::type
             >::type
          >::type;
-
-#if defined(BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
-         //
-         // Guard against use of long double if it's not supported:
-         //
-         static_assert((0 == std::is_same<type, long double>::value), "Sorry, but this platform does not have sufficient long double support for the special functions to be reliably implemented.");
-#endif
       };
 
       template <class T1, class T2=float, class T3=float, class T4=float, class T5=float, class T6=float>
