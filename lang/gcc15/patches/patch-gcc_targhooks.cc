$NetBSD: patch-gcc_targhooks.cc,v 1.2 2026/07/19 11:17:44 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

Pull NetBSD local change for gcc's default_hidden_stack_protect_fail() for NetBSD/i386.
https://cvsweb.netbsd.org/bsdweb.cgi/src/external/gpl3/gcc/dist/gcc/targhooks.cc.diff?r1=1.1.1.2;r2=1.4

--- gcc/targhooks.cc.orig	2026-06-12 06:09:06.827529177 +0000
+++ gcc/targhooks.cc
@@ -163,6 +163,15 @@ default_promote_function_mode_always_pro
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
@@ -890,12 +899,28 @@ default_function_arg_boundary (machine_m
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
@@ -1000,7 +1000,17 @@ default_hidden_stack_protect_fail (void)
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
