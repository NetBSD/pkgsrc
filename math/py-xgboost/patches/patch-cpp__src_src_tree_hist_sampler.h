$NetBSD: patch-cpp__src_src_tree_hist_sampler.h,v 1.1 2026/10/26 07:39:21 wiz Exp $

In file included from /tmp/math/py-xgboost/work/xgboost-3.4.1/cpp_src/src/tree/hist/sampler.cc:4:
/tmp/math/py-xgboost/work/xgboost-3.4.1/cpp_src/src/tree/hist/sampler.h: In function 'float xgboost::tree::SamplingProbability(float, float)':
/tmp/math/py-xgboost/work/xgboost-3.4.1/cpp_src/src/tree/hist/sampler.h:66:9: error: '::isinf' has not been declared; did you mean 'std::isinf'?
   66 |   if (::isinf(u)) {
      |         ^~~~~
      |         std::isinf

--- cpp_src/src/tree/hist/sampler.h.orig	2026-10-26 07:21:07.904416272 +0000
+++ cpp_src/src/tree/hist/sampler.h
@@ -63,7 +63,7 @@ XGBOOST_DEVICE inline float SamplingProbability(float 
 
 XGBOOST_DEVICE inline float SamplingProbability(float u, float reg_abs_grad) {
   // An infinite threshold represents an empty sampling budget exactly.
-  if (::isinf(u)) {
+  if (std::isinf(u)) {
     return 0.0f;
   }
   if (::fabs(u) < kRtEps) {
