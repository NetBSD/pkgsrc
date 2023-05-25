$NetBSD: patch-src_ast_rewriter_seq__eq__solver.cpp,v 1.1 2023/05/25 10:53:24 jperkin Exp $

Avoid ambiguous function call.

--- src/ast/rewriter/seq_eq_solver.cpp.orig	2023-05-12 19:59:04.000000000 +0000
+++ src/ast/rewriter/seq_eq_solver.cpp
@@ -284,7 +284,7 @@ namespace seq {
         bv_util bv(m);
         sort* bv_sort = n->get_sort();
         unsigned sz = bv.get_bv_size(n);
-        if (es.size() > (sz + log2(10)-1)/log2(10)) {
+        if (es.size() > (sz + log2(10.0)-1)/log2(10.0)) {
             set_conflict();
             return true;
         }
