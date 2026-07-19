$NetBSD: patch-libgcc_config_aarch64_lse.S,v 1.1 2026/07/19 11:17:44 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- libgcc/config/aarch64/lse.S.orig	2026-06-12 06:09:09.988578105 +0000
+++ libgcc/config/aarch64/lse.S
@@ -66,7 +66,7 @@ see the files COPYING3 and COPYING.RUNTI
 #endif

 /* Declare the symbol gating the LSE implementations.  */
-	HIDDEN(__aarch64_have_lse_atomics)
+	HIDDEN (ASMNAME (__aarch64_have_lse_atomics))

 /* Turn size and memory model defines into mnemonic fragments.  */
 #if SIZE == 1
@@ -89,6 +89,7 @@ see the files COPYING3 and COPYING.RUNTI
 # error
 #endif

+#undef L
 #if MODEL == 1
 # define SUFF  _relax
 # define A
@@ -171,32 +172,21 @@ see the files COPYING3 and COPYING.RUNTI
 #define tmp3	14
 #define tmp4	13

-/* Start and end a function.  */
-.macro	STARTFN name
-	.text
-	.balign	16
-	.globl	\name
-	HIDDEN(\name)
-	SYMBOL_TYPE(\name, %function)
-	.cfi_startproc
-\name:
-.endm
-
-.macro	ENDFN name
-	.cfi_endproc
-	SYMBOL_SIZE(\name)
-.endm
-
 /* Branch to LABEL if LSE is disabled.  */
 .macro	JUMP_IF_NOT_LSE label
-	adrp	x(tmp0), __aarch64_have_lse_atomics
-	ldrb	w(tmp0), [x(tmp0), :lo12:__aarch64_have_lse_atomics]
+#if __APPLE__
+	adrp	x(tmp0), ASMNAME (__aarch64_have_lse_atomics)@PAGE
+	ldrb	w(tmp0), [x(tmp0), ASMNAME (__aarch64_have_lse_atomics)@PAGEOFF]
+#else
+	adrp	x(tmp0), ASMNAME (__aarch64_have_lse_atomics)
+	ldrb	w(tmp0), [x(tmp0), :lo12:ASMNAME (__aarch64_have_lse_atomics)]
+#endif
 	cbz	w(tmp0), \label
 .endm

 #ifdef L_cas

-STARTFN	NAME(cas)
+ENTRY (ASMNAME (NAME(cas)))
 	JUMP_IF_NOT_LSE	8f

 #if SIZE < 16
@@ -249,7 +239,7 @@ STARTFN	NAME(cas)

 #endif

-ENDFN	NAME(cas)
+ENDm ASMNAME (NAME(cas))
 #endif

 #ifdef L_swp
@@ -259,7 +249,7 @@ ENDFN	NAME(cas)
 # define SWP	.inst 0x38208020 + B + N
 #endif

-STARTFN	NAME(swp)
+ENTRY (ASMNAME (NAME (swp)))
 	JUMP_IF_NOT_LSE	8f

 	SWP		/* s(0), s(0), [x1] */
@@ -272,7 +262,7 @@ STARTFN	NAME(swp)
 	BARRIER
 	ret

-ENDFN	NAME(swp)
+ENDm ASMNAME (NAME (swp))
 #endif

 #if defined(L_ldadd) || defined(L_ldclr) \
@@ -303,7 +293,7 @@ ENDFN	NAME(swp)
 # define LDOP	.inst 0x38200020 + OPN + B + N
 #endif

-STARTFN	NAME(LDNM)
+ENTRY (ASMNAME (NAME (LDNM)))
 	JUMP_IF_NOT_LSE	8f

 	LDOP		/* s(0), s(0), [x1] */
@@ -317,5 +307,5 @@ STARTFN	NAME(LDNM)
 	BARRIER
 	ret

-ENDFN	NAME(LDNM)
+ENDm ASMNAME (NAME (LDNM))
 #endif
