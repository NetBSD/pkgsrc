$NetBSD: patch-deps_v8_src_torque_ast-generator.cc,v 1.1 2020/05/30 20:44:39 joerg Exp $

--- deps/v8/src/torque/ast-generator.cc.orig	2020-05-28 00:01:38.832602482 +0000
+++ deps/v8/src/torque/ast-generator.cc
@@ -120,7 +120,7 @@ Statement* AstGenerator::GetOptionalHelp
 
 antlrcpp::Any AstGenerator::visitParameterList(
     TorqueParser::ParameterListContext* context) {
-  ParameterList result{{}, {}, context->VARARGS(), {}};
+  ParameterList result{{}, {}, context->VARARGS() != nullptr, {}};
   if (context->VARARGS()) {
     result.arguments_variable = context->IDENTIFIER()->getSymbol()->getText();
   }
@@ -141,7 +141,7 @@ antlrcpp::Any AstGenerator::visitTypeLis
 
 antlrcpp::Any AstGenerator::visitTypeListMaybeVarArgs(
     TorqueParser::TypeListMaybeVarArgsContext* context) {
-  ParameterList result{{}, {}, context->VARARGS(), {}};
+  ParameterList result{{}, {}, context->VARARGS() != nullptr, {}};
   result.types.reserve(context->type().size());
   for (auto* type : context->type()) {
     result.types.push_back(GetType(type));
