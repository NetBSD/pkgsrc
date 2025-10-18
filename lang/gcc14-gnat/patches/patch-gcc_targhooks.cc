$NetBSD: patch-gcc_targhooks.cc,v 1.3 2025/10/18 05:31:22 dkazankov Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

Patch from NetBSD src. Fix -fPIC/-fPIE and -fstack-protector-strong/
-fstack-protector-all causes undefined reference to `__stack_chk_fail_local'
under NetBSD/i386 9 at least.

--- gcc/targhooks.cc.orig	2025-07-05 02:14:56.999722429 +0000
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
@@ -987,7 +1012,17 @@ default_hidden_stack_protect_fail (void)
       DECL_ARTIFICIAL (t) = 1;
       DECL_IGNORED_P (t) = 1;
       DECL_VISIBILITY_SPECIFIED (t) = 1;
+#if defined(__NetBSD__)
+      /*
+       * This is a hack:
+       * It appears that our gas does not generate @PLT for hidden
+       * symbols. It could be that we need a newer version, or that
+       * this local function is handled differently on linux.
+       */
+      DECL_VISIBILITY (t) = VISIBILITY_DEFAULT;
+#else
       DECL_VISIBILITY (t) = VISIBILITY_HIDDEN;
+#endif
 
       stack_chk_fail_decl = t;
     }
