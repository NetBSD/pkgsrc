$NetBSD: patch-src_zm__thread.h,v 1.1 2013/03/24 16:47:47 joerg Exp $

--- src/zm_thread.h.orig	2009-06-08 09:20:17.000000000 +0000
+++ src/zm_thread.h
@@ -27,7 +27,7 @@
 class ThreadException : public Exception
 {
 public:
-    ThreadException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)syscall(224) ) )
+    ThreadException( const std::string &message ) : Exception( stringtf( ("(%d) "+message).c_str(), (long int)syscall(224) ) )
     {
     }
 };
