$NetBSD: patch-sources_genesplicer.cpp,v 1.1 2012/11/16 00:31:35 joerg Exp $

--- sources/genesplicer.cpp.orig	2012-11-15 13:01:00.000000000 +0000
+++ sources/genesplicer.cpp
@@ -54,7 +54,7 @@ FILE *  File_Open  (const char *, const 
 void LoadData(FILE *,char *);
 void  Process_Options  (int, char * []);
 
-
+int
 main  (int argc, char * argv [])
 {
   FILE  * fp, *ofp;
