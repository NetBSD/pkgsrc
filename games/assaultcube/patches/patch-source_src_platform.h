$NetBSD: patch-source_src_platform.h,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/platform.h.orig	2013-10-22 18:57:19.000000000 +0000
+++ source/src/platform.h
@@ -2,14 +2,6 @@
     #ifdef _FORTIFY_SOURCE
         #undef _FORTIFY_SOURCE
     #endif
-
-    #define gamma __gamma
-#endif
-
-#include <math.h>
-
-#ifdef __GNUC__
-    #undef gamma
 #endif
 
 #include <string.h>
@@ -19,6 +11,7 @@
 #include <ctype.h>
 #include <time.h>
 #include <limits.h>
+#include <math.h>
 #ifdef __GNUC__
     #include <new>
     #include <signal.h>
