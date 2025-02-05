$NetBSD: patch-gcc_c_c-parser.cc,v 1.1 2025/02/05 16:30:34 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/c/c-parser.cc
+++ gcc/c/c-parser.cc
@@ -217,6 +217,9 @@ struct GTY(()) c_parser {
      should translate them to the execution character set (false
      inside attributes).  */
   BOOL_BITFIELD translate_strings_p : 1;
+  /* True if we want to lex arbitrary number-like sequences as their
+     string representation.  */
+  BOOL_BITFIELD lex_number_as_string : 1;

   /* Objective-C specific parser/lexer information.  */

@@ -308,10 +311,10 @@ c_lex_one_token (c_parser *parser, c_token *token, bool raw = false)

   if (raw || vec_safe_length (parser->raw_tokens) == 0)
     {
+      int lex_flags = parser->lex_joined_string ? 0 : C_LEX_STRING_NO_JOIN;
+      lex_flags |= parser->lex_number_as_string ? C_LEX_NUMBER_AS_STRING : 0;
       token->type = c_lex_with_flags (&token->value, &token->location,
-				      &token->flags,
-				      (parser->lex_joined_string
-				       ? 0 : C_LEX_STRING_NO_JOIN));
+				      &token->flags, lex_flags);
       token->id_kind = C_ID_NONE;
       token->keyword = RID_MAX;
       token->pragma_kind = PRAGMA_NONE;
@@ -2579,15 +2582,28 @@ c_parser_declaration_or_fndef (c_parser *parser, bool fndef_ok,
 	    d = d->declarator;
 	  underspec_name = d->u.id.id;
 	}
+      tree postfix_attrs = NULL_TREE;
+      if (flag_allow_ext_attr_placement
+	  && c_parser_next_token_is_keyword (parser, RID_ATTRIBUTE))
+	{
+	  postfix_attrs = c_parser_gnu_attributes (parser);
+	  /* IF we have a function definition, and we're allowing it then
+	     treat these attributes as if they had been prepended.  */
+	  if (c_parser_next_token_is (parser, CPP_OPEN_BRACE))
+	    {
+	      all_prefix_attrs = chainon (all_prefix_attrs, postfix_attrs);
+	      postfix_attrs = NULL_TREE;
+	    }
+	}
       if (c_parser_next_token_is (parser, CPP_EQ)
 	  || c_parser_next_token_is (parser, CPP_COMMA)
 	  || c_parser_next_token_is (parser, CPP_SEMICOLON)
 	  || c_parser_next_token_is_keyword (parser, RID_ASM)
 	  || c_parser_next_token_is_keyword (parser, RID_ATTRIBUTE)
+	  || postfix_attrs
 	  || c_parser_next_token_is_keyword (parser, RID_IN))
 	{
 	  tree asm_name = NULL_TREE;
-	  tree postfix_attrs = NULL_TREE;
 	  if (!diagnosed_no_specs && !specs->declspecs_seen_p)
 	    {
 	      diagnosed_no_specs = true;
@@ -2599,8 +2615,9 @@ c_parser_declaration_or_fndef (c_parser *parser, bool fndef_ok,
 	  if (c_parser_next_token_is_keyword (parser, RID_ASM))
 	    asm_name = c_parser_simple_asm_expr (parser);
 	  if (c_parser_next_token_is_keyword (parser, RID_ATTRIBUTE))
+	    postfix_attrs = c_parser_gnu_attributes (parser);
+	  if (postfix_attrs)
 	    {
-	      postfix_attrs = c_parser_gnu_attributes (parser);
 	      if (c_parser_next_token_is (parser, CPP_OPEN_BRACE))
 		{
 		  /* This means there is an attribute specifier after
@@ -5213,6 +5230,88 @@ c_parser_gnu_attribute_any_word (c_parser *parser)
   return attr_name;
 }

+/* Handle parsing clang-form attribute arguments, where we need to adjust
+   the parsing rules to relate to a specific attribute.  */
+
+static tree
+c_parser_clang_attribute_arguments (c_parser *parser, tree /*attr_id*/)
+{
+  /* We can, if required, alter the parsing on the basis of the attribute.
+     At present, we handle the availability attr, where ach entry can be :
+	identifier
+	identifier=N.MM.Z
+	identifier="string"
+	followed by ',' or ) for the last entry*/
+
+  tree attr_args = NULL_TREE;
+  do
+    {
+      tree name = NULL_TREE;
+      tree value = NULL_TREE;
+
+      if (c_parser_next_token_is (parser, CPP_NAME)
+	  && c_parser_peek_token (parser)->id_kind == C_ID_ID)
+	{
+	  name = c_parser_peek_token (parser)->value;
+	  c_parser_consume_token (parser);
+	}
+      else if (c_parser_next_token_is (parser, CPP_COMMA))
+	name = error_mark_node; /* Comma handled below.  */
+      else
+	{
+	  bool saved_join_state = parser->lex_joined_string;
+	  parser->lex_number_as_string = 1;
+	  parser->lex_joined_string = 1;
+	  c_parser_skip_until_found (parser, CPP_CLOSE_PAREN,
+				     "expected an attribute keyword");
+	  parser->lex_number_as_string = 0;
+	  parser->lex_joined_string = saved_join_state;
+	  return error_mark_node;
+	}
+      if (c_parser_next_token_is (parser, CPP_EQ))
+	{
+	  c_parser_consume_token (parser); /* eat the '=' */
+	  /* We need to bludgeon the lexer into not trying to interpret the
+	     xx.yy.zz form, since that just looks like a malformed float.
+	     Also, as a result of macro processing, we can have strig literals
+	     that are in multiple pieces so, for this specific part of the
+	     parse, we need to join strings.  */
+	  bool saved_join_state = parser->lex_joined_string;
+	  parser->lex_number_as_string = 1;
+	  parser->lex_joined_string = 1;
+	  /* So look at the next token, expecting a string, or something that
+	     looks initially like a number, but might be a version number.  */
+	  c_parser_peek_token (parser);
+	  /* Done with the funky number parsing.  */
+	  parser->lex_number_as_string = 0;
+	  parser->lex_joined_string = saved_join_state;
+	  if (c_parser_next_token_is_not (parser, CPP_CLOSE_PAREN)
+	      && c_parser_next_token_is_not (parser, CPP_COMMA))
+	    {
+	      value = c_parser_peek_token (parser)->value;
+	      /* ???: check for error mark and early-return?  */
+	      c_parser_consume_token (parser);
+	    }
+	  /* else value is absent.  */
+	}
+      else if (c_parser_next_token_is_not (parser, CPP_CLOSE_PAREN)
+	       && c_parser_next_token_is_not (parser, CPP_COMMA))
+	{
+	  c_parser_skip_until_found (parser, CPP_CLOSE_PAREN,
+				     "expected %<,%> or %<=%>");
+	  return error_mark_node;
+	}
+    if (c_parser_next_token_is (parser, CPP_COMMA))
+      c_parser_consume_token (parser); /* Just skip the comma.  */
+    tree t = tree_cons (value, name, NULL);
+    if (!attr_args)
+      attr_args = t;
+    else
+      chainon (attr_args, t);
+  } while (c_parser_next_token_is_not (parser, CPP_CLOSE_PAREN));
+  return attr_args;
+}
+
 /* Parse attribute arguments.  This is a common form of syntax
    covering all currently valid GNU and standard attributes.

@@ -5378,9 +5477,13 @@ c_parser_gnu_attribute (c_parser *parser, tree attrs,
       attrs = chainon (attrs, attr);
       return attrs;
     }
-  c_parser_consume_token (parser);
+  c_parser_consume_token (parser); /* The '('.  */

-  tree attr_args
+  tree attr_args;
+  if (attribute_clang_form_p (attr_name))
+    attr_args = c_parser_clang_attribute_arguments (parser, attr_name);
+  else
+    attr_args
     = c_parser_attribute_arguments (parser,
 				    attribute_takes_identifier_p (attr_name),
 				    false,
