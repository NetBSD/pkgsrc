$NetBSD: patch-base_thread.cc,v 1.1 2017/12/17 14:15:43 tsutsui Exp $

* tweak for NetBSD pthread_setname_np(3)

--- base/thread.cc.orig	2017-11-02 13:32:45.000000000 +0000
+++ base/thread.cc
@@ -145,9 +145,11 @@ void Thread::Start(const string &thread_
     // NaCl doesn't support setname.
 #elif defined(OS_MACOSX)
     pthread_setname_np(thread_name.c_str());
-#else  // !(OS_NACL | OS_MACOSX)
+#elif defined(OS_NETBSD)
+    pthread_setname_np(*state_->handle_, "%s", (void *)thread_name.c_str());
+#else  // !(OS_NACL | OS_MACOSX | OS_NETBSD)
     pthread_setname_np(*state_->handle_, thread_name.c_str());
-#endif  // !(OS_NACL | OS_MACOSX)
+#endif  // !(OS_NACL | OS_MACOSX | OS_NETBSD)
   }
 }
 
