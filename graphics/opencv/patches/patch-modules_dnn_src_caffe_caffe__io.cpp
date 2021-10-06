$NetBSD: patch-modules_dnn_src_caffe_caffe__io.cpp,v 1.1 2021/10/06 21:10:24 adam Exp $

Avoid deprecated version of profobuf's SetTotalBytesLimit().

--- modules/dnn/src/caffe/caffe_io.cpp.orig	2021-10-06 19:52:42.000000000 +0000
+++ modules/dnn/src/caffe/caffe_io.cpp
@@ -1111,7 +1111,7 @@ static const int kProtoReadBytesLimit = 
 
 bool ReadProtoFromBinary(ZeroCopyInputStream* input, Message *proto) {
     CodedInputStream coded_input(input);
-    coded_input.SetTotalBytesLimit(kProtoReadBytesLimit, 536870912);
+    coded_input.SetTotalBytesLimit(kProtoReadBytesLimit);
 
     return proto->ParseFromCodedStream(&coded_input);
 }
