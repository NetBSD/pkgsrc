$NetBSD: patch-gcc-4.6.4_gcc_cp_cfns.h,v 1.1 2020/08/07 14:09:01 mef Exp $

In file included from ../../gcc-4.6.4/gcc/cp/except.c:912:0:
cfns.gperf: At top level:
cfns.gperf:101:1: error: 'gnu_inline' attribute present on 'libc_name_p'
cfns.gperf:26:14: error: but not here

Found patch in Dragonfly DPorts 

--- gcc/cp/cfns.h.orig	2009-04-21 19:03:23 UTC
+++ gcc-4.6.4/gcc/cp/cfns.h
@@ -53,6 +53,9 @@ __inline
 static unsigned int hash (const char *, unsigned int);
 #ifdef __GNUC__
 __inline
+#ifdef __GNUC_STDC_INLINE__
+__attribute__ ((__gnu_inline__))
+#endif
 #endif
 const char * libc_name_p (const char *, unsigned int);
 /* maximum key range = 391, duplicates = 0 */
@@ -96,7 +99,7 @@ hash (register const char *str, register
       400, 400, 400, 400, 400, 400, 400, 400, 400, 400,
       400, 400, 400, 400, 400, 400, 400
     };
-  register int hval = len;
+  register int hval = (int) len;
 
   switch (hval)
     {
