$NetBSD: patch-src_zm__thread.h,v 1.2.16.1 2015/04/24 16:07:10 hiramatsu Exp $

Fix build with Clang.

pthread_t is opaque, and under NetBSD is a pointer.  It's being abused here,
but the value is only used for logging, and casting pthread_self() is more
portable than syscall(SYS_gettid).

--- src/zm_thread.h.orig	2015-02-05 15:52:37.000000000 +1300
+++ src/zm_thread.h	2015-04-09 18:48:51.419626259 +1200
@@ -22,17 +22,15 @@
 
 #include <unistd.h>
 #include <pthread.h>
+#include <stdint.h>
 #include <unistd.h>
-#ifdef HAVE_SYS_SYSCALL_H
-#include <sys/syscall.h>
-#endif // HAVE_SYS_SYSCALL_H
 #include "zm_exception.h"
 #include "zm_utils.h"
 
 class ThreadException : public Exception
 {
 public:
-    ThreadException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)syscall(SYS_gettid) ) )
+    ThreadException( const std::string &message ) : Exception( stringtf( ("(%lu) "+message).c_str(), (unsigned long)(uintptr_t)pthread_self() ) )
     {
     }
 };
@@ -205,7 +203,7 @@
 
     pid_t id() const
     {
-        return( (pid_t)syscall(SYS_gettid) );
+        return (pid_t)(uintptr_t)pthread_self();
     }
     void exit( int status = 0 )
     {
