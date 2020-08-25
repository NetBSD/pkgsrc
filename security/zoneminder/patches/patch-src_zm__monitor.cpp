$NetBSD: patch-src_zm__monitor.cpp,v 1.2 2020/08/25 16:42:21 gdt Exp $

\todo Explain mem_ptr change.

Avoid type error (suseconds_t is not long).  To be addressed upstream once caught up.

--- src/zm_monitor.cpp.orig	2016-02-03 18:40:30.000000000 +0000
+++ src/zm_monitor.cpp
@@ -160,7 +160,7 @@ bool Monitor::MonitorLink::connect()
             return( false );
         }
         mem_ptr = (unsigned char *)shmat( shm_id, 0, 0 );
-        if ( mem_ptr < 0 )
+        if ( mem_ptr == (void *)-1 )
         {
             Debug( 3, "Can't shmat link memory: %s", strerror(errno) );
             connected = false;
@@ -558,7 +558,7 @@ bool Monitor::connect() {
         exit( -1 );
     }
     mem_ptr = (unsigned char *)shmat( shm_id, 0, 0 );
-    if ( mem_ptr < 0 )
+    if ( mem_ptr == (void *)-1 )
     {
         Error( "Can't shmat: %s", strerror(errno));
         exit( -1 );
@@ -3181,7 +3181,7 @@ void Monitor::TimestampImage( Image *ts_
                         found_macro = true;
                         break;
                     case 'f' :
-                        d_ptr += snprintf( d_ptr, sizeof(label_text)-(d_ptr-label_text), "%02ld", ts_time->tv_usec/10000 );
+		         d_ptr += snprintf( d_ptr, sizeof(label_text)-(d_ptr-label_text), "%02ld", (long) ts_time->tv_usec/10000 );
                         found_macro = true;
                         break;
                 }
