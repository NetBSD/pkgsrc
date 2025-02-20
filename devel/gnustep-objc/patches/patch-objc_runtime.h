$NetBSD: patch-objc_runtime.h,v 1.3 2025/02/20 14:24:03 manu Exp $

In gcc>=10 SEL is implemented as an build-in typedef. Because it's
required to use the typedef by gnustep-objc it's defined to overwrite
it.

--- ./objc/runtime.h.orig	2024-03-21 17:06:36.000000000 +0100
+++ ./objc/runtime.h	2025-02-18 10:57:01.067218002 +0100
@@ -74,8 +74,11 @@
  */
 #if !defined(__clang__) && !defined(__OBJC_RUNTIME_INTERNAL__)
 typedef const struct objc_selector *SEL;
 #else
+#if __GNUC__ >= 10
+#define SEL none
+#endif
 typedef struct objc_selector *SEL;
 #endif
 
 /**
