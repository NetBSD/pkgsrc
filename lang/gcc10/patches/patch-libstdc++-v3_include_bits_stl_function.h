$NetBSD: patch-libstdc++-v3_include_bits_stl_function.h,v 1.1 2024/04/01 14:33:58 js Exp $

--- libstdc++-v3/include/bits/stl_function.h.orig	2023-07-07 07:08:22.000000000 +0000
+++ libstdc++-v3/include/bits/stl_function.h
@@ -60,6 +60,8 @@
 #include <bits/move.h>
 #endif
 
+#include <stdint.h>
+
 namespace std _GLIBCXX_VISIBILITY(default)
 {
 _GLIBCXX_BEGIN_NAMESPACE_VERSION
@@ -421,7 +423,7 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 #endif
 	  return __x > __y;
 #endif
-	return (__UINTPTR_TYPE__)__x > (__UINTPTR_TYPE__)__y;
+	return (uintptr_t)__x > (uintptr_t)__y;
       }
     };
 
@@ -440,7 +442,7 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 #endif
 	  return __x < __y;
 #endif
-	return (__UINTPTR_TYPE__)__x < (__UINTPTR_TYPE__)__y;
+	return (uintptr_t)__x < (uintptr_t)__y;
       }
     };
 
@@ -459,7 +461,7 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 #endif
 	  return __x >= __y;
 #endif
-	return (__UINTPTR_TYPE__)__x >= (__UINTPTR_TYPE__)__y;
+	return (uintptr_t)__x >= (uintptr_t)__y;
       }
     };
 
@@ -478,7 +480,7 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 #endif
 	  return __x <= __y;
 #endif
-	return (__UINTPTR_TYPE__)__x <= (__UINTPTR_TYPE__)__y;
+	return (uintptr_t)__x <= (uintptr_t)__y;
       }
     };
 
