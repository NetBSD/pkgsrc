$NetBSD: patch-src_MihScannerTracert.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/MihScannerTracert.cc.orig	2020-03-27 18:19:54.666910839 +0000
+++ src/MihScannerTracert.cc
@@ -83,7 +83,7 @@ MihScannerTracert::trace () {
     missing = (nbr_replies_received == 0) ? (missing + 1) : 0;
 
     if (missing > opts->max_missing) {
-      log(INFO, "Too many down hops -> stop algo");
+      mylog(INFO, "Too many down hops -> stop algo");
       //pthread_mutex_unlock(&lock);
       stop_algo = true;
     }
@@ -147,6 +147,6 @@ MihScannerTracert::trace () {
 
 uint8
 MihScannerTracert::getNbrReplies(uint8 ttl) {
-  log(WARN, "TODO");
+  mylog(WARN, "TODO");
   return 0;
 }
