$NetBSD: patch-src_PackByPackTracert.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/PackByPackTracert.cc.orig	2020-03-27 18:20:01.586393366 +0000
+++ src/PackByPackTracert.cc
@@ -16,7 +16,7 @@
 
 PackByPackTracert::PackByPackTracert (Options* opts) : TracertImpl(opts){
   // Initialisation
-  log(INFO, "PackByPack algo");
+  mylog(INFO, "PackByPack algo");
 }
 
 PackByPackTracert::~PackByPackTracert () {
@@ -94,7 +94,7 @@ PackByPackTracert::trace (char* target, 
       missing = 0;
     
     if (missing > opts->max_missing) {
-      log(INFO, "Too many down hops -> stop algo");
+      mylog(INFO, "Too many down hops -> stop algo");
       //pthread_mutex_unlock(&lock);
       stop_algo = true;
     }
@@ -116,6 +116,6 @@ PackByPackTracert::trace (char* target, 
 
 uint8
 PackByPackTracert::getNbrReplies(uint8 ttl) {
-  log(WARN, "TODO");
+  mylog(WARN, "TODO");
   return 0;
 }
