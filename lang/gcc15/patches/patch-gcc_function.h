$NetBSD: patch-gcc_function.h,v 1.1 2026/07/19 11:17:44 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/function.h.orig	2026-06-12 06:09:06.484523868 +0000
+++ gcc/function.h
@@ -20,6 +20,7 @@ along with GCC; see the file COPYING3.
 #ifndef GCC_FUNCTION_H
 #define GCC_FUNCTION_H

+#include "cumulative-args.h"

 /* Stack of pending (incomplete) sequences saved by `start_sequence'.
    Each element describes one pending sequence.
@@ -686,6 +687,7 @@ extern bool aggregate_value_p (const_tre
 extern bool use_register_for_decl (const_tree);
 extern gimple_seq gimplify_parameters (gimple_seq *);
 extern void locate_and_pad_parm (machine_mode, tree, int, int, int,
+				 cumulative_args_t,
 				 tree, struct args_size *,
 				 struct locate_and_pad_arg_data *);
 extern void generate_setjmp_warnings (void);
