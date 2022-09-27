$NetBSD: patch-src_zm__monitor.cpp,v 1.3 2022/09/27 01:20:39 gdt Exp $

The shmat() error return is (apparently) -1 as a pointer.  Some compilers
(E.g. clang on MacOS) refuse to consider testing if a pointer is less than
zero as legal code.  Fix compilation by converting to explicit tests for
particular values that might make sense.

Avoid type error (suseconds_t is not long).  To be addressed upstream once caught up.

--- src/zm_monitor.cpp.orig	2019-02-23 04:38:47.000000000 +1300
+++ src/zm_monitor.cpp	2022-01-19 21:56:47.000000000 +1300
@@ -160,7 +160,7 @@
       return( false );
     }
     mem_ptr = (unsigned char *)shmat( shm_id, 0, 0 );
-    if ( mem_ptr < 0 )
+    if ( mem_ptr == (void *)-1 )
     {
       Debug( 3, "Can't shmat link memory: %s", strerror(errno) );
       connected = false;
@@ -194,7 +194,7 @@
     connected = false;
 
 #if ZM_MEM_MAPPED
-    if ( mem_ptr > 0 )
+    if ( mem_ptr != 0 && mem_ptr != (void *)-1 )
     {
       msync( mem_ptr, mem_size, MS_ASYNC );
       munmap( mem_ptr, mem_size );
@@ -3175,7 +3175,7 @@
             found_macro = true;
             break;
           case 'f' :
-            d_ptr += snprintf( d_ptr, sizeof(label_text)-(d_ptr-label_text), "%02ld", ts_time->tv_usec/10000 );
+            d_ptr += snprintf( d_ptr, sizeof(label_text)-(d_ptr-label_text), "%02ld", (long) ts_time->tv_usec/10000 );
             found_macro = true;
             break;
         }
