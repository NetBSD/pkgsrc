$NetBSD: patch-gcc_c-family_c-attribs.cc,v 1.2 2025/06/08 07:37:45 wiz Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/c-family/c-attribs.cc.orig	2025-05-23 11:02:04.244196764 +0000
+++ gcc/c-family/c-attribs.cc
@@ -665,6 +665,18 @@ attribute_takes_identifier_p (const_tree
     return targetm.attribute_takes_identifier_p (attr_id);
 }
 
+/* Returns TRUE iff the attribute indicated by ATTR_ID needs its
+   arguments converted to string constants.  */
+
+bool
+attribute_clang_form_p (const_tree attr_id)
+{
+  const struct attribute_spec *spec = lookup_attribute_spec (attr_id);
+  if (spec && !strcmp ("availability", spec->name))
+    return true;
+  return false;
+}
+
 /* Verify that argument value POS at position ARGNO to attribute NAME
    applied to function FN (which is either a function declaration or function
    type) refers to a function parameter at position POS and the expected type
