$NetBSD: patch-include_my__context.h,v 1.1 2015/05/07 12:45:29 fhajny Exp $

--- include/my_context.h.orig	2015-02-13 12:07:01.000000000 +0000
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
 #elif defined(HAVE_UCONTEXT)
 #define MY_CONTEXT_USE_UCONTEXT
