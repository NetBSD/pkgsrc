$NetBSD: patch-lib_stdbool.mini.h,v 1.1 2021/11/12 12:40:17 nia Exp $

Test for c99 default before using stdbool instead of testing for GCC 2.95.
PR pkg/56488: Solaris 10 compile issues, stdbool.h requires c99

--- lib/stdbool.mini.h.orig	2018-02-12 12:16:29.000000000 +0000
+++ lib/stdbool.mini.h
@@ -71,12 +71,7 @@
      It is know not to work with:
        - Sun C, on Solaris, if __C99FEATURES__ is defined but _STDC_C99 is not,
        - MIPSpro C 7.30, on IRIX.  */
-# if (__GNUC__ >= 3) \
-     || defined __INTEL_COMPILER \
-     || (_MSC_VER >= 1800) \
-     || (defined __SUNPRO_C && defined _STDC_C99) \
-     || (defined _AIX && !defined __GNUC__ && defined _ANSI_C_SOURCE) \
-     || defined __HP_cc
+# if __STDC_VERSION__ >= 199901L
    /* Assume the compiler has <stdbool.h>.  */
 #  include <stdbool.h>
 # else
