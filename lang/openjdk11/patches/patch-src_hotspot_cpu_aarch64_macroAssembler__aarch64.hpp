$NetBSD: patch-src_hotspot_cpu_aarch64_macroAssembler__aarch64.hpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Backport a bugfix appeared in Java 22:
https://github.com/openjdk/jdk/commit/50f31240555888018f0f496ab29c8a5932dce459
https://github.com/openjdk/jdk21u-dev/commit/9e582fcbb8ab34b44ff01ac13de5cc4d6487396d

--- src/hotspot/cpu/aarch64/macroAssembler_aarch64.hpp.orig	2025-08-01 18:05:51.700767534 +0000
+++ src/hotspot/cpu/aarch64/macroAssembler_aarch64.hpp
@@ -559,6 +559,18 @@ public:
     msr(0b011, 0b0100, 0b0100, 0b001, zr);
   }
 
+  // FPCR : op1 == 011
+  //        CRn == 0100
+  //        CRm == 0100
+  //        op2 == 000
+  inline void get_fpcr(Register reg) {
+    mrs(0b11, 0b0100, 0b0100, 0b000, reg);
+  }
+
+  inline void set_fpcr(Register reg) {
+    msr(0b011, 0b0100, 0b0100, 0b000, reg);
+  }
+
   // DCZID_EL0: op1 == 011
   //            CRn == 0000
   //            CRm == 0000
@@ -946,6 +958,9 @@ public:
 #define verify_method_ptr(reg) _verify_method_ptr(reg, "broken method " #reg, __FILE__, __LINE__)
 #define verify_klass_ptr(reg) _verify_klass_ptr(reg, "broken klass " #reg, __FILE__, __LINE__)
 
+  // Restore cpu control state after JNI call
+  void restore_cpu_control_state_after_jni(Register tmp1, Register tmp2);
+
   // only if +VerifyFPU
   void verify_FPU(int stack_depth, const char* s = "illegal FPU state");
 
