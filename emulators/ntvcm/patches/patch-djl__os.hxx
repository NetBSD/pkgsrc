$NetBSD: patch-djl__os.hxx,v 1.1 2025/07/04 16:30:12 hauke Exp $

NetBSD does not have sched_setaffinity()

--- djl_os.hxx.orig	2025-07-02 22:41:46.000000000 +0000
+++ djl_os.hxx
@@ -87,7 +87,7 @@ extern "C" int nanosleep( const struct t
 
     inline void set_process_affinity( uint64_t processAffinityMask )
     {
-#if !defined(__APPLE__) && !defined( OLDGCC ) && !defined( M68K )
+#if !defined(__APPLE__) && !defined( OLDGCC ) && !defined( M68K ) && !defined( __NetBSD__ )
         cpu_set_t mask;
         CPU_ZERO( &mask );
 
