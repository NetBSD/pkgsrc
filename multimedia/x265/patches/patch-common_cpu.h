$NetBSD: patch-common_cpu.h,v 1.1 2018/12/11 17:55:56 jklos Exp $

Retire detect512, use enable512 as a global

--- common/cpu.h.orig	2018-10-05 12:14:40.000000000 +0000
+++ common/cpu.h
@@ -50,7 +50,7 @@ extern "C" void PFX(safe_intel_cpu_indic
 
 namespace X265_NS {
 uint32_t cpu_detect(bool);
-bool detect512();
+extern bool enable512;
 
 struct cpu_name_t
 {
