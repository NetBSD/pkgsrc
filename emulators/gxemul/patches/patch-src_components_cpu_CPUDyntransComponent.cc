$NetBSD: patch-src_components_cpu_CPUDyntransComponent.cc,v 1.1 2012/11/23 12:33:22 joerg Exp $

--- src/components/cpu/CPUDyntransComponent.cc.orig	2012-11-19 20:12:27.000000000 +0000
+++ src/components/cpu/CPUDyntransComponent.cc
@@ -194,7 +194,7 @@ void CPUDyntransComponent::DyntransClear
 	// Fill the page with "to be translated" entries, which when executed
 	// will read the instruction from memory, attempt to translate it, and
 	// then execute it.
-	void (*f)(CPUDyntransComponent*, DyntransIC*) = GetDyntransToBeTranslated();
+	DyntransIC_t f = GetDyntransToBeTranslated();
 
 	for (int i=0; i<m_dyntransICentriesPerPage; ++i)
 		icpage[i].f = f;
