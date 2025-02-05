$NetBSD: patch-gcc_config_aarch64_aarch64.h,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/aarch64/aarch64.h
+++ gcc/config/aarch64/aarch64.h
@@ -72,6 +72,10 @@
 #define TARGET_SIMD (AARCH64_ISA_SIMD && AARCH64_ISA_SM_OFF)
 #define TARGET_FLOAT (AARCH64_ISA_FP)

+/* If this is non-zero then generated code of the object format, ABI and
+   assembler syntax used by Darwin (Mach-O) platforms.  */
+#define TARGET_MACHO		0
+
 #define UNITS_PER_WORD		8

 #define UNITS_PER_VREG		16
@@ -149,6 +153,12 @@
 /* Heap alignment (same as BIGGEST_ALIGNMENT and STACK_BOUNDARY).  */
 #define MALLOC_ABI_ALIGNMENT  128

+/* We will and with this value to test if a custom function descriptor needs
+   a static chain.  The function boundary must the adjusted so that the bit
+   this represents is no longer part of the address.  0 Disables the custom
+   function descriptors.  */
+#define AARCH64_CUSTOM_FUNCTION_TEST 4
+
 /* Defined by the ABI */
 #define WCHAR_TYPE "unsigned int"
 #define WCHAR_TYPE_SIZE			32
@@ -1146,6 +1156,24 @@ typedef struct
 				   aapcs_reg == NULL_RTX.  */
   int aapcs_stack_size;		/* The total size (in words, per 8 byte) of the
 				   stack arg area so far.  */
+
+  /* In the darwinpcs, items smaller than one word are packed onto the stack
+     naturally aligned.  Unnamed parameters passed in a variadic call are,
+     however, aligned the same way as the AAPCS64.  This means that we need to
+     pad the last named arg to the next parm boundary (and hence notice when
+     we are processing that arg).  */
+  int darwinpcs_stack_bytes;	/* If the argument is passed on the stack, this
+				   the byte-size.  */
+  int darwinpcs_sub_word_offset;/* This is the offset of this arg within a word
+				   when placing smaller items for darwinpcs.  */
+  int darwinpcs_sub_word_pos;	/* The next byte available within the word for
+				   darwinpcs.  */
+  unsigned darwinpcs_arg_boundary; /* The computed argument boundary.  */
+  unsigned darwinpcs_arg_padding; /* The computed argument padding.  */
+  unsigned darwinpcs_n_named;	/* Number of named arguments.  */
+  unsigned darwinpcs_n_args_processed; /* Processed so far.  */
+  bool named_p;			/* Is this arg named? */
+  bool last_named_p;		/* Is this the last named arg? */
   bool silent_p;		/* True if we should act silently, rather than
 				   raise an error for invalid calls.  */

@@ -1457,8 +1485,13 @@ extern const char *aarch64_rewrite_mcpu (int argc, const char **argv);
 #define ASM_CPU_SPEC \
    MCPU_TO_MARCH_SPEC

+#ifndef SUBTARGET_EXTRA_SPECS
+#define SUBTARGET_EXTRA_SPECS
+#endif
+
 #define EXTRA_SPECS						\
-  { "asm_cpu_spec",		ASM_CPU_SPEC }
+  { "asm_cpu_spec",		ASM_CPU_SPEC },			\
+  SUBTARGET_EXTRA_SPECS

 #define ASM_OUTPUT_POOL_EPILOGUE  aarch64_asm_output_pool_epilogue

@@ -1471,6 +1504,10 @@ extern GTY(()) tree aarch64_fp16_ptr_type_node;
    bfloat16_type_node.  Defined in aarch64-builtins.cc.  */
 extern GTY(()) tree aarch64_bf16_ptr_type_node;

+/* A pointer to the user-visible __float128 (on Mach-O).  Defined in
+   aarch64-builtins.c.  */
+extern GTY(()) tree aarch64_float128_ptr_type_node;
+
 /* The generic unwind code in libgcc does not initialize the frame pointer.
    So in order to unwind a function using a frame pointer, the very first
    function that is unwound must save the frame pointer.  That way the frame
