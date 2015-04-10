$NetBSD: patch-src_zm__timer.h,v 1.3 2015/04/10 02:58:49 dsainty Exp $

Fix build with Clang.

pthread_t is opaque, and under NetBSD is a pointer.  It's being abused here,
but the value is only used for logging, and casting pthread_self() is more
portable than syscall(SYS_gettid).

--- src/zm_timer.h.orig	2008-07-25 09:33:24.000000000 +0000
+++ src/zm_timer.h
@@ -30,7 +30,7 @@ private:
     class TimerException : public Exception
     {
     public:
-        TimerException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)syscall(SYS_gettid) ) )
+        TimerException( const std::string &message ) : Exception( stringtf( ("(%lu) "+message).c_str(), (unsigned long)(uintptr_t)pthread_self() ) )
         {
         }
     };
