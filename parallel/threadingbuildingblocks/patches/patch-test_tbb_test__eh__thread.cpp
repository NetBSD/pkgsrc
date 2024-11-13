$NetBSD: patch-test_tbb_test__eh__thread.cpp,v 1.1 2024/11/13 08:58:55 nros Exp $

* NetBSD 9 does not have PTHREAD_STACK_MIN,
  so only use it if it is defined

--- test/tbb/test_eh_thread.cpp.orig	2024-11-13 08:50:17.676722493 +0000
+++ test/tbb/test_eh_thread.cpp
@@ -75,7 +75,11 @@ public:
         mValid = false;
         pthread_attr_t attr;
         // Limit the stack size not to consume all virtual memory on 32 bit platforms.
+#ifdef PTHREAD_STACK_MIN
         std::size_t stacksize = utils::max(std::size_t(128*1024), std::size_t(PTHREAD_STACK_MIN));
+#else
+        std::size_t stacksize = std::size_t(128*1024);
+#endif
         if (pthread_attr_init(&attr) == 0 && pthread_attr_setstacksize(&attr, stacksize) == 0) {
             mValid = pthread_create(&mHandle, &attr, thread_routine, /* arg = */ nullptr) == 0;
         }
