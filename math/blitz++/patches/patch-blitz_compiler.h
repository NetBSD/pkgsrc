$NetBSD: patch-blitz_compiler.h,v 1.1 2011/12/29 16:33:09 joerg Exp $

--- blitz/compiler.h.orig	2011-12-29 14:24:12.000000000 +0000
+++ blitz/compiler.h
@@ -114,27 +114,9 @@
     #error In <blitz/config.h>: Your compiler does not support enum computations.  You may have to rerun compiler/bzconfig.
 #endif
 
-#if defined(BZ_MATH_FN_IN_NAMESPACE_STD)
-  #define BZ_MATHFN_SCOPE(x) std::x
-#elif defined(BZ_HAVE_NAMESPACES)
-  #define BZ_MATHFN_SCOPE(x) ::x
-#else
-  #define BZ_MATHFN_SCOPE(x) x
-#endif
-
-#if defined(BZ_HAVE_COMPLEX_MATH_IN_NAMESPACE_STD)
-  #define BZ_CMATHFN_SCOPE(x) std::x
-#elif defined(BZ_HAVE_NAMESPACES)
-  #define BZ_CMATHFN_SCOPE(x) ::x
-#else
-  #define BZ_CMATHFN_SCOPE(x) x
-#endif
-
-#if defined(BZ_HAVE_NAMESPACES)
-  #define BZ_IEEEMATHFN_SCOPE(x) ::x
-#else
-  #define BZ_IEEEMATHFN_SCOPE(x) x
-#endif
+#define BZ_MATHFN_SCOPE(x) x
+#define BZ_CMATHFN_SCOPE(x) x
+#define BZ_IEEEMATHFN_SCOPE(x) x
 
 #if defined(BZ_HAVE_NAMESPACES)
   #define BZ_BLITZ_SCOPE(x) blitz::x
