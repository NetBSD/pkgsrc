$NetBSD: patch-gcc_c_c-decl.cc,v 1.1 2026/07/19 11:17:42 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/c/c-decl.cc.orig	2026-06-12 06:09:06.079517599 +0000
+++ gcc/c/c-decl.cc
@@ -7360,6 +7360,25 @@ grokdeclarator (const struct c_declarato
 		  }

 		size = c_fully_fold (size, false, &size_maybe_const);
+		bool size_const_var = false;
+		if (flag_allow_const_var_array_size)
+		  {
+		    tree maybe_const_size = TREE_CODE (size) == NOP_EXPR
+					    ? TREE_OPERAND (size, 0) : size;
+		    size_const_var
+		      = (TREE_CODE (maybe_const_size) == VAR_DECL
+			 && TREE_READONLY (maybe_const_size)
+			 && !TREE_THIS_VOLATILE (maybe_const_size));
+		    if (size_const_var
+			&& size_maybe_const
+			&& DECL_INITIAL (maybe_const_size))
+		      {
+			size = DECL_INITIAL (maybe_const_size);
+			size = c_fully_fold (size, false, &size_maybe_const);
+			size_int_const = (TREE_CODE (size) == INTEGER_CST
+					  && !TREE_OVERFLOW (size));
+		      }
+		  }

 		if (pedantic && size_maybe_const && integer_zerop (size))
 		  {
@@ -7401,6 +7420,9 @@ grokdeclarator (const struct c_declarato
 			  this_size_varies = size_varies = true;
 			warn_variable_length_array (name, size);
 		      }
+		    if (flag_allow_const_var_array_size && size_const_var)
+		      pedwarn (input_location, OPT_Wpedantic,
+			       "variably modified %qE at file scope", name);
 		  }
 		else if ((decl_context == NORMAL || decl_context == FIELD)
 			 && current_scope == file_scope)
