$NetBSD: patch-gcc_calls.h,v 1.1 2025/02/05 16:30:34 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/calls.h
+++ gcc/calls.h
@@ -35,24 +35,43 @@ class function_arg_info
 {
 public:
   function_arg_info ()
-    : type (NULL_TREE), mode (VOIDmode), named (false),
+    : type (NULL_TREE), mode (VOIDmode), named (false), last_named (false),
       pass_by_reference (false)
   {}

   /* Initialize an argument of mode MODE, either before or after promotion.  */
   function_arg_info (machine_mode mode, bool named)
-    : type (NULL_TREE), mode (mode), named (named), pass_by_reference (false)
+    : type (NULL_TREE), mode (mode), named (named), last_named (false),
+      pass_by_reference (false)
+  {}
+
+  function_arg_info (machine_mode mode, bool named, bool last_named)
+    : type (NULL_TREE), mode (mode), named (named), last_named (last_named),
+      pass_by_reference (false)
   {}

   /* Initialize an unpromoted argument of type TYPE.  */
   function_arg_info (tree type, bool named)
-    : type (type), mode (TYPE_MODE (type)), named (named),
+    : type (type), mode (TYPE_MODE (type)), named (named), last_named (false),
       pass_by_reference (false)
   {}

+  /* Initialize an unpromoted argument of type TYPE.  */
+  function_arg_info (tree type, bool named, bool last_named)
+    : type (type), mode (TYPE_MODE (type)), named (named),
+      last_named (last_named), pass_by_reference (false)
+  {}
+
   /* Initialize an argument with explicit properties.  */
   function_arg_info (tree type, machine_mode mode, bool named)
-    : type (type), mode (mode), named (named), pass_by_reference (false)
+    : type (type), mode (mode), named (named), last_named (false),
+      pass_by_reference (false)
+  {}
+
+  /* Initialize an argument with explicit properties.  */
+  function_arg_info (tree type, machine_mode mode, bool named, bool last_named)
+    : type (type), mode (mode), named (named), last_named (last_named),
+      pass_by_reference (false)
   {}

   /* Return true if the gimple-level type is an aggregate.  */
@@ -105,6 +124,9 @@ public:
      "...").  See also TARGET_STRICT_ARGUMENT_NAMING.  */
   unsigned int named : 1;

+  /* True if this is the last named argument. */
+  unsigned int last_named : 1;
+
   /* True if we have decided to pass the argument by reference, in which case
      the function_arg_info describes a pointer to the original argument.  */
   unsigned int pass_by_reference : 1;
