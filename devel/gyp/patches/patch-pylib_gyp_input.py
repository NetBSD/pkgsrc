$NetBSD: patch-pylib_gyp_input.py,v 1.1 2026/07/04 06:39:26 taca Exp $

Stop SyntaxWarning: "is" with 'str' literal.

--- pylib/gyp/input.py.orig	2026-02-04 00:01:38.000000000 +0000
+++ pylib/gyp/input.py
@@ -1183,7 +1183,7 @@ def LoadVariablesFromVariablesDict(varia
       if variable_name in variables:
         # If the variable is already set, don't set it.
         continue
-      if the_dict_key is 'variables' and variable_name in the_dict:
+      if the_dict_key == 'variables' and variable_name in the_dict:
         # If the variable is set without a % in the_dict, and the_dict is a
         # variables dict (making |variables| a varaibles sub-dict of a
         # variables dict), use the_dict's definition.
