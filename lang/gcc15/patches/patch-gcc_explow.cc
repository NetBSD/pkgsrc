$NetBSD: patch-gcc_explow.cc,v 1.1 2026/07/19 11:17:44 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/explow.cc.orig	2026-06-12 06:09:06.444523249 +0000
+++ gcc/explow.cc
@@ -37,6 +37,7 @@ along with GCC; see the file COPYING3.
 #include "langhooks.h"
 #include "except.h"
 #include "dojump.h"
+#include "calls.h"
 #include "explow.h"
 #include "expr.h"
 #include "stringpool.h"
@@ -864,6 +865,16 @@ promote_function_mode (const_tree type,
       return mode;
     }
 }
+
+machine_mode
+promote_function_mode (cumulative_args_t args_so_far, function_arg_info arg,
+		       const_tree funtype, int *punsignedp , int for_return)
+{
+  return targetm.calls.promote_function_mode_ca (args_so_far, arg, funtype,
+						 punsignedp, for_return);
+//  return promote_function_mode (arg.type, arg.mode, punsignedp, funtype, for_return);
+}
+
 /* Return the mode to use to store a scalar of TYPE and MODE.
    PUNSIGNEDP points to the signedness of the type and may be adjusted
    to show what signedness to use on extension operations.  */
