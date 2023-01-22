$NetBSD: patch-boost_math_tools_promotion.hpp,v 1.2 2023/01/22 16:24:29 ryoon Exp $

Remove the guard; long double should be allowed as a type, even when
long double math functions are not present. Allows py-scipy to build.

--- boost/math/tools/promotion.hpp.orig	2022-12-08 01:02:44.000000000 +0000
+++ boost/math/tools/promotion.hpp
@@ -133,12 +133,6 @@ namespace boost
             >::type
          >::type;
 
-#ifdef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
-         //
-         // Guard against use of long double if it's not supported:
-         //
-         static_assert((0 == std::is_same<type, long double>::value), "Sorry, but this platform does not have sufficient long double support for the special functions to be reliably implemented.");
-#endif
       };
 
       template <class T1, class T2=float, class T3=float, class T4=float, class T5=float, class T6=float>
