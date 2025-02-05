$NetBSD: patch-gcc_calls.cc,v 1.1 2025/02/05 16:30:34 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/calls.cc
+++ gcc/calls.cc
@@ -1376,7 +1376,8 @@ initialize_argument_information (int num_actuals ATTRIBUTE_UNUSED,
 	 with those made by function.cc.  */

       /* See if this argument should be passed by invisible reference.  */
-      function_arg_info arg (type, argpos < n_named_args);
+      function_arg_info arg (type, argpos < n_named_args,
+			     argpos == n_named_args - 1);
       if (pass_by_reference (args_so_far_pnt, arg))
 	{
 	  const bool callee_copies
@@ -1496,10 +1497,13 @@ initialize_argument_information (int num_actuals ATTRIBUTE_UNUSED,

       unsignedp = TYPE_UNSIGNED (type);
       arg.type = type;
-      arg.mode
-	= promote_function_mode (type, TYPE_MODE (type), &unsignedp,
-				 fndecl ? TREE_TYPE (fndecl) : fntype, 0);
-
+      arg.mode = TYPE_MODE (type);
+//      arg.mode
+//	= promote_function_mode (type, TYPE_MODE (type), &unsignedp,
+//				 fndecl ? TREE_TYPE (fndecl) : fntype, 0);
+      arg.mode = promote_function_mode (args_so_far, arg,
+					fndecl ? TREE_TYPE (fndecl) : fntype,
+					&unsignedp, 0);
       args[i].unsignedp = unsignedp;
       args[i].mode = arg.mode;

@@ -1549,6 +1553,7 @@ initialize_argument_information (int num_actuals ATTRIBUTE_UNUSED,
 #endif
 			     reg_parm_stack_space,
 			     args[i].pass_on_stack ? 0 : args[i].partial,
+			     args_so_far,
 			     fndecl, args_size, &args[i].locate);
 #ifdef BLOCK_REG_PADDING
       else
@@ -4096,6 +4101,7 @@ split_complex_types (tree types)
   return types;
 }
 
+extern void debug_tree (tree);
 /* Output a library call to function ORGFUN (a SYMBOL_REF rtx)
    for a value of mode OUTMODE,
    with NARGS different arguments, passed as ARGS.
@@ -4281,6 +4287,7 @@ emit_library_call_value_1 (int retval, rtx orgfun, rtx value,
 			   argvec[count].reg != 0,
 #endif
 			   reg_parm_stack_space, 0,
+			   args_so_far,
 			   NULL_TREE, &args_size, &argvec[count].locate);

       if (argvec[count].reg == 0 || argvec[count].partial != 0
@@ -4351,8 +4358,16 @@ emit_library_call_value_1 (int retval, rtx orgfun, rtx value,
 	  val = force_operand (XEXP (slot, 0), NULL_RTX);
 	}

-      arg.mode = promote_function_mode (NULL_TREE, arg.mode, &unsigned_p,
-					NULL_TREE, 0);
+//      arg.mode = promote_function_mode (NULL_TREE, arg.mode, &unsigned_p,
+//					NULL_TREE, 0);
+      tree t = arg.type;
+if (t)
+  debug_tree (t);
+gcc_assert (!t);
+      arg.type = NULL_TREE;
+      arg.mode = promote_function_mode (args_so_far, arg, NULL_TREE,
+					&unsigned_p, 0);
+      arg.type = t;
       argvec[count].mode = arg.mode;
       argvec[count].value = convert_modes (arg.mode, GET_MODE (val), val,
 					   unsigned_p);
@@ -4372,6 +4387,7 @@ emit_library_call_value_1 (int retval, rtx orgfun, rtx value,
 			       argvec[count].reg != 0,
 #endif
 			       reg_parm_stack_space, argvec[count].partial,
+			       args_so_far,
 			       NULL_TREE, &args_size, &argvec[count].locate);
 	  args_size.constant += argvec[count].locate.size.constant;
 	  gcc_assert (!argvec[count].locate.size.var);
