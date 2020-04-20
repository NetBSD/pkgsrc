$NetBSD: patch-libgo_go_runtime_stubs.go,v 1.1 2020/04/20 14:25:52 bsiegert Exp $

si_code is a macro on NetBSD, add a C trampoline function.

--- libgo/go/runtime/stubs.go.orig	2020-03-12 11:07:24.000000000 +0000
+++ libgo/go/runtime/stubs.go
@@ -326,6 +326,10 @@ func getSigactionHandler(*_sigaction) ui
 //go:noescape
 func setSigactionHandler(*_sigaction, uintptr)
 
+// Get signal code, written in C.
+//go:noescape
+func getSiginfoCode(*_siginfo_t) uintptr
+
 // Retrieve fields from the siginfo_t and ucontext_t pointers passed
 // to a signal handler using C, as they are often hidden in a union.
 // Returns  and, if available, PC where signal occurred.
