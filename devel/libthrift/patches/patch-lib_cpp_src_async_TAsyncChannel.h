$NetBSD: patch-lib_cpp_src_async_TAsyncChannel.h,v 1.1 2013/05/14 19:15:36 joerg Exp $

Incomplete.

--- lib/cpp/src/async/TAsyncChannel.h.orig	2013-04-30 19:12:03.000000000 +0000
+++ lib/cpp/src/async/TAsyncChannel.h
@@ -20,7 +20,11 @@
 #ifndef _THRIFT_ASYNC_TASYNCCHANNEL_H_
 #define _THRIFT_ASYNC_TASYNCCHANNEL_H_ 1
 
+#if __cplusplus >= 201103L
+#include <functional>
+#else
 #include <tr1/functional>
+#endif
 #include <Thrift.h>
 
 namespace apache { namespace thrift { namespace transport {
@@ -32,7 +37,11 @@ using apache::thrift::transport::TMemory
 
 class TAsyncChannel {
  public:
+#if __cplusplus >= 201103L
+  typedef std::function<void()> VoidCallback;
+#else
   typedef std::tr1::function<void()> VoidCallback;
+#endif
 
   virtual ~TAsyncChannel() {}
 
