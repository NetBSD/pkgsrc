$NetBSD: patch-pdns__recursor.cc,v 1.1 2012/02/28 10:49:29 roy Exp $

Cast to int so we use the correct overload.

--- pdns_recursor.cc.orig	2010-09-21 16:22:09.000000000 +0000
+++ pdns_recursor.cc
@@ -1065,7 +1065,7 @@ void doStats(void)
     
     time_t now = time(0);
     if(lastOutputTime && lastQueryCount && now != lastOutputTime) {
-      L<<Logger::Warning<<"stats: "<< (SyncRes::s_queries - lastQueryCount) / (now - lastOutputTime) <<" qps (average over "<< (now - lastOutputTime) << " seconds)"<<endl;
+      L<<Logger::Warning<<"stats: "<< (SyncRes::s_queries - lastQueryCount) / (now - lastOutputTime) <<" qps (average over "<< (int)(now - lastOutputTime) << " seconds)"<<endl;
     }
     lastOutputTime = now;
     lastQueryCount = SyncRes::s_queries;
