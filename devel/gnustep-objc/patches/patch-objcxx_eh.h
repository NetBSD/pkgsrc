$NetBSD: patch-objcxx_eh.h,v 1.1 2020/04/16 09:28:39 manu Exp $

Workaround build failure due to redefinition

--- objcxx_eh.h.orig	2015-08-07 13:33:41.000000000 +0200
+++ objcxx_eh.h	2020-04-14 11:19:51.950615777 +0200
@@ -1,7 +1,12 @@
 #ifdef __cplusplus
 extern "C" {
 #endif
+
+#ifndef _GLIBCXX_NOTHROW
+#define _GLIBCXX_NOTHROW
+#endif
+
 /**
  * Allocates a C++ exception.  This function is part of the Itanium C++ ABI and
  * is provided externally.
  */
@@ -24,9 +29,9 @@
  * Frees an exception object allocated by __cxa_allocate_exception().  Part of
  * the Itanium C++ ABI.
  */
 __attribute__((weak))
-void __cxa_free_exception(void *thrown_exception);
+void __cxa_free_exception(void *thrown_exception) _GLIBCXX_NOTHROW;
 /**
  * Tests whether a C++ exception contains an Objective-C object, and returns if
  * if it does.  The second argument is a pointer to a boolean value indicating
  * whether this is a valid object.
