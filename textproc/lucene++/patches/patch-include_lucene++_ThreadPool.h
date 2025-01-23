$NetBSD: patch-include_lucene++_ThreadPool.h,v 1.1 2025/01/23 20:56:32 wiz Exp $

https://github.com/luceneplusplus/LucenePlusPlus/commit/e6a376836e5c891577eae6369263152106b9bc02

--- include/lucene++/ThreadPool.h.orig	2024-02-18 18:18:26.000000000 +0000
+++ include/lucene++/ThreadPool.h
@@ -14,7 +14,9 @@
 
 namespace Lucene {
 
-typedef boost::shared_ptr<boost::asio::io_service::work> workPtr;
+
+typedef boost::asio::io_context io_context_t;
+typedef boost::asio::executor_work_guard<io_context_t::executor_type> work_t;
 
 /// A Future represents the result of an asynchronous computation. Methods are provided to check if the computation
 /// is complete, to wait for its completion, and to retrieve the result of the computation. The result can only be
@@ -51,8 +53,8 @@ public:
     LUCENE_CLASS(ThreadPool);
 
 protected:
-    boost::asio::io_service io_service;
-    workPtr work;
+    io_context_t io_context;
+    work_t work;
     boost::thread_group threadGroup;
 
     static const int32_t THREADPOOL_SIZE;
@@ -64,7 +66,7 @@ public:
     template <typename FUNC>
     FuturePtr scheduleTask(FUNC func) {
         FuturePtr future(newInstance<Future>());
-        io_service.post(boost::bind(&ThreadPool::execute<FUNC>, this, func, future));
+        boost::asio::post(io_context, boost::bind(&ThreadPool::execute<FUNC>, this, func, future));
         return future;
     }
 
