$NetBSD: patch-.._gcc-3.1_gcc_cp_cfns.h,v 1.1 2013/03/28 21:19:02 joerg Exp $

--- ../gcc-3.1/gcc/cp/cfns.h.orig	2013-03-28 14:02:55.000000000 +0000
+++ ../gcc-3.1/gcc/cp/cfns.h
@@ -4,9 +4,6 @@
 __inline
 #endif
 static unsigned int hash PARAMS ((const char *, unsigned int));
-#ifdef __GNUC__
-__inline
-#endif
 const char * libc_name_p PARAMS ((const char *, unsigned int));
 /* maximum key range = 1020, duplicates = 1 */
 
@@ -69,9 +66,6 @@ hash (str, len)
   return hval + asso_values[(unsigned char)str[len - 1]];
 }
 
-#ifdef __GNUC__
-__inline
-#endif
 const char *
 libc_name_p (str, len)
      register const char *str;
