$NetBSD: patch-gcc_testsuite_gcc.dg_format_format.h,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/testsuite/gcc.dg/format/format.h.orig	2008-03-20 08:24:42.000000000 +0000
+++ gcc/testsuite/gcc.dg/format/format.h
@@ -35,12 +35,14 @@
 #include <stdarg.h>
 #include <stddef.h>
 
+#ifndef _WINT_T_DEFINED_
 #ifndef _WINT_T
 #ifndef __WINT_TYPE__
 #define __WINT_TYPE__ unsigned int
 #endif
 typedef __WINT_TYPE__ wint_t;
 #endif
+#endif
 
 #ifdef _WIN64
 /* Kludges to get types corresponding to size_t and ptrdiff_t.  */
