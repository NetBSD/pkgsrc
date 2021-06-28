$NetBSD: patch-src_hotspot_cpu_arm_c1__LIRGenerator__arm.cpp,v 1.1 2021/06/28 22:53:05 tnn Exp $

error: call of overloaded 'log2_intptr(int)' is ambiguous
     LIR_Address::Scale scale = (LIR_Address::Scale) log2_intptr(c + 1);
note: candidate: int log2_intptr(uintptr_t)
 inline int log2_intptr(uintptr_t x) {
note: candidate: int log2_intptr(intptr_t)
 inline int log2_intptr(intptr_t x) {

--- src/hotspot/cpu/arm/c1_LIRGenerator_arm.cpp.orig	2021-04-24 02:47:22.000000000 +0000
+++ src/hotspot/cpu/arm/c1_LIRGenerator_arm.cpp
@@ -443,13 +443,13 @@ bool LIRGenerator::strength_reduce_multi
     __ shift_left(left, log2_intptr(c + 1), result);
     __ sub(result, left, result);
 #else
-    LIR_Address::Scale scale = (LIR_Address::Scale) log2_intptr(c + 1);
+    LIR_Address::Scale scale = (LIR_Address::Scale) log2_intptr((intptr_t)(c + 1));
     LIR_Address* addr = new LIR_Address(left, left, scale, 0, T_INT);
     __ sub(LIR_OprFact::address(addr), left, result); // rsb with shifted register
 #endif // AARCH64
     return true;
   } else if (is_power_of_2(c - 1)) {
-    LIR_Address::Scale scale = (LIR_Address::Scale) log2_intptr(c - 1);
+    LIR_Address::Scale scale = (LIR_Address::Scale) log2_intptr((intptr_t)(c - 1));
     LIR_Address* addr = new LIR_Address(left, left, scale, 0, T_INT);
     __ add(left, LIR_OprFact::address(addr), result); // add with shifted register
     return true;
