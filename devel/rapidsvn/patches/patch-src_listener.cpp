$NetBSD: patch-src_listener.cpp,v 1.1 2016/07/16 03:32:32 markd Exp $

Dont do things the old 2.6 way

--- src/listener.cpp.orig	2012-06-28 06:39:35.000000000 +0000
+++ src/listener.cpp
@@ -167,7 +167,7 @@ public:
     wxMutexLocker lock(mutex);
     wxString localCertFile = wxFileSelector(
                                _("Select Certificate File"), wxT(""), wxT(""), wxT(""),
-                               wxT("*.*"), wxOPEN | wxFILE_MUST_EXIST, parent);
+                               wxT("*.*"), wxFD_OPEN | wxFD_FILE_MUST_EXIST, parent);
     LocalToUtf8(localCertFile, certFile);
 
     dataReceived = !localCertFile.empty();
