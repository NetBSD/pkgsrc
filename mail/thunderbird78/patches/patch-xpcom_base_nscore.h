$NetBSD: patch-xpcom_base_nscore.h,v 1.1 2023/02/05 08:32:24 he Exp $

--- xpcom/base/nscore.h.orig	2020-08-28 21:33:30.000000000 +0000
+++ xpcom/base/nscore.h
@@ -77,7 +77,7 @@
  *           NS_HIDDEN_(int) NS_FASTCALL func2(char *foo);
  */
 
-#if defined(__i386__) && defined(__GNUC__)
+#if defined(__i386__) && defined(__GNUC__) && !(defined(__clang__) && __clang_major__ == 3 && __clang_minor__ == 4 && __clang_patchlevel__ == 0)
 #  define NS_FASTCALL __attribute__((regparm(3), stdcall))
 #  define NS_CONSTRUCTOR_FASTCALL __attribute__((regparm(3), stdcall))
 #elif defined(XP_WIN) && !defined(_WIN64)
