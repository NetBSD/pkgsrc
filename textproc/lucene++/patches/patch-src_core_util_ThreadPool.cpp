$NetBSD: patch-src_core_util_ThreadPool.cpp,v 1.1 2025/01/23 20:56:32 wiz Exp $

https://github.com/luceneplusplus/LucenePlusPlus/commit/e6a376836e5c891577eae6369263152106b9bc02

--- src/core/util/ThreadPool.cpp.orig	2024-02-18 18:18:26.000000000 +0000
+++ src/core/util/ThreadPool.cpp
@@ -14,15 +14,16 @@ Future::~Future() {
 
 const int32_t ThreadPool::THREADPOOL_SIZE = 5;
 
-ThreadPool::ThreadPool() {
-    work.reset(new boost::asio::io_service::work(io_service));
+ThreadPool::ThreadPool()
+    :
+        work(boost::asio::make_work_guard(io_context))
+{
     for (int32_t i = 0; i < THREADPOOL_SIZE; ++i) {
-        threadGroup.create_thread(boost::bind(&boost::asio::io_service::run, &io_service));
+        threadGroup.create_thread(boost::bind(&boost::asio::io_context::run, &io_context));
     }
 }
 
 ThreadPool::~ThreadPool() {
-    work.reset(); // stop all threads
     threadGroup.join_all(); // wait for all competition
 }
 
