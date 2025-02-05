$NetBSD: patch-gcc_cp_parser.cc,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/cp/parser.cc
+++ gcc/cp/parser.cc
@@ -705,6 +705,91 @@ cp_lexer_handle_early_pragma (cp_lexer *lexer)
 static cp_parser *cp_parser_new (cp_lexer *);
 static GTY (()) cp_parser *the_parser;

+/* Context-sensitive parse-checking for clang-style attributes.  */
+
+enum clang_attr_state {
+  CA_NONE = 0,
+  CA_ATTR,
+  CA_BR1, CA_BR2,
+  CA_LIST,
+  CA_LIST_ARGS,
+  CA_IS_CA,
+  CA_CA_ARGS,
+  CA_LIST_CONT
+};
+
+/* State machine tracking context of attribute lexing.  */
+
+static enum clang_attr_state
+cp_lexer_attribute_state (cp_token& token, enum clang_attr_state attr_state)
+{
+  /* Implement a context-sensitive parser for clang attributes.
+     We detect __attribute__((clang_style_attribute (ARGS))) and lex the
+     args ARGS with the following differences from GNU attributes:
+	(a) number-like values are lexed as strings [this allows lexing XX.YY.ZZ
+	   version numbers].
+	(b) we concatenate strings, since clang attributes allow this too.  */
+  switch (attr_state)
+    {
+    case CA_NONE:
+      if (token.type == CPP_KEYWORD
+	  && token.keyword == RID_ATTRIBUTE)
+	attr_state = CA_ATTR;
+      break;
+    case CA_ATTR:
+      if (token.type == CPP_OPEN_PAREN)
+	attr_state = CA_BR1;
+      else
+	attr_state = CA_NONE;
+      break;
+    case CA_BR1:
+      if (token.type == CPP_OPEN_PAREN)
+	attr_state = CA_BR2;
+      else
+	attr_state = CA_NONE;
+      break;
+    case CA_BR2:
+      if (token.type == CPP_NAME)
+	{
+	  tree identifier = (token.type == CPP_KEYWORD)
+	    /* For keywords, use the canonical spelling, not the
+	       parsed identifier.  */
+	    ? ridpointers[(int) token.keyword]
+	    : token.u.value;
+	  identifier = canonicalize_attr_name (identifier);
+	  if (attribute_clang_form_p (identifier))
+	    attr_state = CA_IS_CA;
+	  else
+	    attr_state = CA_LIST;
+	}
+      else
+	attr_state = CA_NONE;
+      break;
+    case CA_IS_CA:
+    case CA_LIST:
+      if (token.type == CPP_COMMA)
+	attr_state = CA_BR2; /* Back to the list outer.  */
+      else if (token.type == CPP_OPEN_PAREN)
+	attr_state = attr_state == CA_IS_CA ? CA_CA_ARGS
+					    : CA_LIST_ARGS;
+      else
+	attr_state = CA_NONE;
+      break;
+    case CA_CA_ARGS: /* We will special-case args in this state.  */
+    case CA_LIST_ARGS:
+      if (token.type == CPP_CLOSE_PAREN)
+	attr_state = CA_LIST_CONT;
+      break;
+    case CA_LIST_CONT:
+      if (token.type == CPP_COMMA)
+	attr_state = CA_BR2; /* Back to the list outer.  */
+      else
+	attr_state = CA_NONE;
+      break;
+    }
+  return attr_state;
+}
+
 /* Create a new main C++ lexer, the lexer that gets tokens from the
    preprocessor, and also create the main parser.  */

@@ -721,6 +806,8 @@ cp_lexer_new_main (void)
   c_common_no_more_pch ();

   cp_lexer *lexer = cp_lexer_alloc ();
+  enum clang_attr_state attr_state = CA_NONE;
+
   /* Put the first token in the buffer.  */
   cp_token *tok = lexer->buffer->quick_push (token);

@@ -744,8 +831,14 @@ cp_lexer_new_main (void)
       if (tok->type == CPP_PRAGMA_EOL)
 	cp_lexer_handle_early_pragma (lexer);

+      attr_state = cp_lexer_attribute_state (*tok, attr_state);
       tok = vec_safe_push (lexer->buffer, cp_token ());
-      cp_lexer_get_preprocessor_token (C_LEX_STRING_NO_JOIN, tok);
+      unsigned int flags = C_LEX_STRING_NO_JOIN;
+      /* If we are processing clang-style attribute args, lex numbers as
+         potential version strings; NN .. NN.MM .. NN.MM.OO */
+      if (attr_state == CA_CA_ARGS)
+	flags |= C_LEX_NUMBER_AS_STRING;
+      cp_lexer_get_preprocessor_token (flags, tok);
     }

   lexer->next_token = lexer->buffer->address ();
@@ -962,7 +1055,7 @@ cp_lexer_get_preprocessor_token (unsigned flags, cp_token *token)
 {
   static int is_extern_c = 0;

-   /* Get a new token from the preprocessor.  */
+   /* Get a new token from the preprocessor. */
   token->type
     = c_lex_with_flags (&token->u.value, &token->location, &token->flags,
 			flags);
@@ -23348,9 +23441,16 @@ cp_parser_init_declarator (cp_parser* parser,
 		      "an %<asm%> specification is not allowed "
 		      "on a function-definition");
 	  if (attributes)
-	    error_at (attributes_start_token->location,
-		      "attributes are not allowed "
-		      "on a function-definition");
+	    {
+	      /* When we are allowing attributes in this position, then add
+		 them to the prefix ones.  */
+	      if (flag_allow_ext_attr_placement)
+		prefix_attributes = chainon (prefix_attributes, attributes);
+	      else
+		error_at (attributes_start_token->location,
+			  "attributes are not allowed "
+			  "on a function-definition");
+	    }
 	  /* This is a function-definition.  */
 	  *function_definition_p = true;

@@ -29707,6 +29807,91 @@ cp_parser_gnu_attributes_opt (cp_parser* parser)
   return attributes;
 }

+/* Parse the arguments list for a clang attribute.   */
+static tree
+cp_parser_clang_attribute (cp_parser *parser, tree/*attr_id*/)
+{
+  /* Each entry can be :
+     identifier
+     identifier=N.MM.Z
+     identifier="string"
+     followed by ',' or ) for the last entry*/
+
+  matching_parens parens;
+  if (!parens.require_open (parser))
+    return NULL;
+
+  bool save_translate_strings_p = parser->translate_strings_p;
+  parser->translate_strings_p = false;
+  tree attr_args = NULL_TREE;
+  cp_token *token;
+  do
+    {
+      tree name = NULL_TREE;
+      tree value = NULL_TREE;
+
+      token = cp_lexer_peek_token (parser->lexer);
+      if (token->type == CPP_NAME)
+	name = token->u.value;
+      else if (token->type == CPP_KEYWORD)
+	name = ridpointers[(int) token->keyword];
+      else if (token->flags & NAMED_OP)
+	name = get_identifier (cpp_type2name (token->type, token->flags));
+      else
+	{
+	  /* FIXME: context-sensitive for that attrib.  */
+	  error_at (token->location, "expected an attribute keyword");
+	  cp_parser_skip_to_closing_parenthesis (parser,
+						 /*recovering=*/true,
+						 /*or_comma=*/false,
+						 /*consume_paren=*/false);
+	  attr_args = error_mark_node;
+	  break;
+	}
+      cp_lexer_consume_token (parser->lexer);
+
+      if (cp_lexer_next_token_is (parser->lexer, CPP_EQ))
+	{
+	  cp_lexer_consume_token (parser->lexer); /* eat the '=' */
+	  if (cp_lexer_next_token_is_not (parser->lexer, CPP_CLOSE_PAREN)
+	      && cp_lexer_next_token_is_not (parser->lexer, CPP_COMMA))
+	    {
+	      token = cp_lexer_peek_token (parser->lexer);
+	      if (token->type == CPP_STRING)
+		value = cp_parser_string_literal (parser, /*translate=*/false,
+					    /*wide_ok=*/false);
+	      else
+		{
+		  value = token->u.value;
+		  cp_lexer_consume_token (parser->lexer);
+		}
+	    }
+	  /* else value is missing.  */
+	}
+      else if (cp_lexer_next_token_is_not (parser->lexer, CPP_CLOSE_PAREN)
+	       && cp_lexer_next_token_is_not (parser->lexer, CPP_COMMA))
+	{
+	  error_at (token->location, "expected %<,%>, %<=%> or %<)%>");
+	  cp_parser_skip_to_closing_parenthesis (parser,
+						 /*recovering=*/true,
+						 /*or_comma=*/false,
+						 /*consume_paren=*/false);
+	  attr_args = error_mark_node;
+	  break;
+	}
+    if (cp_lexer_next_token_is (parser->lexer, CPP_COMMA))
+      cp_lexer_consume_token (parser->lexer);
+    tree t = tree_cons (value, name, NULL_TREE);
+    attr_args = chainon (attr_args, t);
+  } while (cp_lexer_next_token_is_not (parser->lexer, CPP_CLOSE_PAREN));
+
+  parser->translate_strings_p = save_translate_strings_p;
+  if (!parens.require_close (parser))
+    return error_mark_node;
+
+  return attr_args;
+}
+
 /* Parse a GNU attribute-list.

    attribute-list:
@@ -29766,9 +29951,12 @@ cp_parser_gnu_attribute_list (cp_parser* parser, bool exactly_one /* = false */)

 	  /* Peek at the next token.  */
 	  token = cp_lexer_peek_token (parser->lexer);
-	  /* If it's an `(', then parse the attribute arguments.  */
-	  if (token->type == CPP_OPEN_PAREN)
+	  if (token->type == CPP_OPEN_PAREN
+	      && attribute_clang_form_p (identifier))
+	    arguments = cp_parser_clang_attribute (parser, identifier);
+	  else if (token->type == CPP_OPEN_PAREN)
 	    {
+	      /* If it's an `(', then parse the attribute arguments.  */
 	      vec<tree, va_gc> *vec;
 	      int attr_flag = (attribute_takes_identifier_p (identifier)
 			       ? id_attr : normal_attr);
@@ -29785,12 +29973,12 @@ cp_parser_gnu_attribute_list (cp_parser* parser, bool exactly_one /* = false */)
 		  arguments = build_tree_list_vec (vec);
 		  release_tree_vector (vec);
 		}
-	      /* Save the arguments away.  */
-	      TREE_VALUE (attribute) = arguments;
 	    }

 	  if (arguments != error_mark_node)
 	    {
+	      /* Save the arguments away.  */
+	      TREE_VALUE (attribute) = arguments;
 	      /* Add this attribute to the list.  */
 	      TREE_CHAIN (attribute) = attribute_list;
 	      attribute_list = attribute;
