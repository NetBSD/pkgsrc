$NetBSD: patch-kpimidentities_identity.cpp,v 1.1 2014/02/01 01:54:59 markd Exp $

While still using old (4.4) kmail don't expect akonadi id's for folders.

--- kpimidentities/identity.cpp.orig	2013-08-28 17:06:13.909954162 +0000
+++ kpimidentities/identity.cpp
@@ -674,16 +674,16 @@ bool Identity::matchesEmailAddress( cons
 
 QString Identity::verifyAkonadiId(const QString& str) const
 {
-  if(str.isEmpty())
+//  if(str.isEmpty())
     return str;
-  bool ok = false;
-  const qlonglong val = str.toLongLong(&ok);
-  Q_UNUSED(val);
-  if(ok) {
-    return str;
-  } else {
-    return QString();
-  }
+//  bool ok = false;
+//  const qlonglong val = str.toLongLong(&ok);
+//  Q_UNUSED(val);
+//  if(ok) {
+//    return str;
+//  } else {
+//    return QString();
+//  }
 }
 
 void Identity::setAutocorrectionLanguage(const QString& language)
