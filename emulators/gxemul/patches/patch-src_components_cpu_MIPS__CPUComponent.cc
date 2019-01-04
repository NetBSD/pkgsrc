$NetBSD: patch-src_components_cpu_MIPS__CPUComponent.cc,v 1.2 2019/01/04 13:35:16 ryoon Exp $

Don't define functions returning functions.

--- src/components/cpu/MIPS_CPUComponent.cc.orig	2018-12-07 06:29:22.000000000 +0000
+++ src/components/cpu/MIPS_CPUComponent.cc
@@ -327,7 +327,7 @@ int MIPS_CPUComponent::GetDyntransICshif
 }
 
 
-void (*MIPS_CPUComponent::GetDyntransToBeTranslated())(CPUDyntransComponent*, DyntransIC*)
+DyntransIC_t MIPS_CPUComponent::GetDyntransToBeTranslated()
 {
 	bool mips16 = m_pc & 1? true : false;
 	return mips16? instr_ToBeTranslated_MIPS16 : instr_ToBeTranslated;
