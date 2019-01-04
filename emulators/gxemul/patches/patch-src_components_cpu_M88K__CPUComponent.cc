$NetBSD: patch-src_components_cpu_M88K__CPUComponent.cc,v 1.2 2019/01/04 13:35:16 ryoon Exp $

Don't define functions returning functions.

--- src/components/cpu/M88K_CPUComponent.cc.orig	2018-12-07 06:29:22.000000000 +0000
+++ src/components/cpu/M88K_CPUComponent.cc
@@ -337,7 +337,7 @@ int M88K_CPUComponent::GetDyntransICshif
 }
 
 
-void (*M88K_CPUComponent::GetDyntransToBeTranslated())(CPUDyntransComponent*, DyntransIC*)
+DyntransIC_t M88K_CPUComponent::GetDyntransToBeTranslated()
 {
 	return instr_ToBeTranslated;
 }
