$NetBSD: patch-gcc_builtins.cc,v 1.1 2025/04/25 19:35:10 dkazankov Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/builtins.cc
+++ gcc/builtins.cc
@@ -5929,6 +5929,13 @@ expand_builtin_trap (void)
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
