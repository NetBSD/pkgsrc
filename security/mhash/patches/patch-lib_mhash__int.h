$NetBSD: patch-lib_mhash__int.h,v 1.1 2026/08/17 12:10:06 hubertf Exp $

Do not use unprototyped declarations for the keygen functions when
compiling as C23.

In C23 an empty parameter list means "(void)" rather than "unspecified
arguments", so these declarations conflict with the definitions in
keygen.c and the build fails with compilers defaulting to C23 (e.g.
clang on macOS).  The full prototypes are already present in the #else
branch.  Older language modes keep the previous behaviour.

--- lib/mhash_int.h~	2015-06-18 06:08:36.000000000 +0000
+++ lib/mhash_int.h
@@ -36,7 +36,14 @@
 
 /* Key generation functions */
 
+/*
+ * In C23 an empty parameter list means "(void)" rather than "unspecified
+ * arguments", so the unprototyped declarations below conflict with the
+ * definitions in keygen.c.  Use the full prototypes in that case.
+ */
+#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 202311L
 #define EMPTY_PROTOTYPES 1
+#endif
 
 #if defined(EMPTY_PROTOTYPES)
 
