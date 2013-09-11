$NetBSD: patch-include_ctlib.h,v 1.1 2013/09/11 16:11:44 jperkin Exp $

Disable symbol visibility on SunOS, causes strlen() issues.

--- include/ctlib.h.orig	2010-10-05 08:36:36.000000000 +0000
+++ include/ctlib.h
@@ -24,7 +24,7 @@
  * Internal (not part of the exposed API) prototypes and such.
  */
 
-#if defined(__GNUC__) && __GNUC__ >= 4 && !defined(__MINGW32__)
+#if defined(__GNUC__) && __GNUC__ >= 4 && !defined(__MINGW32__) && !defined(__sun)
 #pragma GCC visibility push(hidden)
 #endif
 
@@ -286,7 +286,7 @@ int _cs_locale_copy_inplace(CS_LOCALE *n
 }
 #endif
 
-#if defined(__GNUC__) && __GNUC__ >= 4 && !defined(__MINGW32__)
+#if defined(__GNUC__) && __GNUC__ >= 4 && !defined(__MINGW32__) && !defined(__sun)
 #pragma GCC visibility pop
 #endif
 
