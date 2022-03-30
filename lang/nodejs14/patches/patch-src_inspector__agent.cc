$NetBSD: patch-src_inspector__agent.cc,v 1.1 2022/03/30 06:51:31 adam Exp $

--- src/inspector_agent.cc.orig	2019-11-19 08:29:09.000000000 +0000
+++ src/inspector_agent.cc
@@ -112,7 +112,7 @@ static int StartDebugSignalHandler() {
   CHECK_EQ(0, uv_sem_init(&start_io_thread_semaphore, 0));
   pthread_attr_t attr;
   CHECK_EQ(0, pthread_attr_init(&attr));
-#if defined(PTHREAD_STACK_MIN) && !defined(__FreeBSD__)
+#if defined(PTHREAD_STACK_MIN) && !defined(__FreeBSD__) && !defined(__NetBSD__)
   // PTHREAD_STACK_MIN is 2 KB with musl libc, which is too small to safely
   // receive signals. PTHREAD_STACK_MIN + MINSIGSTKSZ is 8 KB on arm64, which
   // is the musl architecture with the biggest MINSIGSTKSZ so let's use that
