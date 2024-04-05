$NetBSD: patch-encoder_encoder.cpp,v 1.5 2024/04/05 13:45:51 ryoon Exp $

Fix error: call of overloaded 'pow(int, int)' is ambiguous

--- encoder/encoder.cpp.orig	2024-04-04 09:39:50.000000000 +0000
+++ encoder/encoder.cpp
@@ -118,6 +118,7 @@ VideoSignalTypePresets vstPresets[] =
 static const char* defaultAnalysisFileName = "x265_analysis.dat";
 
 using namespace X265_NS;
+using std::pow;
 
 Encoder::Encoder()
 {
