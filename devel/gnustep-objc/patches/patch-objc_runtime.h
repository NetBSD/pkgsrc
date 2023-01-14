$NetBSD: patch-objc_runtime.h,v 1.2 2023/01/14 01:30:53 manu Exp $

In gcc>=10 SEL is implemented as an build-in typedef. Because it's
required to use the typedef by gnustep-objc it's defined to overwrite
it.

--- ./objc/runtime.h.orig	2020-08-23 15:10:20.000000000 +0000
+++ ./objc/runtime.h	2023-01-11 10:07:01.905661420 +0000
@@ -68,8 +68,11 @@
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
