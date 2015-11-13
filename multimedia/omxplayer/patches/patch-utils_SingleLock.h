$NetBSD: patch-utils_SingleLock.h,v 1.1 2015/11/13 15:12:15 skrll Exp $

--- utils/SingleLock.h.orig	2015-01-12 15:10:50.000000000 +0000
+++ utils/SingleLock.h
@@ -40,6 +40,10 @@ public:
   inline void Lock()         { pthread_mutex_lock(&m_lock); }
   inline void Unlock()       { pthread_mutex_unlock(&m_lock); }
 
+private:
+  CCriticalSection(CCriticalSection &other) = delete;
+  CCriticalSection& operator=(const CCriticalSection&) = delete;
+
 protected:
   pthread_mutex_t m_lock;
 };
@@ -48,11 +52,11 @@ protected:
 class CSingleLock
 {
 public:
-  inline CSingleLock(CCriticalSection& cs) { m_section = cs; m_section.Lock(); }
+  inline CSingleLock(CCriticalSection& cs) : m_section(cs) { m_section.Lock(); }
   inline ~CSingleLock()                    { m_section.Unlock(); }
 
 protected:
-  CCriticalSection m_section;
+  CCriticalSection &m_section;
 };
 
 
