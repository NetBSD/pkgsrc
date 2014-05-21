$NetBSD: patch-src_arm_sysv.S,v 1.3 2014/05/21 01:36:23 joerg Exp $

--- src/arm/sysv.S.orig	2013-03-16 11:19:39.000000000 +0000
+++ src/arm/sysv.S
@@ -103,7 +103,7 @@
 #endif
 
 /* Conditionally compile unwinder directives.  */
-#ifdef __ARM_EABI__
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
 #define UNWIND
 #else
 #define UNWIND @
@@ -125,6 +125,7 @@
 	nop
 	.arm
 	UNWIND .fnstart
+	.cfi_startproc
 /* A hook to tell gdb that we've switched to ARM mode.  Also used to call
    directly from other local arm routines.  */
 #ifdef __APPLE__
@@ -144,6 +145,7 @@ _L__\name:
 	ENTRY(\name)
 #endif
 	UNWIND .fnstart
+        .cfi_startproc
 .endm
 #endif
 
@@ -175,6 +177,7 @@ ARM_FUNC_START ffi_call_SYSV
 	@ Save registers
         stmfd	sp!, {r0-r3, fp, lr}
 	UNWIND .save	{r0-r3, fp, lr}
+
 	mov	fp, sp
 
 	UNWIND .setfp	fp, sp
@@ -228,7 +231,7 @@ ARM_FUNC_START ffi_call_SYSV
 #if defined(__SOFTFP__) || defined(__ARM_EABI__)
 	cmpne	r3, #FFI_TYPE_DOUBLE
 #endif
-	stmeqia	r2, {r0, r1}
+	stmiaeq	r2, {r0, r1}
 
 #if !defined(__SOFTFP__) && !defined(__ARM_EABI__)
 	beq	LSYM(Lepilogue)
@@ -253,6 +256,7 @@ LSYM(Lepilogue):
 
 .ffi_call_SYSV_end:
 	UNWIND .fnend
+	.cfi_endproc
 #ifdef __ELF__
         .size    CNAME(ffi_call_SYSV),.ffi_call_SYSV_end-CNAME(ffi_call_SYSV)
 #endif
@@ -328,6 +332,7 @@ ARM_FUNC_START ffi_closure_SYSV
 
 .ffi_closure_SYSV_end:
 	UNWIND .fnend
+	.cfi_endproc
 #ifdef __ELF__
         .size    CNAME(ffi_closure_SYSV),.ffi_closure_SYSV_end-CNAME(ffi_closure_SYSV)
 #endif
@@ -410,7 +415,7 @@ LSYM(Lbase_args):
 	beq	LSYM(Lepilogue_vfp)
 
 	cmp	r3, #FFI_TYPE_SINT64
-	stmeqia	r2, {r0, r1}
+	stmiaeq	r2, {r0, r1}
 	beq	LSYM(Lepilogue_vfp)
 
 	cmp	r3, #FFI_TYPE_FLOAT
@@ -430,6 +435,7 @@ LSYM(Lepilogue_vfp):
 
 .ffi_call_VFP_end:
 	UNWIND .fnend
+	.cfi_endproc
         .size    CNAME(ffi_call_VFP),.ffi_call_VFP_end-CNAME(ffi_call_VFP)
 
 
@@ -492,6 +498,7 @@ ARM_FUNC_START ffi_closure_VFP
 
 .ffi_closure_VFP_end:
 	UNWIND .fnend
+	.cfi_endproc
         .size    CNAME(ffi_closure_VFP),.ffi_closure_VFP_end-CNAME(ffi_closure_VFP)
 #endif
 
