$NetBSD: patch-generic_tclInt.h,v 1.1 2012/08/21 21:31:47 marino Exp $

--- generic/tclInt.h.orig	2012-07-16 11:57:05.000000000 +0000
+++ generic/tclInt.h
@@ -38,21 +38,9 @@
 #include <stdio.h>
 
 #include <ctype.h>
-#ifdef NO_STDLIB_H
-#   include "../compat/stdlib.h"
-#else
-#   include <stdlib.h>
-#endif
-#ifdef NO_STRING_H
-#include "../compat/string.h"
-#else
+#include <stdlib.h>
 #include <string.h>
-#endif
-#ifdef STDC_HEADERS
 #include <stddef.h>
-#else
-typedef int ptrdiff_t;
-#endif
 
 /*
  * Ensure WORDS_BIGENDIAN is defined correctly:
