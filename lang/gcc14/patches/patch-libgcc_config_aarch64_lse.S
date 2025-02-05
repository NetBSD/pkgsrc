$NetBSD: patch-libgcc_config_aarch64_lse.S,v 1.1 2025/02/05 16:30:37 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- libgcc/config/aarch64/lse.S
+++ libgcc/config/aarch64/lse.S
@@ -62,7 +62,7 @@ see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
 #endif

 /* Declare the symbol gating the LSE implementations.  */
-	HIDDEN(__aarch64_have_lse_atomics)
+	HIDDEN (ASMNAME (__aarch64_have_lse_atomics))

 /* Turn size and memory model defines into mnemonic fragments.  */
 #if SIZE == 1
@@ -85,6 +85,7 @@ see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
 # error
 #endif

+#undef L
 #if MODEL == 1
 # define SUFF  _relax
 # define A
@@ -167,32 +168,21 @@ see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
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
@@ -245,7 +235,7 @@ STARTFN	NAME(cas)

 #endif

-ENDFN	NAME(cas)
+ENDm ASMNAME (NAME(cas))
 #endif

 #ifdef L_swp
@@ -255,7 +245,7 @@ ENDFN	NAME(cas)
 # define SWP	.inst 0x38208020 + B + N
 #endif

-STARTFN	NAME(swp)
+ENTRY (ASMNAME (NAME (swp)))
 	JUMP_IF_NOT_LSE	8f

 	SWP		/* s(0), s(0), [x1] */
@@ -268,7 +258,7 @@ STARTFN	NAME(swp)
 	BARRIER
 	ret

-ENDFN	NAME(swp)
+ENDm ASMNAME (NAME (swp))
 #endif

 #if defined(L_ldadd) || defined(L_ldclr) \
@@ -299,7 +289,7 @@ ENDFN	NAME(swp)
 # define LDOP	.inst 0x38200020 + OPN + B + N
 #endif

-STARTFN	NAME(LDNM)
+ENTRY (ASMNAME (NAME (LDNM)))
 	JUMP_IF_NOT_LSE	8f

 	LDOP		/* s(0), s(0), [x1] */
@@ -313,5 +303,5 @@ STARTFN	NAME(LDNM)
 	BARRIER
 	ret

-ENDFN	NAME(LDNM)
+ENDm ASMNAME (NAME (LDNM))
 #endif
