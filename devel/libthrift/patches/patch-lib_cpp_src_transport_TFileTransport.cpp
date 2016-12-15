$NetBSD: patch-lib_cpp_src_transport_TFileTransport.cpp,v 1.1 2016/12/15 23:50:01 joerg Exp $

Don't compare pointers to 0, there is no order relation.

--- lib/cpp/src/transport/TFileTransport.cpp.orig	2016-12-13 21:29:23.196467473 +0000
+++ lib/cpp/src/transport/TFileTransport.cpp
@@ -136,7 +136,7 @@ void TFileTransport::resetOutputFile(int
 
 TFileTransport::~TFileTransport() {
   // flush the buffer if a writer thread is active
-  if (writerThreadId_ > 0) {
+  if (writerThreadId_) {
     // set state to closing
     closing_ = true;
 
@@ -521,7 +521,7 @@ void TFileTransport::writerThread() {
 
 void TFileTransport::flush() {
   // file must be open for writing for any flushing to take place
-  if (writerThreadId_ <= 0) {
+  if (writerThreadId_ == 0) {
     return;
   }
   // wait for flush to take place
