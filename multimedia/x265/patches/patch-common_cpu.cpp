$NetBSD: patch-common_cpu.cpp,v 1.4 2024/04/05 13:45:50 ryoon Exp $

Retire detect512, make enable512 a global.

--- common/cpu.cpp.orig	2024-04-04 09:39:50.000000000 +0000
+++ common/cpu.cpp
@@ -62,7 +62,7 @@ static void sigill_handler(int sig)
 #endif // if X265_ARCH_ARM
 
 namespace X265_NS {
-static bool enable512 = false;
+bool enable512 = false;
 const cpu_name_t cpu_names[] =
 {
 #if X265_ARCH_X86
@@ -135,10 +135,6 @@ uint64_t PFX(cpu_xgetbv)(int xcr);
 #pragma warning(disable: 4309) // truncation of constant value
 #endif
 
-bool detect512()
-{
-    return(enable512);
-}
 
 uint32_t cpu_detect(bool benableavx512 )
 {
