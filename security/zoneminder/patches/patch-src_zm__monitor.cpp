$NetBSD: patch-src_zm__monitor.cpp,v 1.5 2026/01/07 01:03:59 gdt Exp $

The shmat() error return is (apparently) -1 as a pointer.  Some compilers
(E.g. clang on MacOS) refuse to consider testing if a pointer is less than
zero as legal code.  Fix compilation by converting to explicit tests for
particular values that might make sense.

Avoid type error (suseconds_t is not long).  To be addressed upstream once caught up.

--- src/zm_monitor.cpp.orig	2026-01-06 13:05:00.000000000 +0000
+++ src/zm_monitor.cpp
@@ -187,7 +187,7 @@ bool Monitor::MonitorLink::connect() {
       disconnect();
       return false;
     } else if (map_stat.st_size < mem_size) {
-      Error("Got unexpected memory map file size %ld, expected %jd", static_cast<intmax_t>(map_stat.st_size), static_cast<intmax_t>(mem_size));
+      Error("Got unexpected memory map file size %jd, expected %jd", static_cast<intmax_t>(map_stat.st_size), static_cast<intmax_t>(mem_size));
       disconnect();
       return false;
     }
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
@@ -943,41 +943,41 @@ bool Monitor::connect() {
     if (purpose == CAPTURE) {
       // Allocate the size
       if (ftruncate(map_fd, mem_size) < 0) {
-        Error("Can't extend memory map file %s to %jd bytes: %s", mem_file.c_str(), mem_size, strerror(errno));
+        Error("Can't extend memory map file %s to %jd bytes: %s", mem_file.c_str(), static_cast<intmax_t>(mem_size), strerror(errno));
         close(map_fd);
         map_fd = -1;
         return false;
       }
     } else if (map_stat.st_size == 0) {
-      Error("Got empty memory map file size %ld, is the zmc process for this monitor running?", map_stat.st_size);
+      Error("Got empty memory map file size %jd, is the zmc process for this monitor running?", static_cast<intmax_t>(map_stat.st_size));
       close(map_fd);
       map_fd = -1;
       return false;
     } else {
-      Error("Got unexpected memory map file size %ld, expected %jd", map_stat.st_size, mem_size);
+      Error("Got unexpected memory map file size %jd, expected %jd", static_cast<intmax_t>(map_stat.st_size), static_cast<intmax_t>(mem_size));
       close(map_fd);
       map_fd = -1;
       return false;
     }
   }  // end if map_stat.st_size != mem_size
 
-  Debug(3, "MMap file size is %ld", map_stat.st_size);
+  Debug(3, "MMap file size is %jd", static_cast<intmax_t>(map_stat.st_size));
 #ifdef MAP_LOCKED
   mem_ptr = (unsigned char *)mmap(nullptr, mem_size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_LOCKED, map_fd, 0);
   if (mem_ptr == MAP_FAILED) {
     if (errno == EAGAIN) {
-      Debug(1, "Unable to map file %s (%jd bytes) to locked memory, trying unlocked", mem_file.c_str(), mem_size);
+      Debug(1, "Unable to map file %s (%jd bytes) to locked memory, trying unlocked", mem_file.c_str(), static_cast<intmax_t>(mem_size));
 #endif
       mem_ptr = (unsigned char *)mmap(nullptr, mem_size, PROT_READ|PROT_WRITE, MAP_SHARED, map_fd, 0);
-      Debug(1, "Mapped file %s (%jd bytes) to unlocked memory", mem_file.c_str(), mem_size);
+      Debug(1, "Mapped file %s (%jd bytes) to unlocked memory", mem_file.c_str(), static_cast<intmax_t>(mem_size));
 #ifdef MAP_LOCKED
     } else {
-      Error("Unable to map file %s (%jd bytes) to locked memory (%s)", mem_file.c_str(), mem_size, strerror(errno));
+      Error("Unable to map file %s (%jd bytes) to locked memory (%s)", mem_file.c_str(), static_cast<intmax_t>(mem_size), strerror(errno));
     }
   }
 #endif
   if ((mem_ptr == MAP_FAILED) or (mem_ptr == nullptr)) {
-    Error("Can't map file %s (%jd bytes) to memory: %s(%d)", mem_file.c_str(), mem_size, strerror(errno), errno);
+    Error("Can't map file %s (%jd bytes) to memory: %s(%d)", mem_file.c_str(), static_cast<intmax_t>(mem_size), strerror(errno), errno);
     close(map_fd);
     map_fd = -1;
     mem_ptr = nullptr;
@@ -2625,8 +2625,8 @@ bool Monitor::Decode() {
   gettimeofday(&now, nullptr);
   shared_data->last_write_time = now.tv_sec;
   if (now.tv_sec - packet->timestamp.tv_sec > ZM_WATCH_MAX_DELAY) {
-    Warning("Decoding is not keeping up. We are %ld seconds behind capture.",
-        now.tv_sec - packet->timestamp.tv_sec);
+    Warning("Decoding is not keeping up. We are %jd seconds behind capture.",
+    static_cast<intmax_t>(now.tv_sec - packet->timestamp.tv_sec));
   }
 
   packetqueue.unlock(packet_lock);
@@ -2657,7 +2657,7 @@ void Monitor::TimestampImage(Image *ts_i
           found_macro = true;
           break;
         case 'f' :
-          d_ptr += snprintf(d_ptr, sizeof(label_text)-(d_ptr-label_text), "%02ld", ts_time.tv_usec/10000);
+          d_ptr += snprintf(d_ptr, sizeof(label_text)-(d_ptr-label_text), "%02ld", (long) ts_time.tv_usec/10000);
           found_macro = true;
           break;
       }
