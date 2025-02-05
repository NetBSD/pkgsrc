$NetBSD: patch-libitm_config_aarch64_sjlj.S,v 1.1 2025/02/05 16:30:37 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- libitm/config/aarch64/sjlj.S
+++ libitm/config/aarch64/sjlj.S
@@ -57,10 +57,19 @@

 	.text
 	.align	2
+#if __ELF__
 	.global	_ITM_beginTransaction
 	.type	_ITM_beginTransaction, %function

 _ITM_beginTransaction:
+
+#elif __MACH__
+	.global	__ITM_beginTransaction
+
+__ITM_beginTransaction:
+
+#endif
+
 	cfi_startproc
 	CFI_PAC_KEY
 	PAC_AND_BTI
@@ -84,8 +93,13 @@ _ITM_beginTransaction:

 	/* Invoke GTM_begin_transaction with the struct we just built.  */
 	mov	x1, sp
+#if __ELF__
 	bl	GTM_begin_transaction
-
+#elif __MACH__
+	bl	_GTM_begin_transaction
+#else
+#error "unexpected object format"
+#endif
 	/* Return; we don't need to restore any of the call-saved regs.  */
 	ldp	x29, x30, [sp], 11*16
 	cfi_adjust_cfa_offset(-11*16)
@@ -95,14 +109,23 @@ _ITM_beginTransaction:
 	CFI_PAC_TOGGLE
 	ret
 	cfi_endproc
+#if __ELF__
 	.size	_ITM_beginTransaction, . - _ITM_beginTransaction
+#endif

 	.align	2
+#if __ELF__
 	.global	GTM_longjmp
 	.hidden	GTM_longjmp
 	.type	GTM_longjmp, %function

 GTM_longjmp:
+
+#elif __MACH__
+	.private_extern _GTM_longjmp
+
+_GTM_longjmp:
+#endif
 	/* The first parameter becomes the return value (x0).
 	   The third parameter is ignored for now.  */
 	cfi_startproc
@@ -126,7 +149,9 @@ GTM_longjmp:
 	CFI_PAC_TOGGLE
 	br	x30
 	cfi_endproc
+#if __ELF__
 	.size	GTM_longjmp, . - GTM_longjmp
+#endif

 /* GNU_PROPERTY_AARCH64_* macros from elf.h for use in asm code.  */
 #define FEATURE_1_AND 0xc0000000
