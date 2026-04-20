$NetBSD: patch-common_cpu.cpp,v 1.5 2026/04/20 18:05:26 adam Exp $

Retire detect512, make enable512 a global.

--- common/cpu.cpp.orig	2026-04-19 06:29:17.000000000 +0000
+++ common/cpu.cpp
@@ -63,7 +63,7 @@ static void sigill_handler(int sig)
 
 namespace X265_NS {
 #if X265_ARCH_X86
-static bool enable512 = false;
+bool enable512 = false;
 #endif
 const cpu_name_t cpu_names[] =
 {
@@ -150,10 +150,6 @@ uint64_t PFX(cpu_xgetbv)(int xcr);
 #pragma warning(disable: 4309) // truncation of constant value
 #endif
 
-bool detect512()
-{
-    return(enable512);
-}
 
 uint32_t cpu_detect(bool benableavx512 )
 {
