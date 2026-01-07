$NetBSD: patch-src_zm__event.cpp,v 1.7 2026/01/07 01:03:59 gdt Exp $

zoneminder uses %ld for time_t, which is troublesome on NetBSD arm and
presumably i386.  (Note that there are multiple patch files for the
same issue.)

Not yet sent upstream -- needs update to latest release first, where
it might be fixed, or the patch might simply need to be rebased.
Also, this fix is expedient and probably a better fix is appropriate.

Avoid sendfile code when sendfile doesn't exist.

--- src/zm_event.cpp.orig	2026-01-06 13:05:00.000000000 +0000
+++ src/zm_event.cpp
@@ -93,8 +93,9 @@ Event::Event(
     localtime_r(&now.tv_sec, &tm_info);
     strftime(buffer_now, 26, "%Y:%m:%d %H:%M:%S", &tm_info);
 
-    Error("StartDateTime in the future starttime %ld.%06ld >? now %ld.%06ld difference %" PRIi64 "\nstarttime: %s\nnow: %s",
-          start_time.tv_sec, start_time.tv_usec, now.tv_sec, now.tv_usec,
+    Error("StartDateTime in the future starttime %jd.%06ld >? now %jd.%06ld difference %" PRIi64 "\nstarttime: %s\nnow: %s",
+          static_cast<intmax_t>(start_time.tv_sec), static_cast<long>(start_time.tv_usec),
+          static_cast<intmax_t>(now.tv_sec), static_cast<long>(now.tv_usec),
           static_cast<int64>(now.tv_sec - start_time.tv_sec),
           buffer, buffer_now);
     start_time = now;
@@ -116,10 +117,10 @@ Event::Event(
       "INSERT INTO `Events` "
       "( `MonitorId`, `StorageId`, `Name`, `StartDateTime`, `Width`, `Height`, `Cause`, `Notes`, `StateId`, `Orientation`, `Videoed`, `DefaultVideo`, `SaveJPEGs`, `Scheme` )"
       " VALUES "
-      "( %d, %d, 'New Event', from_unixtime( %ld ), %d, %d, '%s', '%s', %d, %d, %d, '%s', %d, '%s' )",
+      "( %d, %d, 'New Event', from_unixtime( %jd ), %d, %d, '%s', '%s', %d, %d, %d, '%s', %d, '%s' )",
       monitor->Id(), 
       storage->Id(),
-      start_time.tv_sec,
+      (intmax_t) start_time.tv_sec,
       monitor->Width(),
       monitor->Height(),
       cause.c_str(),
@@ -374,12 +375,12 @@ void Event::WriteDbFrames() {
   while (frame_data.size()) {
     Frame *frame = frame_data.front();
     frame_data.pop();
-    frame_insert_sql += stringtf("\n( %" PRIu64 ", %d, '%s', from_unixtime( %jd ), %s%ld.%02ld, %d ),",
+    frame_insert_sql += stringtf("\n( %" PRIu64 ", %d, '%s', from_unixtime( %jd ), %s%jd.%02ld, %d ),",
         id, frame->frame_id,
         frame_type_names[frame->type],
         static_cast<intmax_t>(frame->timestamp.tv_sec),
         frame->delta.positive ? "" : "-",
-        frame->delta.sec,
+	static_cast<intmax_t>(frame->delta.sec),
         frame->delta.fsec,
         frame->score);
     if (config.record_event_stats and frame->zone_stats.size()) {
@@ -527,9 +528,9 @@ void Event::AddFrame(const std::shared_p
 
       char sql[ZM_SQL_MED_BUFSIZ];
       snprintf(sql, sizeof(sql), 
-          "UPDATE Events SET Length = %s%ld.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d WHERE Id = %" PRIu64, 
+          "UPDATE Events SET Length = %s%jd.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d WHERE Id = %" PRIu64, 
           ( delta_time.positive?"":"-" ),
-          delta_time.sec, delta_time.fsec,
+          (intmax_t) delta_time.sec, delta_time.fsec,
           frames, 
           alarm_frames,
           tot_score,
