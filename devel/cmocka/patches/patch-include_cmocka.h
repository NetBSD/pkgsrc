$NetBSD: patch-include_cmocka.h,v 1.3 2025/07/23 08:09:09 pin Exp $

C99 fix.

--- include/cmocka.h.orig	2025-07-23 07:24:12.915739467 +0000
+++ include/cmocka.h
@@ -121,6 +121,11 @@ typedef uintmax_t LargestIntegralType;
     ((LargestIntegralType)(value))
 
 /* Smallest integral type capable of holding a pointer. */
+#if (__STDC_VERSION__ - 0 >= 199901L) && !defined(_UINTPTR_T) && !defined(_UINTPTR_T_DEFINED)
+# include <stdint.h>
+# define _UINTPTR_T
+# define _UINTPTR_T_DEFINED
+#endif
 #if !defined(_UINTPTR_T) && !defined(_UINTPTR_T_DEFINED) && !defined(HAVE_UINTPTR_T) && !defined(__UINTPTR_TYPE__)
 # if defined(_WIN32)
     /* WIN32 is an ILP32 platform */
