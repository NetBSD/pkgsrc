$NetBSD: patch-include_windef.h,v 1.1 2015/02/09 13:30:44 adam Exp $

Clang does not have __builtin_ms_va_list.
See http://reviews.llvm.org/D1622?id=4152

--- include/windef.h.orig	2015-01-20 09:29:53.000000000 +0000
+++ include/windef.h
@@ -85,7 +85,7 @@ extern "C" {
 #endif /* __cdecl */
 
 #ifndef __ms_va_list
-# if defined(__x86_64__) && defined (__GNUC__)
+# if defined(__x86_64__) && defined(__GNUC__) && !defined(__clang__)
 #  define __ms_va_list __builtin_ms_va_list
 #  define __ms_va_start(list,arg) __builtin_ms_va_start(list,arg)
 #  define __ms_va_end(list) __builtin_ms_va_end(list)
