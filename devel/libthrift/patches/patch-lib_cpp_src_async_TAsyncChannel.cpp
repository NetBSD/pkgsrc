$NetBSD: patch-lib_cpp_src_async_TAsyncChannel.cpp,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- lib/cpp/src/async/TAsyncChannel.cpp.orig	2013-05-03 21:55:49.000000000 +0000
+++ lib/cpp/src/async/TAsyncChannel.cpp
@@ -18,15 +18,23 @@
  */
 
 #include <async/TAsyncChannel.h>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+using std::bind;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+using std::tr1::bind;
+#endif
 
 namespace apache { namespace thrift { namespace async {
 
 void TAsyncChannel::sendAndRecvMessage(const VoidCallback& cob,
                                        TMemoryBuffer* sendBuf,
                                        TMemoryBuffer* recvBuf) {
-  std::tr1::function<void()> send_done =
-    std::tr1::bind(&TAsyncChannel::recvMessage, this, cob, recvBuf);
+  function<void()> send_done =
+    bind(&TAsyncChannel::recvMessage, this, cob, recvBuf);
 
   sendMessage(send_done, sendBuf);
 }
