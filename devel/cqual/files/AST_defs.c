/* Automatically generated from nodetypes.def, do not edit. */

/* See the copyright notice in nodetypes.def */
node new_node(region r, location loc)
{
  node obj = ralloc(r, struct AST_node);

  obj->kind = kind_node;
  obj->loc = loc;

  return obj;
}

declaration new_declaration(region r, location loc)
{
  declaration obj = ralloc(r, struct AST_declaration);

  obj->kind = kind_declaration;
  obj->loc = loc;

  return obj;
}

statement new_statement(region r, location loc)
{
  statement obj = ralloc(r, struct AST_statement);

  obj->kind = kind_statement;
  obj->loc = loc;

  return obj;
}

expression new_expression(region r, location loc)
{
  expression obj = ralloc(r, struct AST_expression);

  obj->kind = kind_expression;
  obj->loc = loc;

  return obj;
}

type_element new_type_element(region r, location loc)
{
  type_element obj = ralloc(r, struct AST_type_element);

  obj->kind = kind_type_element;
  obj->loc = loc;

  return obj;
}

declarator new_declarator(region r, location loc)
{
  declarator obj = ralloc(r, struct AST_declarator);

  obj->kind = kind_declarator;
  obj->loc = loc;

  return obj;
}

label new_label(region r, location loc)
{
  label obj = ralloc(r, struct AST_label);

  obj->kind = kind_label;
  obj->loc = loc;

  return obj;
}

asm_decl new_asm_decl(region r, location loc, asm_stmt asm_stmt)
{
  asm_decl obj = ralloc(r, struct AST_asm_decl);

  obj->kind = kind_asm_decl;
  obj->loc = loc;
  obj->asm_stmt = asm_stmt;

  return obj;
}

data_decl new_data_decl(region r, location loc, type_element modifiers, attribute attributes, declaration decls)
{
  data_decl obj = ralloc(r, struct AST_data_decl);

  obj->kind = kind_data_decl;
  obj->loc = loc;
  obj->modifiers = modifiers;
  obj->attributes = attributes;
  obj->decls = decls;

  return obj;
}

extension_decl new_extension_decl(region r, location loc, declaration decl)
{
  extension_decl obj = ralloc(r, struct AST_extension_decl);

  obj->kind = kind_extension_decl;
  obj->loc = loc;
  obj->decl = decl;

  return obj;
}

ellipsis_decl new_ellipsis_decl(region r, location loc, type_element qualifiers)
{
  ellipsis_decl obj = ralloc(r, struct AST_ellipsis_decl);

  obj->kind = kind_ellipsis_decl;
  obj->loc = loc;
  obj->qualifiers = qualifiers;

  return obj;
}

enumerator new_enumerator(region r, location loc, cstring cstring, expression arg1, data_declaration ddecl)
{
  enumerator obj = ralloc(r, struct AST_enumerator);

  obj->kind = kind_enumerator;
  obj->loc = loc;
  obj->cstring = cstring;
  obj->arg1 = arg1;
  obj->ddecl = ddecl;

  return obj;
}

oldidentifier_decl new_oldidentifier_decl(region r, location loc, cstring cstring, data_declaration ddecl)
{
  oldidentifier_decl obj = ralloc(r, struct AST_oldidentifier_decl);

  obj->kind = kind_oldidentifier_decl;
  obj->loc = loc;
  obj->cstring = cstring;
  obj->ddecl = ddecl;

  return obj;
}

function_decl new_function_decl(region r, location loc, declarator declarator, type_element qualifiers, attribute attributes, declaration old_parms, statement stmt, function_decl parent_function, data_declaration ddecl)
{
  function_decl obj = ralloc(r, struct AST_function_decl);

  obj->kind = kind_function_decl;
  obj->loc = loc;
  obj->declarator = declarator;
  obj->qualifiers = qualifiers;
  obj->attributes = attributes;
  obj->old_parms = old_parms;
  obj->stmt = stmt;
  obj->parent_function = parent_function;
  obj->ddecl = ddecl;

  return obj;
}

implicit_decl new_implicit_decl(region r, location loc, identifier ident)
{
  implicit_decl obj = ralloc(r, struct AST_implicit_decl);

  obj->kind = kind_implicit_decl;
  obj->loc = loc;
  obj->ident = ident;

  return obj;
}

variable_decl new_variable_decl(region r, location loc, declarator declarator, attribute attributes, expression arg1, asm_stmt asm_stmt, data_declaration ddecl)
{
  variable_decl obj = ralloc(r, struct AST_variable_decl);

  obj->kind = kind_variable_decl;
  obj->loc = loc;
  obj->declarator = declarator;
  obj->attributes = attributes;
  obj->arg1 = arg1;
  obj->asm_stmt = asm_stmt;
  obj->ddecl = ddecl;

  return obj;
}

field_decl new_field_decl(region r, location loc, declarator declarator, attribute attributes, expression arg1)
{
  field_decl obj = ralloc(r, struct AST_field_decl);

  obj->kind = kind_field_decl;
  obj->loc = loc;
  obj->declarator = declarator;
  obj->attributes = attributes;
  obj->arg1 = arg1;

  return obj;
}

asttype new_asttype(region r, location loc, declarator declarator, type_element qualifiers)
{
  asttype obj = ralloc(r, struct AST_asttype);

  obj->kind = kind_asttype;
  obj->loc = loc;
  obj->declarator = declarator;
  obj->qualifiers = qualifiers;

  return obj;
}

typename new_typename(region r, location loc, data_declaration ddecl)
{
  typename obj = ralloc(r, struct AST_typename);

  obj->kind = kind_typename;
  obj->loc = loc;
  obj->ddecl = ddecl;

  return obj;
}

type_variable new_type_variable(region r, location loc, cstring cstring)
{
  type_variable obj = ralloc(r, struct AST_type_variable);

  obj->kind = kind_type_variable;
  obj->loc = loc;
  obj->cstring = cstring;

  return obj;
}

typeof_expr new_typeof_expr(region r, location loc, expression arg1)
{
  typeof_expr obj = ralloc(r, struct AST_typeof_expr);

  obj->kind = kind_typeof_expr;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

typeof_type new_typeof_type(region r, location loc, asttype asttype)
{
  typeof_type obj = ralloc(r, struct AST_typeof_type);

  obj->kind = kind_typeof_type;
  obj->loc = loc;
  obj->asttype = asttype;

  return obj;
}

attribute new_attribute(region r, location loc, word word1, word word2, expression args)
{
  attribute obj = ralloc(r, struct AST_attribute);

  obj->kind = kind_attribute;
  obj->loc = loc;
  obj->word1 = word1;
  obj->word2 = word2;
  obj->args = args;

  return obj;
}

rid new_rid(region r, location loc, enum rid id)
{
  rid obj = ralloc(r, struct AST_rid);

  obj->kind = kind_rid;
  obj->loc = loc;
  obj->id = id;

  return obj;
}

user_qual new_user_qual(region r, location loc, cstring cstring)
{
  user_qual obj = ralloc(r, struct AST_user_qual);

  obj->kind = kind_user_qual;
  obj->loc = loc;
  obj->cstring = cstring;

  return obj;
}

qualifier new_qualifier(region r, location loc, enum rid id)
{
  qualifier obj = ralloc(r, struct AST_qualifier);

  obj->kind = kind_qualifier;
  obj->loc = loc;
  obj->id = id;

  return obj;
}

tag_ref new_tag_ref(region r, location loc, word word1, attribute attributes, declaration fields, bool defined)
{
  tag_ref obj = ralloc(r, struct AST_tag_ref);

  obj->kind = kind_tag_ref;
  obj->loc = loc;
  obj->word1 = word1;
  obj->attributes = attributes;
  obj->fields = fields;
  obj->defined = defined;

  return obj;
}

function_declarator new_function_declarator(region r, location loc, declarator declarator, declaration parms, type_element qualifiers, environment env)
{
  function_declarator obj = ralloc(r, struct AST_function_declarator);

  obj->kind = kind_function_declarator;
  obj->loc = loc;
  obj->declarator = declarator;
  obj->parms = parms;
  obj->qualifiers = qualifiers;
  obj->env = env;

  return obj;
}

pointer_declarator new_pointer_declarator(region r, location loc, declarator declarator, type_element qualifiers)
{
  pointer_declarator obj = ralloc(r, struct AST_pointer_declarator);

  obj->kind = kind_pointer_declarator;
  obj->loc = loc;
  obj->declarator = declarator;
  obj->qualifiers = qualifiers;

  return obj;
}

array_declarator new_array_declarator(region r, location loc, declarator declarator, expression arg1, type_element qualifiers)
{
  array_declarator obj = ralloc(r, struct AST_array_declarator);

  obj->kind = kind_array_declarator;
  obj->loc = loc;
  obj->declarator = declarator;
  obj->arg1 = arg1;
  obj->qualifiers = qualifiers;

  return obj;
}

identifier_declarator new_identifier_declarator(region r, location loc, cstring cstring)
{
  identifier_declarator obj = ralloc(r, struct AST_identifier_declarator);

  obj->kind = kind_identifier_declarator;
  obj->loc = loc;
  obj->cstring = cstring;

  return obj;
}

asm_stmt new_asm_stmt(region r, location loc, expression arg1, asm_operand asm_operands1, asm_operand asm_operands2, string asm_clobbers, type_element qualifiers)
{
  asm_stmt obj = ralloc(r, struct AST_asm_stmt);

  obj->kind = kind_asm_stmt;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->asm_operands1 = asm_operands1;
  obj->asm_operands2 = asm_operands2;
  obj->asm_clobbers = asm_clobbers;
  obj->qualifiers = qualifiers;

  return obj;
}

compound_stmt new_compound_stmt(region r, location loc, id_label id_labels, declaration decls, statement stmts, environment env)
{
  compound_stmt obj = ralloc(r, struct AST_compound_stmt);

  obj->kind = kind_compound_stmt;
  obj->loc = loc;
  obj->id_labels = id_labels;
  obj->decls = decls;
  obj->stmts = stmts;
  obj->env = env;

  return obj;
}

if_stmt new_if_stmt(region r, location loc, expression condition, statement stmt1, statement stmt2)
{
  if_stmt obj = ralloc(r, struct AST_if_stmt);

  obj->kind = kind_if_stmt;
  obj->loc = loc;
  obj->condition = condition;
  obj->stmt1 = stmt1;
  obj->stmt2 = stmt2;

  return obj;
}

labeled_stmt new_labeled_stmt(region r, location loc, label label, statement stmt)
{
  labeled_stmt obj = ralloc(r, struct AST_labeled_stmt);

  obj->kind = kind_labeled_stmt;
  obj->loc = loc;
  obj->label = label;
  obj->stmt = stmt;

  return obj;
}

expression_stmt new_expression_stmt(region r, location loc, expression arg1)
{
  expression_stmt obj = ralloc(r, struct AST_expression_stmt);

  obj->kind = kind_expression_stmt;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

breakable_stmt new_breakable_stmt(region r, location loc)
{
  breakable_stmt obj = ralloc(r, struct AST_breakable_stmt);

  obj->kind = kind_breakable_stmt;
  obj->loc = loc;

  return obj;
}

conditional_stmt new_conditional_stmt(region r, location loc, expression condition, statement stmt)
{
  conditional_stmt obj = ralloc(r, struct AST_conditional_stmt);

  obj->kind = kind_conditional_stmt;
  obj->loc = loc;
  obj->condition = condition;
  obj->stmt = stmt;

  return obj;
}

switch_stmt new_switch_stmt(region r, location loc, expression condition, statement stmt)
{
  switch_stmt obj = ralloc(r, struct AST_switch_stmt);

  obj->kind = kind_switch_stmt;
  obj->loc = loc;
  obj->condition = condition;
  obj->stmt = stmt;

  return obj;
}

for_stmt new_for_stmt(region r, location loc, expression arg1, expression arg2, expression arg3, statement stmt)
{
  for_stmt obj = ralloc(r, struct AST_for_stmt);

  obj->kind = kind_for_stmt;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;
  obj->arg3 = arg3;
  obj->stmt = stmt;

  return obj;
}

break_stmt new_break_stmt(region r, location loc)
{
  break_stmt obj = ralloc(r, struct AST_break_stmt);

  obj->kind = kind_break_stmt;
  obj->loc = loc;

  return obj;
}

continue_stmt new_continue_stmt(region r, location loc)
{
  continue_stmt obj = ralloc(r, struct AST_continue_stmt);

  obj->kind = kind_continue_stmt;
  obj->loc = loc;

  return obj;
}

return_stmt new_return_stmt(region r, location loc, expression arg1)
{
  return_stmt obj = ralloc(r, struct AST_return_stmt);

  obj->kind = kind_return_stmt;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

goto_stmt new_goto_stmt(region r, location loc, id_label id_label)
{
  goto_stmt obj = ralloc(r, struct AST_goto_stmt);

  obj->kind = kind_goto_stmt;
  obj->loc = loc;
  obj->id_label = id_label;

  return obj;
}

computed_goto_stmt new_computed_goto_stmt(region r, location loc, expression arg1)
{
  computed_goto_stmt obj = ralloc(r, struct AST_computed_goto_stmt);

  obj->kind = kind_computed_goto_stmt;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

empty_stmt new_empty_stmt(region r, location loc)
{
  empty_stmt obj = ralloc(r, struct AST_empty_stmt);

  obj->kind = kind_empty_stmt;
  obj->loc = loc;

  return obj;
}

assert_type_stmt new_assert_type_stmt(region r, location loc, expression arg1, asttype asttype)
{
  assert_type_stmt obj = ralloc(r, struct AST_assert_type_stmt);

  obj->kind = kind_assert_type_stmt;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->asttype = asttype;

  return obj;
}

change_type_stmt new_change_type_stmt(region r, location loc, expression arg1, asttype asttype)
{
  change_type_stmt obj = ralloc(r, struct AST_change_type_stmt);

  obj->kind = kind_change_type_stmt;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->asttype = asttype;

  return obj;
}

deep_restrict_stmt new_deep_restrict_stmt(region r, location loc, expression arg1, statement stmt)
{
  deep_restrict_stmt obj = ralloc(r, struct AST_deep_restrict_stmt);

  obj->kind = kind_deep_restrict_stmt;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->stmt = stmt;

  return obj;
}

unary new_unary(region r, location loc, expression arg1)
{
  unary obj = ralloc(r, struct AST_unary);

  obj->kind = kind_unary;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

binary new_binary(region r, location loc, expression arg1, expression arg2)
{
  binary obj = ralloc(r, struct AST_binary);

  obj->kind = kind_binary;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

comma new_comma(region r, location loc, expression arg1)
{
  comma obj = ralloc(r, struct AST_comma);

  obj->kind = kind_comma;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

sizeof_type new_sizeof_type(region r, location loc, asttype asttype)
{
  sizeof_type obj = ralloc(r, struct AST_sizeof_type);

  obj->kind = kind_sizeof_type;
  obj->loc = loc;
  obj->asttype = asttype;

  return obj;
}

alignof_type new_alignof_type(region r, location loc, asttype asttype)
{
  alignof_type obj = ralloc(r, struct AST_alignof_type);

  obj->kind = kind_alignof_type;
  obj->loc = loc;
  obj->asttype = asttype;

  return obj;
}

label_address new_label_address(region r, location loc, id_label id_label)
{
  label_address obj = ralloc(r, struct AST_label_address);

  obj->kind = kind_label_address;
  obj->loc = loc;
  obj->id_label = id_label;

  return obj;
}

cast new_cast(region r, location loc, expression arg1, asttype asttype)
{
  cast obj = ralloc(r, struct AST_cast);

  obj->kind = kind_cast;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->asttype = asttype;

  return obj;
}

cast_list new_cast_list(region r, location loc, asttype asttype, expression init_expr)
{
  cast_list obj = ralloc(r, struct AST_cast_list);

  obj->kind = kind_cast_list;
  obj->loc = loc;
  obj->asttype = asttype;
  obj->init_expr = init_expr;

  return obj;
}

conditional new_conditional(region r, location loc, expression condition, expression arg1, expression arg2)
{
  conditional obj = ralloc(r, struct AST_conditional);

  obj->kind = kind_conditional;
  obj->loc = loc;
  obj->condition = condition;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

identifier new_identifier(region r, location loc, cstring cstring, data_declaration ddecl)
{
  identifier obj = ralloc(r, struct AST_identifier);

  obj->kind = kind_identifier;
  obj->loc = loc;
  obj->cstring = cstring;
  obj->ddecl = ddecl;

  return obj;
}

compound_expr new_compound_expr(region r, location loc, statement stmt)
{
  compound_expr obj = ralloc(r, struct AST_compound_expr);

  obj->kind = kind_compound_expr;
  obj->loc = loc;
  obj->stmt = stmt;

  return obj;
}

function_call new_function_call(region r, location loc, expression arg1, expression args, asttype va_arg_call)
{
  function_call obj = ralloc(r, struct AST_function_call);

  obj->kind = kind_function_call;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->args = args;
  obj->va_arg_call = va_arg_call;

  return obj;
}

array_ref new_array_ref(region r, location loc, expression arg1, expression arg2)
{
  array_ref obj = ralloc(r, struct AST_array_ref);

  obj->kind = kind_array_ref;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

field_ref new_field_ref(region r, location loc, expression arg1, cstring cstring, location cstring_loc)
{
  field_ref obj = ralloc(r, struct AST_field_ref);

  obj->kind = kind_field_ref;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->cstring = cstring;
  obj->cstring_loc = cstring_loc;

  return obj;
}

init_list new_init_list(region r, location loc, expression args)
{
  init_list obj = ralloc(r, struct AST_init_list);

  obj->kind = kind_init_list;
  obj->loc = loc;
  obj->args = args;

  return obj;
}

init_index new_init_index(region r, location loc, expression arg1, expression arg2, expression init_expr)
{
  init_index obj = ralloc(r, struct AST_init_index);

  obj->kind = kind_init_index;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;
  obj->init_expr = init_expr;

  return obj;
}

init_field new_init_field(region r, location loc, word word1, expression init_expr)
{
  init_field obj = ralloc(r, struct AST_init_field);

  obj->kind = kind_init_field;
  obj->loc = loc;
  obj->word1 = word1;
  obj->init_expr = init_expr;

  return obj;
}

lexical_cst new_lexical_cst(region r, location loc, cstring cstring)
{
  lexical_cst obj = ralloc(r, struct AST_lexical_cst);

  obj->kind = kind_lexical_cst;
  obj->loc = loc;
  obj->cstring = cstring;

  return obj;
}

string_cst new_string_cst(region r, location loc, cstring cstring, wchar_t * chars, size_t length)
{
  string_cst obj = ralloc(r, struct AST_string_cst);

  obj->kind = kind_string_cst;
  obj->loc = loc;
  obj->cstring = cstring;
  obj->chars = chars;
  obj->length = length;

  return obj;
}

string new_string(region r, location loc, expression strings, data_declaration ddecl)
{
  string obj = ralloc(r, struct AST_string);

  obj->kind = kind_string;
  obj->loc = loc;
  obj->strings = strings;
  obj->ddecl = ddecl;

  return obj;
}

id_label new_id_label(region r, location loc, cstring cstring)
{
  id_label obj = ralloc(r, struct AST_id_label);

  obj->kind = kind_id_label;
  obj->loc = loc;
  obj->cstring = cstring;

  return obj;
}

case_label new_case_label(region r, location loc, expression arg1, expression arg2)
{
  case_label obj = ralloc(r, struct AST_case_label);

  obj->kind = kind_case_label;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

default_label new_default_label(region r, location loc)
{
  default_label obj = ralloc(r, struct AST_default_label);

  obj->kind = kind_default_label;
  obj->loc = loc;

  return obj;
}

word new_word(region r, location loc, cstring cstring)
{
  word obj = ralloc(r, struct AST_word);

  obj->kind = kind_word;
  obj->loc = loc;
  obj->cstring = cstring;

  return obj;
}

asm_operand new_asm_operand(region r, location loc, string string, expression arg1)
{
  asm_operand obj = ralloc(r, struct AST_asm_operand);

  obj->kind = kind_asm_operand;
  obj->loc = loc;
  obj->string = string;
  obj->arg1 = arg1;

  return obj;
}

error_decl new_error_decl(region r, location loc)
{
  error_decl obj = ralloc(r, struct AST_declaration);

  obj->kind = kind_error_decl;
  obj->loc = loc;

  return obj;
}

struct_ref new_struct_ref(region r, location loc, word word1, attribute attributes, declaration fields, bool defined)
{
  struct_ref obj = ralloc(r, struct AST_tag_ref);

  obj->kind = kind_struct_ref;
  obj->loc = loc;
  obj->word1 = word1;
  obj->attributes = attributes;
  obj->fields = fields;
  obj->defined = defined;

  return obj;
}

union_ref new_union_ref(region r, location loc, word word1, attribute attributes, declaration fields, bool defined)
{
  union_ref obj = ralloc(r, struct AST_tag_ref);

  obj->kind = kind_union_ref;
  obj->loc = loc;
  obj->word1 = word1;
  obj->attributes = attributes;
  obj->fields = fields;
  obj->defined = defined;

  return obj;
}

enum_ref new_enum_ref(region r, location loc, word word1, attribute attributes, declaration fields, bool defined)
{
  enum_ref obj = ralloc(r, struct AST_tag_ref);

  obj->kind = kind_enum_ref;
  obj->loc = loc;
  obj->word1 = word1;
  obj->attributes = attributes;
  obj->fields = fields;
  obj->defined = defined;

  return obj;
}

error_stmt new_error_stmt(region r, location loc)
{
  error_stmt obj = ralloc(r, struct AST_statement);

  obj->kind = kind_error_stmt;
  obj->loc = loc;

  return obj;
}

while_stmt new_while_stmt(region r, location loc, expression condition, statement stmt)
{
  while_stmt obj = ralloc(r, struct AST_conditional_stmt);

  obj->kind = kind_while_stmt;
  obj->loc = loc;
  obj->condition = condition;
  obj->stmt = stmt;

  return obj;
}

dowhile_stmt new_dowhile_stmt(region r, location loc, expression condition, statement stmt)
{
  dowhile_stmt obj = ralloc(r, struct AST_conditional_stmt);

  obj->kind = kind_dowhile_stmt;
  obj->loc = loc;
  obj->condition = condition;
  obj->stmt = stmt;

  return obj;
}

error_expr new_error_expr(region r, location loc)
{
  error_expr obj = ralloc(r, struct AST_expression);

  obj->kind = kind_error_expr;
  obj->loc = loc;

  return obj;
}

dereference new_dereference(region r, location loc, expression arg1)
{
  dereference obj = ralloc(r, struct AST_unary);

  obj->kind = kind_dereference;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

extension_expr new_extension_expr(region r, location loc, expression arg1)
{
  extension_expr obj = ralloc(r, struct AST_unary);

  obj->kind = kind_extension_expr;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

sizeof_expr new_sizeof_expr(region r, location loc, expression arg1)
{
  sizeof_expr obj = ralloc(r, struct AST_unary);

  obj->kind = kind_sizeof_expr;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

alignof_expr new_alignof_expr(region r, location loc, expression arg1)
{
  alignof_expr obj = ralloc(r, struct AST_unary);

  obj->kind = kind_alignof_expr;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

realpart new_realpart(region r, location loc, expression arg1)
{
  realpart obj = ralloc(r, struct AST_unary);

  obj->kind = kind_realpart;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

imagpart new_imagpart(region r, location loc, expression arg1)
{
  imagpart obj = ralloc(r, struct AST_unary);

  obj->kind = kind_imagpart;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

address_of new_address_of(region r, location loc, expression arg1)
{
  address_of obj = ralloc(r, struct AST_unary);

  obj->kind = kind_address_of;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

unary_minus new_unary_minus(region r, location loc, expression arg1)
{
  unary_minus obj = ralloc(r, struct AST_unary);

  obj->kind = kind_unary_minus;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

unary_plus new_unary_plus(region r, location loc, expression arg1)
{
  unary_plus obj = ralloc(r, struct AST_unary);

  obj->kind = kind_unary_plus;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

conjugate new_conjugate(region r, location loc, expression arg1)
{
  conjugate obj = ralloc(r, struct AST_unary);

  obj->kind = kind_conjugate;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

preincrement new_preincrement(region r, location loc, expression arg1)
{
  preincrement obj = ralloc(r, struct AST_unary);

  obj->kind = kind_preincrement;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

predecrement new_predecrement(region r, location loc, expression arg1)
{
  predecrement obj = ralloc(r, struct AST_unary);

  obj->kind = kind_predecrement;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

postincrement new_postincrement(region r, location loc, expression arg1)
{
  postincrement obj = ralloc(r, struct AST_unary);

  obj->kind = kind_postincrement;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

postdecrement new_postdecrement(region r, location loc, expression arg1)
{
  postdecrement obj = ralloc(r, struct AST_unary);

  obj->kind = kind_postdecrement;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

bitnot new_bitnot(region r, location loc, expression arg1)
{
  bitnot obj = ralloc(r, struct AST_unary);

  obj->kind = kind_bitnot;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

not new_not(region r, location loc, expression arg1)
{
  not obj = ralloc(r, struct AST_unary);

  obj->kind = kind_not;
  obj->loc = loc;
  obj->arg1 = arg1;

  return obj;
}

plus new_plus(region r, location loc, expression arg1, expression arg2)
{
  plus obj = ralloc(r, struct AST_binary);

  obj->kind = kind_plus;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

minus new_minus(region r, location loc, expression arg1, expression arg2)
{
  minus obj = ralloc(r, struct AST_binary);

  obj->kind = kind_minus;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

times new_times(region r, location loc, expression arg1, expression arg2)
{
  times obj = ralloc(r, struct AST_binary);

  obj->kind = kind_times;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

divide new_divide(region r, location loc, expression arg1, expression arg2)
{
  divide obj = ralloc(r, struct AST_binary);

  obj->kind = kind_divide;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

modulo new_modulo(region r, location loc, expression arg1, expression arg2)
{
  modulo obj = ralloc(r, struct AST_binary);

  obj->kind = kind_modulo;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

lshift new_lshift(region r, location loc, expression arg1, expression arg2)
{
  lshift obj = ralloc(r, struct AST_binary);

  obj->kind = kind_lshift;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

rshift new_rshift(region r, location loc, expression arg1, expression arg2)
{
  rshift obj = ralloc(r, struct AST_binary);

  obj->kind = kind_rshift;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

leq new_leq(region r, location loc, expression arg1, expression arg2)
{
  leq obj = ralloc(r, struct AST_binary);

  obj->kind = kind_leq;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

geq new_geq(region r, location loc, expression arg1, expression arg2)
{
  geq obj = ralloc(r, struct AST_binary);

  obj->kind = kind_geq;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

lt new_lt(region r, location loc, expression arg1, expression arg2)
{
  lt obj = ralloc(r, struct AST_binary);

  obj->kind = kind_lt;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

gt new_gt(region r, location loc, expression arg1, expression arg2)
{
  gt obj = ralloc(r, struct AST_binary);

  obj->kind = kind_gt;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

eq new_eq(region r, location loc, expression arg1, expression arg2)
{
  eq obj = ralloc(r, struct AST_binary);

  obj->kind = kind_eq;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

ne new_ne(region r, location loc, expression arg1, expression arg2)
{
  ne obj = ralloc(r, struct AST_binary);

  obj->kind = kind_ne;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

bitand new_bitand(region r, location loc, expression arg1, expression arg2)
{
  bitand obj = ralloc(r, struct AST_binary);

  obj->kind = kind_bitand;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

bitor new_bitor(region r, location loc, expression arg1, expression arg2)
{
  bitor obj = ralloc(r, struct AST_binary);

  obj->kind = kind_bitor;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

bitxor new_bitxor(region r, location loc, expression arg1, expression arg2)
{
  bitxor obj = ralloc(r, struct AST_binary);

  obj->kind = kind_bitxor;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

andand new_andand(region r, location loc, expression arg1, expression arg2)
{
  andand obj = ralloc(r, struct AST_binary);

  obj->kind = kind_andand;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

oror new_oror(region r, location loc, expression arg1, expression arg2)
{
  oror obj = ralloc(r, struct AST_binary);

  obj->kind = kind_oror;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

assign new_assign(region r, location loc, expression arg1, expression arg2)
{
  assign obj = ralloc(r, struct AST_binary);

  obj->kind = kind_assign;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

plus_assign new_plus_assign(region r, location loc, expression arg1, expression arg2)
{
  plus_assign obj = ralloc(r, struct AST_binary);

  obj->kind = kind_plus_assign;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

minus_assign new_minus_assign(region r, location loc, expression arg1, expression arg2)
{
  minus_assign obj = ralloc(r, struct AST_binary);

  obj->kind = kind_minus_assign;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

times_assign new_times_assign(region r, location loc, expression arg1, expression arg2)
{
  times_assign obj = ralloc(r, struct AST_binary);

  obj->kind = kind_times_assign;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

divide_assign new_divide_assign(region r, location loc, expression arg1, expression arg2)
{
  divide_assign obj = ralloc(r, struct AST_binary);

  obj->kind = kind_divide_assign;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

modulo_assign new_modulo_assign(region r, location loc, expression arg1, expression arg2)
{
  modulo_assign obj = ralloc(r, struct AST_binary);

  obj->kind = kind_modulo_assign;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

lshift_assign new_lshift_assign(region r, location loc, expression arg1, expression arg2)
{
  lshift_assign obj = ralloc(r, struct AST_binary);

  obj->kind = kind_lshift_assign;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

rshift_assign new_rshift_assign(region r, location loc, expression arg1, expression arg2)
{
  rshift_assign obj = ralloc(r, struct AST_binary);

  obj->kind = kind_rshift_assign;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

bitand_assign new_bitand_assign(region r, location loc, expression arg1, expression arg2)
{
  bitand_assign obj = ralloc(r, struct AST_binary);

  obj->kind = kind_bitand_assign;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

bitor_assign new_bitor_assign(region r, location loc, expression arg1, expression arg2)
{
  bitor_assign obj = ralloc(r, struct AST_binary);

  obj->kind = kind_bitor_assign;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}

bitxor_assign new_bitxor_assign(region r, location loc, expression arg1, expression arg2)
{
  bitxor_assign obj = ralloc(r, struct AST_binary);

  obj->kind = kind_bitxor_assign;
  obj->loc = loc;
  obj->arg1 = arg1;
  obj->arg2 = arg2;

  return obj;
}



node node_chain(node l1, node l2)
{ return CAST(node, ast_chain(CAST(node, l1), CAST(node, l2))); }

declaration declaration_chain(declaration l1, declaration l2)
{ return CAST(declaration, ast_chain(CAST(node, l1), CAST(node, l2))); }

statement statement_chain(statement l1, statement l2)
{ return CAST(statement, ast_chain(CAST(node, l1), CAST(node, l2))); }

expression expression_chain(expression l1, expression l2)
{ return CAST(expression, ast_chain(CAST(node, l1), CAST(node, l2))); }

type_element type_element_chain(type_element l1, type_element l2)
{ return CAST(type_element, ast_chain(CAST(node, l1), CAST(node, l2))); }

declarator declarator_chain(declarator l1, declarator l2)
{ return CAST(declarator, ast_chain(CAST(node, l1), CAST(node, l2))); }

label label_chain(label l1, label l2)
{ return CAST(label, ast_chain(CAST(node, l1), CAST(node, l2))); }

asm_decl asm_decl_chain(asm_decl l1, asm_decl l2)
{ return CAST(asm_decl, ast_chain(CAST(node, l1), CAST(node, l2))); }

data_decl data_decl_chain(data_decl l1, data_decl l2)
{ return CAST(data_decl, ast_chain(CAST(node, l1), CAST(node, l2))); }

extension_decl extension_decl_chain(extension_decl l1, extension_decl l2)
{ return CAST(extension_decl, ast_chain(CAST(node, l1), CAST(node, l2))); }

ellipsis_decl ellipsis_decl_chain(ellipsis_decl l1, ellipsis_decl l2)
{ return CAST(ellipsis_decl, ast_chain(CAST(node, l1), CAST(node, l2))); }

enumerator enumerator_chain(enumerator l1, enumerator l2)
{ return CAST(enumerator, ast_chain(CAST(node, l1), CAST(node, l2))); }

oldidentifier_decl oldidentifier_decl_chain(oldidentifier_decl l1, oldidentifier_decl l2)
{ return CAST(oldidentifier_decl, ast_chain(CAST(node, l1), CAST(node, l2))); }

function_decl function_decl_chain(function_decl l1, function_decl l2)
{ return CAST(function_decl, ast_chain(CAST(node, l1), CAST(node, l2))); }

implicit_decl implicit_decl_chain(implicit_decl l1, implicit_decl l2)
{ return CAST(implicit_decl, ast_chain(CAST(node, l1), CAST(node, l2))); }

variable_decl variable_decl_chain(variable_decl l1, variable_decl l2)
{ return CAST(variable_decl, ast_chain(CAST(node, l1), CAST(node, l2))); }

field_decl field_decl_chain(field_decl l1, field_decl l2)
{ return CAST(field_decl, ast_chain(CAST(node, l1), CAST(node, l2))); }

asttype asttype_chain(asttype l1, asttype l2)
{ return CAST(asttype, ast_chain(CAST(node, l1), CAST(node, l2))); }

typename typename_chain(typename l1, typename l2)
{ return CAST(typename, ast_chain(CAST(node, l1), CAST(node, l2))); }

type_variable type_variable_chain(type_variable l1, type_variable l2)
{ return CAST(type_variable, ast_chain(CAST(node, l1), CAST(node, l2))); }

typeof_expr typeof_expr_chain(typeof_expr l1, typeof_expr l2)
{ return CAST(typeof_expr, ast_chain(CAST(node, l1), CAST(node, l2))); }

typeof_type typeof_type_chain(typeof_type l1, typeof_type l2)
{ return CAST(typeof_type, ast_chain(CAST(node, l1), CAST(node, l2))); }

attribute attribute_chain(attribute l1, attribute l2)
{ return CAST(attribute, ast_chain(CAST(node, l1), CAST(node, l2))); }

rid rid_chain(rid l1, rid l2)
{ return CAST(rid, ast_chain(CAST(node, l1), CAST(node, l2))); }

user_qual user_qual_chain(user_qual l1, user_qual l2)
{ return CAST(user_qual, ast_chain(CAST(node, l1), CAST(node, l2))); }

qualifier qualifier_chain(qualifier l1, qualifier l2)
{ return CAST(qualifier, ast_chain(CAST(node, l1), CAST(node, l2))); }

tag_ref tag_ref_chain(tag_ref l1, tag_ref l2)
{ return CAST(tag_ref, ast_chain(CAST(node, l1), CAST(node, l2))); }

function_declarator function_declarator_chain(function_declarator l1, function_declarator l2)
{ return CAST(function_declarator, ast_chain(CAST(node, l1), CAST(node, l2))); }

pointer_declarator pointer_declarator_chain(pointer_declarator l1, pointer_declarator l2)
{ return CAST(pointer_declarator, ast_chain(CAST(node, l1), CAST(node, l2))); }

array_declarator array_declarator_chain(array_declarator l1, array_declarator l2)
{ return CAST(array_declarator, ast_chain(CAST(node, l1), CAST(node, l2))); }

identifier_declarator identifier_declarator_chain(identifier_declarator l1, identifier_declarator l2)
{ return CAST(identifier_declarator, ast_chain(CAST(node, l1), CAST(node, l2))); }

asm_stmt asm_stmt_chain(asm_stmt l1, asm_stmt l2)
{ return CAST(asm_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

compound_stmt compound_stmt_chain(compound_stmt l1, compound_stmt l2)
{ return CAST(compound_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

if_stmt if_stmt_chain(if_stmt l1, if_stmt l2)
{ return CAST(if_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

labeled_stmt labeled_stmt_chain(labeled_stmt l1, labeled_stmt l2)
{ return CAST(labeled_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

expression_stmt expression_stmt_chain(expression_stmt l1, expression_stmt l2)
{ return CAST(expression_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

breakable_stmt breakable_stmt_chain(breakable_stmt l1, breakable_stmt l2)
{ return CAST(breakable_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

conditional_stmt conditional_stmt_chain(conditional_stmt l1, conditional_stmt l2)
{ return CAST(conditional_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

switch_stmt switch_stmt_chain(switch_stmt l1, switch_stmt l2)
{ return CAST(switch_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

for_stmt for_stmt_chain(for_stmt l1, for_stmt l2)
{ return CAST(for_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

break_stmt break_stmt_chain(break_stmt l1, break_stmt l2)
{ return CAST(break_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

continue_stmt continue_stmt_chain(continue_stmt l1, continue_stmt l2)
{ return CAST(continue_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

return_stmt return_stmt_chain(return_stmt l1, return_stmt l2)
{ return CAST(return_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

goto_stmt goto_stmt_chain(goto_stmt l1, goto_stmt l2)
{ return CAST(goto_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

computed_goto_stmt computed_goto_stmt_chain(computed_goto_stmt l1, computed_goto_stmt l2)
{ return CAST(computed_goto_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

empty_stmt empty_stmt_chain(empty_stmt l1, empty_stmt l2)
{ return CAST(empty_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

assert_type_stmt assert_type_stmt_chain(assert_type_stmt l1, assert_type_stmt l2)
{ return CAST(assert_type_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

change_type_stmt change_type_stmt_chain(change_type_stmt l1, change_type_stmt l2)
{ return CAST(change_type_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

deep_restrict_stmt deep_restrict_stmt_chain(deep_restrict_stmt l1, deep_restrict_stmt l2)
{ return CAST(deep_restrict_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

unary unary_chain(unary l1, unary l2)
{ return CAST(unary, ast_chain(CAST(node, l1), CAST(node, l2))); }

binary binary_chain(binary l1, binary l2)
{ return CAST(binary, ast_chain(CAST(node, l1), CAST(node, l2))); }

comma comma_chain(comma l1, comma l2)
{ return CAST(comma, ast_chain(CAST(node, l1), CAST(node, l2))); }

sizeof_type sizeof_type_chain(sizeof_type l1, sizeof_type l2)
{ return CAST(sizeof_type, ast_chain(CAST(node, l1), CAST(node, l2))); }

alignof_type alignof_type_chain(alignof_type l1, alignof_type l2)
{ return CAST(alignof_type, ast_chain(CAST(node, l1), CAST(node, l2))); }

label_address label_address_chain(label_address l1, label_address l2)
{ return CAST(label_address, ast_chain(CAST(node, l1), CAST(node, l2))); }

cast cast_chain(cast l1, cast l2)
{ return CAST(cast, ast_chain(CAST(node, l1), CAST(node, l2))); }

cast_list cast_list_chain(cast_list l1, cast_list l2)
{ return CAST(cast_list, ast_chain(CAST(node, l1), CAST(node, l2))); }

conditional conditional_chain(conditional l1, conditional l2)
{ return CAST(conditional, ast_chain(CAST(node, l1), CAST(node, l2))); }

identifier identifier_chain(identifier l1, identifier l2)
{ return CAST(identifier, ast_chain(CAST(node, l1), CAST(node, l2))); }

compound_expr compound_expr_chain(compound_expr l1, compound_expr l2)
{ return CAST(compound_expr, ast_chain(CAST(node, l1), CAST(node, l2))); }

function_call function_call_chain(function_call l1, function_call l2)
{ return CAST(function_call, ast_chain(CAST(node, l1), CAST(node, l2))); }

array_ref array_ref_chain(array_ref l1, array_ref l2)
{ return CAST(array_ref, ast_chain(CAST(node, l1), CAST(node, l2))); }

field_ref field_ref_chain(field_ref l1, field_ref l2)
{ return CAST(field_ref, ast_chain(CAST(node, l1), CAST(node, l2))); }

init_list init_list_chain(init_list l1, init_list l2)
{ return CAST(init_list, ast_chain(CAST(node, l1), CAST(node, l2))); }

init_index init_index_chain(init_index l1, init_index l2)
{ return CAST(init_index, ast_chain(CAST(node, l1), CAST(node, l2))); }

init_field init_field_chain(init_field l1, init_field l2)
{ return CAST(init_field, ast_chain(CAST(node, l1), CAST(node, l2))); }

lexical_cst lexical_cst_chain(lexical_cst l1, lexical_cst l2)
{ return CAST(lexical_cst, ast_chain(CAST(node, l1), CAST(node, l2))); }

string_cst string_cst_chain(string_cst l1, string_cst l2)
{ return CAST(string_cst, ast_chain(CAST(node, l1), CAST(node, l2))); }

string string_chain(string l1, string l2)
{ return CAST(string, ast_chain(CAST(node, l1), CAST(node, l2))); }

id_label id_label_chain(id_label l1, id_label l2)
{ return CAST(id_label, ast_chain(CAST(node, l1), CAST(node, l2))); }

case_label case_label_chain(case_label l1, case_label l2)
{ return CAST(case_label, ast_chain(CAST(node, l1), CAST(node, l2))); }

default_label default_label_chain(default_label l1, default_label l2)
{ return CAST(default_label, ast_chain(CAST(node, l1), CAST(node, l2))); }

word word_chain(word l1, word l2)
{ return CAST(word, ast_chain(CAST(node, l1), CAST(node, l2))); }

asm_operand asm_operand_chain(asm_operand l1, asm_operand l2)
{ return CAST(asm_operand, ast_chain(CAST(node, l1), CAST(node, l2))); }

error_decl error_decl_chain(error_decl l1, error_decl l2)
{ return CAST(error_decl, ast_chain(CAST(node, l1), CAST(node, l2))); }

struct_ref struct_ref_chain(struct_ref l1, struct_ref l2)
{ return CAST(struct_ref, ast_chain(CAST(node, l1), CAST(node, l2))); }

union_ref union_ref_chain(union_ref l1, union_ref l2)
{ return CAST(union_ref, ast_chain(CAST(node, l1), CAST(node, l2))); }

enum_ref enum_ref_chain(enum_ref l1, enum_ref l2)
{ return CAST(enum_ref, ast_chain(CAST(node, l1), CAST(node, l2))); }

error_stmt error_stmt_chain(error_stmt l1, error_stmt l2)
{ return CAST(error_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

while_stmt while_stmt_chain(while_stmt l1, while_stmt l2)
{ return CAST(while_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

dowhile_stmt dowhile_stmt_chain(dowhile_stmt l1, dowhile_stmt l2)
{ return CAST(dowhile_stmt, ast_chain(CAST(node, l1), CAST(node, l2))); }

error_expr error_expr_chain(error_expr l1, error_expr l2)
{ return CAST(error_expr, ast_chain(CAST(node, l1), CAST(node, l2))); }

dereference dereference_chain(dereference l1, dereference l2)
{ return CAST(dereference, ast_chain(CAST(node, l1), CAST(node, l2))); }

extension_expr extension_expr_chain(extension_expr l1, extension_expr l2)
{ return CAST(extension_expr, ast_chain(CAST(node, l1), CAST(node, l2))); }

sizeof_expr sizeof_expr_chain(sizeof_expr l1, sizeof_expr l2)
{ return CAST(sizeof_expr, ast_chain(CAST(node, l1), CAST(node, l2))); }

alignof_expr alignof_expr_chain(alignof_expr l1, alignof_expr l2)
{ return CAST(alignof_expr, ast_chain(CAST(node, l1), CAST(node, l2))); }

realpart realpart_chain(realpart l1, realpart l2)
{ return CAST(realpart, ast_chain(CAST(node, l1), CAST(node, l2))); }

imagpart imagpart_chain(imagpart l1, imagpart l2)
{ return CAST(imagpart, ast_chain(CAST(node, l1), CAST(node, l2))); }

address_of address_of_chain(address_of l1, address_of l2)
{ return CAST(address_of, ast_chain(CAST(node, l1), CAST(node, l2))); }

unary_minus unary_minus_chain(unary_minus l1, unary_minus l2)
{ return CAST(unary_minus, ast_chain(CAST(node, l1), CAST(node, l2))); }

unary_plus unary_plus_chain(unary_plus l1, unary_plus l2)
{ return CAST(unary_plus, ast_chain(CAST(node, l1), CAST(node, l2))); }

conjugate conjugate_chain(conjugate l1, conjugate l2)
{ return CAST(conjugate, ast_chain(CAST(node, l1), CAST(node, l2))); }

preincrement preincrement_chain(preincrement l1, preincrement l2)
{ return CAST(preincrement, ast_chain(CAST(node, l1), CAST(node, l2))); }

predecrement predecrement_chain(predecrement l1, predecrement l2)
{ return CAST(predecrement, ast_chain(CAST(node, l1), CAST(node, l2))); }

postincrement postincrement_chain(postincrement l1, postincrement l2)
{ return CAST(postincrement, ast_chain(CAST(node, l1), CAST(node, l2))); }

postdecrement postdecrement_chain(postdecrement l1, postdecrement l2)
{ return CAST(postdecrement, ast_chain(CAST(node, l1), CAST(node, l2))); }

bitnot bitnot_chain(bitnot l1, bitnot l2)
{ return CAST(bitnot, ast_chain(CAST(node, l1), CAST(node, l2))); }

not not_chain(not l1, not l2)
{ return CAST(not, ast_chain(CAST(node, l1), CAST(node, l2))); }

plus plus_chain(plus l1, plus l2)
{ return CAST(plus, ast_chain(CAST(node, l1), CAST(node, l2))); }

minus minus_chain(minus l1, minus l2)
{ return CAST(minus, ast_chain(CAST(node, l1), CAST(node, l2))); }

times times_chain(times l1, times l2)
{ return CAST(times, ast_chain(CAST(node, l1), CAST(node, l2))); }

divide divide_chain(divide l1, divide l2)
{ return CAST(divide, ast_chain(CAST(node, l1), CAST(node, l2))); }

modulo modulo_chain(modulo l1, modulo l2)
{ return CAST(modulo, ast_chain(CAST(node, l1), CAST(node, l2))); }

lshift lshift_chain(lshift l1, lshift l2)
{ return CAST(lshift, ast_chain(CAST(node, l1), CAST(node, l2))); }

rshift rshift_chain(rshift l1, rshift l2)
{ return CAST(rshift, ast_chain(CAST(node, l1), CAST(node, l2))); }

leq leq_chain(leq l1, leq l2)
{ return CAST(leq, ast_chain(CAST(node, l1), CAST(node, l2))); }

geq geq_chain(geq l1, geq l2)
{ return CAST(geq, ast_chain(CAST(node, l1), CAST(node, l2))); }

lt lt_chain(lt l1, lt l2)
{ return CAST(lt, ast_chain(CAST(node, l1), CAST(node, l2))); }

gt gt_chain(gt l1, gt l2)
{ return CAST(gt, ast_chain(CAST(node, l1), CAST(node, l2))); }

eq eq_chain(eq l1, eq l2)
{ return CAST(eq, ast_chain(CAST(node, l1), CAST(node, l2))); }

ne ne_chain(ne l1, ne l2)
{ return CAST(ne, ast_chain(CAST(node, l1), CAST(node, l2))); }

bitand bitand_chain(bitand l1, bitand l2)
{ return CAST(bitand, ast_chain(CAST(node, l1), CAST(node, l2))); }

bitor bitor_chain(bitor l1, bitor l2)
{ return CAST(bitor, ast_chain(CAST(node, l1), CAST(node, l2))); }

bitxor bitxor_chain(bitxor l1, bitxor l2)
{ return CAST(bitxor, ast_chain(CAST(node, l1), CAST(node, l2))); }

andand andand_chain(andand l1, andand l2)
{ return CAST(andand, ast_chain(CAST(node, l1), CAST(node, l2))); }

oror oror_chain(oror l1, oror l2)
{ return CAST(oror, ast_chain(CAST(node, l1), CAST(node, l2))); }

assign assign_chain(assign l1, assign l2)
{ return CAST(assign, ast_chain(CAST(node, l1), CAST(node, l2))); }

plus_assign plus_assign_chain(plus_assign l1, plus_assign l2)
{ return CAST(plus_assign, ast_chain(CAST(node, l1), CAST(node, l2))); }

minus_assign minus_assign_chain(minus_assign l1, minus_assign l2)
{ return CAST(minus_assign, ast_chain(CAST(node, l1), CAST(node, l2))); }

times_assign times_assign_chain(times_assign l1, times_assign l2)
{ return CAST(times_assign, ast_chain(CAST(node, l1), CAST(node, l2))); }

divide_assign divide_assign_chain(divide_assign l1, divide_assign l2)
{ return CAST(divide_assign, ast_chain(CAST(node, l1), CAST(node, l2))); }

modulo_assign modulo_assign_chain(modulo_assign l1, modulo_assign l2)
{ return CAST(modulo_assign, ast_chain(CAST(node, l1), CAST(node, l2))); }

lshift_assign lshift_assign_chain(lshift_assign l1, lshift_assign l2)
{ return CAST(lshift_assign, ast_chain(CAST(node, l1), CAST(node, l2))); }

rshift_assign rshift_assign_chain(rshift_assign l1, rshift_assign l2)
{ return CAST(rshift_assign, ast_chain(CAST(node, l1), CAST(node, l2))); }

bitand_assign bitand_assign_chain(bitand_assign l1, bitand_assign l2)
{ return CAST(bitand_assign, ast_chain(CAST(node, l1), CAST(node, l2))); }

bitor_assign bitor_assign_chain(bitor_assign l1, bitor_assign l2)
{ return CAST(bitor_assign, ast_chain(CAST(node, l1), CAST(node, l2))); }

bitxor_assign bitxor_assign_chain(bitxor_assign l1, bitxor_assign l2)
{ return CAST(bitxor_assign, ast_chain(CAST(node, l1), CAST(node, l2))); }

