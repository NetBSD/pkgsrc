$NetBSD: patch-gcc_config_aarch64_aarch64-builtins.cc,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/aarch64/aarch64-builtins.cc
+++ gcc/config/aarch64/aarch64-builtins.cc
@@ -788,6 +788,8 @@ enum aarch64_builtins
   AARCH64_PLDX,
   AARCH64_PLI,
   AARCH64_PLIX,
+  /* OS-specific */
+  AARCH64_BUILTIN_CFSTRING,
   AARCH64_BUILTIN_MAX
 };

@@ -887,6 +889,9 @@ tree aarch64_fp16_ptr_type_node = NULL_TREE;
 /* Back-end node type for brain float (bfloat) types.  */
 tree aarch64_bf16_ptr_type_node = NULL_TREE;

+/* Pointer to __float128 on Mach-O, where the 128b float is not long double.  */
+tree aarch64_float128_ptr_type_node = NULL_TREE;
+
 /* Wrapper around add_builtin_function.  NAME is the name of the built-in
    function, TYPE is the function type, CODE is the function subcode
    (relative to AARCH64_BUILTIN_GENERAL), and ATTRS is the function
@@ -1662,6 +1667,29 @@ aarch64_init_bf16_types (void)
   aarch64_bf16_ptr_type_node = build_pointer_type (bfloat16_type_node);
 }

+/* Initialize the backend REAL_TYPE type supporting __float128 on Mach-O,
+   as well as the related built-ins.  */
+static void
+aarch64_init_float128_types (void)
+{
+  /* The __float128 type.  The node has already been created as
+     _Float128, so for C we only need to register the __float128 name for
+     it.  For C++, we create a distinct type which will mangle differently
+     (g) vs. _Float128 (DF128_) and behave backwards compatibly.  */
+  if (float128t_type_node == NULL_TREE)
+    {
+      float128t_type_node = make_node (REAL_TYPE);
+      TYPE_PRECISION (float128t_type_node)
+	= TYPE_PRECISION (float128_type_node);
+      SET_TYPE_MODE (float128t_type_node, TYPE_MODE (float128_type_node));
+      layout_type (float128t_type_node);
+    }
+  lang_hooks.types.register_builtin_type (float128t_type_node, "__float128");
+
+  aarch64_float128_ptr_type_node = build_pointer_type (float128t_type_node);
+}
+
+
 /* Pointer authentication builtins that will become NOP on legacy platform.
    Currently, these builtins are for internal use only (libgcc EH unwinder).  */

@@ -2047,8 +2075,9 @@ aarch64_general_init_builtins (void)
   aarch64_init_fpsr_fpcr_builtins ();

   aarch64_init_fp16_types ();
-
   aarch64_init_bf16_types ();
+  if (TARGET_MACHO)
+    aarch64_init_float128_types ();

   {
     aarch64_simd_switcher simd;
@@ -2088,6 +2117,14 @@ aarch64_general_init_builtins (void)
     handle_arm_acle_h ();
 }

+void
+aarch64_init_subtarget_builtins (void)
+{
+#ifdef SUBTARGET_INIT_BUILTINS
+  SUBTARGET_INIT_BUILTINS;
+#endif
+}
+
 /* Implement TARGET_BUILTIN_DECL for the AARCH64_BUILTIN_GENERAL group.  */
 tree
 aarch64_general_builtin_decl (unsigned code, bool)
