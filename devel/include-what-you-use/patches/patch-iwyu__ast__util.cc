$NetBSD: patch-iwyu__ast__util.cc,v 1.1 2016/03/14 14:36:39 tnn Exp $

try to fix build w/ clang-3.8
Not sure if this change is correct, but it seems to work

--- iwyu_ast_util.cc.orig	2015-12-11 05:45:54.000000000 +0000
+++ iwyu_ast_util.cc
@@ -105,6 +105,7 @@ using clang::TagDecl;
 using clang::TagType;
 using clang::TemplateArgument;
 using clang::TemplateArgumentList;
+using clang::TemplateArgumentListInfo;
 using clang::TemplateArgumentLoc;
 using clang::TemplateDecl;
 using clang::TemplateName;
@@ -759,7 +760,7 @@ map<const Type*, const Type*> GetTplType
     num_args = call_expr->getNumArgs();
     const Expr* callee_expr = call_expr->getCallee()->IgnoreParenCasts();
     if (const ASTTemplateArgumentListInfo* explicit_tpl_args
-        = GetExplicitTplArgs(callee_expr)) {
+        = GetExplicitTplArgs(decl, callee_expr)) {
       retval = GetTplTypeResugarMapForFunctionExplicitTplArgs(
           decl, explicit_tpl_args);
       start_of_implicit_args = explicit_tpl_args->NumTemplateArgs;
@@ -767,7 +768,7 @@ map<const Type*, const Type*> GetTplType
   } else {
     // If calling_expr has explicit template args, then consider them.
     if (const ASTTemplateArgumentListInfo* explicit_tpl_args
-        = GetExplicitTplArgs(calling_expr)) {
+        = GetExplicitTplArgs(decl, calling_expr)) {
       retval = GetTplTypeResugarMapForFunctionExplicitTplArgs(
           decl, explicit_tpl_args);
       retval = ResugarTypeComponents(retval);
@@ -1319,18 +1320,27 @@ bool IsCastToReferenceType(const CastExp
   CHECK_UNREACHABLE_("Unexpected type of cast expression");
 }
 
-const ASTTemplateArgumentListInfo* GetExplicitTplArgs(const Expr* expr) {
-  if (const DeclRefExpr* decl_ref = DynCastFrom(expr))
-    return decl_ref->getOptionalExplicitTemplateArgs();
-  if (const MemberExpr* member_expr = DynCastFrom(expr))
-    return member_expr->getOptionalExplicitTemplateArgs();
+const ASTTemplateArgumentListInfo* GetExplicitTplArgs(const FunctionDecl* decl, const Expr* expr) {
+  TemplateArgumentListInfo tali;
+  if (const DeclRefExpr* decl_ref = DynCastFrom(expr)) {
+    decl_ref->copyTemplateArgumentsInto(tali);
+    return ASTTemplateArgumentListInfo::Create(decl->getASTContext(), tali);
+  }
+  if (const MemberExpr* member_expr = DynCastFrom(expr)) {
+    member_expr->copyTemplateArgumentsInto(tali);
+    return ASTTemplateArgumentListInfo::Create(decl->getASTContext(), tali);
+  }
   // Ugh, annoying casts needed because no const methods exist.
-  if (const OverloadExpr* overload_expr = DynCastFrom(expr))
-    return const_cast<OverloadExpr*>(overload_expr)
-        ->getOptionalExplicitTemplateArgs();
-  if (const DependentScopeDeclRefExpr* dependent_decl_ref = DynCastFrom(expr))
-    return const_cast<DependentScopeDeclRefExpr*>(dependent_decl_ref)
-        ->getOptionalExplicitTemplateArgs();
+  if (const OverloadExpr* overload_expr = DynCastFrom(expr)) {
+    const_cast<OverloadExpr*>(overload_expr)
+        ->copyTemplateArgumentsInto(tali);
+    return ASTTemplateArgumentListInfo::Create(decl->getASTContext(), tali);
+  }
+  if (const DependentScopeDeclRefExpr* dependent_decl_ref = DynCastFrom(expr)) {
+    const_cast<DependentScopeDeclRefExpr*>(dependent_decl_ref)
+        ->copyTemplateArgumentsInto(tali);
+    return ASTTemplateArgumentListInfo::Create(decl->getASTContext(), tali);
+  }
   return NULL;
 }
 
