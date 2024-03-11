$NetBSD: patch-modules_objdetect_src_qrcode__encoder.cpp,v 1.1 2024/03/11 09:37:20 jperkin Exp $

Avoid ambiguous function call.

--- modules/objdetect/src/qrcode_encoder.cpp.orig	2024-03-11 09:34:13.498700601 +0000
+++ modules/objdetect/src/qrcode_encoder.cpp
@@ -8,6 +8,7 @@
 #include "qrcode_encoder_table.inl.hpp"
 namespace cv
 {
+using std::ceil;
 using std::vector;
 
 const int MAX_PAYLOAD_LEN = 8896;
