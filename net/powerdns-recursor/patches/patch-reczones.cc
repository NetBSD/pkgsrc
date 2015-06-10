$NetBSD: patch-reczones.cc,v 1.2 2015/06/10 14:22:29 fhajny Exp $

Straighten Boost namespace.

--- reczones.cc.orig	2015-04-21 13:02:57.000000000 +0000
+++ reczones.cc
@@ -378,7 +378,7 @@ SyncRes::domainmap_t* parseAuthAndForwar
       throw PDNSException("Error opening forward-zones-file '"+::arg()["forward-zones-file"]+"': "+stringerror());
     }
 
-    shared_ptr<FILE> fp=shared_ptr<FILE>(rfp, fclose);
+    boost::shared_ptr<FILE> fp=boost::shared_ptr<FILE>(rfp, fclose);
     
     string line;
     int linenum=0;
