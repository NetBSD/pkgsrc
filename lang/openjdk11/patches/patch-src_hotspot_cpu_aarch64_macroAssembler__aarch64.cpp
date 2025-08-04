$NetBSD: patch-src_hotspot_cpu_aarch64_macroAssembler__aarch64.cpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Backport a bugfix appeared in Java 22:
https://github.com/openjdk/jdk/commit/50f31240555888018f0f496ab29c8a5932dce459

--- src/hotspot/cpu/aarch64/macroAssembler_aarch64.cpp.orig	2025-08-01 18:07:27.105868141 +0000
+++ src/hotspot/cpu/aarch64/macroAssembler_aarch64.cpp
@@ -3670,6 +3670,23 @@ void MacroAssembler::load_klass(Register
   }
 }
 
+void MacroAssembler::restore_cpu_control_state_after_jni(Register tmp1, Register tmp2) {
+  if (RestoreMXCSROnJNICalls) {
+    Label OK;
+    get_fpcr(tmp1);
+    mov(tmp2, tmp1);
+    // Set FPCR to the state we need. We do want Round to Nearest. We
+    // don't want non-IEEE rounding modes or floating-point traps.
+    bfi(tmp1, zr, 22, 4); // Clear DN, FZ, and Rmode
+    bfi(tmp1, zr, 8, 5);  // Clear exception-control bits (8-12)
+    bfi(tmp1, zr, 0, 2);  // Clear AH:FIZ
+    eor(tmp2, tmp1, tmp2);
+    cbz(tmp2, OK);        // Only reset FPCR if it's wrong
+    set_fpcr(tmp1);
+    bind(OK);
+  }
+}
+
 // ((OopHandle)result).resolve();
 void MacroAssembler::resolve_oop_handle(Register result, Register tmp) {
   // OopHandle::resolve is an indirection.
