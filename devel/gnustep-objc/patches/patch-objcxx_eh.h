$NetBSD: patch-objcxx_eh.h,v 1.2 2020/04/17 13:32:23 joerg Exp $

Workaround build failure due to redefinition

--- objcxx_eh.h.orig	2015-08-07 11:33:41.000000000 +0000
+++ objcxx_eh.h
@@ -1,6 +1,11 @@
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
@@ -25,7 +30,7 @@ __attribute__((weak)) DECLARE_PERSONALIT
  * the Itanium C++ ABI.
  */
 __attribute__((weak))
-void __cxa_free_exception(void *thrown_exception);
+void __cxa_free_exception(void *thrown_exception) _GLIBCXX_NOTHROW;
 /**
  * Tests whether a C++ exception contains an Objective-C object, and returns if
  * if it does.  The second argument is a pointer to a boolean value indicating
