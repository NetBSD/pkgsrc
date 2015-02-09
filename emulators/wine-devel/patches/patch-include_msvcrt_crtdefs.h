$NetBSD: patch-include_msvcrt_crtdefs.h,v 1.1 2015/02/09 13:30:44 adam Exp $

--- include/msvcrt/crtdefs.h.orig	2015-01-20 11:09:23.000000000 +0000
+++ include/msvcrt/crtdefs.h
@@ -76,7 +76,7 @@
 #endif /* __cdecl */
 
 #ifndef __ms_va_list
-# if defined(__x86_64__) && defined (__GNUC__)
+# if defined(__x86_64__) && defined(__GNUC__) && !defined(__clang__)
 #  define __ms_va_list __builtin_ms_va_list
 #  define __ms_va_start(list,arg) __builtin_ms_va_start(list,arg)
 #  define __ms_va_end(list) __builtin_ms_va_end(list)
