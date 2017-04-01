$NetBSD: patch-generator_annotator.cpp,v 1.1 2017/04/01 12:38:54 adam Exp $

Fix building.

--- generator/annotator.cpp.orig	2017-04-01 12:24:27.000000000 +0000
+++ generator/annotator.cpp
@@ -194,7 +194,7 @@ std::string Annotator::htmlNameForFile(c
     }
 
     const clang::FileEntry* entry = getSourceMgr().getFileEntryForID(id);
-    if (!entry || !entry->getName())
+    if (!entry)
     {
         cache[id] = {false, {} };
         return {};
@@ -520,7 +520,7 @@ std::string Annotator::pathTo(clang::Fil
 {
   //this is a bit duplicated with the other pathTo and htmlNameForFile
 
-    if (!To || !To->getName())
+    if (!To)
         return {};
 
     std::string fromFN = htmlNameForFile(From);
