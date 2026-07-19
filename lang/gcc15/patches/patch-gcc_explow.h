$NetBSD: patch-gcc_explow.h,v 1.1 2026/07/19 11:17:44 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/explow.h.orig	2026-06-12 06:09:06.444523249 +0000
+++ gcc/explow.h
@@ -20,6 +20,8 @@ along with GCC; see the file COPYING3.
 #ifndef GCC_EXPLOW_H
 #define GCC_EXPLOW_H

+#include "calls.h" /* for cummulative args stuff.  */
+
 /* Return a memory reference like MEMREF, but which is known to have a
    valid address.  */
 extern rtx validize_mem (rtx);
@@ -51,8 +53,13 @@ extern rtx force_not_mem (rtx);

 /* Return mode and signedness to use when an argument or result in the
    given mode is promoted.  */
-extern machine_mode promote_function_mode (const_tree, machine_mode, int *,
-					        const_tree, int);
+machine_mode promote_function_mode (const_tree, machine_mode, int *,
+				    const_tree, int);
+
+/* Return mode and signedness to use when an argument or result in the
+   given mode is promoted.  */
+machine_mode promote_function_mode (cumulative_args_t, function_arg_info,
+				    const_tree, int *, int);

 /* Return mode and signedness to use when an object in the given mode
    is promoted.  */
