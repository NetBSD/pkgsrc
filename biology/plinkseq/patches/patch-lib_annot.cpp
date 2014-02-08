$NetBSD: patch-lib_annot.cpp,v 1.1 2014/02/08 12:27:14 wiedi Exp $

rename to avoid collision on sunos
--- lib/annot.cpp.orig	2012-03-19 20:00:45.000000000 +0000
+++ lib/annot.cpp
@@ -34,7 +34,7 @@ std::map<seq_annot_t,std::string> popula
   m[SPLICE3]  = "splice3";
   m[ESPLICE3] = "esplice3";
   m[ESPLICE5] = "esplice5"; 
-  m[FS]       = "frameshift";
+  m[FS_]      = "frameshift";
   m[RT]       = "readthrough";
   return m;
 }
