$NetBSD: patch-gcc_config_darwin-protos.h,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/darwin-protos.h
+++ gcc/config/darwin-protos.h
@@ -86,9 +86,12 @@ extern void darwin_asm_lto_end (void);
 extern void darwin_mark_decl_preserved (const char *);

 extern tree darwin_handle_kext_attribute (tree *, tree, tree, int, bool *);
-extern tree darwin_handle_weak_import_attribute (tree *node, tree name,
-						 tree args, int flags,
-						 bool * no_add_attrs);
+extern tree darwin_handle_weak_import_attribute (tree *, tree, tree, int,
+						 bool *);
+extern tree darwin_handle_availability_attribute (tree *, tree, tree,
+						  int, bool *);
+extern bool darwin_attribute_takes_identifier_p (const_tree);
+
 extern void machopic_output_stub (FILE *, const char *, const char *);
 extern void darwin_globalize_label (FILE *, const char *);
 extern void darwin_assemble_visibility (tree, int);
@@ -124,6 +127,7 @@ extern void darwin_enter_string_into_cfstring_table (tree);
 extern void darwin_asm_output_anchor (rtx symbol);
 extern bool darwin_use_anchors_for_symbol_p (const_rtx symbol);
 extern bool darwin_kextabi_p (void);
+extern bool darwin_unreachable_traps_p (void);
 extern void darwin_override_options (void);
 extern void darwin_patch_builtins (void);
 extern void darwin_rename_builtins (void);
