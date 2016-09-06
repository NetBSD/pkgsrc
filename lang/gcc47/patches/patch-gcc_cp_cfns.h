$NetBSD: patch-gcc_cp_cfns.h,v 1.1 2016/09/06 06:45:32 maya Exp $

cfns: fix mismatch in gnu_inline attributes
https://gcc.gnu.org/ml/gcc-patches/2015-08/msg00375.html

fixes build of using gcc5.

--- gcc/cp/cfns.h.orig	2009-04-21 19:03:23.000000000 +0000
+++ gcc/cp/cfns.h
@@ -54,6 +54,9 @@ static unsigned int hash (const char *, 
 #ifdef __GNUC__
 __inline
 #endif
+#ifdef __GNUC_STDC_INLINE__
+__attribute__ ((__gnu_inline__))
+#endif
 const char * libc_name_p (const char *, unsigned int);
 /* maximum key range = 391, duplicates = 0 */
 
