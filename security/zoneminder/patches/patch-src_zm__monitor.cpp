$NetBSD: patch-src_zm__monitor.cpp,v 1.4 2024/12/01 13:49:48 gdt Exp $

The shmat() error return is (apparently) -1 as a pointer.  Some compilers
(E.g. clang on MacOS) refuse to consider testing if a pointer is less than
zero as legal code.  Fix compilation by converting to explicit tests for
particular values that might make sense.

Avoid type error (suseconds_t is not long).  To be addressed upstream once caught up.

--- src/zm_monitor.cpp.orig	2023-02-23 21:44:01.000000000 +0000
+++ src/zm_monitor.cpp
@@ -200,7 +200,7 @@ bool Monitor::MonitorLink::connect() {
     }
 #else // ZM_MEM_MAPPED
     shm_id = shmget((config.shm_key&0xffff0000)|id, mem_size, 0700);
-    if (shm_id < 0) {
+    if (shm_id == (void *)-1) {
       Debug(3, "Can't shmget link memory: %s", strerror(errno));
       connected = false;
       return false;
@@ -236,7 +236,7 @@ bool Monitor::MonitorLink::disconnect() 
     connected = false;
 
 #if ZM_MEM_MAPPED
-    if (mem_ptr > (void *)0) {
+    if (mem_ptr != (void *)0 && mem_ptr != (void *)-1) {
       msync(mem_ptr, mem_size, MS_ASYNC);
       munmap(mem_ptr, mem_size);
     }
@@ -2649,7 +2649,7 @@ void Monitor::TimestampImage(Image *ts_i
           found_macro = true;
           break;
         case 'f' :
-          d_ptr += snprintf(d_ptr, sizeof(label_text)-(d_ptr-label_text), "%02ld", ts_time.tv_usec/10000);
+          d_ptr += snprintf(d_ptr, sizeof(label_text)-(d_ptr-label_text), "%02ld", (long) ts_time.tv_usec/10000);
           found_macro = true;
           break;
       }
