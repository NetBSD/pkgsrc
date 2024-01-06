$NetBSD: patch-include_cmocka.h,v 1.2 2024/01/06 09:07:07 pin Exp $

C99 fix.

--- include/cmocka.h.orig	2024-01-05 09:30:00.219203105 +0000
+++ include/cmocka.h
@@ -121,6 +121,11 @@ typedef uintmax_t LargestIntegralType;
     ((LargestIntegralType)(value))
 
 /* Smallest integral type capable of holding a pointer. */
+#if (__STDC_VERSION__ - 0 >= 199901L) && !defined(_UINTPTR_T) && !defined(_UINTPTR_T_DEFINED)
+# include <stdint.h>
+# define _UINTPTR_T
+# define _UINTPTR_T_DEFINED
+#endif
 #if !defined(_UINTPTR_T) && !defined(_UINTPTR_T_DEFINED) && !defined(HAVE_UINTPTR_T)
 # if defined(_WIN32)
     /* WIN32 is an ILP32 platform */
