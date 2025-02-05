$NetBSD: patch-gcc_explow.h,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/explow.h
+++ gcc/explow.h
@@ -20,6 +20,8 @@ along with GCC; see the file COPYING3.  If not see
 #ifndef GCC_EXPLOW_H
 #define GCC_EXPLOW_H

+#include "calls.h" /* for cummulative args stuff.  */
+
 /* Return a memory reference like MEMREF, but which is known to have a
    valid address.  */
 extern rtx validize_mem (rtx);
@@ -47,8 +49,13 @@ extern rtx force_not_mem (rtx);

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
