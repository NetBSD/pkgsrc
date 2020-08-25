$NetBSD: patch-src_zm__timer.h,v 1.4 2020/08/25 16:42:21 gdt Exp $

Fix build with Clang.

pthread_t is opaque, and under NetBSD is a pointer.  It's being abused here,
but the value is only used for logging, and casting pthread_self() is more
portable than syscall(SYS_gettid).

--- src/zm_timer.h.orig	2016-02-03 18:40:30.000000000 +0000
+++ src/zm_timer.h
@@ -33,7 +33,7 @@ private:
     class TimerException : public Exception
     {
     private:
-#ifndef SOLARIS
+#if !defined(SOLARIS) && !defined(__NetBSD__)
         pid_t pid() {
 		pid_t tid;
 #ifdef __FreeBSD__
@@ -53,7 +53,7 @@ private:
 	pthread_t pid() { return( pthread_self() ); }
 #endif
     public:
-        TimerException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)pid() ) )
+        TimerException( const std::string &message ) : Exception( stringtf( ("(%d) "+message).c_str(), (intmax_t)pid() ) )
         {
         }
     };
