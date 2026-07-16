$NetBSD: patch-src_cpu_i487.cpp,v 1.1 2026/07/16 11:03:33 nia Exp $

Hack around C++ math namespacing problems.

--- src/cpu/i487.cpp.orig	2026-07-15 23:27:25.456268838 +0000
+++ src/cpu/i487.cpp
@@ -14,7 +14,7 @@ THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 << LICENSE */
 #include "i486.h"
 #include <algorithm>
-#include <math.h>
+#include <cmath>
 #include <stdint.h>
 
 
@@ -29,7 +29,7 @@ void i486DXCommon::FPUState::BreakOnNan(i486DXCommon &
 
 void i486DXCommon::FPUState::BreakOnNan(i486DXCommon &cpu,double value)
 {
-	if(nullptr!=cpu.debuggerPtr && true==isnan(value))
+	if(nullptr!=cpu.debuggerPtr && true==std::isnan(value))
 	{
 		cpu.debuggerPtr->ExternalBreak("FPU: NaN detected.");
 	}
@@ -124,7 +124,7 @@ void i486DXCommon::FPUState::BreakOnNan(i486DXCommon &
 		value80[0]=0;
 		return;
 	}
-	else if(isnan(src))
+	else if(std::isnan(src))
 	{
 		value80[9]=0x7F;
 		value80[8]=0xFF;
@@ -1857,7 +1857,7 @@ unsigned int i486DXCommon::FPUState::FPTAN(i486DXCommo
 
 		auto &ST=this->ST(cpu);
 		auto t=tan(ST.value);
-		if(true==isnan(t))
+		if(true==std::isnan(t))
 		{
 			statusWord|=STATUS_C2;
 		}
@@ -2136,7 +2136,7 @@ unsigned int i486DXCommon::FPUState::FXAM(i486DXCommon
 			{
 				statusWord|=STATUS_C1;
 			}
-			if(isnan(st.value))
+			if(std::isnan(st.value))
 			{
 				// Nan C3,C2,C0=001
 				statusWord|=STATUS_C0;
