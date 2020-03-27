$NetBSD: patch-src_HopByHopTracert.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/HopByHopTracert.cc.orig	2020-03-27 18:19:29.074226888 +0000
+++ src/HopByHopTracert.cc
@@ -104,7 +104,7 @@ HopByHopTracert::trace (char* target, in
     missing = (nbr_replies_received == 0) ? (missing + 1) : 0;
 
     if (missing >= opts->max_missing) {
-      log(INFO, "Too many down hops -> stop algo");
+      mylog(INFO, "Too many down hops -> stop algo");
       //pthread_mutex_unlock(&lock);
       stop_algo = true;
     }
@@ -126,6 +126,6 @@ HopByHopTracert::trace (char* target, in
 
 uint8
 HopByHopTracert::getNbrReplies(uint8 ttl) {
-  log(WARN, "TODO");
+  mylog(WARN, "TODO");
   return 0;
 }
