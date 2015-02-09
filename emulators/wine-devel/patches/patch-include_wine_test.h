$NetBSD: patch-include_wine_test.h,v 1.1 2015/02/09 13:30:44 adam Exp $

--- include/wine/test.h.orig	2015-01-20 09:39:59.000000000 +0000
+++ include/wine/test.h
@@ -85,7 +85,7 @@ static inline int winetest_strcmpW( cons
 #define START_TEST(name) void func_##name(void)
 #endif
 
-#if defined(__x86_64__) && defined(__GNUC__) && defined(__WINE_USE_MSVCRT)
+#if defined(__x86_64__) && defined(__GNUC__) && defined(__WINE_USE_MSVCRT) && !defined(__clang__)
 #define __winetest_cdecl __cdecl
 #define __winetest_va_list __builtin_ms_va_list
 #else
@@ -180,7 +180,7 @@ extern void __winetest_cdecl winetest_tr
 #include <stdio.h>
 #include <excpt.h>
 
-#if defined(__x86_64__) && defined(__GNUC__) && defined(__WINE_USE_MSVCRT)
+#if defined(__x86_64__) && defined(__GNUC__) && defined(__WINE_USE_MSVCRT) && !defined(__clang__)
 # define __winetest_va_start(list,arg) __builtin_ms_va_start(list,arg)
 # define __winetest_va_end(list) __builtin_ms_va_end(list)
 #else
