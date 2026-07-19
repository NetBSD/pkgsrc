$NetBSD: patch-libgcc_config_aarch64_____arm__tpidr2__restore.S,v 1.1 2026/07/19 11:17:44 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- libgcc/config/aarch64/__arm_tpidr2_restore.S.orig	2026-06-12 06:09:09.988305985 +0000
+++ libgcc/config/aarch64/__arm_tpidr2_restore.S
@@ -31,9 +31,9 @@
    - Does not return a value.
    - Can abort on failure (then registers are not preserved).  */

-variant_pcs (__arm_tpidr2_restore)
+variant_pcs (ASMNAME (__arm_tpidr2_restore))

-ENTRY (__arm_tpidr2_restore)
+ENTRY (ASMNAME (__arm_tpidr2_restore))
 	.inst	0xd53bd0ae  /* mrs	x14, tpidr2_el0  */
 	cbnz	x14, L(fail)

@@ -85,5 +85,5 @@ L(fail):
 	str	x16, [sp, 16]
 	.cfi_rel_offset 46, 16
 	.inst	0xd503467f  /* smstop  */
-	bl	abort
-END (__arm_tpidr2_restore)
+	bl	ASMNAME (abort)
+ENDm ASMNAME (__arm_tpidr2_restore)
