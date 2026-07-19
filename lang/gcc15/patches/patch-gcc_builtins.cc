$NetBSD: patch-gcc_builtins.cc,v 1.1 2026/07/19 11:17:42 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/builtins.cc.orig	2026-06-12 06:09:06.067517413 +0000
+++ gcc/builtins.cc
@@ -5962,6 +5962,13 @@ expand_builtin_trap (void)
 static void
 expand_builtin_unreachable (void)
 {
+  /* If the target wants a trap in place of the fall-through, use that.  */
+  if (targetm.unreachable_should_trap ())
+    {
+      expand_builtin_trap ();
+      return;
+    }
+
   /* Use gimple_build_builtin_unreachable or builtin_decl_unreachable
      to avoid this.  */
   gcc_checking_assert (!sanitize_flags_p (SANITIZE_UNREACHABLE));
