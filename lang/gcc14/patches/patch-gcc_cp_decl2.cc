$NetBSD: patch-gcc_cp_decl2.cc,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/cp/decl2.cc
+++ gcc/cp/decl2.cc
@@ -3839,9 +3839,8 @@ get_tls_init_fn (tree var)
   if (!flag_extern_tls_init && DECL_EXTERNAL (var))
     return NULL_TREE;

-  /* If the variable is internal, or if we can't generate aliases,
-     call the local init function directly.  */
-  if (!TREE_PUBLIC (var) || !TARGET_SUPPORTS_ALIASES)
+  /* If the variable is internal call the local init function directly.  */
+  if (!TREE_PUBLIC (var))
     return get_local_tls_init_fn (DECL_SOURCE_LOCATION (var));

   tree sname = mangle_tls_init_fn (var);
@@ -4005,6 +4004,25 @@ generate_tls_wrapper (tree fn)
   expand_or_defer_fn (finish_function (/*inline_p=*/false));
 }

+/* A dummy init function to act as a weak placeholder for a (possibly non-
+   existent) dynamic init.  */
+static void
+generate_tls_dummy_init (tree fn)
+{
+  tree var = DECL_BEFRIENDING_CLASSES (fn);
+  tree init_fn = get_tls_init_fn (var);
+  /* If have no init fn, or it is non-weak, then we do not need to make a
+     dummy.  */
+  if (!init_fn || !lookup_attribute ("weak", DECL_ATTRIBUTES (init_fn)))
+    return;
+  start_preparsed_function (init_fn, NULL_TREE, SF_DEFAULT | SF_PRE_PARSED);
+  tree body = begin_function_body ();
+  declare_weak (init_fn);
+  finish_return_stmt (NULL_TREE);
+  finish_function_body (body);
+  expand_or_defer_fn (finish_function (/*inline_p=*/false));
+}
+
 /* Start a global constructor or destructor function.  */

 static tree
@@ -4823,22 +4841,24 @@ handle_tls_init (void)
   finish_expr_stmt (cp_build_modify_expr (loc, guard, NOP_EXPR,
 					  boolean_true_node,
 					  tf_warning_or_error));
+  auto_vec<tree> direct_calls;
   for (; vars; vars = TREE_CHAIN (vars))
     {
       tree var = TREE_VALUE (vars);
       tree init = TREE_PURPOSE (vars);
       one_static_initialization_or_destruction (/*initp=*/true, var, init);

-      /* Output init aliases even with -fno-extern-tls-init.  */
-      if (TARGET_SUPPORTS_ALIASES && TREE_PUBLIC (var))
+      /* Output inits even with -fno-extern-tls-init.
+	We save the list here and output either an alias or a stub function
+	below.  */
+      if (TREE_PUBLIC (var))
 	{
-          tree single_init_fn = get_tls_init_fn (var);
+	  tree single_init_fn = get_tls_init_fn (var);
 	  if (single_init_fn == NULL_TREE)
 	    continue;
-	  cgraph_node *alias
-	    = cgraph_node::get_create (fn)->create_same_body_alias
-		(single_init_fn, fn);
-	  gcc_assert (alias != NULL);
+	  if (single_init_fn == fn)
+	    continue;
+	  direct_calls.safe_push (single_init_fn);
 	}
     }

@@ -4846,6 +4866,30 @@ handle_tls_init (void)
   finish_if_stmt (if_stmt);
   finish_function_body (body);
   expand_or_defer_fn (finish_function (/*inline_p=*/false));
+
+  /* For each TLS var that we have an init function, we either emit an alias
+     between that and the tls_init, or a stub function that just calls the
+     tls_init.  */
+  while (!direct_calls.is_empty())
+    {
+      tree single_init_fn = direct_calls.pop ();
+      if (TARGET_SUPPORTS_ALIASES)
+	{
+	  cgraph_node *alias
+	     = cgraph_node::get_create (fn)->create_same_body_alias
+		(single_init_fn, fn);
+	  gcc_assert (alias != NULL);
+	}
+      else
+	{
+	  start_preparsed_function (single_init_fn, NULL_TREE, SF_PRE_PARSED);
+	  tree body = begin_function_body ();
+	  tree r = build_call_expr (fn, 0);
+	  finish_expr_stmt (r);
+	  finish_function_body (body);
+	  expand_or_defer_fn (finish_function (/*inline_p=*/false));
+	}
+    }
 }

 /* We're at the end of compilation, so generate any mangling aliases that
@@ -5265,7 +5309,14 @@ c_parse_final_cleanups (void)
 	    }

 	  if (!DECL_INITIAL (decl) && decl_tls_wrapper_p (decl))
-	    generate_tls_wrapper (decl);
+	    {
+	      generate_tls_wrapper (decl);
+	      /* The wrapper might have a weak reference to an init, we provide
+		 a dummy function to satisfy that here.  The linker/dynamic
+		 loader will override this with the actual init, if one is
+		 required.  */
+	      generate_tls_dummy_init (decl);
+	    }

 	  if (!DECL_SAVED_TREE (decl))
 	    continue;
