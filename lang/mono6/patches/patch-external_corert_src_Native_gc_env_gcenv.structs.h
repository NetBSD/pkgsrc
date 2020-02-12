$NetBSD: patch-external_corert_src_Native_gc_env_gcenv.structs.h,v 1.1 2020/02/12 15:25:16 ryoon Exp $

* Workaround for NetBSD's pthread_equal

--- external/corert/src/Native/gc/env/gcenv.structs.h.orig	2020-02-04 17:00:39.000000000 +0000
+++ external/corert/src/Native/gc/env/gcenv.structs.h
@@ -42,7 +42,7 @@ class EEThreadId
 public:
     bool IsCurrentThread()
     {
-        return m_isValid && pthread_equal(m_id, pthread_self());
+        return m_isValid && (m_id == pthread_self());
     }
 
     void SetToCurrentThread()
