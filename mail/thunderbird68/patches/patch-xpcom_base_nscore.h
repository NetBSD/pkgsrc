$NetBSD: patch-xpcom_base_nscore.h,v 1.1 2020/09/03 20:22:26 ryoon Exp $

--- xpcom/base/nscore.h.orig	2019-09-09 23:43:45.000000000 +0000
+++ xpcom/base/nscore.h
@@ -76,7 +76,7 @@
  *           NS_HIDDEN_(int) NS_FASTCALL func2(char *foo);
  */
 
-#if defined(__i386__) && defined(__GNUC__)
+#if defined(__i386__) && defined(__GNUC__) && !(defined(__clang__) && __clang_major__ == 3 && __clang_minor__ == 4 && __clang_patchlevel__ == 0)
 #  define NS_FASTCALL __attribute__((regparm(3), stdcall))
 #  define NS_CONSTRUCTOR_FASTCALL __attribute__((regparm(3), stdcall))
 #elif defined(XP_WIN) && !defined(_WIN64)
