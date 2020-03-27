$NetBSD: patch-src_TracertImpl.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/TracertImpl.cc.orig	2007-05-31 15:34:28.000000000 +0000
+++ src/TracertImpl.cc
@@ -5,6 +5,7 @@
 #include "Reply.h"
 #include "Time.h"
 
+#include <stdint.h>
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -26,7 +27,7 @@ TracertImpl::TracertImpl () {
 TracertImpl::TracertImpl (Options* opts) {
   //printf("tracert impl 1\n");	
   //if (opts->debug)
-  //  log(WARN, "TracertImpl::TracertImpl(opts)");
+  //  mylog(WARN, "TracertImpl::TracertImpl(opts)");
   
   // Initialisation
   this->opts = opts;
@@ -45,7 +46,7 @@ TracertImpl::TracertImpl (Options* opts)
   
   ttl_current = opts->ttl_initial;
   
-  log(INFO, "HopByHop algo");
+  mylog(INFO, "HopByHop algo");
 }
 
 /**
@@ -180,7 +181,7 @@ TracertImpl::sendProbe3 (int id, int xtu
   probes_by_id[probe->getID()] = tprobe;
 
   // ... and send it
-  log(INFO, "Send probe, ttl=%d, id=%x", ttl_current, probe->getID());
+  mylog(INFO, "Send probe, ttl=%d, id=%x", ttl_current, probe->getID());
   tprobe->probe->dump();
   tprobe->send_time    = time->getCurrentTime();
   tprobe->timeout_time = tprobe->send_time + (opts->timeout * 1000);
@@ -212,7 +213,7 @@ TracertImpl::reSendProbe(TimedProbe * tp
 void
 TracertImpl::waitProbes () {
   //if (opts->debug)
-  //log(WARN, "TracertImpl::waitProbes sent=%d recv=%d", nbr_probes_sent, nbr_replies_received);
+  //mylog(WARN, "TracertImpl::waitProbes sent=%d recv=%d", nbr_probes_sent, nbr_replies_received);
 
   // Wait all replies for this TTL
   struct timeval  now;
@@ -227,7 +228,7 @@ TracertImpl::waitProbes () {
     
     if (res == ETIMEDOUT) {
       // Timeout
-      log(DUMP, "Timeout");
+      mylog(DUMP, "Timeout");
     }
   }
 }
@@ -251,12 +252,12 @@ TracertImpl::validateReply(Reply *reply,
     
     host_addr.s_addr         = reply->getSourceAddress();
     
-    log(WARN, "IP Options in this reply, from %s !", inet_ntoa(host_addr));
+    mylog(WARN, "IP Options in this reply, from %s !", inet_ntoa(host_addr));
     reply->dumpRaw();
   }
 
   if (reply->getOriginalProtocol() != opts->protocole) {
-    log(DUMP, "Bad protocol %d %d", opts->protocole, reply->getOriginalProtocol());
+    mylog(DUMP, "Bad protocol %d %d", opts->protocole, reply->getOriginalProtocol());
     
     //reply->dumpRaw();
     
@@ -265,7 +266,7 @@ TracertImpl::validateReply(Reply *reply,
 
 	if (reply->getProcId() != opts->proc_id) {
   //if (reply->getProcId() != opts->src_port) {
-    log(DUMP, "Bad ProcId : %d %d", reply->getProcId(), opts->src_port);
+    mylog(DUMP, "Bad ProcId : %d %d", reply->getProcId(), opts->src_port);
     
     return NULL;
   }
@@ -321,14 +322,14 @@ TracertImpl::validateReply(Reply *reply,
   
   int ret_flow_id = reply->getReturnFlowId();
   
-  //log(WARN, "Return Flow id : 0x%x", ret_flow_id);
+  //mylog(WARN, "Return Flow id : 0x%x", ret_flow_id);
   if (opts->return_flow_id != -1 && ret_flow_id != opts->return_flow_id) {
-  	log(WARN, "Bad return flow id 0x%x from %s", ret_flow_id, Util::my_inet_ntoa(reply->getSourceAddress()));
+  	mylog(WARN, "Bad return flow id 0x%x from %s", ret_flow_id, Util::my_inet_ntoa(reply->getSourceAddress()));
   	
   	uint32 resw = reply->getReservedWords();
   	unsigned char *p = (unsigned char *)&resw;
   	
-  	log(WARN, "ICMP reserved words %x %d %d %d %d", resw, p[3], p[2], p[1], p[0]);
+  	mylog(WARN, "ICMP reserved words %x %d %d %d %d", resw, p[3], p[2], p[1], p[0]);
   	
   	//reply->dumpRaw();
 	}
@@ -337,7 +338,7 @@ TracertImpl::validateReply(Reply *reply,
 
   // If this reply is not associated to a probe, don't handle it
   if (tprobe == NULL) {
-    log(DUMP, "Can't find the probe associated to this reply to target %s", target);
+    mylog(DUMP, "Can't find the probe associated to this reply to target %" PRIu32, target);
     //printf("ID=0x%x, initial=0x%x\n", id, id_initial);
     //reply->dumpRaw();
     return NULL;
@@ -345,7 +346,7 @@ TracertImpl::validateReply(Reply *reply,
 
   // If the reply is a duplicate, don't handle it
   if (tprobe->arrival_time != 0) {
-    log(DUMP, "Duplicated reply received");
+    mylog(DUMP, "Duplicated reply received");
     
     return NULL;
   }
@@ -353,7 +354,7 @@ TracertImpl::validateReply(Reply *reply,
   // If the reply has timed out, don't handle it
   //long arrival_time = time->getCurrentTime();
   if (arrival_time > tprobe->timeout_time) {
-    log(DUMP, "A reply received which has timed out %d", arrival_time - tprobe->timeout_time);
+    mylog(DUMP, "A reply received which has timed out %d", arrival_time - tprobe->timeout_time);
     return NULL;
   }
 
@@ -365,7 +366,7 @@ TracertImpl::validateReply(Reply *reply,
         && reply->getOriginalDestAddress() != tprobe->destination_address)
   {
   	char *dest = strdup(Util::my_inet_ntoa(tprobe->destination_address));
-    log(WARN, "A reply received with bad original destination address %s, should be %s", Util::my_inet_ntoa(reply->getOriginalDestAddress()), dest);
+    mylog(WARN, "A reply received with bad original destination address %s, should be %s", Util::my_inet_ntoa(reply->getOriginalDestAddress()), dest);
     delete dest;
     
     //return NULL;
@@ -420,13 +421,13 @@ TracertImpl::wakeup(Reply* reply) {
 
   // Check if a connection reset is required
   if (reply->resetRequired()) {
-    log(INFO, "Reset, id=%x", reply->getID());
+    mylog(INFO, "Reset, id=%x", reply->getID());
     Probe* probe = Probe::probeFactory(opts->protocol,
         opts->src_addr, opts->src_port,
         target, opts->dst_port,
         opts->ttl_max, opts->tos, 0, 0,
         reply->getResetID(), opts->return_flow_id, true);
-    log(DUMP, "Send message :");
+    mylog(DUMP, "Send message :");
     probe->dump();
     probe->send();
   }
@@ -449,7 +450,7 @@ TracertImpl::wakeup(Reply* reply) {
   // Check if all replies for this ttl have been received
   nbr_replies_received++;
   if (all_probes_sent && nbr_probes_sent == nbr_replies_received) {
-    log(INFO, "All probes have been acknowledged");
+    mylog(INFO, "All probes have been acknowledged");
     pthread_cond_signal(&cond_wait);
   }
 }
@@ -469,13 +470,13 @@ TracertImpl::notifyReply (Reply* reply, 
   }
 
   // The reply is OK, update the timed probe associated to it
-  log(DUMP, "Valid reply, id=%x", reply->getID());
+  mylog(DUMP, "Valid reply, id=%x", reply->getID());
 	//printf(".\n");
 	//printf("update\n");
   updateInfos(tprobe, reply);
   //printf("update done\n");
   if (reply->IPOptions())
-    log(WARN, "IP Options in this reply, from %s !", tprobe->host_address);
+    mylog(WARN, "IP Options in this reply, from %s !", tprobe->host_address);
   
   //printf("wakeup\n");
   wakeup(reply);
@@ -504,7 +505,7 @@ TracertImpl::getNbrProbes(uint8 ttl) {
 
 uint8
 TracertImpl::getNbrReplies(uint8 ttl) {
-  log(WARN, "TODO");
+  mylog(WARN, "TODO");
   return 0;
 }
 
