$NetBSD: patch-libgcc_config_aarch64___arm_tpidr2_save.S,v 1.1 2025/02/05 16:30:37 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- libgcc/config/aarch64/__arm_tpidr2_save.S
+++ libgcc/config/aarch64/__arm_tpidr2_save.S
@@ -35,10 +35,15 @@ HIDDEN (__aarch64_have_sme)

 variant_pcs (__arm_tpidr2_save)

-ENTRY (__arm_tpidr2_save)
+ENTRY (ASMNAME (__arm_tpidr2_save))
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
@@ -92,10 +97,18 @@ L(fail):
 	str	x16, [sp, 16]
 	.cfi_rel_offset 46, 16
 	.inst	0xd503467f  /* smstop  */
-	bl	abort
-END (__arm_tpidr2_save)
-
+	bl	ASMNAME (abort)
+ENDm ASMNAME (__arm_tpidr2_save)
+
+	GLOBAL(ASMNAME (__libgcc_arm_tpidr2_save))
+	HIDDEN (ASMNAME (__libgcc_arm_tpidr2_save))
+#if __APPLE__
+	.text
+	.p2align 4
+ASMNAME (__libgcc_arm_tpidr2_save):
+	b ASMNAME (__arm_tpidr2_save)
+#else
 /* Hidden alias used by __arm_za_disable.  */
-.global __libgcc_arm_tpidr2_save
-HIDDEN (__libgcc_arm_tpidr2_save)
-.set __libgcc_arm_tpidr2_save, __arm_tpidr2_save
+.set ASMNAME (__libgcc_arm_tpidr2_save), ASMNAME (__arm_tpidr2_save)
+#endif
+
