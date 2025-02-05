$NetBSD: patch-gcc_config_aarch64_aarch64-protos.h,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/aarch64/aarch64-protos.h
+++ gcc/config/aarch64/aarch64-protos.h
@@ -109,6 +109,14 @@ enum aarch64_symbol_type
   SYMBOL_TLSLE24,
   SYMBOL_TLSLE32,
   SYMBOL_TLSLE48,
+  SYMBOL_MO_SMALL_ABS,
+  SYMBOL_MO_SMALL_PCR,
+  SYMBOL_MO_SMALL_GOT,
+  SYMBOL_MO_SMALL_TLS,
+  SYMBOL_MO_LARGE_ABS,
+  SYMBOL_MO_LARGE_PCR,
+  SYMBOL_MO_LARGE_GOT,
+  SYMBOL_MO_LARGE_TLS,
   SYMBOL_FORCE_TO_MEM
 };

@@ -748,6 +756,7 @@ void aarch64_post_cfi_startproc (void);
 poly_int64 aarch64_initial_elimination_offset (unsigned, unsigned);
 int aarch64_get_condition_code (rtx);
 bool aarch64_address_valid_for_prefetch_p (rtx, bool);
+bool aarch64_address_valid_for_unscaled_prefetch_p (rtx, bool);
 bool aarch64_bitmask_imm (unsigned HOST_WIDE_INT val, machine_mode);
 unsigned HOST_WIDE_INT aarch64_and_split_imm1 (HOST_WIDE_INT val_in);
 unsigned HOST_WIDE_INT aarch64_and_split_imm2 (HOST_WIDE_INT val_in);
@@ -782,7 +791,11 @@ bool aarch64_is_extend_from_extract (scalar_int_mode, rtx, rtx);
 bool aarch64_is_long_call_p (rtx);
 bool aarch64_is_noplt_call_p (rtx);
 bool aarch64_label_mentioned_p (rtx);
+#if TARGET_MACHO
+void aarch64_darwin_declare_function_name (FILE *, const char*, tree );
+#else
 void aarch64_declare_function_name (FILE *, const char*, tree);
+#endif
 void aarch64_asm_output_alias (FILE *, const tree, const tree);
 void aarch64_asm_output_external (FILE *, tree, const char*);
 bool aarch64_legitimate_pic_operand_p (rtx);
@@ -999,6 +1012,7 @@ void aarch64_override_options_internal (struct gcc_options *);

 const char *aarch64_general_mangle_builtin_type (const_tree);
 void aarch64_general_init_builtins (void);
+void aarch64_init_subtarget_builtins (void);
 tree aarch64_general_fold_builtin (unsigned int, tree, unsigned int, tree *);
 gimple *aarch64_general_gimple_fold_builtin (unsigned int, gcall *,
 					     gimple_stmt_iterator *);
