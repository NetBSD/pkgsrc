$NetBSD: patch-gcc_system.h,v 1.2 2024/12/15 19:31:05 brook Exp $

  Building gcc against libc++, e.g., with clang, poisons the ctype macros
  due to including safe-ctype.h before including C++ standard headers such
  as <list>, <map>, etc.

  See https://gcc.gnu.org/bugzilla/show_bug.cgi?id=111632
  
--- gcc/system.h.orig	2018-02-16 09:05:35.000000000 +0000
+++ gcc/system.h
@@ -44,6 +44,9 @@ along with GCC; see the file COPYING3.
 #endif
 
 #include <stdio.h>
+#ifdef __cplusplus
+# include <cstdio>
+#endif
 
 /* Define a generic NULL if one hasn't already been defined.  */
 #ifndef NULL
@@ -194,27 +197,8 @@ extern int fprintf_unlocked (FILE *, con
 #undef fread_unlocked
 #undef fwrite_unlocked
 
-/* Include <string> before "safe-ctype.h" to avoid GCC poisoning
-   the ctype macros through safe-ctype.h */
-
-#ifdef __cplusplus
-#ifdef INCLUDE_STRING
-# include <string>
-#endif
-#endif
-
-/* There are an extraordinary number of issues with <ctype.h>.
-   The last straw is that it varies with the locale.  Use libiberty's
-   replacement instead.  */
-#include "safe-ctype.h"
-
-#include <sys/types.h>
-
-#include <errno.h>
-
-#if !defined (errno) && defined (HAVE_DECL_ERRNO) && !HAVE_DECL_ERRNO
-extern int errno;
-#endif
+/* Include C++ standard headers before "safe-ctype.h" to avoid GCC
+   poisoning the ctype macros through safe-ctype.h */
 
 #ifdef __cplusplus
 #if defined (INCLUDE_ALGORITHM) || !defined (HAVE_SWAP_IN_UTILITY)
@@ -229,6 +213,9 @@ extern int errno;
 #ifdef INCLUDE_SET
 # include <set>
 #endif
+#ifdef INCLUDE_STRING
+# include <string>
+#endif
 #ifdef INCLUDE_VECTOR
 # include <vector>
 #endif
@@ -237,6 +224,19 @@ extern int errno;
 # include <utility>
 #endif
 
+/* There are an extraordinary number of issues with <ctype.h>.
+   The last straw is that it varies with the locale.  Use libiberty's
+   replacement instead.  */
+#include "safe-ctype.h"
+
+#include <sys/types.h>
+
+#include <errno.h>
+
+#if !defined (errno) && defined (HAVE_DECL_ERRNO) && !HAVE_DECL_ERRNO
+extern int errno;
+#endif
+
 /* Some of glibc's string inlines cause warnings.  Plus we'd rather
    rely on (and therefore test) GCC's string builtins.  */
 #define __NO_STRING_INLINES
