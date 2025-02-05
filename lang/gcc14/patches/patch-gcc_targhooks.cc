$NetBSD: patch-gcc_targhooks.cc,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/targhooks.cc
+++ gcc/targhooks.cc
@@ -161,6 +161,15 @@ default_promote_function_mode_always_promote (const_tree type,
   return promote_mode (type, mode, punsignedp);
 }

+machine_mode
+default_promote_function_mode_ca (cumulative_args_t, function_arg_info arg,
+				  const_tree funtype, int *punsignedp,
+				  int for_return)
+{
+  return promote_function_mode (arg.type, arg.mode, punsignedp,
+				funtype, for_return);
+}
+
 machine_mode
 default_cc_modes_compatible (machine_mode m1, machine_mode m2)
 {
@@ -876,6 +885,14 @@ default_function_arg_boundary (machine_mode mode ATTRIBUTE_UNUSED,
   return PARM_BOUNDARY;
 }

+unsigned int
+default_function_arg_boundary_ca (machine_mode mode ATTRIBUTE_UNUSED,
+				  const_tree type ATTRIBUTE_UNUSED,
+				  cumulative_args_t ca ATTRIBUTE_UNUSED)
+{
+  return default_function_arg_boundary (mode, type);
+}
+
 unsigned int
 default_function_arg_round_boundary (machine_mode mode ATTRIBUTE_UNUSED,
 				     const_tree type ATTRIBUTE_UNUSED)
@@ -883,6 +900,14 @@ default_function_arg_round_boundary (machine_mode mode ATTRIBUTE_UNUSED,
   return PARM_BOUNDARY;
 }

+unsigned int
+default_function_arg_round_boundary_ca (machine_mode mode ATTRIBUTE_UNUSED,
+					const_tree type ATTRIBUTE_UNUSED,
+					cumulative_args_t ca ATTRIBUTE_UNUSED)
+{
+  return default_function_arg_round_boundary (mode, type);
+}
+
 void
 hook_void_bitmap (bitmap regs ATTRIBUTE_UNUSED)
 {
