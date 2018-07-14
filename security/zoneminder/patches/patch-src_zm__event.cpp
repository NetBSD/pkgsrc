$NetBSD: patch-src_zm__event.cpp,v 1.2 2018/07/14 15:03:57 gdt Exp $

zoneminder uses %ld for time_t, which is troublesome on NetBSD mrm and
presumably i386.  (Note that there are multiple patch files for the
same issue.)

Not yet sent upstream -- needs update to latest release first, where
it might be fixed, or the patch might simply need to be rebased.
Also, this fix is expedient and probably a better fix is appropriate.

--- src/zm_event.cpp.orig	2015-02-05 02:52:37.000000000 +0000
+++ src/zm_event.cpp
@@ -74,7 +74,7 @@ Event::Event( Monitor *p_monitor, struct
     static char sql[ZM_SQL_MED_BUFSIZ];
 
     struct tm *stime = localtime( &start_time.tv_sec );
-    snprintf( sql, sizeof(sql), "insert into Events ( MonitorId, Name, StartTime, Width, Height, Cause, Notes ) values ( %d, 'New Event', from_unixtime( %ld ), %d, %d, '%s', '%s' )", monitor->Id(), start_time.tv_sec, monitor->Width(), monitor->Height(), cause.c_str(), notes.c_str() );
+    snprintf( sql, sizeof(sql), "insert into Events ( MonitorId, Name, StartTime, Width, Height, Cause, Notes ) values ( %d, 'New Event', from_unixtime( %jd ), %d, %d, '%s', '%s' )", monitor->Id(), (intmax_t) start_time.tv_sec, monitor->Width(), monitor->Height(), cause.c_str(), notes.c_str() );
     if ( mysql_query( &dbconn, sql ) )
     {
         Error( "Can't insert event: %s", mysql_error( &dbconn ) );
@@ -172,7 +172,7 @@ Event::~Event()
 
         Debug( 1, "Adding closing frame %d to DB", frames );
         static char sql[ZM_SQL_SML_BUFSIZ];
-        snprintf( sql, sizeof(sql), "insert into Frames ( EventId, FrameId, TimeStamp, Delta ) values ( %d, %d, from_unixtime( %ld ), %s%ld.%02ld )", id, frames, end_time.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec );
+        snprintf( sql, sizeof(sql), "insert into Frames ( EventId, FrameId, TimeStamp, Delta ) values ( %d, %d, from_unixtime( %jd ), %s%ld.%02ld )", id, frames, (intmax_t) end_time.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec );
         if ( mysql_query( &dbconn, sql ) )
         {
             Error( "Can't insert frame: %s", mysql_error( &dbconn ) );
@@ -185,7 +185,7 @@ Event::~Event()
     struct DeltaTimeval delta_time;
     DELTA_TIMEVAL( delta_time, end_time, start_time, DT_PREC_2 );
 
-    snprintf( sql, sizeof(sql), "update Events set Name='%s%d', EndTime = from_unixtime( %ld ), Length = %s%ld.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d where Id = %d", monitor->EventPrefix(), id, end_time.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec, frames, alarm_frames, tot_score, (int)(alarm_frames?(tot_score/alarm_frames):0), max_score, id );
+    snprintf( sql, sizeof(sql), "update Events set Name='%s%d', EndTime = from_unixtime( %jd ), Length = %s%ld.%02ld, Frames = %d, AlarmFrames = %d, TotScore = %d, AvgScore = %d, MaxScore = %d where Id = %d", monitor->EventPrefix(), id, (intmax_t) end_time.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec, frames, alarm_frames, tot_score, (int)(alarm_frames?(tot_score/alarm_frames):0), max_score, id );
     if ( mysql_query( &dbconn, sql ) )
     {
         Error( "Can't update event: %s", mysql_error( &dbconn ) );
@@ -520,7 +520,7 @@ void Event::AddFramesInternal( int n_fra
         DELTA_TIMEVAL( delta_time, *(timestamps[i]), start_time, DT_PREC_2 );
 
         int sql_len = strlen(sql);
-        snprintf( sql+sql_len, sizeof(sql)-sql_len, "( %d, %d, from_unixtime(%ld), %s%ld.%02ld ), ", id, frames, timestamps[i]->tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec );
+        snprintf( sql+sql_len, sizeof(sql)-sql_len, "( %d, %d, from_unixtime( %jd ), %s%ld.%02ld ), ", id, frames, (intmax_t) timestamps[i]->tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec );
 
         frameCount++;
     }
@@ -569,7 +569,7 @@ void Event::AddFrame( Image *image, stru
 
         Debug( 1, "Adding frame %d to DB", frames );
         static char sql[ZM_SQL_MED_BUFSIZ];
-        snprintf( sql, sizeof(sql), "insert into Frames ( EventId, FrameId, Type, TimeStamp, Delta, Score ) values ( %d, %d, '%s', from_unixtime( %ld ), %s%ld.%02ld, %d )", id, frames, frame_type, timestamp.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec, score );
+        snprintf( sql, sizeof(sql), "insert into Frames ( EventId, FrameId, Type, TimeStamp, Delta, Score ) values ( %d, %d, '%s', from_unixtime( %jd ), %s%ld.%02ld, %d )", id, frames, frame_type, (intmax_t) timestamp.tv_sec, delta_time.positive?"":"-", delta_time.sec, delta_time.fsec, score );
         if ( mysql_query( &dbconn, sql ) )
         {
             Error( "Can't insert frame: %s", mysql_error( &dbconn ) );
@@ -656,7 +656,7 @@ bool EventStream::loadInitialEventData( 
 {
     static char sql[ZM_SQL_SML_BUFSIZ];
 
-    snprintf( sql, sizeof(sql), "select Id from Events where MonitorId = %d and unix_timestamp( EndTime ) > %ld order by Id asc limit 1", monitor_id, event_time );
+    snprintf( sql, sizeof(sql), "select Id from Events where MonitorId = %d and unix_timestamp( EndTime ) > %jd order by Id asc limit 1", monitor_id, (intmax_t) event_time );
 
     if ( mysql_query( &dbconn, sql ) )
     {
