$NetBSD: patch-src_paris-traceroute.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/paris-traceroute.cc.orig	2020-03-27 18:20:36.333264404 +0000
+++ src/paris-traceroute.cc
@@ -21,7 +21,7 @@ int main (int argc, char** argv) {
 
   // Check CAP_NET_RAW capabilities
   if (getuid() != 0) {
-    //log(FATAL, "You must be root to run this program");
+    //mylog(FATAL, "You must be root to run this program");
     //exit(-1);
   }
   
@@ -53,7 +53,7 @@ int main (int argc, char** argv) {
     algo = CONCURRENT_TRACERT;
   } else if (strncmp(opts->algo, "scout", strlen(opts->algo)) == 0) {
     if (strncmp(opts->protocol, "udp", 5) != 0) {
-      log(WARN, "Scout algo is only usable with udp => hopbyhopalgo");
+      mylog(WARN, "Scout algo is only usable with udp => hopbyhopalgo");
       algo = HOPBYHOP_TRACERT;
     } else { 
     	algo = SCOUT_TRACERT;
@@ -69,7 +69,7 @@ int main (int argc, char** argv) {
     strcpy(opts->algo, "null");
     // warn user.
     // maybe he made a mistake when typing the so-long-algo-names !
-    log(WARN, "Unknown algo (--algo=help for more help)");
+    mylog(WARN, "Unknown algo (--algo=help for more help)");
   }
 
 	opts->algo_id = algo;
@@ -79,7 +79,7 @@ int main (int argc, char** argv) {
 		FILE *targets = NULL;
 		if (opts->targets[0] != 0x00) {
 			if ((targets = fopen(opts->targets, "r")) == NULL) {
-				log(FATAL, "can't open file\n");
+				mylog(FATAL, "can't open file\n");
 			}
 		}
 		
@@ -172,12 +172,12 @@ int main (int argc, char** argv) {
 	      // Execute concurrent traceroute
 	      int reply_ttl = traceroute->getHopInfo(0, 0)->reply_ttl;
 	      int ttl_dest  = opts->ttl_max - reply_ttl + 1;
-	      log(WARN, "ttl of the destination is %d (%d)", ttl_dest, reply_ttl);
+	      mylog(WARN, "ttl of the destination is %d (%d)", ttl_dest, reply_ttl);
 	      delete traceroute;
 	      traceroute = new ConcurrentTracert(opts, ttl_dest);
 	    } else {
 	      // Execute hop-by-hop traceroute
-	      log(INFO, "Concurrent algo is not usable => use hopbyhop algo");
+	      mylog(INFO, "Concurrent algo is not usable => use hopbyhop algo");
 	      delete traceroute;
 	      traceroute = new HopByHopTracert(opts);
 	    }
