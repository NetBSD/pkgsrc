$NetBSD: patch-gcc_cp_cfns.h,v 1.1 2012/12/19 12:49:16 joerg Exp $

--- gcc/cp/cfns.h.orig	2012-11-21 15:33:40.000000000 +0000
+++ gcc/cp/cfns.h
@@ -37,7 +37,7 @@ static unsigned int hash (const char *, 
 #ifdef __GNUC__
 __inline
 #endif
-const char * libc_name_p (const char *, unsigned int);
+static const char * libc_name_p (const char *, unsigned int);
 /* maximum key range = 391, duplicates = 0 */
 
 #ifdef __GNUC__
@@ -108,7 +108,7 @@ hash (register const char *str, register
 #ifdef __GNUC__
 __inline
 #endif
-const char *
+static const char *
 libc_name_p (register const char *str, register unsigned int len)
 {
   enum
