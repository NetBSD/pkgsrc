$NetBSD: patch-encoder_analysis.cpp,v 1.3 2024/04/05 13:45:51 ryoon Exp $

Ensure std::log() is used.

--- encoder/analysis.cpp.orig	2024-04-04 09:39:50.000000000 +0000
+++ encoder/analysis.cpp
@@ -3739,7 +3739,7 @@ void Analysis::normFactor(const pixel* s
 
     // 2. Calculate ac component
     uint64_t z_k = 0;
-    int block = (int)(((log(blockSize) / log(2)) - 2) + 0.5);
+    int block = (int)(((std::log(blockSize) / std::log(2)) - 2) + 0.5);
     primitives.cu[block].normFact(src, blockSize, shift, &z_k);
 
     // Remove the DC part
