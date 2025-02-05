$NetBSD: patch-gcc_explow.cc,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/explow.cc
+++ gcc/explow.cc
@@ -37,6 +37,7 @@ along with GCC; see the file COPYING3.  If not see
 #include "langhooks.h"
 #include "except.h"
 #include "dojump.h"
+#include "calls.h"
 #include "explow.h"
 #include "expr.h"
 #include "stringpool.h"
@@ -817,6 +818,16 @@ promote_function_mode (const_tree type, machine_mode mode, int *punsignedp,
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
