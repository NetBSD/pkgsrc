$NetBSD: patch-src_f4lm.cpp,v 1.1 2016/12/22 21:05:01 joerg Exp $

--- src/f4lm.cpp.orig	2016-12-22 14:21:37.623447732 +0000
+++ src/f4lm.cpp
@@ -1617,7 +1617,7 @@ void F4lmApp::openDocumentFile (const ch
 
   F4lmDoc * doc;
   // check, if document already open. If yes, set the focus to the first view
-  for (doc = pDocList->first (); doc > 0; doc = pDocList->next ())
+  for (doc = pDocList->first (); doc; doc = pDocList->next ())
   {
     if (doc->pathName () == file)
     {
