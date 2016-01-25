$NetBSD: patch-src_arm_sysv.S,v 1.7 2016/01/25 17:56:39 jperkin Exp $

ARM fixes.

--- src/arm/sysv.S.orig	2014-11-08 12:47:24.000000000 +0000
+++ src/arm/sysv.S
@@ -25,6 +25,8 @@
    DEALINGS IN THE SOFTWARE.
    ----------------------------------------------------------------------- */
 
+.syntax unified
+
 #define LIBFFI_ASM	
 #include <fficonfig.h>
 #include <ffi.h>
@@ -103,7 +105,7 @@
 #endif
 
 /* Conditionally compile unwinder directives.  */
-#ifdef __ARM_EABI__
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
 #define UNWIND
 #else
 #define UNWIND @
@@ -121,6 +123,7 @@
 	bx pc; \
 	nop; \
 	.arm; \
+	.cfi_startproc; \
 	UNWIND .fnstart; \
 _L__##name:
 #else
@@ -129,6 +132,7 @@ _L__##name:
 	.align 2; \
 	.arm; \
 	ENTRY(name); \
+	.cfi_startproc; \
 	UNWIND .fnstart
 #endif
 
@@ -160,6 +164,7 @@ ARM_FUNC_START(ffi_call_SYSV)
 	@ Save registers
         stmfd	sp!, {r0-r3, fp, lr}
 	UNWIND .save	{r0-r3, fp, lr}
+
 	mov	fp, sp
 
 	UNWIND .setfp	fp, sp
@@ -238,6 +243,7 @@ LSYM(Lepilogue):
 
 .ffi_call_SYSV_end:
 	UNWIND .fnend
+	.cfi_endproc
 #ifdef __ELF__
         .size    CNAME(ffi_call_SYSV),.ffi_call_SYSV_end-CNAME(ffi_call_SYSV)
 #endif
@@ -313,6 +319,7 @@ ARM_FUNC_START(ffi_closure_SYSV)
 
 .ffi_closure_SYSV_end:
 	UNWIND .fnend
+	.cfi_endproc
 #ifdef __ELF__
         .size    CNAME(ffi_closure_SYSV),.ffi_closure_SYSV_end-CNAME(ffi_closure_SYSV)
 #endif
@@ -396,7 +403,7 @@ LSYM(Lbase_args):
 	beq	LSYM(Lepilogue_vfp)
 
 	cmp	r3, #FFI_TYPE_SINT64
-	stmeqia	r2, {r0, r1}
+	stmiaeq	r2, {r0, r1}
 	beq	LSYM(Lepilogue_vfp)
 
 	cmp	r3, #FFI_TYPE_FLOAT
@@ -416,6 +423,7 @@ LSYM(Lepilogue_vfp):
 
 .ffi_call_VFP_end:
 	UNWIND .fnend
+	.cfi_endproc
         .size    CNAME(ffi_call_VFP),.ffi_call_VFP_end-CNAME(ffi_call_VFP)
 
 
@@ -478,6 +486,7 @@ ARM_FUNC_START(ffi_closure_VFP)
 
 .ffi_closure_VFP_end:
 	UNWIND .fnend
+	.cfi_endproc
         .size    CNAME(ffi_closure_VFP),.ffi_closure_VFP_end-CNAME(ffi_closure_VFP)
 #endif
 
