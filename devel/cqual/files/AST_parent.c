/* Automatically generated from nodetypes.def, do not edit. */

/* See the copyright notice in nodetypes.def */
case kind_node: break;
case kind_declaration: case kind_error_decl: break;
case kind_statement: case kind_error_stmt: break;
case kind_expression: case kind_error_expr: break;
case kind_type_element: break;
case kind_declarator: break;
case kind_label: break;
case kind_asm_decl: {
  asm_decl x = CAST(asm_decl, n);

  AST_set_parent_list(&x->asm_stmt, n);
  break;
}
case kind_data_decl: {
  data_decl x = CAST(data_decl, n);

  AST_set_parent_list(&x->modifiers, n);
  AST_set_parent_list(&x->attributes, n);
  AST_set_parent_list(&x->decls, n);
  break;
}
case kind_extension_decl: {
  extension_decl x = CAST(extension_decl, n);

  AST_set_parent_list(&x->decl, n);
  break;
}
case kind_ellipsis_decl: {
  ellipsis_decl x = CAST(ellipsis_decl, n);

  AST_set_parent_list(&x->qualifiers, n);
  break;
}
case kind_enumerator: {
  enumerator x = CAST(enumerator, n);

  AST_set_parent_list(&x->arg1, n);
  break;
}
case kind_oldidentifier_decl: break;
case kind_function_decl: {
  function_decl x = CAST(function_decl, n);

  AST_set_parent_list(&x->declarator, n);
  AST_set_parent_list(&x->qualifiers, n);
  AST_set_parent_list(&x->attributes, n);
  AST_set_parent_list(&x->stmt, n);
  break;
}
case kind_implicit_decl: break;
case kind_variable_decl: {
  variable_decl x = CAST(variable_decl, n);

  AST_set_parent_list(&x->declarator, n);
  AST_set_parent_list(&x->attributes, n);
  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->asm_stmt, n);
  break;
}
case kind_field_decl: {
  field_decl x = CAST(field_decl, n);

  AST_set_parent_list(&x->declarator, n);
  AST_set_parent_list(&x->attributes, n);
  AST_set_parent_list(&x->arg1, n);
  break;
}
case kind_asttype: {
  asttype x = CAST(asttype, n);

  AST_set_parent_list(&x->declarator, n);
  AST_set_parent_list(&x->qualifiers, n);
  break;
}
case kind_typename: break;
case kind_type_variable: break;
case kind_typeof_expr: {
  typeof_expr x = CAST(typeof_expr, n);

  AST_set_parent_list(&x->arg1, n);
  break;
}
case kind_typeof_type: {
  typeof_type x = CAST(typeof_type, n);

  AST_set_parent_list(&x->asttype, n);
  break;
}
case kind_attribute: {
  attribute x = CAST(attribute, n);

  AST_set_parent_list(&x->word1, n);
  AST_set_parent_list(&x->word2, n);
  AST_set_parent_list(&x->args, n);
  break;
}
case kind_rid: break;
case kind_user_qual: break;
case kind_qualifier: break;
case kind_tag_ref: case kind_enum_ref: case kind_union_ref: case kind_struct_ref: {
  tag_ref x = CAST(tag_ref, n);

  AST_set_parent_list(&x->word1, n);
  AST_set_parent_list(&x->attributes, n);
  AST_set_parent_list(&x->fields, n);
  break;
}
case kind_function_declarator: {
  function_declarator x = CAST(function_declarator, n);

  AST_set_parent_list(&x->declarator, n);
  AST_set_parent_list(&x->parms, n);
  AST_set_parent_list(&x->qualifiers, n);
  break;
}
case kind_pointer_declarator: {
  pointer_declarator x = CAST(pointer_declarator, n);

  AST_set_parent_list(&x->declarator, n);
  AST_set_parent_list(&x->qualifiers, n);
  break;
}
case kind_array_declarator: {
  array_declarator x = CAST(array_declarator, n);

  AST_set_parent_list(&x->declarator, n);
  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->qualifiers, n);
  break;
}
case kind_identifier_declarator: break;
case kind_asm_stmt: {
  asm_stmt x = CAST(asm_stmt, n);

  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->asm_operands1, n);
  AST_set_parent_list(&x->asm_operands2, n);
  AST_set_parent_list(&x->asm_clobbers, n);
  AST_set_parent_list(&x->qualifiers, n);
  break;
}
case kind_compound_stmt: {
  compound_stmt x = CAST(compound_stmt, n);

  AST_set_parent_list(&x->id_labels, n);
  AST_set_parent_list(&x->decls, n);
  AST_set_parent_list(&x->stmts, n);
  break;
}
case kind_if_stmt: {
  if_stmt x = CAST(if_stmt, n);

  AST_set_parent_list(&x->condition, n);
  AST_set_parent_list(&x->stmt1, n);
  AST_set_parent_list(&x->stmt2, n);
  break;
}
case kind_labeled_stmt: {
  labeled_stmt x = CAST(labeled_stmt, n);

  AST_set_parent_list(&x->label, n);
  AST_set_parent_list(&x->stmt, n);
  break;
}
case kind_expression_stmt: {
  expression_stmt x = CAST(expression_stmt, n);

  AST_set_parent_list(&x->arg1, n);
  break;
}
case kind_breakable_stmt: break;
case kind_conditional_stmt: case kind_dowhile_stmt: case kind_while_stmt: {
  conditional_stmt x = CAST(conditional_stmt, n);

  AST_set_parent_list(&x->condition, n);
  AST_set_parent_list(&x->stmt, n);
  break;
}
case kind_switch_stmt: {
  switch_stmt x = CAST(switch_stmt, n);

  AST_set_parent_list(&x->condition, n);
  AST_set_parent_list(&x->stmt, n);
  break;
}
case kind_for_stmt: {
  for_stmt x = CAST(for_stmt, n);

  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->arg2, n);
  AST_set_parent_list(&x->arg3, n);
  AST_set_parent_list(&x->stmt, n);
  break;
}
case kind_break_stmt: break;
case kind_continue_stmt: break;
case kind_return_stmt: {
  return_stmt x = CAST(return_stmt, n);

  AST_set_parent_list(&x->arg1, n);
  break;
}
case kind_goto_stmt: {
  goto_stmt x = CAST(goto_stmt, n);

  AST_set_parent_list(&x->id_label, n);
  break;
}
case kind_computed_goto_stmt: {
  computed_goto_stmt x = CAST(computed_goto_stmt, n);

  AST_set_parent_list(&x->arg1, n);
  break;
}
case kind_empty_stmt: break;
case kind_assert_type_stmt: {
  assert_type_stmt x = CAST(assert_type_stmt, n);

  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->asttype, n);
  break;
}
case kind_change_type_stmt: {
  change_type_stmt x = CAST(change_type_stmt, n);

  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->asttype, n);
  break;
}
case kind_deep_restrict_stmt: {
  deep_restrict_stmt x = CAST(deep_restrict_stmt, n);

  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->stmt, n);
  break;
}
case kind_unary: case kind_not: case kind_bitnot: case kind_postdecrement: case kind_postincrement: case kind_predecrement: case kind_preincrement: case kind_conjugate: case kind_unary_plus: case kind_unary_minus: case kind_address_of: case kind_imagpart: case kind_realpart: case kind_alignof_expr: case kind_sizeof_expr: case kind_extension_expr: case kind_dereference: {
  unary x = CAST(unary, n);

  AST_set_parent_list(&x->arg1, n);
  break;
}
case kind_binary: case kind_bitxor_assign: case kind_bitor_assign: case kind_bitand_assign: case kind_rshift_assign: case kind_lshift_assign: case kind_modulo_assign: case kind_divide_assign: case kind_times_assign: case kind_minus_assign: case kind_plus_assign: case kind_assign: case kind_oror: case kind_andand: case kind_bitxor: case kind_bitor: case kind_bitand: case kind_ne: case kind_eq: case kind_gt: case kind_lt: case kind_geq: case kind_leq: case kind_rshift: case kind_lshift: case kind_modulo: case kind_divide: case kind_times: case kind_minus: case kind_plus: {
  binary x = CAST(binary, n);

  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->arg2, n);
  break;
}
case kind_comma: {
  comma x = CAST(comma, n);

  AST_set_parent_list(&x->arg1, n);
  break;
}
case kind_sizeof_type: {
  sizeof_type x = CAST(sizeof_type, n);

  AST_set_parent_list(&x->asttype, n);
  break;
}
case kind_alignof_type: {
  alignof_type x = CAST(alignof_type, n);

  AST_set_parent_list(&x->asttype, n);
  break;
}
case kind_label_address: {
  label_address x = CAST(label_address, n);

  AST_set_parent_list(&x->id_label, n);
  break;
}
case kind_cast: {
  cast x = CAST(cast, n);

  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->asttype, n);
  break;
}
case kind_cast_list: {
  cast_list x = CAST(cast_list, n);

  AST_set_parent_list(&x->asttype, n);
  AST_set_parent_list(&x->init_expr, n);
  break;
}
case kind_conditional: {
  conditional x = CAST(conditional, n);

  AST_set_parent_list(&x->condition, n);
  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->arg2, n);
  break;
}
case kind_identifier: break;
case kind_compound_expr: {
  compound_expr x = CAST(compound_expr, n);

  AST_set_parent_list(&x->stmt, n);
  break;
}
case kind_function_call: {
  function_call x = CAST(function_call, n);

  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->args, n);
  break;
}
case kind_array_ref: {
  array_ref x = CAST(array_ref, n);

  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->arg2, n);
  break;
}
case kind_field_ref: {
  field_ref x = CAST(field_ref, n);

  AST_set_parent_list(&x->arg1, n);
  break;
}
case kind_init_list: {
  init_list x = CAST(init_list, n);

  AST_set_parent_list(&x->args, n);
  break;
}
case kind_init_index: {
  init_index x = CAST(init_index, n);

  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->arg2, n);
  AST_set_parent_list(&x->init_expr, n);
  break;
}
case kind_init_field: {
  init_field x = CAST(init_field, n);

  AST_set_parent_list(&x->word1, n);
  AST_set_parent_list(&x->init_expr, n);
  break;
}
case kind_lexical_cst: break;
case kind_string_cst: break;
case kind_string: {
  string x = CAST(string, n);

  AST_set_parent_list(&x->strings, n);
  break;
}
case kind_id_label: break;
case kind_case_label: {
  case_label x = CAST(case_label, n);

  AST_set_parent_list(&x->arg1, n);
  AST_set_parent_list(&x->arg2, n);
  break;
}
case kind_default_label: break;
case kind_word: break;
case kind_asm_operand: {
  asm_operand x = CAST(asm_operand, n);

  AST_set_parent_list(&x->string, n);
  AST_set_parent_list(&x->arg1, n);
  break;
}
