$NetBSD: patch-src_util_scoped__timer.cpp,v 1.1 2018/03/13 21:20:34 khorben Exp $

Add support for NetBSD.

--- src/util/scoped_timer.cpp.orig	2016-11-07 22:02:30.000000000 +0000
+++ src/util/scoped_timer.cpp
@@ -33,8 +33,8 @@ Revision History:
 #include<sys/time.h>
 #include<sys/errno.h>
 #include<pthread.h>
-#elif defined(_LINUX_) || defined(_FREEBSD_)
-// Linux
+#elif defined(_LINUX_) || defined(_FREEBSD_) || defined(_NETBSD_)
+// Linux & FreeBSD & NetBSD
 #include<errno.h>
 #include<pthread.h>
 #include<sched.h>
@@ -66,8 +66,8 @@ struct scoped_timer::imp {
     pthread_mutex_t  m_mutex;
     pthread_cond_t   m_condition_var;
     struct timespec  m_end_time;
-#elif defined(_LINUX_) || defined(_FREEBSD_)
-    // Linux & FreeBSD
+#elif defined(_LINUX_) || defined(_FREEBSD_) || defined(_NETBSD_)
+    // Linux & FreeBSD & NetBSD
     pthread_t       m_thread_id;
     pthread_mutex_t m_mutex;
     pthread_cond_t  m_cond;
@@ -103,7 +103,7 @@ struct scoped_timer::imp {
 
         return st;
     }
-#elif defined(_LINUX_) || defined(_FREEBSD_)
+#elif defined(_LINUX_) || defined(_FREEBSD_) || defined(_NETBSD_)
     static void* thread_func(void *arg) {
         scoped_timer::imp *st = static_cast<scoped_timer::imp*>(arg);
 
@@ -166,8 +166,8 @@ struct scoped_timer::imp {
 
         if (pthread_create(&m_thread_id, &m_attributes, &thread_func, this) != 0)
             throw default_exception("failed to start timer thread");
-#elif defined(_LINUX_) || defined(_FREEBSD_)
-        // Linux & FreeBSD
+#elif defined(_LINUX_) || defined(_FREEBSD_) || defined(_NETBSD_)
+        // Linux & FreeBSD & NetBSD
         m_ms = ms;
         m_initialized = false;
         ENSURE(pthread_mutex_init(&m_mutex, NULL) == 0);
@@ -206,8 +206,8 @@ struct scoped_timer::imp {
             throw default_exception("failed to destroy pthread condition variable");
         if (pthread_attr_destroy(&m_attributes) != 0)
             throw default_exception("failed to destroy pthread attributes object");
-#elif defined(_LINUX_) || defined(_FREEBSD_)
-        // Linux & FreeBSD
+#elif defined(_LINUX_) || defined(_FREEBSD_) || defined(_NETBSD_)
+        // Linux & FreeBSD & NetBSD
         bool init = false;
 
         // spin until timer thread has been created
