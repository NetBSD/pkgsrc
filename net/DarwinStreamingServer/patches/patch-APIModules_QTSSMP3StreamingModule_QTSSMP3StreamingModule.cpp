$NetBSD: patch-APIModules_QTSSMP3StreamingModule_QTSSMP3StreamingModule.cpp,v 1.1 2013/03/24 16:51:07 joerg Exp $

--- APIModules/QTSSMP3StreamingModule/QTSSMP3StreamingModule.cpp.orig	2004-12-01 13:05:34.000000000 +0000
+++ APIModules/QTSSMP3StreamingModule/QTSSMP3StreamingModule.cpp
@@ -1172,7 +1172,7 @@ MP3SessionRefKey::MP3SessionRefKey(MP3Se
     {
         fMP3Session = fKeyValue->GetMP3Session();
         if (fMP3Session != NULL)
-            fHashValue = (SInt32)fMP3Session->GetSession();
+            fHashValue = (SInt32)(intptr_t)fMP3Session->GetSession();
     }
     else
     {
@@ -1182,7 +1182,7 @@ MP3SessionRefKey::MP3SessionRefKey(MP3Se
 
 MP3SessionRefKey::MP3SessionRefKey(QTSS_RTSPSessionObject rtspSessRef) : 
     fKeyValue(NULL),
-    fHashValue((SInt32)rtspSessRef),
+    fHashValue((SInt32)(intptr_t)rtspSessRef),
     fMP3Session(NULL)
 {
 }
