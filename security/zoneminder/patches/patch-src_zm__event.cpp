$NetBSD: patch-src_zm__event.cpp,v 1.3 2020/08/25 16:42:21 gdt Exp $

zoneminder uses %ld for time_t, which is troublesome on NetBSD arm and
presumably i386.  (Note that there are multiple patch files for the
same issue.)

Not yet sent upstream -- needs update to latest release first, where
it might be fixed, or the patch might simply need to be rebased.
Also, this fix is expedient and probably a better fix is appropriate.

Avoid sendfile code when sendfile doesn't exist.

--- src/zm_event.cpp.orig	2016-02-03 18:40:30.000000000 +0000
+++ src/zm_event.cpp
@@ -36,11 +36,13 @@
 #include "zm_event.h"
 #include "zm_monitor.h"
 
+#if HAVE_SENDFILE
 // sendfile tricks
 extern "C"
 {
 #include "zm_sendfile.h"
 }
+#endif
 
 #include "zmf.h"
 
@@ -80,7 +82,7 @@ Event::Event( Monitor *p_monitor, struct
     static char sql[ZM_SQL_MED_BUFSIZ];
 
     struct tm *stime = localtime( &start_time.tv_sec );
-    snprintf( sql, sizeof(sql), "insert into Events ( MonitorId, Name, StartTime, Width, Height, Cause, Notes ) values ( %d, 'New Event', from_unixtime( %ld ), %d, %d, '%s', '%s' )", monitor->Id(), start_time.tv_sec, monitor->Width(), monitor->Height(), cause.c_str(), notes.c_str() );
+    snprintf( sql, sizeof(sql), "insert into Events ( MonitorId, Name, StartTime, Width, Height, Cause, Notes ) values ( %d, 'New Event', from_unixtime( %jd ), %d, %d, '%s', '%s' )", monitor->Id(), (intmax_t) start_time.tv_sec, monitor->Width(), monitor->Height(), cause.c_str(), notes.c_str() );
     if ( mysql_query( &dbconn, sql ) )
     {
         Error( "Can't insert event: %s", mysql_error( &dbconn ) );
@@ -178,7 +180,7 @@ Event::~Event()
 
         Debug( 1, "Adding closing frame %d to DB", frames );
         static char sql[ZM_SQL_SML_BUFSIZ];
-        snprintf( sql, sizeof(sql), "insert into Frames ( EventId, FrameId, TimeStamp, Delta ) values ( %d, %d, from_unixtime( %ld ), %s%ld.%02ld )", id, frames, end_time.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec );
+        snprintf( sql, sizeof(sql), "insert into Frames ( EventId, FrameId, TimeStamp, Delta ) values ( %d, %d, from_unixtime( %jd ), %s%ld.%02ld )", id, frames, (intmax_t) end_time.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec );
         if ( mysql_query( &dbconn, sql ) )
         {
             Error( "Can't insert frame: %s", mysql_error( &dbconn ) );
@@ -191,7 +193,7 @@ Event::~Event()
     struct DeltaTimeval delta_time;
     DELTA_TIMEVAL( delta_time, end_time, start_time, DT_PREC_2 );
 
-    snprintf( sql, sizeof(sql), "update Events set Name='%s%d', EndTime = from_unixtime( %ld ), Length = %s%ld.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d where Id = %d", monitor->EventPrefix(), id, end_time.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec, frames, alarm_frames, tot_score, (int)(alarm_frames?(tot_score/alarm_frames):0), max_score, id );
+    snprintf( sql, sizeof(sql), "update Events set Name='%s%d', EndTime = from_unixtime( %jd ), Length = %s%ld.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d where Id = %d", monitor->EventPrefix(), id, (intmax_t) end_time.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec, frames, alarm_frames, tot_score, (int)(alarm_frames?(tot_score/alarm_frames):0), max_score, id );
     if ( mysql_query( &dbconn, sql ) )
     {
         Error( "Can't update event: %s", mysql_error( &dbconn ) );
@@ -522,7 +524,7 @@ void Event::AddFramesInternal( int n_fra
         DELTA_TIMEVAL( delta_time, *(timestamps[i]), start_time, DT_PREC_2 );
 
         int sql_len = strlen(sql);
-        snprintf( sql+sql_len, sizeof(sql)-sql_len, "( %d, %d, from_unixtime(%ld), %s%ld.%02ld ), ", id, frames, timestamps[i]->tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec );
+        snprintf( sql+sql_len, sizeof(sql)-sql_len, "( %d, %d, from_unixtime( %jd ), %s%ld.%02ld ), ", id, frames, (intmax_t) timestamps[i]->tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec );
 
         frameCount++;
     }
@@ -573,7 +575,7 @@ void Event::AddFrame( Image *image, stru
 
         Debug( 1, "Adding frame %d of type \"%s\" to DB", frames, frame_type );
         static char sql[ZM_SQL_MED_BUFSIZ];
-        snprintf( sql, sizeof(sql), "insert into Frames ( EventId, FrameId, Type, TimeStamp, Delta, Score ) values ( %d, %d, '%s', from_unixtime( %ld ), %s%ld.%02ld, %d )", id, frames, frame_type, timestamp.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec, score );
+        snprintf( sql, sizeof(sql), "insert into Frames ( EventId, FrameId, Type, TimeStamp, Delta, Score ) values ( %d, %d, '%s', from_unixtime( %jd ), %s%ld.%02ld, %d )", id, frames, frame_type, (intmax_t) timestamp.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec, score );
         if ( mysql_query( &dbconn, sql ) )
         {
             Error( "Can't insert frame: %s", mysql_error( &dbconn ) );
@@ -661,7 +663,7 @@ bool EventStream::loadInitialEventData( 
 {
     static char sql[ZM_SQL_SML_BUFSIZ];
 
-    snprintf( sql, sizeof(sql), "select Id from Events where MonitorId = %d and unix_timestamp( EndTime ) > %ld order by Id asc limit 1", monitor_id, event_time );
+    snprintf( sql, sizeof(sql), "select Id from Events where MonitorId = %d and unix_timestamp( EndTime ) > %jd order by Id asc limit 1", monitor_id, (intmax_t) event_time );
 
     if ( mysql_query( &dbconn, sql ) )
     {
@@ -1219,7 +1221,9 @@ bool EventStream::sendFrame( int delta_u
     Debug( 2, "Sending frame %d", curr_frame_id );
 
     static char filepath[PATH_MAX];
+#if HAVE_SENDFILE
     static struct stat filestat;
+#endif
     FILE *fdj = NULL;
     
     snprintf( filepath, sizeof(filepath), Event::capture_file_format, event_data->path, curr_frame_id );
