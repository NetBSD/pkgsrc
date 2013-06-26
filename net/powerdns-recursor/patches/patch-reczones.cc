$NetBSD: patch-reczones.cc,v 1.1 2013/06/26 15:52:22 joerg Exp $

--- reczones.cc.orig	2010-09-21 16:22:09.000000000 +0000
+++ reczones.cc
@@ -343,7 +343,7 @@ SyncRes::domainmap_t* parseAuthAndForwar
       throw AhuException("Error opening forward-zones-file '"+::arg()["forward-zones-file"]+"': "+stringerror());
     }
 
-    shared_ptr<FILE> fp=shared_ptr<FILE>(rfp, fclose);
+    boost::shared_ptr<FILE> fp=boost::shared_ptr<FILE>(rfp, fclose);
     
     string line;
     int linenum=0;
