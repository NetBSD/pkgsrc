$NetBSD: patch-src_mpfr.h,v 1.1 2022/11/27 03:17:13 mef Exp $

openscad-2021.01nb13 failed with math/mpfr-4.1.1
patch is supplied at  
 https://www.mpfr.org/mpfr-4.1.1/patch01
and this is one of piece for file to file from above
See:
 http://mail-index.netbsd.org/pkgsrc-users/2022/11/26/msg036540.html

--- mpfr-4.1.1-a/src/mpfr.h	2022-11-17 13:28:44.000000000 +0000
+++ ./src/mpfr.h	2022-11-23 11:45:26.840475978 +0000
@@ -27,7 +27,7 @@
 #define MPFR_VERSION_MAJOR 4
 #define MPFR_VERSION_MINOR 1
 #define MPFR_VERSION_PATCHLEVEL 1
-#define MPFR_VERSION_STRING "4.1.1"
+#define MPFR_VERSION_STRING "4.1.1-p1"
 
 /* User macros:
    MPFR_USE_FILE:        Define it to make MPFR define functions dealing
@@ -1027,7 +1027,7 @@
 #if __GNUC__ > 2 || __GNUC_MINOR__ >= 95
 #define mpfr_custom_get_kind(x)                                         \
   __extension__ ({                                                      \
-    mpfr_ptr _x = (x);                                                  \
+    mpfr_srcptr _x = (x);                                               \
     _x->_mpfr_exp >  __MPFR_EXP_INF ?                                   \
       (mpfr_int) MPFR_REGULAR_KIND * MPFR_SIGN (_x)                     \
       : _x->_mpfr_exp == __MPFR_EXP_INF ?                               \
