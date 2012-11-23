$NetBSD: patch-src_components_cpu_MIPS__CPUComponent.cc,v 1.1 2012/11/23 12:33:22 joerg Exp $

--- src/components/cpu/MIPS_CPUComponent.cc.orig	2012-11-19 20:12:23.000000000 +0000
+++ src/components/cpu/MIPS_CPUComponent.cc
@@ -327,7 +327,7 @@ int MIPS_CPUComponent::GetDyntransICshif
 }
 
 
-void (*MIPS_CPUComponent::GetDyntransToBeTranslated())(CPUDyntransComponent*, DyntransIC*) const
+DyntransIC_t MIPS_CPUComponent::GetDyntransToBeTranslated() const
 {
 	bool mips16 = m_pc & 1? true : false;
 	return mips16? instr_ToBeTranslated_MIPS16 : instr_ToBeTranslated;
