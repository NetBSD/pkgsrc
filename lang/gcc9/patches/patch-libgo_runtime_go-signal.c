$NetBSD: patch-libgo_runtime_go-signal.c,v 1.1 2020/04/20 14:25:52 bsiegert Exp $

si_code is a macro on NetBSD, add a C trampoline function.

--- libgo/runtime/go-signal.c.orig	2020-03-12 11:07:24.000000000 +0000
+++ libgo/runtime/go-signal.c
@@ -179,6 +179,18 @@ setSigactionHandler(struct sigaction* sa
 // C code to fetch values from the siginfo_t and ucontext_t pointers
 // passed to a signal handler.
 
+uintptr getSiginfoCode(siginfo_t *)
+	__attribute__ ((no_split_stack));
+
+uintptr getSiginfoCode(siginfo_t *)
+	__asm__ (GOSYM_PREFIX "runtime.getSiginfoCode");
+
+uintptr
+getSiginfoCode(siginfo_t *info)
+{
+	return (uintptr)(info->si_code);
+}
+
 struct getSiginfoRet {
 	uintptr sigaddr;
 	uintptr sigpc;
