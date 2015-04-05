$NetBSD: patch-src_zm__thread.h,v 1.3 2015/04/05 08:51:08 dsainty Exp $

--- src/zm_thread.h.orig	2015-02-05 15:52:37.000000000 +1300
+++ src/zm_thread.h	2015-04-01 17:04:46.728233504 +1300
@@ -32,7 +32,7 @@
 class ThreadException : public Exception
 {
 public:
-    ThreadException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)syscall(SYS_gettid) ) )
+    ThreadException( const std::string &message ) : Exception( stringtf( ("(%d) "+message).c_str(), (long int)syscall(SYS_gettid) ) )
     {
     }
 };
