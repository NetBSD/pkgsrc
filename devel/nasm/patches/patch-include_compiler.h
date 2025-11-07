$NetBSD: patch-include_compiler.h,v 1.1 2025/11/07 22:10:31 ryoon Exp $

* For NetBSD, do not use complicated trick.

--- include/compiler.h.orig	2025-10-11 06:44:05.000000000 +0000
+++ include/compiler.h
@@ -183,6 +183,7 @@ char * pure_func strrchrnul(const char *
 
 #if !defined(__cplusplus) || (__STDC_VERSION >= 202311L)
 /* C++ and C23 have bool, false, and true as proper keywords */
+#if !defined(__NetBSD__)
 # ifdef HAVE_STDBOOL_H
 /* If <stdbool.h> exists, include it explicitly to prevent it from
    begin included later, causing the "bool" macro to be defined. */
@@ -209,6 +210,11 @@ typedef enum bool { false, true } bool;
    argument and because bool was redefined as a typedef if it previously
    was defined as a macro (see above.) */
 # define bool(x) ((bool)!!(x))
+#else /* __NetBSD__ */
+#include <stdbool.h>
+#undef bool
+#define bool(x) ((bool)!!(x))
+#endif
 #endif
 
 /* Create a NULL pointer of the same type as the address of
