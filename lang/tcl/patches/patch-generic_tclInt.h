$NetBSD: patch-generic_tclInt.h,v 1.3 2020/04/16 17:07:07 adam Exp $

--- generic/tclInt.h.orig	2019-11-13 17:57:08.000000000 +0000
+++ generic/tclInt.h
@@ -38,16 +38,8 @@
 #include <stdio.h>
 
 #include <ctype.h>
-#ifdef NO_STDLIB_H
-#   include "../compat/stdlib.h"
-#else
 #   include <stdlib.h>
-#endif
-#ifdef NO_STRING_H
-#include "../compat/string.h"
-#else
 #include <string.h>
-#endif
 #if defined(STDC_HEADERS) || defined(__STDC__) || defined(__C99__FUNC__) \
      || defined(__cplusplus) || defined(_MSC_VER) || defined(__ICC)
 #include <stddef.h>
