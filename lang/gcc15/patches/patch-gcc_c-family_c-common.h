$NetBSD: patch-gcc_c-family_c-common.h,v 1.1 2026/07/19 11:17:42 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/c-family/c-common.h.orig	2026-06-12 06:09:06.072517491 +0000
+++ gcc/c-family/c-common.h
@@ -447,6 +447,8 @@ extern machine_mode c_default_pointer_mo
 #define D_CXX20		0x8000  /* In C++, C++20 only.  */
 #define D_CXX_COROUTINES 0x10000  /* In C++, only with coroutines.  */
 #define D_CXX_MODULES	0x20000  /* In C++, only with modules.  */
+#define D_EXT_C_IN_CXX	0x40000  /* In C++, allow additional C keywords.  */
+#define D_EXT_CXX_IN_C	0x80000  /* In C, allow additional C++ keywords.  */

 #define D_CXX_CONCEPTS_FLAGS D_CXXONLY | D_CXX_CONCEPTS
 #define D_CXX_CHAR8_T_FLAGS D_CXXONLY | D_CXX_CHAR8_T
@@ -1671,6 +1673,7 @@ extern void check_for_xor_used_as_pow (l
 /* In c-attribs.cc.  */
 extern bool attribute_takes_identifier_p (const_tree);
 extern tree handle_deprecated_attribute (tree *, tree, tree, int, bool *);
+extern bool attribute_clang_form_p (const_tree);
 extern tree handle_unused_attribute (tree *, tree, tree, int, bool *);
 extern tree handle_fallthrough_attribute (tree *, tree, tree, int, bool *);
 extern int parse_tm_stmt_attr (tree, int);
