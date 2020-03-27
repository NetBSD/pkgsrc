$NetBSD: patch-src_ExhaustiveTracert.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/ExhaustiveTracert.cc.orig	2020-03-27 18:19:26.755600510 +0000
+++ src/ExhaustiveTracert.cc
@@ -22,7 +22,7 @@
  * @param opts List of options
  */
 ExhaustiveTracert::ExhaustiveTracert (Options* opts, bool	per_dest) : TracertImpl(opts) {
-  log(INFO, "Exhaustive algo");
+  mylog(INFO, "Exhaustive algo");
   this->per_dest = per_dest;
 }
 
@@ -494,7 +494,7 @@ ExhaustiveTracert::trace (char* target, 
     missing = (nbr_replies_received == 0) ? (missing + 1) : 0;
 
     if (missing >= opts->max_missing) {
-      log(INFO, "Too many down hops -> stop algo");
+      mylog(INFO, "Too many down hops -> stop algo");
       //pthread_mutex_unlock(&lock);
       stop_algo = true;
     }
@@ -626,7 +626,7 @@ ExhaustiveTracert::notifyReply (Reply* r
 
   //printf("valide!\n");
   // The reply is OK, update the timed probe associated to it
-  log(INFO, "Valid reply, id=%x", reply->getID());
+  mylog(INFO, "Valid reply, id=%x", reply->getID());
   
   updateInfos(tprobe, reply);
   
@@ -638,7 +638,7 @@ ExhaustiveTracert::notifyReply (Reply* r
   if (tprobe->classif_expected_addr == 0) {
   	Interface* interf = add_interface(current_mprobes, tprobe->host_address_raw);
     //if (opts->debug)
-    //  log(WARN, "[%d] new interface : %s", ttl_current, tprobe->host_address);
+    //  mylog(WARN, "[%d] new interface : %s", ttl_current, tprobe->host_address);
   	
   	tprobe->interf = interf;
   	//printf("current_mprobes->backward_update %d\n", current_mprobes->backward_update);
@@ -666,10 +666,10 @@ ExhaustiveTracert::notifyReply (Reply* r
         //struct in_addr host_addr;
  				//host_addr.s_addr         = tprobe->classif_expected_addr;
  				//char* host_address     = inet_ntoa(host_addr);
-        log(WARN, "[%d] %s NOT per-flow, expected %s", ttl_current, tprobe->host_address, Util::my_inet_ntoa(tprobe->classif_expected_addr));
+        mylog(WARN, "[%d] %s NOT per-flow, expected %s", ttl_current, tprobe->host_address, Util::my_inet_ntoa(tprobe->classif_expected_addr));
   		}
   	}/* else {
-  		log(WARN, "[%d] %s per-flow, expected %s", ttl_current, tprobe->host_address, my_inet_ntoa(tprobe->classif_expected_addr));
+  		mylog(WARN, "[%d] %s per-flow, expected %s", ttl_current, tprobe->host_address, my_inet_ntoa(tprobe->classif_expected_addr));
   	}*/
   }
   
