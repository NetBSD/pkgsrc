$NetBSD: patch-pdns__recursor.cc,v 1.2 2013/06/14 22:13:03 dholland Exp $

Cast to int so we use the correct overload.
Fix C++ semantic whitespace.

Caution: this file is also SUBST'd at pre-configure time to insert
more C++ semantic whitespace around the VERSION macro. Don't roll
those changes back into the pkgsrc patch as one of them contains
an rcsid string. (sigh)

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
@@ -2017,7 +2017,7 @@ int main(int argc, char **argv) 
       exit(99);
     }
     if(::arg().mustDo("version")) {
-      cerr<<"version: "VERSION<<endl;
+      cerr<<"version: " VERSION <<endl;
       exit(99);
     }
 
