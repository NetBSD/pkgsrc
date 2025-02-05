$NetBSD: patch-libgcc_config_aarch64___arm_za_disable.S,v 1.1 2025/02/05 16:30:37 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- libgcc/config/aarch64/__arm_za_disable.S
+++ libgcc/config/aarch64/__arm_za_disable.S
@@ -31,16 +31,33 @@
    - Does not return a value.
    - Can abort on failure (then registers are not preserved).  */

-HIDDEN (__aarch64_have_sme)
+HIDDEN (ASMNAME(__aarch64_have_sme))

-HIDDEN (__libgcc_arm_tpidr2_save)
+HIDDEN (ASMNAME(__libgcc_arm_tpidr2_save))

-variant_pcs (__arm_za_disable)
+variant_pcs (ASMNAME(__arm_za_disable))

-ENTRY (__arm_za_disable)
+GLOBAL (ASMNAME (__libgcc_arm_za_disable))
+HIDDEN (ASMNAME (__libgcc_arm_za_disable))
+#if __APPLE__
+	.text
+	.p2align 4
+ASMNAME (__libgcc_arm_za_disable):
+	b ASMNAME (__arm_za_disable)
+#else
+/* Hidden alias used by the unwinder.  */
+.set ASMNAME (__libgcc_arm_za_disable), ASMNAME (__arm_za_disable)
+#endif
+
+ENTRY (ASMNAME (__arm_za_disable))
 	/* Check if SME is available.  */
-	adrp	x14, __aarch64_have_sme
-	ldrb	w14, [x14, :lo12:__aarch64_have_sme]
+#if __APPLE__
+	adrp	x14, ASMNAME (__aarch64_have_sme)@PAGE
+	ldrb	w14, [x14, ASMNAME (__aarch64_have_sme)@PAGEOFF]
+#else
+	adrp	x14, ASMNAME (__aarch64_have_sme)
+	ldrb	w14, [x14, :lo12:ASMNAME (__aarch64_have_sme)]
+#endif
 	cbz	w14, L(end)

 	.inst	0xd53bd0ae  /* mrs	x14, tpidr2_el0  */
@@ -52,7 +69,7 @@ ENTRY (__arm_za_disable)
 	.cfi_rel_offset x29, 0
 	.cfi_rel_offset x30, 8
 	mov	x29, sp
-	bl	__libgcc_arm_tpidr2_save
+	bl	ASMNAME (__libgcc_arm_tpidr2_save)
 	.inst	0xd51bd0bf  /* msr	tpidr2_el0, xzr  */
 	.inst	0xd503447f  /* smstop	za  */
 	ldp	x29, x30, [sp], 16
@@ -62,9 +79,5 @@ ENTRY (__arm_za_disable)
 	AUTIASP
 L(end):
 	ret
-END (__arm_za_disable)
+ENDm ASMNAME(__arm_za_disable)

-/* Hidden alias used by the unwinder.  */
-.global __libgcc_arm_za_disable
-HIDDEN (__libgcc_arm_za_disable)
-.set __libgcc_arm_za_disable, __arm_za_disable
