$NetBSD: patch-encoder_encoder.cpp,v 1.3 2018/05/25 14:42:07 jperkin Exp $

Fix error: call of overloaded 'pow(int, int)' is ambiguous

--- encoder/encoder.cpp.orig	2018-05-21 08:33:10.000000000 +0000
+++ encoder/encoder.cpp
@@ -55,6 +55,7 @@ const char g_sliceTypeToChar[] = {'B', '
 static const char* defaultAnalysisFileName = "x265_analysis.dat";
 
 using namespace X265_NS;
+using std::pow;
 
 Encoder::Encoder()
 {
