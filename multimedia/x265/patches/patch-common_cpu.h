$NetBSD: patch-common_cpu.h,v 1.3 2024/04/05 13:45:50 ryoon Exp $

Retire detect512, use enable512 as a global

--- common/cpu.h.orig	2024-04-05 09:13:16.246340956 +0000
+++ common/cpu.h
@@ -50,7 +50,7 @@ extern "C" void PFX(safe_intel_cpu_indic
 
 namespace X265_NS {
 uint32_t cpu_detect(bool);
-bool detect512();
+extern bool enable512;
 
 struct cpu_name_t
 {
