$NetBSD: patch-src_network_nNetObject.cpp,v 1.1 2016/12/15 23:52:43 joerg Exp $

Pointers don't order with 0, check for non-NULL instead.

--- src/network/nNetObject.cpp.orig	2016-12-15 17:38:01.972071566 +0000
+++ src/network/nNetObject.cpp
@@ -1530,7 +1530,7 @@ void nNetObject::SyncAll(){
             // con << sn_SyncRequestedObject.Len() << "/" << sn_netObjects.Len() << "\n";
 
             int currentSync = sn_SyncRequestedObject.Len()-1;
-            while(sn_Connections[user].socket>0 &&
+            while(sn_Connections[user].socket &&
                     sn_Connections[user].bandwidthControl_.CanSend() &&
                     sn_Connections[user].ackPending<sn_maxNoAck &&
                     currentSync >= 0){
