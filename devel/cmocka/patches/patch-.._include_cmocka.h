$NetBSD: patch-.._include_cmocka.h,v 1.1 2015/03/31 15:13:06 joerg Exp $

--- ../include/cmocka.h.orig	2015-03-25 16:04:39.000000000 +0000
+++ ../include/cmocka.h
@@ -100,6 +100,11 @@ typedef uintmax_t LargestIntegralType;
     ((LargestIntegralType)(value))
 
 /* Smallest integral type capable of holding a pointer. */
+#if (__STDC_VERSION__ - 0 >= 199901L) && !defined(_UINTPTR_T) && !defined(_UINTPTR_T_DEFINED)
+# include <stdint.h>
+# define _UINTPTR_T
+# define _UINTPTR_T_DEFINED
+#endif
 #if !defined(_UINTPTR_T) && !defined(_UINTPTR_T_DEFINED)
 # if defined(_WIN32)
     /* WIN32 is an ILP32 platform */
