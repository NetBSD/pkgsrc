$NetBSD: patch-src_zm__eventstream.cpp,v 1.1 2024/12/01 13:49:48 gdt Exp $

Only include local sendfile header if there is sendfile support, to
avoid #error for no sendfile implementation.

--- src/zm_eventstream.cpp.orig	2023-02-23 21:44:01.000000000 +0000
+++ src/zm_eventstream.cpp
@@ -43,8 +43,8 @@ const std::string EventStream::StreamMod
 
 bool EventStream::loadInitialEventData(int monitor_id, time_t event_time) {
   std::string sql = stringtf("SELECT `Id` FROM `Events` WHERE "
-                             "`MonitorId` = %d AND unix_timestamp(`EndDateTime`) > %ld "
-                             "ORDER BY `Id` ASC LIMIT 1", monitor_id, event_time);
+                             "`MonitorId` = %d AND unix_timestamp(`EndDateTime`) > %jd "
+                             "ORDER BY `Id` ASC LIMIT 1", monitor_id, (intmax_t) event_time);
 
   MYSQL_RES *result = zmDbFetch(sql.c_str());
   if (!result)
