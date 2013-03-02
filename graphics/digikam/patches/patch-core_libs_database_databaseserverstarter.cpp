$NetBSD: patch-core_libs_database_databaseserverstarter.cpp,v 1.1 2013/03/02 18:10:03 joerg Exp $

--- core/libs/database/databaseserverstarter.cpp.orig	2013-02-28 09:52:35.000000000 +0000
+++ core/libs/database/databaseserverstarter.cpp
@@ -82,7 +82,7 @@ public:
     }
 };
 
-DatabaseServerStarter::DatabaseServerStarter(QObject* parent=0)
+DatabaseServerStarter::DatabaseServerStarter(QObject* parent)
     : QObject(parent)
 {
 }
