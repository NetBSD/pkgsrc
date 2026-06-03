$NetBSD: patch-torch_csrc_utils_python__arg__parser.cpp,v 1.1 2026/06/03 06:45:40 wiz Exp $

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

--- torch/csrc/utils/python_arg_parser.cpp.orig	2025-08-06 17:08:06.000000000 +0000
+++ torch/csrc/utils/python_arg_parser.cpp
@@ -673,9 +673,12 @@ auto handle_torch_function_indexing(
   }
   py::object func =
       PyObject_FastGetAttrString(THPVariableClass, (char*)func_name);
-  py::object args = (val == nullptr)
-      ? py::make_tuple(py::handle(self), py::handle(index))
-      : py::make_tuple(py::handle(self), py::handle(index), py::handle(val));
+  py::tuple args;
+  if (val == nullptr) {
+    args = py::make_tuple(py::handle(self), py::handle(index));
+  } else {
+    args = py::make_tuple(py::handle(self), py::handle(index), py::handle(val));
+  }
   return handle_torch_function_no_python_arg_parser(
       overridable_args,
       args.ptr(),
