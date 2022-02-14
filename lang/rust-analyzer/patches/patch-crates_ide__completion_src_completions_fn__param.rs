$NetBSD: patch-crates_ide__completion_src_completions_fn__param.rs,v 1.1 2022/02/14 08:27:17 adam Exp $

Use pre-1.58.0 format strings.

--- crates/ide_completion/src/completions/fn_param.rs.orig	2022-02-14 08:22:58.000000000 +0000
+++ crates/ide_completion/src/completions/fn_param.rs
@@ -45,7 +45,7 @@ pub(crate) fn complete_fn_param(acc: &mu
         ParamKind::Closure(closure) => {
             let stmt_list = closure.syntax().ancestors().find_map(ast::StmtList::cast)?;
             params_from_stmt_list_scope(ctx, stmt_list, |name, ty| {
-                add_new_item_to_acc(&format!("{name}: {ty}"), name.to_string());
+                add_new_item_to_acc(&format!("{}: {}", name, ty), name.to_string());
             });
         }
     }
@@ -94,7 +94,7 @@ fn fill_fn_params(
 
     if let Some(stmt_list) = function.syntax().parent().and_then(ast::StmtList::cast) {
         params_from_stmt_list_scope(ctx, stmt_list, |name, ty| {
-            file_params.entry(format!("{name}: {ty}")).or_insert(name.to_string());
+            file_params.entry(format!("{}: {}", name, ty)).or_insert(name.to_string());
         });
     }
 
