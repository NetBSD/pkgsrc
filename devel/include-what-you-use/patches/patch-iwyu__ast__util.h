$NetBSD: patch-iwyu__ast__util.h,v 1.1 2016/03/14 14:36:39 tnn Exp $

try to fix build w/ clang-3.8
Not sure if this change is correct, but it seems to work

--- iwyu_ast_util.h.orig	2015-12-11 05:45:54.000000000 +0000
+++ iwyu_ast_util.h
@@ -800,6 +800,7 @@ bool IsCastToReferenceType(const clang::
 // Returns the list of explicit template args for all exprs that support
 // such a concept (declrefexpr, memberexpr), and NULL if none is present.
 const clang::ASTTemplateArgumentListInfo* GetExplicitTplArgs(
+    const clang::FunctionDecl* decl,
     const clang::Expr* expr);
 
 }  // namespace include_what_you_use
