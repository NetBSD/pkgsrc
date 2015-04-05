$NetBSD: patch-src_zm__timer.h,v 1.2 2015/04/05 08:51:08 dsainty Exp $

--- src/zm_timer.h.orig	2008-07-25 09:33:24.000000000 +0000
+++ src/zm_timer.h
@@ -30,7 +30,7 @@ private:
     class TimerException : public Exception
     {
     public:
-        TimerException( const std::string &message ) : Exception( stringtf( "(%d) "+message, (long int)syscall(SYS_gettid) ) )
+        TimerException( const std::string &message ) : Exception( stringtf( ("(%d) "+message).c_str(), (long int)syscall(SYS_gettid) ) )
         {
         }
     };
