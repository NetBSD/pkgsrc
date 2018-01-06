$NetBSD: patch-py_nlrx64.c,v 1.1.2.2 2018/01/06 23:06:27 spz Exp $

Remove illegal cpp abuse that fails the clang build.

--- py/nlrx64.c~	2017-08-23 01:50:10.000000000 +0000
+++ py/nlrx64.c
@@ -34,7 +34,11 @@
 // x86-64 callee-save registers are:
 //  rbx, rbp, rsp, r12, r13, r14, r15
 
-#define NLR_OS_WINDOWS (defined(_WIN32) || defined(__CYGWIN__))
+#if (defined(_WIN32) || defined(__CYGWIN__))
+#define NLR_OS_WINDOWS 1
+#else
+#define NLR_OS_WINDOWS 0
+#endif
 
 __attribute__((used)) unsigned int nlr_push_tail(nlr_buf_t *nlr);
 
