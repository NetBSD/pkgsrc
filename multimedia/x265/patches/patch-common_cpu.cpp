$NetBSD: patch-common_cpu.cpp,v 1.1 2018/12/11 17:55:56 jklos Exp $

Retire detect512, make enable512 a global.

--- common/cpu.cpp.orig	2018-10-05 12:14:40.000000000 +0000
+++ common/cpu.cpp
@@ -58,7 +58,7 @@ static void sigill_handler(int sig)
 #endif // if X265_ARCH_ARM
 
 namespace X265_NS {
-static bool enable512 = false;
+bool enable512 = false;
 const cpu_name_t cpu_names[] =
 {
 #if X265_ARCH_X86
@@ -123,10 +123,6 @@ uint64_t PFX(cpu_xgetbv)(int xcr);
 #pragma warning(disable: 4309) // truncation of constant value
 #endif
 
-bool detect512()
-{
-    return(enable512);
-}
 uint32_t cpu_detect(bool benableavx512 )
 {
 
