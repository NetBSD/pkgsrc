$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_wtf_ThreadSafeRefCounted.h,v 1.1 2017/09/10 19:58:36 joerg Exp $

--- qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/ThreadSafeRefCounted.h.orig	2016-08-23 06:13:30.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/ThreadSafeRefCounted.h
@@ -96,7 +96,7 @@ public:
 #if !USE(LOCKFREE_THREADSAFEREFCOUNTED)
         MutexLocker locker(m_mutex);
 #endif
-        return static_cast<int const volatile &>(m_refCount);
+        return m_refCount;
     }
 
 protected:
@@ -126,7 +126,7 @@ private:
     template<class T>
     friend class CrossThreadRefCounted;
 
-    int m_refCount;
+    atomic_int m_refCount;
 #if !USE(LOCKFREE_THREADSAFEREFCOUNTED)
     mutable Mutex m_mutex;
 #endif
