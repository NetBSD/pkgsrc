$NetBSD: patch-backend_wbpublic_sqlide_sqlide__generics.cpp,v 1.1 2012/12/25 21:12:31 joerg Exp $

--- backend/wbpublic/sqlide/sqlide_generics.cpp.orig	2012-12-25 14:37:05.000000000 +0000
+++ backend/wbpublic/sqlide/sqlide_generics.cpp
@@ -38,7 +38,7 @@ public:
   template <typename T> result_type operator()(const T &v1, const T &v2) const { return true; }
   template <typename T1, typename T2> result_type operator()(const T1 &v1, const T2 &v2) const { return false; }
 };
-static const IsVarTypeEqTo is_var_type_eq_to;
+static IsVarTypeEqTo is_var_type_eq_to;
 
 bool is_var_null(const sqlite::Variant &value)
 {
