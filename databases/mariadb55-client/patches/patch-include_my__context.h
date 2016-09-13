$NetBSD: patch-include_my__context.h,v 1.2 2016/09/13 19:15:14 maya Exp $

--- include/my_context.h.orig	2016-09-12 14:54:54.000000000 +0000
+++ include/my_context.h
@@ -27,9 +27,9 @@
 
 #ifdef __WIN__
 #define MY_CONTEXT_USE_WIN32_FIBERS 1
-#elif defined(__GNUC__) && __GNUC__ >= 3 && defined(__x86_64__) && !defined(__ILP32__)
+#elif defined(__GNUC__) && __GNUC__ >= 3 && defined(__x86_64__) && !defined(__ILP32__) && !defined(__sun)
 #define MY_CONTEXT_USE_X86_64_GCC_ASM
-#elif defined(__GNUC__) && __GNUC__ >= 3 && defined(__i386__)
+#elif defined(__GNUC__) && __GNUC__ >= 3 && defined(__i386__) && !defined(__sun)
 #define MY_CONTEXT_USE_I386_GCC_ASM
 #elif defined(HAVE_UCONTEXT_H)
 #define MY_CONTEXT_USE_UCONTEXT
