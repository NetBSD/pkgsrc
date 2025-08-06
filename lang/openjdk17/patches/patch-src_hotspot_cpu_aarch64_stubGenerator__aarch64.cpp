$NetBSD: patch-src_hotspot_cpu_aarch64_stubGenerator__aarch64.cpp,v 1.1 2025/08/06 08:47:16 pho Exp $

Backport a bugfix appeared in Java 22:
https://github.com/openjdk/jdk21u-dev/commit/9e582fcbb8ab34b44ff01ac13de5cc4d6487396d

--- src/hotspot/cpu/aarch64/stubGenerator_aarch64.cpp.orig	2025-08-01 18:21:30.132638820 +0000
+++ src/hotspot/cpu/aarch64/stubGenerator_aarch64.cpp
@@ -160,8 +160,9 @@ class StubGenerator: public StubCodeGene
 
   // Call stub stack layout word offsets from fp
   enum call_stub_layout {
-    sp_after_call_off = -26,
+    sp_after_call_off = -28,
 
+    fpcr_off           = sp_after_call_off,
     d15_off            = -26,
     d13_off            = -24,
     d11_off            = -22,
@@ -191,8 +192,9 @@ class StubGenerator: public StubCodeGene
     StubCodeMark mark(this, "StubRoutines", "call_stub");
     address start = __ pc();
 
-    const Address sp_after_call(rfp, sp_after_call_off * wordSize);
+    const Address sp_after_call (rfp, sp_after_call_off * wordSize);
 
+    const Address fpcr_save     (rfp, fpcr_off           * wordSize);
     const Address call_wrapper  (rfp, call_wrapper_off   * wordSize);
     const Address result        (rfp, result_off         * wordSize);
     const Address result_type   (rfp, result_type_off    * wordSize);
@@ -241,6 +243,14 @@ class StubGenerator: public StubCodeGene
     __ stpd(v13, v12,  d13_save);
     __ stpd(v15, v14,  d15_save);
 
+    __ get_fpcr(rscratch1);
+    __ str(rscratch1, fpcr_save);
+    // Set FPCR to the state we need. We do want Round to Nearest. We
+    // don't want non-IEEE rounding modes or floating-point traps.
+    __ bfi(rscratch1, zr, 22, 4); // Clear DN, FZ, and Rmode
+    __ bfi(rscratch1, zr, 8, 5);  // Clear exception-control bits (8-12)
+    __ set_fpcr(rscratch1);
+
     // install Java thread in global register now we have saved
     // whatever value it held
     __ mov(rthread, c_rarg7);
@@ -352,6 +362,10 @@ class StubGenerator: public StubCodeGene
     __ ldp(r22, r21,   r22_save);
     __ ldp(r20, r19,   r20_save);
 
+    // restore fpcr
+    __ ldr(rscratch1,  fpcr_save);
+    __ set_fpcr(rscratch1);
+
     __ ldp(c_rarg0, c_rarg1,  call_wrapper);
     __ ldrw(c_rarg2, result_type);
     __ ldr(c_rarg3,  method);
