$NetBSD: patch-girara_macros.h,v 1.1 2024/08/10 07:49:42 adam Exp $

pragma GCC diagnostic only acts on some lines.
See http://gcc.gnu.org/bugzilla/show_bug.cgi?id=52116

--- girara/macros.h.orig	2024-05-01 21:25:02.000000000 +0000
+++ girara/macros.h
@@ -72,7 +72,7 @@
 #endif
 
 #ifndef GIRARA_DO_PRAGMA
-#if defined(__GNUC__) || defined(__clang__)
+#if defined(__clang__)
 #define GIRARA_DO_PRAGMA(x) _Pragma(#x)
 #else
 #define GIRARA_DO_PRAGMA(x)
