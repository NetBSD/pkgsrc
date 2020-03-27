$NetBSD: patch-src_ExhaustiveOldTracert.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/ExhaustiveOldTracert.cc.orig	2020-03-27 18:19:24.295954828 +0000
+++ src/ExhaustiveOldTracert.cc
@@ -20,7 +20,7 @@
  * @param opts List of options
  */
 ExhaustiveOldTracert::ExhaustiveOldTracert (Options* opts, bool per_dest) : TracertImpl(opts) {
-  log(INFO, "Exhaustive algo");
+  mylog(INFO, "Exhaustive algo");
   this->per_dest = per_dest;
 }
 
@@ -467,7 +467,7 @@ ExhaustiveOldTracert::trace (char* targe
     missing = (nbr_replies_received == 0) ? (missing + 1) : 0;
 
     if (missing >= opts->max_missing) {
-      log(INFO, "Too many down hops -> stop algo");
+      mylog(INFO, "Too many down hops -> stop algo");
       //pthread_mutex_unlock(&lock);
       stop_algo = true;
     }
@@ -607,7 +607,7 @@ ExhaustiveOldTracert::notifyReply (Reply
 
   //printf("valide!\n");
   // The reply is OK, update the timed probe associated to it
-  log(INFO, "Valid reply, id=%x", reply->getID());
+  mylog(INFO, "Valid reply, id=%x", reply->getID());
   
   updateInfos(tprobe, reply);
   
