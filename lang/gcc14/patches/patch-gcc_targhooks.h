$NetBSD: patch-gcc_targhooks.h,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/targhooks.h
+++ gcc/targhooks.h
@@ -34,6 +34,9 @@ extern machine_mode default_promote_function_mode (const_tree, machine_mode,
 extern machine_mode default_promote_function_mode_always_promote
 			(const_tree, machine_mode, int *, const_tree, int);

+extern machine_mode default_promote_function_mode_ca
+  (cumulative_args_t, function_arg_info, const_tree, int *, int);
+
 extern machine_mode default_cc_modes_compatible (machine_mode,
 						      machine_mode);

@@ -160,6 +163,12 @@ extern unsigned int default_function_arg_boundary (machine_mode,
 						   const_tree);
 extern unsigned int default_function_arg_round_boundary (machine_mode,
 							 const_tree);
+extern unsigned int default_function_arg_boundary_ca (machine_mode,
+						      const_tree,
+						      cumulative_args_t ca);
+extern unsigned int default_function_arg_round_boundary_ca (machine_mode,
+							    const_tree,
+							    cumulative_args_t ca);
 extern bool hook_bool_const_rtx_commutative_p (const_rtx, int);
 extern rtx default_function_value (const_tree, const_tree, bool);
 extern HARD_REG_SET default_zero_call_used_regs (HARD_REG_SET);
