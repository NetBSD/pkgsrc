$NetBSD: patch-gcc_function.cc,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/function.cc
+++ gcc/function.cc
@@ -58,8 +58,8 @@ along with GCC; see the file COPYING3.  If not see
 #include "varasm.h"
 #include "except.h"
 #include "dojump.h"
-#include "explow.h"
 #include "calls.h"
+#include "explow.h"
 #include "expr.h"
 #include "optabs-tree.h"
 #include "output.h"
@@ -2449,7 +2449,10 @@ assign_parm_find_data_types (struct assign_parm_data_all *all, tree parm,
   else if (DECL_CHAIN (parm))
     data->arg.named = 1;  /* Not the last non-variadic parm. */
   else if (targetm.calls.strict_argument_naming (all->args_so_far))
-    data->arg.named = 1;  /* Only variadic ones are unnamed.  */
+    {
+      data->arg.named = 1;  /* Only variadic ones are unnamed.  */
+      data->arg.last_named = 1;
+    }
   else
     data->arg.named = 0;  /* Treat as variadic.  */

@@ -2491,9 +2494,12 @@ assign_parm_find_data_types (struct assign_parm_data_all *all, tree parm,

   /* Find mode as it is passed by the ABI.  */
   unsignedp = TYPE_UNSIGNED (data->arg.type);
-  data->arg.mode
-    = promote_function_mode (data->arg.type, data->arg.mode, &unsignedp,
-			     TREE_TYPE (current_function_decl), 0);
+//  data->arg.mode
+//    = promote_function_mode (data->arg.type, data->arg.mode, &unsignedp,
+//			     TREE_TYPE (current_function_decl), 0);
+  data->arg.mode = promote_function_mode (all->args_so_far, data->arg,
+					  TREE_TYPE (current_function_decl),
+					  &unsignedp, 0);
 }

 /* A subroutine of assign_parms.  Invoke setup_incoming_varargs.  */
@@ -2506,6 +2512,7 @@ assign_parms_setup_varargs (struct assign_parm_data_all *all,

   function_arg_info last_named_arg = data->arg;
   last_named_arg.named = true;
+  last_named_arg.last_named = true;
   targetm.calls.setup_incoming_varargs (all->args_so_far, last_named_arg,
 					&varargs_pretend_bytes, no_rtl);

@@ -2614,7 +2621,9 @@ assign_parm_find_entry_rtl (struct assign_parm_data_all *all,

   locate_and_pad_parm (data->arg.mode, data->arg.type, in_regs,
 		       all->reg_parm_stack_space,
-		       entry_parm ? data->partial : 0, current_function_decl,
+		       entry_parm ? data->partial : 0,
+		       all->args_so_far,
+		       current_function_decl,
 		       &all->stack_args_size, &data->locate);

   /* Update parm_stack_boundary if this parameter is passed in the
@@ -3921,7 +3930,8 @@ gimplify_parameters (gimple_seq *cleanup)
       if (data.arg.pass_by_reference)
 	{
 	  tree type = TREE_TYPE (data.arg.type);
-	  function_arg_info orig_arg (type, data.arg.named);
+	  function_arg_info orig_arg (type, data.arg.named,
+				      data.arg.last_named);
 	  if (reference_callee_copied (&all.args_so_far_v, orig_arg))
 	    {
 	      tree local, t;
@@ -4024,6 +4034,7 @@ gimplify_parameters (gimple_seq *cleanup)
 void
 locate_and_pad_parm (machine_mode passed_mode, tree type, int in_regs,
 		     int reg_parm_stack_space, int partial,
+		     cumulative_args_t ca,
 		     tree fndecl ATTRIBUTE_UNUSED,
 		     struct args_size *initial_offset_ptr,
 		     struct locate_and_pad_arg_data *locate)
@@ -4061,9 +4072,23 @@ locate_and_pad_parm (machine_mode passed_mode, tree type, int in_regs,
 	      ? arg_size_in_bytes (type)
 	      : size_int (GET_MODE_SIZE (passed_mode)));
   where_pad = targetm.calls.function_arg_padding (passed_mode, type);
-  boundary = targetm.calls.function_arg_boundary (passed_mode, type);
-  round_boundary = targetm.calls.function_arg_round_boundary (passed_mode,
-							      type);
+
+  if (flag_stack_use_cumulative_args)
+    {
+      boundary = targetm.calls.function_arg_boundary_ca (passed_mode,
+							 type,
+							 ca);
+      round_boundary = targetm.calls.function_arg_round_boundary_ca
+	(passed_mode, type, ca);
+    }
+  else
+    {
+      boundary = targetm.calls.function_arg_boundary (passed_mode,
+						      type);
+      round_boundary = targetm.calls.function_arg_round_boundary
+	(passed_mode, type);
+    }
+
   locate->where_pad = where_pad;

   /* Alignment can't exceed MAX_SUPPORTED_STACK_ALIGNMENT.  */
