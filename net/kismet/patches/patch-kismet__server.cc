$NetBSD: patch-kismet__server.cc,v 1.1 2013/05/06 14:56:35 joerg Exp $

--- kismet_server.cc.orig	2013-05-06 07:13:15.000000000 +0000
+++ kismet_server.cc
@@ -759,7 +759,7 @@ void NetWriteInfo() {
     snprintf(tmpstr, 32, "%d", tracker.FetchNumPackets() - last_packnum);
     idata.rate = tmpstr;
 
-    if (time(0) - last_info.ts.tv_sec < decay && last_info.signal != -1)
+    if (time(0) - last_info.ts.tv_sec < ::decay && last_info.signal != -1)
         snprintf(tmpstr, 16, "%d %d" , last_info.signal, last_info.noise);
     else if (last_info.quality == -1)
         snprintf(tmpstr, 16, "-1 -1");
@@ -1543,7 +1543,7 @@ int ProcessBulkConf(ConfigFile *conf) {
     }
 
     if (conf->FetchOpt("decay") != "") {
-        if (sscanf(conf->FetchOpt("decay").c_str(), "%d", &decay) != 1) {
+        if (sscanf(conf->FetchOpt("decay").c_str(), "%d", &::decay) != 1) {
             fprintf(stderr, "FATAL:  Illegal config file value for decay.\n");
             ErrorShutdown();
         }
@@ -2237,7 +2237,7 @@ int main(int argc,char *argv[]) {
         { 0, 0, 0, 0 }
     };
     int option_index;
-    decay = 5;
+    ::decay = 5;
 
     // Catch the interrupt handler to shut down
     signal(SIGINT, CatchShutdown);
@@ -2950,7 +2950,7 @@ int main(int argc,char *argv[]) {
         timetracker.RegisterTimer(datainterval * SERVER_TIMESLICES_SEC, NULL, 1, &ExportSyncEvent, NULL);
     // Write waypoints if requested
     if (waypoint)
-        timetracker.RegisterTimer(decay * SERVER_TIMESLICES_SEC, NULL, 1, &WaypointSyncEvent, NULL);
+        timetracker.RegisterTimer(::decay * SERVER_TIMESLICES_SEC, NULL, 1, &WaypointSyncEvent, NULL);
     // Channel hop if requested
     if (channel_hop) {
         if (channel_dwell)
@@ -3175,7 +3175,7 @@ daemon_parent_cleanup:
                     num_networks = tracker.FetchNumNetworks();
 
                     if (tracker.FetchNumPackets() != num_packets) {
-                        if (cur_time - last_click >= decay && sound == 1) {
+                        if (cur_time - last_click >= ::decay && sound == 1) {
                             if (tracker.FetchNumPackets() - num_packets >
                                 tracker.FetchNumDropped() + localdropnum - num_dropped) {
                                 sound = PlaySound("traffic");
