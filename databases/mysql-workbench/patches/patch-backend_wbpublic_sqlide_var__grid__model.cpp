$NetBSD: patch-backend_wbpublic_sqlide_var__grid__model.cpp,v 1.1 2012/12/25 21:12:31 joerg Exp $

--- backend/wbpublic/sqlide/var_grid_model.cpp.orig	2012-12-25 14:43:01.000000000 +0000
+++ backend/wbpublic/sqlide/var_grid_model.cpp
@@ -410,7 +410,7 @@ bool VarGridModel::set_field(const NodeI
       bool is_blob_column= sqlide::is_var_blob(_real_column_types[column]);
       if (!_optimized_blob_fetching || !is_blob_column)
       {
-        static const sqlide::VarEq var_eq;
+        static sqlide::VarEq var_eq;
         if (!is_blob_column)
           res= !boost::apply_visitor(var_eq, value, *cell);
         if (res)
