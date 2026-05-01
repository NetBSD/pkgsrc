$NetBSD: patch-djl__os.hxx,v 1.2 2026/05/01 19:52:47 hauke Exp $

NetBSD does not have sched_setaffinity()

--- djl_os.hxx.orig	2026-03-29 16:33:15.000000000 +0000
+++ djl_os.hxx
@@ -86,7 +86,7 @@
 
     inline void set_process_affinity( uint64_t processAffinityMask )
     {
-#if !defined(__APPLE__) && !defined( __mc68000__ )
+#if !defined(__APPLE__) && !defined( __mc68000__ ) && !defined( __NetBSD__ )
         cpu_set_t mask;
         CPU_ZERO( &mask );
 
