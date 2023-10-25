$NetBSD: patch-src_c-writer.cc,v 1.1 2023/10/25 09:05:25 adam Exp $

Fix build: when C++ extensions are enabled, 'typeof' is a keyword.

--- src/c-writer.cc.orig	2023-10-25 09:00:25.236147060 +0000
+++ src/c-writer.cc
@@ -2957,14 +2957,14 @@ void CWriter::Write(const Func& func) {
 
 template <typename Vars, typename TypeOf, typename ToDo>
 void CWriter::WriteVarsByType(const Vars& vars,
-                              const TypeOf& typeof,
+                              const TypeOf& type_of,
                               const ToDo& todo) {
   for (Type type : {Type::I32, Type::I64, Type::F32, Type::F64, Type::V128,
                     Type::FuncRef, Type::ExternRef}) {
     Index var_index = 0;
     size_t count = 0;
     for (const auto& var : vars) {
-      if (typeof(var) == type) {
+      if (type_of(var) == type) {
         if (count == 0) {
           Write(type, " ");
           Indent(4);
