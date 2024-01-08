$NetBSD: patch-m4_R.m4,v 1.5 2024/01/08 23:15:39 mef Exp $

Ensure tests for clog & co. fail, not just emit warning

--- m4/R.m4.orig	2023-07-30 07:15:01.000000000 +0900
+++ m4/R.m4	2024-01-09 08:02:14.228733733 +0900
@@ -226,7 +226,7 @@ if test -z "${texi2any_version_maj}" \
 elif test ${texi2any_version_maj} -gt 5; then
   r_cv_prog_texi2any_v5=yes
 elif test ${texi2any_version_maj} -lt 5 \
-     || test ${texi2any_version_min} -lt 1; then
+     || test ${texi2any_version_maj} = 5 -a ${texi2any_version_min} -lt 1; then
   r_cv_prog_texi2any_v5=no
 else
   r_cv_prog_texi2any_v5=yes
@@ -905,6 +905,9 @@ dnl Yes we need to double quote this ...
 
 extern void F77_SYMBOL(cftest)(int *a, int *b, double *x, double *y);
 
+int MAIN_ () { return 0; }
+int MAIN__ () { return 0; }
+
 int main () {
   int a[3] = {17, 237, 2000000000}, b[2], res = 0;
   double x[3] = {3.14159265, 123.456789, 2.3e34}, z[3];
@@ -1000,6 +1003,9 @@ typedef union {
 
 extern void F77_SYMBOL(cftest)(Rcomplex *x);
 
+int MAIN_ () { return 0; }
+int MAIN__ () { return 0; }
+
 int main () {
     Rcomplex z[3];
 
@@ -3858,9 +3864,9 @@ R_CHECK_FUNCS([cabs carg cexp clog csqrt
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
@@ -4682,9 +4688,9 @@ AC_CACHE_CHECK([if libcurl is >= 7.28.0]
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
