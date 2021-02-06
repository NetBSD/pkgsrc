$NetBSD: patch-src_libixion_model__context.cpp,v 1.1 2021/02/06 06:23:22 ryoon Exp $

* Fix build.
  model_context.cpp:20:38: error: expected constructor, destructor, or type conversion before '(' token

--- src/libixion/model_context.cpp.orig	2020-08-28 21:23:48.000000000 +0000
+++ src/libixion/model_context.cpp
@@ -17,7 +17,7 @@
 
 namespace ixion {
 
-model_context::input_cell::input_cell(nullptr_t) : type(celltype_t::empty) {}
+model_context::input_cell::input_cell(std::nullptr_t) : type(celltype_t::empty) {}
 model_context::input_cell::input_cell(bool b) : type(celltype_t::boolean)
 {
     value.boolean = b;
