$NetBSD: patch-dep_RtspServer_src_net_EventLoop.cpp,v 1.1 2024/12/01 13:49:47 gdt Exp $

Add NetBSD to BSD conditional.

\todo File upstream PR.

--- dep/RtspServer/src/net/EventLoop.cpp.orig	2024-01-14 21:16:28.747478445 +0000
+++ dep/RtspServer/src/net/EventLoop.cpp
@@ -60,7 +60,7 @@ void EventLoop::Loop()
 	{
 #if defined(__linux) || defined(__linux__)
 		std::shared_ptr<TaskScheduler> task_scheduler_ptr(new EpollTaskScheduler(n));
-#elif defined(WIN32) || defined(_WIN32) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(WIN32) || defined(_WIN32) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 		std::shared_ptr<TaskScheduler> task_scheduler_ptr(new SelectTaskScheduler(n));
 #endif
 		task_schedulers_.push_back(task_scheduler_ptr);
