$NetBSD: patch-aczsh.m4,v 1.1 2013/05/10 01:17:33 riastradh Exp $

Add a utility for compile tests to compare rlimit keys.

--- aczsh.m4.orig	2009-05-16 12:08:44.000000000 +0000
+++ aczsh.m4
@@ -688,3 +688,22 @@ if test $zsh_cv_have_$1 = yes; then
   AC_DEFINE(HAVE_$1)
 fi])
 
+dnl Check whether rlimit $1, e.g. AS, is the same as rlmit $3, e.g. VMEM.
+dnl $2 is lowercase $1, $4 is lowercase $3.
+AC_DEFUN(zsh_LIMITS_EQUAL,
+[AH_TEMPLATE([RLIMIT_]$1[_IS_]$3,
+[Define to 1 if RLIMIT_]$1[ and RLIMIT_]$3[ both exist and are equal.])
+AC_CACHE_CHECK([if RLIMIT_]$1[ and RLIMIT_]$3[ are the same],
+zsh_cv_rlimit_$2_is_$4,
+[AC_TRY_COMPILE([
+#include <sys/types.h>
+#ifdef HAVE_SYS_TIME_H
+#include <sys/time.h>
+#endif
+#include <sys/resource.h>],
+[static char x[(RLIMIT_$1 == RLIMIT_$3)? 1 : -1]],
+  zsh_cv_rlimit_$2_is_$4=yes,
+  zsh_cv_rlimit_$2_is_$4=no)])
+if test x$zsh_cv_rlimit_$2_is_$4 = xyes; then
+  AC_DEFINE(RLIMIT_$1_IS_$3)
+fi])
