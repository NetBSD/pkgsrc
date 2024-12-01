$NetBSD: patch-src_zm__event.cpp,v 1.5 2024/12/01 13:49:48 gdt Exp $

zoneminder uses %ld for time_t, which is troublesome on NetBSD arm and
presumably i386.  (Note that there are multiple patch files for the
same issue.)

Not yet sent upstream -- needs update to latest release first, where
it might be fixed, or the patch might simply need to be rebased.
Also, this fix is expedient and probably a better fix is appropriate.

Avoid sendfile code when sendfile doesn't exist.

--- src/zm_event.cpp.orig	2023-02-23 21:44:01.000000000 +0000
+++ src/zm_event.cpp
@@ -113,10 +113,10 @@ Event::Event(
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
@@ -164,8 +164,8 @@ Event::~Event() {
   // Should not be static because we might be multi-threaded
   char sql[ZM_SQL_LGE_BUFSIZ];
   snprintf(sql, sizeof(sql),
-      "UPDATE Events SET Name='%s%" PRIu64 "', EndDateTime = from_unixtime(%ld), Length = %s%ld.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d WHERE Id = %" PRIu64 " AND Name='New Event'",
-      monitor->EventPrefix(), id, end_time.tv_sec,
+      "UPDATE Events SET Name='%s%" PRIu64 "', EndDateTime = from_unixtime(%jd), Length = %s%ld.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d WHERE Id = %" PRIu64 " AND Name='New Event'",
+      monitor->EventPrefix(), id, (intmax_t) end_time.tv_sec,
       delta_time.positive?"":"-", delta_time.sec, delta_time.fsec,
       frames, alarm_frames,
       tot_score, (int)(alarm_frames?(tot_score/alarm_frames):0), max_score,
@@ -373,12 +373,12 @@ void Event::WriteDbFrames() {
   while (frame_data.size()) {
     Frame *frame = frame_data.front();
     frame_data.pop();
-    frame_insert_sql += stringtf("\n( %" PRIu64 ", %d, '%s', from_unixtime( %ld ), %s%ld.%02ld, %d ),",
+    frame_insert_sql += stringtf("\n( %" PRIu64 ", %d, '%s', from_unixtime( %jd ), %s%jd.%02ld, %d ),",
         id, frame->frame_id,
         frame_type_names[frame->type],
-        frame->timestamp.tv_sec,
+        (intmax_t) frame->timestamp.tv_sec,
         frame->delta.positive ? "" : "-",
-        frame->delta.sec,
+        (intmax_t) frame->delta.sec,
         frame->delta.fsec,
         frame->score);
     if (config.record_event_stats and frame->zone_stats.size()) {
@@ -526,9 +526,9 @@ void Event::AddFrame(const std::shared_p
 
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
