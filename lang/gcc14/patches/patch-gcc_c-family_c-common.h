$NetBSD: patch-gcc_c-family_c-common.h,v 1.1 2025/02/05 16:30:34 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/c-family/c-common.h
+++ gcc/c-family/c-common.h
@@ -1628,6 +1628,7 @@ extern void check_for_xor_used_as_pow (location_t lhs_loc, tree lhs_val,
 /* In c-attribs.cc.  */
 extern bool attribute_takes_identifier_p (const_tree);
 extern tree handle_deprecated_attribute (tree *, tree, tree, int, bool *);
+extern bool attribute_clang_form_p (const_tree);
 extern tree handle_unused_attribute (tree *, tree, tree, int, bool *);
 extern tree handle_fallthrough_attribute (tree *, tree, tree, int, bool *);
 extern int parse_tm_stmt_attr (tree, int);
