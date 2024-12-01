$NetBSD: patch-src_zmu.cpp,v 1.5 2024/12/01 13:49:48 gdt Exp $

time types

--- src/zmu.cpp.orig	2023-02-23 21:44:01.000000000 +0000
+++ src/zmu.cpp
@@ -542,12 +542,12 @@ int main(int argc, char *argv[]) {
           strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", localtime_r(&timestamp.tv_sec, &tm_info));
         }
         if ( image_idx == -1 )
-          printf("Time of last image capture: %s.%02ld\n", timestamp_str, timestamp.tv_usec/10000);
+          printf("Time of last image capture: %s.%02ld\n", timestamp_str, (long) timestamp.tv_usec/10000);
         else
-          printf("Time of image %d capture: %s.%02ld\n", image_idx, timestamp_str, timestamp.tv_usec/10000);
+          printf("Time of image %d capture: %s.%02ld\n", image_idx, timestamp_str, (long) timestamp.tv_usec/10000);
       } else {
         if ( have_output ) fputc(separator, stdout);
-        printf("%ld.%02ld", timestamp.tv_sec, timestamp.tv_usec/10000);
+        printf("%jd.%02ld", (intmax_t) timestamp.tv_sec, (long) timestamp.tv_usec/10000);
         have_output = true;
       }
     }
@@ -777,12 +777,12 @@ int main(int argc, char *argv[]) {
             std::shared_ptr<Monitor> monitor = Monitor::Load(monitor_id, false, Monitor::QUERY);
             if ( monitor && monitor->connect() ) {
               struct timeval tv = monitor->GetTimestamp();
-              printf( "%4d%5d%6d%9d%11ld.%02ld%6d%6d%8" PRIu64 "%8.2f\n",
+              printf( "%4d%5d%6d%9d%11jd.%02ld%6d%6d%8" PRIu64 "%8.2f\n",
                 monitor->Id(),
                 monitor_function,
                 monitor->GetState(),
                 monitor->GetTriggerState(),
-                tv.tv_sec, tv.tv_usec/10000,
+		(intmax_t) tv.tv_sec, (long) tv.tv_usec/10000,
                 monitor->GetLastReadIndex(),
                 monitor->GetLastWriteIndex(),
                 monitor->GetLastEventId(),
@@ -791,12 +791,12 @@ int main(int argc, char *argv[]) {
             }
           } else {
             struct timeval tv = { 0, 0 };
-            printf("%4d%5d%6d%9d%11ld.%02ld%6d%6d%8d%8.2f\n",
+            printf("%4d%5d%6d%9d%11jd.%02ld%6d%6d%8d%8.2f\n",
               mon_id,
               function,
               0,
               0,
-              tv.tv_sec, tv.tv_usec/10000,
+              (intmax_t) tv.tv_sec, (long) tv.tv_usec/10000,
               0,
               0,
               0,
