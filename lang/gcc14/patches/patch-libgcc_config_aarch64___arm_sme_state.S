$NetBSD: patch-libgcc_config_aarch64___arm_sme_state.S,v 1.1 2025/02/05 16:30:37 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- libgcc/config/aarch64/__arm_sme_state.S
+++ libgcc/config/aarch64/__arm_sme_state.S
@@ -30,14 +30,19 @@
    - Takes no argument.
    - Returns SME state in x0 and TPIDR2_EL0 in x1.  */

-HIDDEN (__aarch64_have_sme)
+HIDDEN (ASMNAME (__aarch64_have_sme))

-variant_pcs (__arm_sme_state)
+variant_pcs (ASMNAME (__arm_sme_state))

-ENTRY (__arm_sme_state)
+ENTRY (ASMNAME (__arm_sme_state))
 	/* Check if SME is available.  */
-	adrp	x1, __aarch64_have_sme
-	ldrb	w1, [x1, :lo12:__aarch64_have_sme]
+#ifdef __APPLE__
+	adrp	x1, ASMNAME (__aarch64_have_sme)@PAGE
+	ldrb	w1, [x1, ASMNAME (__aarch64_have_sme)@PAGEOFF]
+#else
+	adrp	x1, ASMNAME (__aarch64_have_sme)
+	ldrb	w1, [x1, :lo12:ASMNAME (__aarch64_have_sme)]
+#endif
 	cbz	w1, L(nosme)

 	/* Expose the bottom 2 bits of svcr (SM, ZA) in x0 and set the
@@ -52,4 +57,4 @@ L(nosme):
 	mov	x0, 0
 	mov	x1, 0
 	ret
-END (__arm_sme_state)
+ENDm ASMNAME(__arm_sme_state)
