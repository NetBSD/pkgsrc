$NetBSD: patch-asmrun_power-bsd.S,v 1.3 2015/12/29 23:34:52 dholland Exp $

Add profiling to power architecture

   --- asmrun/power-bsd.S.orig	2014-08-19 13:37:35.000000000 +0000
+++ asmrun/power-bsd.S
@@ -11,6 +11,35 @@
 /*                                                                     */
 /***********************************************************************/
 
+#if defined(PROFILING)
+#define PROFILE_CAML \
+        stwu 1, -32(1) \
+        mflr 0 \
+        stw 0, 4(1) \
+        stw 2, 8(1) \
+        stw 3, 12(1) \
+        stw 4, 16(1) \
+        stw 5, 20(1) \
+        stw 6, 24(1) \
+        stw 7, 28(1) \
+        bl _mcount \                
+        lwz 2, 8(1) \               
+        lwz 3, 12(1) \              
+        lwz 4, 16(1) \              
+        lwz 5, 20(1) \              
+        lwz 6, 24(1) \              
+        lwz 7, 28(1) \
+        addic 1, 1, 32
+
+#define PROFILE_C \
+        mflr 0 \
+        stw 0, 4(1) \               
+        bl _mcount                  
+#else                               
+#define PROFILE_CAML                
+#define PROFILE_C                   
+#endif                              
+
 #define Addrglobal(reg,glob) \
         addis   reg, 0, glob@ha; \
         addi    reg, reg, glob@l
@@ -31,6 +60,7 @@ caml_system__code_begin:
         .globl  caml_call_gc
         .type   caml_call_gc, @function
 caml_call_gc:
+        PROFILE_CAML
     /* Set up stack frame */
         stwu    1, -0x1A0(1)
     /* 0x1A0 = 4*32 (int regs) + 8*32 (float regs) + 32 (space for C call) */
@@ -183,6 +213,7 @@ caml_call_gc:
         .globl  caml_c_call
         .type   caml_c_call, @function
 caml_c_call:
+        PROFILE_CAML
     /* Save return address */
         mflr    25
     /* Get ready to call C function (address in 11) */
@@ -253,6 +284,7 @@ caml_reraise_exn:
         .globl  caml_raise_exception
         .type   caml_raise_exception, @function
 caml_raise_exception:
+        PROFILE_C
         Loadglobal(0, caml_backtrace_active, 11)
         cmpwi   0, 0
         bne     .L121
@@ -287,6 +319,7 @@ caml_raise_exception:
         .globl  caml_start_program
         .type   caml_start_program, @function
 caml_start_program:
+        PROFILE_C
         Addrglobal(12, caml_program)
 
 /* Code shared between caml_start_program and caml_callback */
@@ -437,6 +470,7 @@ caml_start_program:
         .globl  caml_callback_exn
         .type   caml_callback_exn, @function
 caml_callback_exn:
+        PROFILE_C
     /* Initial shuffling of arguments */
         mr      0, 3            /* Closure */
         mr      3, 4            /* Argument */
@@ -447,6 +481,7 @@ caml_callback_exn:
         .globl  caml_callback2_exn
         .type   caml_callback2_exn, @function
 caml_callback2_exn:
+        PROFILE_C
         mr      0, 3            /* Closure */
         mr      3, 4            /* First argument */
         mr      4, 5            /* Second argument */
@@ -457,6 +492,7 @@ caml_callback2_exn:
         .globl  caml_callback3_exn
         .type   caml_callback3_exn, @function
 caml_callback3_exn:
+        PROFILE_C
         mr      0, 3            /* Closure */
         mr      3, 4            /* First argument */
         mr      4, 5            /* Second argument */
