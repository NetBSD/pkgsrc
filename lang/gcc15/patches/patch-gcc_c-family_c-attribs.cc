$NetBSD: patch-gcc_c-family_c-attribs.cc,v 1.1 2026/07/19 11:17:42 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/c-family/c-attribs.cc.orig	2026-06-12 06:09:06.070517460 +0000
+++ gcc/c-family/c-attribs.cc
@@ -721,6 +721,18 @@ set_musttail_on_return (tree retval, loc
     error_at (loc, "cannot tail-call: return value must be a call");
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
