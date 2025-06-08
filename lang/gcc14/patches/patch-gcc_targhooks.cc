$NetBSD: patch-gcc_targhooks.cc,v 1.2 2025/06/08 07:37:45 wiz Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/targhooks.cc.orig	2025-05-23 11:02:05.072209824 +0000
+++ gcc/targhooks.cc
@@ -162,6 +162,15 @@ default_promote_function_mode_always_pro
 }
 
 machine_mode
+default_promote_function_mode_ca (cumulative_args_t, function_arg_info arg,
+				  const_tree funtype, int *punsignedp,
+				  int for_return)
+{
+  return promote_function_mode (arg.type, arg.mode, punsignedp,
+				funtype, for_return);
+}
+
+machine_mode
 default_cc_modes_compatible (machine_mode m1, machine_mode m2)
 {
   if (m1 == m2)
@@ -877,12 +886,28 @@ default_function_arg_boundary (machine_m
 }
 
 unsigned int
+default_function_arg_boundary_ca (machine_mode mode ATTRIBUTE_UNUSED,
+				  const_tree type ATTRIBUTE_UNUSED,
+				  cumulative_args_t ca ATTRIBUTE_UNUSED)
+{
+  return default_function_arg_boundary (mode, type);
+}
+
+unsigned int
 default_function_arg_round_boundary (machine_mode mode ATTRIBUTE_UNUSED,
 				     const_tree type ATTRIBUTE_UNUSED)
 {
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
