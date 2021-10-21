$NetBSD: patch-modules_dnn_src_layers_accum__layer.cpp,v 1.1 2021/10/21 16:25:07 jperkin Exp $

Explicitly use std::ceil.

--- modules/dnn/src/layers/accum_layer.cpp.orig	2021-10-08 18:31:56.000000000 +0000
+++ modules/dnn/src/layers/accum_layer.cpp
@@ -8,6 +8,7 @@
 #include "../precomp.hpp"
 #include "layers_common.hpp"
 
+using std::ceil;
 
 namespace cv { namespace dnn {
 
