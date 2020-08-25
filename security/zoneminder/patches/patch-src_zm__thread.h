$NetBSD: patch-src_zm__thread.h,v 1.5 2020/08/25 16:42:21 gdt Exp $

Fix build with Clang.

pthread_t is opaque, and under NetBSD is a pointer.  It's being abused here,
but the value is only used for logging, and casting pthread_self() is more
portable than syscall(SYS_gettid).

\todo Fix correctly upstream.

--- src/zm_thread.h.orig	2016-02-03 18:40:30.000000000 +0000
+++ src/zm_thread.h
@@ -22,20 +22,21 @@
 
 #include <unistd.h>
 #include <pthread.h>
+#include <stdint.h>
 #include <unistd.h>
-#ifdef HAVE_SYS_SYSCALL_H
-#include <sys/syscall.h>
-#endif // HAVE_SYS_SYSCALL_H
 #include "zm_exception.h"
 #include "zm_utils.h"
 #ifdef __FreeBSD__
 #include <sys/thr.h>
 #endif
 
+/* Assume that because pthread.h was included, all systems have pthread.*/
+#define USE_PTHREAD
+
 class ThreadException : public Exception
 {
 private:
-#ifndef SOLARIS
+#ifndef USE_PTHREAD
 pid_t pid() {
     pid_t tid; 
 #ifdef __FreeBSD__ 
@@ -55,7 +56,8 @@ pid_t pid() {
 pthread_t pid() { return( pthread_self() ); }
 #endif
 public:
-    ThreadException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)pid() ) ) {
+ /* The type of pid() varies by OS */
+ ThreadException( const std::string &message ) : Exception( stringtf( ("(%jd) "+message).c_str(), (intmax_t)pid() ) ) {
     }
 };
 
@@ -217,7 +219,7 @@ protected:
 
     Mutex mThreadMutex;
     Condition mThreadCondition;
-#ifndef SOLARIS
+#ifndef USE_PTHREAD
     pid_t mPid;
 #else
     pthread_t mPid;
@@ -229,7 +231,7 @@ protected:
     Thread();
     virtual ~Thread();
 
-#ifndef SOLARIS
+#ifndef USE_PTHREAD
     pid_t id() const
     {
         pid_t tid; 
@@ -237,22 +239,21 @@ protected:
         long lwpid; 
         thr_self(&lwpid); 
         tid = lwpid; 
-#else 
+#else /* __FreeBSD__ */
     #ifdef __FreeBSD_kernel__
         if ( (syscall(SYS_thr_self, &tid)) < 0 ) // Thread/Process id
-
     #else
         tid=syscall(SYS_gettid); 
     #endif
-#endif
+#endif /* __FreeBSD__ */
 return tid;
     }
-#else
+#else /* USE_PTHREAD */
     pthread_t id() const
     {
         return( pthread_self() );
     }
-#endif
+#endif /* USE_PTHREAD */
     void exit( int status = 0 )
     {
         //INFO( "Exiting" );
@@ -268,7 +269,7 @@ public:
     void kill( int signal );
     bool isThread()
     {
-        return( mPid > -1 && pthread_equal( pthread_self(), mThread ) );
+        return( /* mPid > -1 && */ pthread_equal( pthread_self(), mThread ) );
     }
     bool isStarted() const { return( mStarted ); }
     bool isRunning() const { return( mRunning ); }
