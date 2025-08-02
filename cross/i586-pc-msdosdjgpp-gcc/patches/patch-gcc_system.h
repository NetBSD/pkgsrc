$NetBSD: patch-gcc_system.h,v 1.1 2025/08/02 19:00:21 js Exp $

--- gcc/system.h.orig	2025-08-02 15:58:31.986157456 +0000
+++ gcc/system.h
@@ -203,11 +203,6 @@ extern int fprintf_unlocked (FILE *, con
 #endif
 #endif
 
-/* There are an extraordinary number of issues with <ctype.h>.
-   The last straw is that it varies with the locale.  Use libiberty's
-   replacement instead.  */
-#include "safe-ctype.h"
-
 #include <sys/types.h>
 
 #include <errno.h>
@@ -245,6 +240,11 @@ extern int errno;
 # include <type_traits>
 #endif
 
+/* There are an extraordinary number of issues with <ctype.h>.
+   The last straw is that it varies with the locale.  Use libiberty's
+   replacement instead.  */
+#include "safe-ctype.h"
+
 /* Some of glibc's string inlines cause warnings.  Plus we'd rather
    rely on (and therefore test) GCC's string builtins.  */
 #define __NO_STRING_INLINES
