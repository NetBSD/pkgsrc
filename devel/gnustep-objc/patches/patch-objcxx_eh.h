$NetBSD: patch-objcxx_eh.h,v 1.3 2023/01/14 01:30:53 manu Exp $

Workaround build failure due to redefinition

--- ./objcxx_eh.h.orig	2020-08-23 15:10:20.000000000 +0000
+++ ./objcxx_eh.h	2023-01-11 10:07:02.311233320 +0000
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
@@ -34,9 +39,9 @@
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
