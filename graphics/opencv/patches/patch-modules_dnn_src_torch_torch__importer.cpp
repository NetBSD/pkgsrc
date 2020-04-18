$NetBSD: patch-modules_dnn_src_torch_torch__importer.cpp,v 1.1 2020/04/18 22:01:34 joerg Exp $

--- modules/dnn/src/torch/torch_importer.cpp.orig	2020-04-18 02:45:10.074752904 +0000
+++ modules/dnn/src/torch/torch_importer.cpp
@@ -46,6 +46,7 @@
 #include <algorithm>
 #include <iostream>
 #include <fstream>
+#include <sstream>
 
 #include "THDiskFile.h"
 
