$NetBSD: patch-boost_math_tools_promotion.hpp,v 1.1 2021/11/30 16:57:25 adam Exp $

Remove the guard; long double should be allowed as a type, even when
long double math functions are not present. Allows py-scipy to build.

--- boost/math/tools/promotion.hpp.orig	2021-11-30 14:39:04.000000000 +0000
+++ boost/math/tools/promotion.hpp
@@ -127,12 +127,6 @@ namespace boost
             >::type
          >::type;
 
-#ifdef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
-         //
-         // Guard against use of long double if it's not supported:
-         //
-         static_assert((0 == std::is_same<type, long double>::value), "Sorry, but this platform does not have sufficient long double support for the special functions to be reliably implemented.");
-#endif
       };
 
       //
