$NetBSD: patch-gcc_c_c-decl.c,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/c/c-decl.c.orig	2014-04-10 07:54:08.000000000 +0000
+++ gcc/c/c-decl.c
@@ -4859,6 +4859,8 @@ warn_variable_length_array (tree name, t
 		     "variable length array is used");
 	}
     }
+    if (warn_variable_decl)
+      warning (OPT_Wvariable_decl, "variable-sized array %qE", name);
 }
 
 /* Given declspecs and a declarator,
