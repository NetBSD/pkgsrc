$NetBSD: patch-src_third__party_v8-3.25_src_platform-posix.cc,v 1.1 2015/05/02 08:10:33 ryoon Exp $

* Add NetBSD support from lang/nodejs.

--- src/third_party/v8-3.25/src/platform-posix.cc.orig	2015-04-08 20:28:08.000000000 +0000
+++ src/third_party/v8-3.25/src/platform-posix.cc
@@ -588,8 +588,13 @@ Thread::Thread(const Options& options)
     : data_(new PlatformData),
       stack_size_(options.stack_size()),
       start_semaphore_(NULL) {
+#if defined(__NetBSD__)
+  if (stack_size_ > 0 && stack_size_ < sysconf(_SC_THREAD_STACK_MIN)) {
+    stack_size_ = sysconf(_SC_THREAD_STACK_MIN);
+#else
   if (stack_size_ > 0 && stack_size_ < PTHREAD_STACK_MIN) {
     stack_size_ = PTHREAD_STACK_MIN;
+#endif
   }
   set_name(options.name());
 }
@@ -605,7 +610,7 @@ static void SetThreadName(const char* na
   pthread_set_name_np(pthread_self(), name);
 #elif V8_OS_NETBSD
   STATIC_ASSERT(Thread::kMaxThreadNameLength <= PTHREAD_MAX_NAMELEN_NP);
-  pthread_setname_np(pthread_self(), "%s", name);
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif V8_OS_MACOSX
   // pthread_setname_np is only available in 10.6 or later, so test
   // for it at runtime.
