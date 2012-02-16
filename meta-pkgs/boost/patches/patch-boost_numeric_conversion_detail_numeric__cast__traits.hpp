$NetBSD: patch-boost_numeric_conversion_detail_numeric__cast__traits.hpp,v 1.1 2012/02/16 18:24:12 hans Exp $

--- boost/numeric/conversion/detail/numeric_cast_traits.hpp.orig	2011-10-06 19:27:17.000000000 +0200
+++ boost/numeric/conversion/detail/numeric_cast_traits.hpp	2012-02-14 15:17:49.823827394 +0100
@@ -1,26 +1,33 @@
 //
-//! Copyright (c) 2011
+//! Copyright (c) 2011-2012
 //! Brandon Kohn
 //
 //  Distributed under the Boost Software License, Version 1.0. (See
 //  accompanying file LICENSE_1_0.txt or copy at
 //  http://www.boost.org/LICENSE_1_0.txt)
 //
+
 #if !defined(BOOST_NUMERIC_CONVERSION_DONT_USE_PREPROCESSED_FILES)
-    #include <boost/numeric/conversion/detail/preprocessed/numeric_cast_traits.hpp>
+
+    #include <boost/numeric/conversion/detail/preprocessed/numeric_cast_traits_common.hpp>
+
+        #if !defined(BOOST_NO_LONG_LONG)
+        #include <boost/numeric/conversion/detail/preprocessed/numeric_cast_traits_long_long.hpp>
+        #endif
+
 #else
 #if !BOOST_PP_IS_ITERATING
 
-    #include <boost/preprocessor/iteration/iterate.hpp>
     #include <boost/preprocessor/seq/elem.hpp>
     #include <boost/preprocessor/seq/size.hpp>
+    #include <boost/preprocessor/iteration/iterate.hpp>
 
     #if defined(__WAVE__) && defined(BOOST_NUMERIC_CONVERSION_CREATE_PREPROCESSED_FILES)
-        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/numeric_cast_traits.hpp")
+        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/numeric_cast_traits_common.hpp")
     #endif
 
 //
-//! Copyright (c) 2011
+//! Copyright (c) 2011-2012
 //! Brandon Kohn
 //
 //  Distributed under the Boost Software License, Version 1.0. (See
@@ -31,40 +38,28 @@
         #pragma wave option(preserve: 1)
     #endif
 
-    //! Generate the specializations for the built-in types.
-    #if !defined( BOOST_NO_INT64_T )    
-        #define BOOST_NUMERIC_CONVERSION_BUILTIN_TYPES() \
-                (char)                                   \
-                (boost::int8_t)                          \
-                (boost::uint8_t)                         \
-                (boost::int16_t)                         \
-                (boost::uint16_t)                        \
-                (boost::int32_t)                         \
-                (boost::uint32_t)                        \
-                (boost::int64_t)                         \
-                (boost::uint64_t)                        \
-                (float)                                  \
-                (double)                                 \
-                (long double)                            \
-        /***/
-    #else
-        #define BOOST_NUMERIC_CONVERSION_BUILTIN_TYPES() \
-                (char)                                   \
-                (boost::int8_t)                          \
-                (boost::uint8_t)                         \
-                (boost::int16_t)                         \
-                (boost::uint16_t)                        \
-                (boost::int32_t)                         \
-                (boost::uint32_t)                        \
-                (float)                                  \
-                (double)                                 \
-                (long double)                            \
-        /***/
-    #endif
+        //! These are the assumed common built in fundamental types (not typdefs/macros.)
+        #define BOOST_NUMERIC_CONVERSION_BASE_BUILTIN_TYPES() \
+         (char)                                            \
+         (signed char)                                     \
+         (unsigned char)                                   \
+         (short)                                           \
+         (unsigned short)                                  \
+         (int)                                             \
+         (unsigned int)                                    \
+         (long)                                            \
+         (unsigned long)                                   \
+         (float)                                           \
+         (double)                                          \
+         (long double)                                     \
+    /***/
+
+    #define BOOST_NUMERIC_CONVERSION_SEQ_A() BOOST_NUMERIC_CONVERSION_BASE_BUILTIN_TYPES()
+       #define BOOST_NUMERIC_CONVERSION_SEQ_B() BOOST_NUMERIC_CONVERSION_BASE_BUILTIN_TYPES()
 
 namespace boost { namespace numeric {
 
-    #define BOOST_PP_ITERATION_PARAMS_1 (3, (0, BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(BOOST_NUMERIC_CONVERSION_BUILTIN_TYPES())), <boost/numeric/conversion/detail/numeric_cast_traits.hpp>))
+    #define BOOST_PP_ITERATION_PARAMS_1 (3, (0, BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(BOOST_NUMERIC_CONVERSION_SEQ_A())), <boost/numeric/conversion/detail/numeric_cast_traits.hpp>))
     #include BOOST_PP_ITERATE()    
 
 }}//namespace boost::numeric;
@@ -72,12 +67,53 @@ namespace boost { namespace numeric {
     #if defined(__WAVE__) && defined(BOOST_NUMERIC_CONVERSION_CREATE_PREPROCESSED_FILES)
         #pragma wave option(output: null)
     #endif   
+       
+       #if ( defined(__WAVE__) && defined(BOOST_NUMERIC_CONVERSION_CREATE_PREPROCESSED_FILES) ) || !defined(BOOST_NO_LONG_LONG)
+       
+           #undef BOOST_NUMERIC_CONVERSION_SEQ_A
+           #undef BOOST_NUMERIC_CONVERSION_SEQ_B
+
+           #if defined(__WAVE__) && defined(BOOST_NUMERIC_CONVERSION_CREATE_PREPROCESSED_FILES)
+            #pragma wave option(preserve: 2, line: 0, output: "preprocessed/numeric_cast_traits_long_long.hpp")
+        #endif
+
+//
+//! Copyright (c) 2011-2012
+//! Brandon Kohn
+//
+//  Distributed under the Boost Software License, Version 1.0. (See
+//  accompanying file LICENSE_1_0.txt or copy at
+//  http://www.boost.org/LICENSE_1_0.txt)
+//
+        #if defined(__WAVE__) && defined(BOOST_NUMERIC_CONVERSION_CREATE_PREPROCESSED_FILES)
+            #pragma wave option(preserve: 1)
+        #endif
+
+namespace boost { namespace numeric {
+
+    #define BOOST_NUMERIC_CONVERSION_SEQ_A() BOOST_NUMERIC_CONVERSION_BASE_BUILTIN_TYPES()(long long)(unsigned long long)
+       #define BOOST_NUMERIC_CONVERSION_SEQ_B() (long long)(unsigned long long)
+    
+    #define BOOST_PP_ITERATION_PARAMS_1 (3, (0, BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(BOOST_NUMERIC_CONVERSION_SEQ_A())), <boost/numeric/conversion/detail/numeric_cast_traits.hpp>))
+    #include BOOST_PP_ITERATE()    
+
+}}//namespace boost::numeric;
+
+        #if defined(__WAVE__) && defined(BOOST_NUMERIC_CONVERSION_CREATE_PREPROCESSED_FILES)
+            #pragma wave option(output: null)
+        #endif   
+       
+       #endif
+               
+    #undef BOOST_NUMERIC_CONVERSION_BASE_BUILTIN_TYPES
+       #undef BOOST_NUMERIC_CONVERSION_SEQ_A
+       #undef BOOST_NUMERIC_CONVERSION_SEQ_B
+    
 
-    #undef BOOST_NUMERIC_CONVERSION_BUILTIN_TYPES
 
 #elif BOOST_PP_ITERATION_DEPTH() == 1
 
-   #define BOOST_PP_ITERATION_PARAMS_2 (3, (0, BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(BOOST_NUMERIC_CONVERSION_BUILTIN_TYPES())), <boost/numeric/conversion/detail/numeric_cast_traits.hpp>))
+   #define BOOST_PP_ITERATION_PARAMS_2 (3, (0, BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(BOOST_NUMERIC_CONVERSION_SEQ_B())), <boost/numeric/conversion/detail/numeric_cast_traits.hpp>))
    #include BOOST_PP_ITERATE()
        
 #elif BOOST_PP_ITERATION_DEPTH() == 2
@@ -89,13 +125,13 @@ namespace boost { namespace numeric {
     template <>
     struct numeric_cast_traits
         <
-            BOOST_PP_SEQ_ELEM(BOOST_NUMERIC_CONVERSION_A, BOOST_NUMERIC_CONVERSION_BUILTIN_TYPES())
-          , BOOST_PP_SEQ_ELEM(BOOST_NUMERIC_CONVERSION_B, BOOST_NUMERIC_CONVERSION_BUILTIN_TYPES())
+            BOOST_PP_SEQ_ELEM(BOOST_NUMERIC_CONVERSION_A, BOOST_NUMERIC_CONVERSION_SEQ_A())
+          , BOOST_PP_SEQ_ELEM(BOOST_NUMERIC_CONVERSION_B, BOOST_NUMERIC_CONVERSION_SEQ_B())
         >
     {
         typedef def_overflow_handler overflow_policy;
         typedef UseInternalRangeChecker range_checking_policy;
-        typedef Trunc<BOOST_PP_SEQ_ELEM(BOOST_NUMERIC_CONVERSION_B, BOOST_NUMERIC_CONVERSION_BUILTIN_TYPES())> rounding_policy;
+        typedef Trunc<BOOST_PP_SEQ_ELEM(BOOST_NUMERIC_CONVERSION_B, BOOST_NUMERIC_CONVERSION_SEQ_B())> rounding_policy;
     };     
 
     #undef BOOST_NUMERIC_CONVERSION_A
