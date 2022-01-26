$NetBSD: patch-objc_runtime.h,v 1.1 2022/01/26 15:57:54 tm Exp $

In gcc>=10 SEL is implemented as an build-in typedef. Because it's
required to use the typedef by gnustep-objc it's defined to overwrite
it.

--- objc/runtime.h.orig	2015-08-07 11:33:41.000000000 +0000
+++ objc/runtime.h
@@ -68,6 +68,9 @@ typedef struct objc_ivar* Ivar;
 #if !defined(__clang__) && !defined(__OBJC_RUNTIME_INTERNAL__)
 typedef const struct objc_selector *SEL;
 #else
+#if __GNUC__ >= 10
+#define SEL none
+#endif
 typedef struct objc_selector *SEL;
 #endif
 
