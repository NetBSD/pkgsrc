$NetBSD: patch-objcxx_eh.h,v 1.4 2025/02/20 14:24:03 manu Exp $

Workaround build failure due to redefinition

--- objcxx_eh.h.orig	2024-03-21 17:06:36.000000000 +0100
+++ objcxx_eh.h	2025-02-18 11:03:56.455965494 +0100
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
@@ -31,9 +36,9 @@
 /**
  * Frees an exception object allocated by __cxa_allocate_exception().  Part of
  * the Itanium C++ ABI.
  */
-void __cxa_free_exception(void *thrown_exception);
+void __cxa_free_exception(void *thrown_exception) _GLIBCXX_NOTHROW;
 /**
  * Tests whether a C++ exception contains an Objective-C object, and returns if
  * if it does.  The second argument is a pointer to a boolean value indicating
  * whether this is a valid object.
