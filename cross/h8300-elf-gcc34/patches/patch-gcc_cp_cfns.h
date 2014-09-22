$NetBSD: patch-gcc_cp_cfns.h,v 1.1 2014/09/22 11:51:14 joerg Exp $

--- gcc/cp/cfns.h.orig	2014-09-22 10:57:39.000000000 +0000
+++ gcc/cp/cfns.h
@@ -34,9 +34,6 @@
 __inline
 #endif
 static unsigned int hash (const char *, unsigned int);
-#ifdef __GNUC__
-__inline
-#endif
 const char * libc_name_p (const char *, unsigned int);
 /* maximum key range = 391, duplicates = 0 */
 
@@ -105,9 +102,6 @@ hash (register const char *str, register
   return hval + asso_values[(unsigned char)str[len - 1]];
 }
 
-#ifdef __GNUC__
-__inline
-#endif
 const char *
 libc_name_p (register const char *str, register unsigned int len)
 {
