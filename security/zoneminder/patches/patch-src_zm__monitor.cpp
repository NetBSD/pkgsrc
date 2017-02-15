$NetBSD: patch-src_zm__monitor.cpp,v 1.1 2017/02/15 00:54:25 joerg Exp $

--- src/zm_monitor.cpp.orig	2017-02-15 00:50:20.875646245 +0000
+++ src/zm_monitor.cpp
@@ -149,7 +149,7 @@ bool Monitor::MonitorLink::connect()
             return( false );
         }
         mem_ptr = (unsigned char *)shmat( shm_id, 0, 0 );
-        if ( mem_ptr < 0 )
+        if ( mem_ptr == (void *)-1 )
         {
             Debug( 3, "Can't shmat link memory: %s", strerror(errno) );
             connected = false;
@@ -534,7 +534,7 @@ bool Monitor::connect() {
         exit( -1 );
     }
     mem_ptr = (unsigned char *)shmat( shm_id, 0, 0 );
-    if ( mem_ptr < 0 )
+    if ( mem_ptr == (void *)-1 )
     {
         Error( "Can't shmat: %s", strerror(errno));
         exit( -1 );
