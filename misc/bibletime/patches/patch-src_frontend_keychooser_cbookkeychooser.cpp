$NetBSD: patch-src_frontend_keychooser_cbookkeychooser.cpp,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/72adbba869a14be47967d7e5d877d0e7c49f0375

--- src/frontend/keychooser/cbookkeychooser.cpp.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/frontend/keychooser/cbookkeychooser.cpp
@@ -66,7 +66,7 @@ void CBookKeyChooser::setKey(CSwordKey *
 
     QStringList siblings; // Split up key
     if (m_key && !oldKey.isEmpty())
-        siblings = oldKey.split('/', QString::SkipEmptyParts);
+        siblings = oldKey.split('/', Qt::SkipEmptyParts);
 
     int depth = 0;
 
