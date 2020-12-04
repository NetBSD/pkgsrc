$NetBSD: patch-src_backend_managers_clanguagemgr.h,v 1.1 2020/12/04 12:17:58 nros Exp $

* remove deprecation warning
 taken from upstream https://github.com/bibletime/bibletime/commit/72adbba869a14be47967d7e5d877d0e7c49f0375

--- src/backend/managers/clanguagemgr.h.orig	2020-08-02 18:32:25.000000000 +0000
+++ src/backend/managers/clanguagemgr.h
@@ -163,7 +163,7 @@ class CLanguageMgr {
     private:
         void init();
         inline const QStringList makeStringList(const QString& abbrevs) {
-            return abbrevs.split( ";", QString::KeepEmptyParts, Qt::CaseSensitive );
+            return abbrevs.split( ";", Qt::KeepEmptyParts, Qt::CaseSensitive );
         }
 
         Language m_defaultLanguage;
