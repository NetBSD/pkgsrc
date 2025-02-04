$NetBSD: patch-src_util_Logs.cpp,v 1.1 2025/02/04 11:25:45 wiz Exp $

Fix build on NetBSD.
https://github.com/wolfpld/vv/commit/b13920153b945d8b2531b7892789c438032bf5c6

--- src/util/Logs.cpp.orig	2024-12-23 10:46:59.000000000 +0000
+++ src/util/Logs.cpp
@@ -101,10 +101,12 @@ void MCoreLogMessage( LogLevel level, co
     va_start( args, fmt );
     const auto len = strlen( fileName );
 
+#ifndef DISABLE_CALLSTACK
     // Get callstack outside of lock
     const bool printCallstack = level >= LogLevel::Error && s_logLevel <= LogLevel::Callstack;
     CallstackData stack;
     if( printCallstack ) stack.count = backtrace( stack.addr, 64 );
+#endif
 
     s_logLock.lock();
     PrintLevel( level );
@@ -121,7 +123,9 @@ void MCoreLogMessage( LogLevel level, co
         fprintf( s_logFile, ANSI_RESET "\n" );
         fflush( s_logFile );
     }
+#ifndef DISABLE_CALLSTACK
     if( printCallstack ) PrintCallstack( stack, 1 );
+#endif
     s_logLock.unlock();
     va_end( args );
 
