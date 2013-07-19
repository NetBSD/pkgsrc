$NetBSD: patch-packages_CLPBN_horus_HorusCli.cpp,v 1.1 2013/07/19 12:51:56 joerg Exp $

--- packages/CLPBN/horus/HorusCli.cpp.orig	2013-07-19 10:05:58.000000000 +0000
+++ packages/CLPBN/horus/HorusCli.cpp
@@ -121,7 +121,7 @@ readQueryAndEvidence (
       }
       VarId vid = Util::stringToUnsigned (arg);
       VarNode* queryVar = fg.getVarNode (vid);
-      if (queryVar == false) {
+      if (queryVar == NULL) {
         cerr << "Error: unknow variable with id " ;
         cerr << "`" << vid << "'."  << endl;
         exit (EXIT_FAILURE);
@@ -143,7 +143,7 @@ readQueryAndEvidence (
       }
       VarId vid = Util::stringToUnsigned (leftArg);
       VarNode* observedVar = fg.getVarNode (vid);
-      if (observedVar == false) {
+      if (observedVar == NULL) {
         cerr << "Error: unknow variable with id " ;
         cerr << "`" << vid << "'."  << endl;
         exit (EXIT_FAILURE);
