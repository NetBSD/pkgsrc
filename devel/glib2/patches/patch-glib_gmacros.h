$NetBSD: patch-glib_gmacros.h,v 1.1 2019/12/06 14:36:58 nros Exp $
* on some compilers __STDC_VERSION__ is defined when using c++
  but _Static_assert is not available
--- glib/gmacros.h.orig	2019-12-06 12:21:18.948881370 +0000
+++ glib/gmacros.h
@@ -734,7 +734,7 @@
 #ifndef __GI_SCANNER__ /* The static assert macro really confuses the introspection parser */
 #define G_PASTE_ARGS(identifier1,identifier2) identifier1 ## identifier2
 #define G_PASTE(identifier1,identifier2)      G_PASTE_ARGS (identifier1, identifier2)
-#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
+#if defined(__STDC_VERSION__) && !defined(__cplusplus) && __STDC_VERSION__ >= 201112L
 #define G_STATIC_ASSERT(expr) _Static_assert (expr, "Expression evaluates to false")
 #elif (defined(__cplusplus) && __cplusplus >= 201103L) || \
       (defined(__cplusplus) && defined (_MSC_VER) && (_MSC_VER >= 1600)) || \
