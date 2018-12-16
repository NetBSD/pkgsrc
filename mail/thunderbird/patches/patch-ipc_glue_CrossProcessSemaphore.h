$NetBSD: patch-ipc_glue_CrossProcessSemaphore.h,v 1.1 2018/12/16 08:12:15 ryoon Exp $

--- ipc/glue/CrossProcessSemaphore.h.orig	2018-12-04 23:11:48.000000000 +0000
+++ ipc/glue/CrossProcessSemaphore.h
@@ -93,7 +93,13 @@ private:
   HANDLE mSemaphore;
 #elif !defined(OS_MACOSX)
   RefPtr<mozilla::ipc::SharedMemoryBasic> mSharedBuffer;
+#if defined(__NetBSD__)
+  pthread_mutex_t* mMutex;
+  pthread_cond_t* mNotZero;
+  uint32_t* mValue;
+#else
   sem_t* mSemaphore;
+#endif
   mozilla::Atomic<int32_t>* mRefCount;
 #endif
 };
