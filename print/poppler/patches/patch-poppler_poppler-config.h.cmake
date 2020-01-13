$NetBSD: patch-poppler_poppler-config.h.cmake,v 1.1 2020/01/13 00:57:17 joerg Exp $

--- poppler/poppler-config.h.cmake.orig	2020-01-13 00:10:29.414712344 +0000
+++ poppler/poppler-config.h.cmake
@@ -139,7 +139,11 @@
 //------------------------------------------------------------------------
 
 #if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
-#include <cstdio> // __MINGW_PRINTF_FORMAT is defined in the mingw stdio.h
+#  if __cplusplus
+#  include <cstdio> // __MINGW_PRINTF_FORMAT is defined in the mingw stdio.h
+#  else
+#  include <stdio.h>
+#  endif
 #ifdef __MINGW_PRINTF_FORMAT
 #define GCC_PRINTF_FORMAT(fmt_index, va_index) \
 	__attribute__((__format__(__MINGW_PRINTF_FORMAT, fmt_index, va_index)))
