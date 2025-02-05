$NetBSD: patch-gcc_c-family_c-lex.cc,v 1.1 2025/02/05 16:30:34 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/c-family/c-lex.cc
+++ gcc/c-family/c-lex.cc
@@ -584,6 +584,21 @@ c_lex_with_flags (tree *value, location_t *loc, unsigned char *cpp_flags,

     case CPP_NUMBER:
       {
+	/* If the user wants number-like entities to be returned as a raw
+	   string, then don't try to classify them, which emits unwanted
+	   diagnostics.  */
+	if (lex_flags & C_LEX_NUMBER_AS_STRING)
+	  {
+	    /* build_string adds a trailing NUL at [len].  */
+	    tree num_string = build_string (tok->val.str.len + 1,
+					    (const char *) tok->val.str.text);
+	    TREE_TYPE (num_string) = char_array_type_node;
+	    *value = num_string;
+	    /* We will effectively note this as CPP_N_INVALID, because we
+	       made no checks here.  */
+	    break;
+	  }
+
 	const char *suffix = NULL;
 	unsigned int flags = cpp_classify_number (parse_in, tok, &suffix, *loc);
