$NetBSD: patch-modules_dnn_src_tensorflow_tf__importer.cpp,v 1.1 2020/04/18 22:01:34 joerg Exp $

--- modules/dnn/src/tensorflow/tf_importer.cpp.orig	2020-04-18 02:43:16.265690888 +0000
+++ modules/dnn/src/tensorflow/tf_importer.cpp
@@ -14,6 +14,7 @@ Implementation of Tensorflow models pars
 #ifdef HAVE_PROTOBUF
 #include "tf_io.hpp"
 
+#include <sstream>
 #include <iostream>
 #include <fstream>
 #include <algorithm>
