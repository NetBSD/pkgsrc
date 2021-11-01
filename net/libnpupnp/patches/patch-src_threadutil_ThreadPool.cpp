$NetBSD: patch-src_threadutil_ThreadPool.cpp,v 1.1 2021/11/01 21:47:01 wiz Exp $

Add header for setpriority().

--- src/threadutil/ThreadPool.cpp.orig	2021-08-19 06:17:24.000000000 +0000
+++ src/threadutil/ThreadPool.cpp
@@ -42,6 +42,7 @@
 #include <mutex>
 #include <condition_variable>
 #include <iostream>
+#include <sys/resource.h>
 
 using namespace std::chrono;
 
