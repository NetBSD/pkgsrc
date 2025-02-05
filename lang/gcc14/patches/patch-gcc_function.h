$NetBSD: patch-gcc_function.h,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/function.h
+++ gcc/function.h
@@ -20,6 +20,7 @@ along with GCC; see the file COPYING3.  If not see
 #ifndef GCC_FUNCTION_H
 #define GCC_FUNCTION_H

+#include "cumulative-args.h"

 /* Stack of pending (incomplete) sequences saved by `start_sequence'.
    Each element describes one pending sequence.
@@ -680,6 +681,7 @@ extern bool aggregate_value_p (const_tree, const_tree);
 extern bool use_register_for_decl (const_tree);
 extern gimple_seq gimplify_parameters (gimple_seq *);
 extern void locate_and_pad_parm (machine_mode, tree, int, int, int,
+				 cumulative_args_t,
 				 tree, struct args_size *,
 				 struct locate_and_pad_arg_data *);
 extern void generate_setjmp_warnings (void);
