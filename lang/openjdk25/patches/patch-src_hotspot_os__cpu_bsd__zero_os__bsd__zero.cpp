$NetBSD: patch-src_hotspot_os__cpu_bsd__zero_os__bsd__zero.cpp,v 1.1 2026/09/26 12:54:51 tnn Exp $

Fix zero build on NetBSD.

--- src/hotspot/os_cpu/bsd_zero/os_bsd_zero.cpp.orig	2026-07-24 17:22:09.000000000 +0000
+++ src/hotspot/os_cpu/bsd_zero/os_bsd_zero.cpp
@@ -91,7 +91,13 @@ address os::Posix::ucontext_get_pc(const ucontext_t* u
 
 address os::Posix::ucontext_get_pc(const ucontext_t* uc) {
   if (DecodeErrorContext) {
-#if defined(IA32)
+#if defined(__NetBSD__) && defined(IA32)
+    return (address)uc->uc_mcontext.__gregs[_REG_EIP];
+#elif defined(__NetBSD__) && defined(AMD64)
+    return (address)uc->uc_mcontext.__gregs[_REG_RIP];
+#elif defined(__NetBSD__) && defined(AARCH64)
+    return (address)uc->uc_mcontext.__gregs[_REG_ELR];
+#elif defined(IA32)
     return (address)uc->uc_mcontext.mc_eip;
 #elif defined(AMD64)
     return (address)uc->uc_mcontext.mc_rip;
@@ -116,7 +122,13 @@ intptr_t* os::Bsd::ucontext_get_sp(const ucontext_t* u
 
 intptr_t* os::Bsd::ucontext_get_sp(const ucontext_t* uc) {
   if (DecodeErrorContext) {
-#if defined(IA32)
+#if defined(__NetBSD__) && defined(IA32)
+    return (intptr_t*)uc->uc_mcontext.__gregs[_REG_ESP];
+#elif defined(__NetBSD__) && defined(AMD64)
+    return (intptr_t*)uc->uc_mcontext.__gregs[_REG_RSP];
+#elif defined(__NetBSD__) && defined(AARCH64)
+    return (intptr_t*)uc->uc_mcontext.__gregs[_REG_SP];
+#elif defined(IA32)
     return (intptr_t*)uc->uc_mcontext.mc_esp;
 #elif defined(AMD64)
     return (intptr_t*)uc->uc_mcontext.mc_rsp;
@@ -137,7 +149,13 @@ intptr_t* os::Bsd::ucontext_get_fp(const ucontext_t* u
 
 intptr_t* os::Bsd::ucontext_get_fp(const ucontext_t* uc) {
   if (DecodeErrorContext) {
-#if defined(IA32)
+#if defined(__NetBSD__) && defined(IA32)
+    return (intptr_t*)uc->uc_mcontext.__gregs[_REG_EBP];
+#elif defined(__NetBSD__) && defined(AMD64)
+    return (intptr_t*)uc->uc_mcontext.__gregs[_REG_RBP];
+#elif defined(__NetBSD__) && defined(AARCH64)
+    return (intptr_t*)uc->uc_mcontext.__gregs[_REG_FP];
+#elif defined(IA32)
     return (intptr_t*)uc->uc_mcontext.mc_ebp;
 #elif defined(AMD64)
     return (intptr_t*)uc->uc_mcontext.mc_rbp;
