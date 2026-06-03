$NetBSD: patch-torch_csrc_distributed_c10d_init.cpp,v 1.1 2026/06/03 06:45:40 wiz Exp $

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

--- torch/csrc/distributed/c10d/init.cpp.orig	2025-08-06 17:08:06.000000000 +0000
+++ torch/csrc/distributed/c10d/init.cpp
@@ -875,7 +875,7 @@ This class does not support ``__members__`` property.)
             return ::c10d::ReduceOp(self);
           })
       .def(py::pickle(
-          [](const ::c10d::ReduceOp& r) {
+          [](const ::c10d::ReduceOp& r) -> py::tuple {
             // __getstate__
             if (r.op_ != ::c10d::ReduceOp::RedOpType::PREMUL_SUM) {
               return py::make_tuple(r.op_, py::none());
