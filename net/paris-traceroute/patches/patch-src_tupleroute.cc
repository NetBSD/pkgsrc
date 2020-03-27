$NetBSD: patch-src_tupleroute.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/tupleroute.cc.orig	2020-03-27 18:20:38.643120847 +0000
+++ src/tupleroute.cc
@@ -20,7 +20,7 @@ int main (int argc, char** argv) {
   
   // Check CAP_NET_RAW capabilities
   if (getuid() != 0) {
-    //log(FATAL, "You must be root to run this program");
+    //mylog(FATAL, "You must be root to run this program");
     //exit(-1);
   }
 
@@ -45,7 +45,7 @@ int main (int argc, char** argv) {
     algo = CONCURRENT_TRACERT;
   } else if (strncmp(opts->algo, "scout", strlen(opts->algo)) == 0) {
     if (strncmp(opts->protocol, "udp", 5) != 0) {
-      log(INFO, "Scout algo is only usable with udp => hopbyhopalgo");
+      mylog(INFO, "Scout algo is only usable with udp => hopbyhopalgo");
       algo = HOPBYHOP_TRACERT;
     } else algo = SCOUT_TRACERT;
   } else if (strncmp(opts->algo, "exhaustive", strlen(opts->algo)) == 0) {
@@ -54,7 +54,7 @@ int main (int argc, char** argv) {
     strcpy(opts->algo, "null");
     // warn user.
     // maybe he made a mistake when typing the so-long-algo-names !
-    log(WARN, "Unknown algo (--algo=help for more help)");
+    mylog(WARN, "Unknown algo (--algo=help for more help)");
   }
 
   // Create algo structures
@@ -103,12 +103,12 @@ int main (int argc, char** argv) {
       // Execute concurrent traceroute
       int reply_ttl = traceroute->getHopInfo(0, 0)->reply_ttl;
       int ttl_dest  = opts->ttl_max - reply_ttl + 1;
-      log(INFO, "ttl of the destination is %d", ttl_dest);
+      mylog(INFO, "ttl of the destination is %d", ttl_dest);
       delete traceroute;
       traceroute = new ConcurrentTracert(opts, ttl_dest);
     } else {
       // Execute hop-by-hop traceroute
-      log(INFO, "Concurrent algo is not usable => use hopbyhop algo");
+      mylog(INFO, "Concurrent algo is not usable => use hopbyhop algo");
       delete traceroute;
       traceroute = new HopByHopTracert(opts);
     }
@@ -125,17 +125,17 @@ int main (int argc, char** argv) {
   //else
   //  printf("Output disabled for ExhaustiveTracert\n");
   
-  log(INFO, "output done");
+  mylog(INFO, "output done");
   
   // Free ressources
   delete icmp_server;
-  log(INFO, "deleted icmp_server");
+  mylog(INFO, "deleted icmp_server");
   if (tcp_server != NULL) delete tcp_server;
   delete traceroute;
-  log(INFO, "deleted traceroute");
+  mylog(INFO, "deleted traceroute");
   delete opts;
 
-  log(INFO, "exiting...");
+  mylog(INFO, "exiting...");
   
   return 0;
 }
