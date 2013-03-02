$NetBSD: patch-core_databaseserver_databaseserver.cpp,v 1.1 2013/03/02 18:10:03 joerg Exp $

--- core/databaseserver/databaseserver.cpp.orig	2013-02-28 09:57:38.000000000 +0000
+++ core/databaseserver/databaseserver.cpp
@@ -73,7 +73,7 @@ public:
     PollThread*       pollThread;
 };
 
-DatabaseServer::DatabaseServer(QCoreApplication* application=0)
+DatabaseServer::DatabaseServer(QCoreApplication* application)
     : QObject(application), d(new DatabaseServerPriv)
 {
     d->app = application;
