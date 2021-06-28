$NetBSD: patch-src_hotspot_cpu_arm_c1__LIRAssembler__arm.cpp,v 1.1 2021/06/28 22:53:05 tnn Exp $

error: call of overloaded 'log2_intptr(int&)' is ambiguous
note: candidate: int log2_intptr(uintptr_t)
 inline int log2_intptr(uintptr_t x) {
note: candidate: int log2_intptr(intptr_t)
 inline int log2_intptr(intptr_t x) {

--- src/hotspot/cpu/arm/c1_LIRAssembler_arm.cpp.orig	2021-04-24 02:47:22.000000000 +0000
+++ src/hotspot/cpu/arm/c1_LIRAssembler_arm.cpp
@@ -1062,7 +1062,7 @@ void LIR_Assembler::emit_op3(LIR_Op3* op
       __ add_32(dest, left, AsmOperand(left, lsr, 31));
       __ asr_32(dest, dest, 1);
     } else if (c != (int) 0x80000000) {
-      int power = log2_intptr(c);
+      int power = log2_intptr((intptr_t)c);
       __ asr_32(Rtemp, left, 31);
       __ add_32(dest, left, AsmOperand(Rtemp, lsr, 32-power)); // dest = left + (left < 0 ? 2^power - 1 : 0);
       __ asr_32(dest, dest, power);                            // dest = dest >>> power;
