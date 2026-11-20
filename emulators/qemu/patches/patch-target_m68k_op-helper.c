$NetBSD: patch-target_m68k_op-helper.c,v 1.1 2026/11/20 16:43:05 thorpej Exp $

Patch for Qemu issue #2078.

* Avoid integer division underflow that can cause arithmetic exception
  on the host system and crash Qemu.

--- target/m68k/op_helper.c.orig	2026-10-28 19:57:39.000000000 +0000
+++ target/m68k/op_helper.c	2026-11-20 16:33:08.490830343 +0000
@@ -679,12 +679,22 @@ void HELPER(divsl)(CPUM68KState *env, in
     if (den == 0) {
         raise_exception_format2(env, EXCP_DIV0, ilen, GETPC());
     }
-    quot = num / den;
-    rem = num % den;
+    if (unlikely(num == INT32_MIN) && den == -1) {
+        env->cc_v = -1;
+        /*
+         * real 68040 keeps N and unset Z on overflow,
+         * whereas documentation says "undefined"
+         */
+        env->cc_z = 1;
+	return;
+    } else {
+        quot = num / den;
+        rem = num % den;
 
-    env->cc_z = quot;
-    env->cc_n = quot;
-    env->cc_v = 0;
+        env->cc_z = quot;
+        env->cc_n = quot;
+        env->cc_v = 0;
+    }
 
     if (m68k_feature(env, M68K_FEATURE_CF_ISA_A)) {
         if (numr == regr) {
