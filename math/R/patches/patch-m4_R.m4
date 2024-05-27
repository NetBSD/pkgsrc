$NetBSD: patch-m4_R.m4,v 1.6 2024/05/27 20:45:14 mef Exp $

Ensure tests for clog & co. fail, not just emit warning

--- m4/R.m4.orig	2024-04-05 07:15:01.000000000 +0900
+++ m4/R.m4	2024-04-28 23:55:22.817246115 +0900
@@ -1,4 +1,4 @@
-### R.m4 -- extra macros for configuring R		-*- Autoconf -*-
+:### R.m4 -- extra macros for configuring R		-*- Autoconf -*-
 ###
 ### Copyright (C) 1998-2024 R Core Team
 ###
@@ -927,6 +927,9 @@ dnl Yes we need to double quote this ...
 
 extern void F77_SYMBOL(cftest)(int *a, int *b, double *x, double *y);
 
+int MAIN_ () { return 0; }
+int MAIN__ () { return 0; }
+
 int main (void) {
   int a[3] = {17, 237, 2000000000}, b[2], res = 0;
   double x[3] = {3.14159265, 123.456789, 2.3e34}, z[3];
@@ -1022,6 +1025,9 @@ typedef union {
 
 extern void F77_SYMBOL(cftest)(Rcomplex *x);
 
+int MAIN_ () { return 0; }
+int MAIN__ () { return 0; }
+
 int main (void) {
     Rcomplex z[3];
 
@@ -4081,9 +4087,9 @@ R_CHECK_FUNCS([cabs carg cexp clog csqrt
 AC_DEFUN([R_CHECK_DECL],
 [AS_VAR_PUSHDEF([ac_Symbol], [ac_cv_have_decl_$1])dnl
 AC_CACHE_CHECK([whether $1 exists and is declared], ac_Symbol,
-[AC_LINK_IFELSE([AC_LANG_PROGRAM([AC_INCLUDES_DEFAULT([$4])],
-[#ifndef $1
-  char *p = (char *) $1;
+[AC_LINK_IFELSE([AC_LANG_PROGRAM([AC_INCLUDES_DEFAULT([$4])
+#ifndef $1
+char *p = (char *) $1;
 #endif
 ])],
                    [AS_VAR_SET(ac_Symbol, yes)],
@@ -4905,9 +4911,9 @@ AC_CACHE_CHECK([if libcurl is >= 7.28.0]
 int main(void) 
 {
 #ifdef LIBCURL_VERSION_MAJOR
-#if LIBCURL_VERSION_MAJOR > 7
+#if LIBCURL_VERSION_MAJOR > 8
   exit(0);
-#elif LIBCURL_VERSION_MAJOR == 7 && LIBCURL_VERSION_MINOR >= 28
+#elif (LIBCURL_VERSION_MAJOR == 7 && LIBCURL_VERSION_MINOR >= 28) || LIBCURL_VERSION_MAJOR == 8
   exit(0);
 #else
   exit(1);
