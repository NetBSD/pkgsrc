$NetBSD: patch-src_zm__thread.h,v 1.2 2013/04/29 21:31:13 joerg Exp $

--- src/zm_thread.h.orig	2009-06-08 09:20:17.000000000 +0000
+++ src/zm_thread.h
@@ -20,6 +20,7 @@
 #ifndef ZM_THREAD_H
 #define ZM_THREAD_H
 
+#include <unistd.h>
 #include <pthread.h>
 #include "zm_exception.h"
 #include "zm_utils.h"
@@ -27,7 +28,7 @@
 class ThreadException : public Exception
 {
 public:
-    ThreadException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)syscall(224) ) )
+    ThreadException( const std::string &message ) : Exception( stringtf( ("(%d) "+message).c_str(), (long int)syscall(224) ) )
     {
     }
 };
