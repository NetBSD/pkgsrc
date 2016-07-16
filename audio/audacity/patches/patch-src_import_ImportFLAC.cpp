$NetBSD: patch-src_import_ImportFLAC.cpp,v 1.1 2016/07/16 01:32:51 markd Exp $

gcc6 fix

--- src/import/ImportFLAC.cpp.orig	2016-01-13 14:31:24.000000000 +0000
+++ src/import/ImportFLAC.cpp
@@ -296,7 +296,7 @@ ImportFileHandle *FLACImportPlugin::Open
    int cnt;
    wxFile binaryFile;
    if (!binaryFile.Open(filename)) {
-      return false; // File not found
+      return NULL; // File not found
    }
 
 #ifdef USE_LIBID3TAG
@@ -313,7 +313,7 @@ ImportFileHandle *FLACImportPlugin::Open
 
    if (cnt == wxInvalidOffset || strncmp(buf, FLAC_HEADER, 4) != 0) {
       // File is not a FLAC file
-      return false;
+      return NULL;
    }
 
    // Open the file for import
