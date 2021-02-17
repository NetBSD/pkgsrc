$NetBSD: patch-base_thread.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* tweak for NetBSD pthread_setname_np(3)

--- base/thread.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ base/thread.cc
@@ -145,9 +145,11 @@ void Thread::Start(const std::string &th
     // WASM doesn't support setname?
 #elif defined(__APPLE__)  // !OS_WASM
     pthread_setname_np(thread_name.c_str());
-#else                     // !(OS_WASM | __APPLE__)
+#elif defined(OS_NETBSD)
+    pthread_setname_np(*state_->handle, "%s", (void *)thread_name.c_str());
+#else                     // !(OS_WASM | __APPLE__ | OS_NETBSD)
     pthread_setname_np(*state_->handle, thread_name.c_str());
-#endif                    // !(OS_WASM | __APPLE__)
+#endif                    // !(OS_WASM | __APPLE__ | OS_NETBSD)
   }
 }
 
