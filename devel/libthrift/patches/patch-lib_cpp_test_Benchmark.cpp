$NetBSD: patch-lib_cpp_test_Benchmark.cpp,v 1.1 2013/05/28 19:01:00 joerg Exp $

--- lib/cpp/test/Benchmark.cpp.orig	2013-05-28 10:49:31.000000000 +0000
+++ lib/cpp/test/Benchmark.cpp
@@ -65,7 +65,7 @@ int main() {
   ooe.zomg_unicode     = "\xd7\n\a\t";
   ooe.base64 = "\1\2\3\255";
 
-  shared_ptr<TMemoryBuffer> buf(new TMemoryBuffer());
+  boost::shared_ptr<TMemoryBuffer> buf(new TMemoryBuffer());
 
   int num = 1000000;
 
@@ -91,7 +91,7 @@ int main() {
 
     for (int i = 0; i < num; i ++) {
       OneOfEach ooe2;
-      shared_ptr<TMemoryBuffer> buf2(new TMemoryBuffer(data, datasize));
+      boost::shared_ptr<TMemoryBuffer> buf2(new TMemoryBuffer(data, datasize));
       //buf2->resetBuffer(data, datasize);
       TBinaryProtocolT<TBufferBase> prot(buf2);
       ooe2.read(&prot);
