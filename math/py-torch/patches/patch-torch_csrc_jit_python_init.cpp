$NetBSD: patch-torch_csrc_jit_python_init.cpp,v 1.1 2026/06/03 06:45:40 wiz Exp $

commit b248ebc17075c0c3ad2b2532970d2ada32b2cf94
Author: Itamar Oren <itamaro@meta.com>
Date:   Sun Apr 5 17:39:43 2026 +0000

    [caffe2] Fix pybind11 3.0.3 ambiguous return type deduction (#179277)
    
    Summary:
    Add explicit return type annotations to resolve ambiguous type
    deduction in ternary/multi-branch expressions with py::make_tuple.
    
    Differential Revision: D99391633
    
    Pull Request resolved: https://github.com/pytorch/pytorch/pull/179277
    Approved by: https://github.com/Skylion007

--- torch/csrc/jit/python/init.cpp.orig	2025-08-06 17:08:06.000000000 +0000
+++ torch/csrc/jit/python/init.cpp
@@ -1785,7 +1785,7 @@ void initJITBindings(PyObject* module) {
 
   m.def(
       "_jit_get_operation",
-      [](const std::string& op_name) {
+      [](const std::string& op_name) -> py::tuple {
         try {
           auto symbol = Symbol::fromQualString(op_name);
           const auto sortedOps = getAllSortedOperatorsFor(symbol);
@@ -1832,7 +1832,7 @@ void initJITBindings(PyObject* module) {
       "_maybe_call_torch_function_for_op_packet",
       [](py::handle op_overload_packet,
          const py::args& args,
-         const py::kwargs& kwargs) {
+         const py::kwargs& kwargs) -> py::tuple {
         py::list ns_method =
             op_overload_packet.attr("_qualified_op_name").attr("split")("::");
         auto res = _maybe_handle_torch_function(
