$NetBSD: patch-encoder_analysis.cpp,v 1.1 2019/09/18 10:04:51 jperkin Exp $

Ensure std::log() is used.

--- encoder/analysis.cpp.orig	2019-07-08 11:10:19.000000000 +0000
+++ encoder/analysis.cpp
@@ -3702,7 +3702,7 @@ void Analysis::normFactor(const pixel* s
 
     // 2. Calculate ac component
     uint64_t z_k = 0;
-    int block = (int)(((log(blockSize) / log(2)) - 2) + 0.5);
+    int block = (int)(((std::log(blockSize) / std::log(2)) - 2) + 0.5);
     primitives.cu[block].normFact(src, blockSize, shift, &z_k);
 
     // Remove the DC part
