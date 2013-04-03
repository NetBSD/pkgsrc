$NetBSD: patch-server_src_nepomuk_queryserviceclient.h,v 1.2 2013/04/03 07:37:12 markd Exp $

Workaround for gcc4.[12]  https://bugs.kde.org/show_bug.cgi?id=295813

--- server/src/nepomuk/queryserviceclient.h.orig	2013-03-02 11:51:18.000000000 +0000
+++ server/src/nepomuk/queryserviceclient.h
@@ -23,6 +23,7 @@
 
 #include <QtCore/QObject>
 #include <QtCore/QHash>
+typedef QHash<QString, QString> hss;
 
 class QUrl;
 
@@ -82,7 +83,7 @@ namespace Nepomuk {
              *
              * \sa QueryParser
              */
-            bool query(const QString& query, const QHash<QString, QString> &encodedRps = ( QHash<QString, QString>() ) );
+            bool query(const QString& query, const hss &encodedRps = ( hss() ) );
 
             /**
              * Start a query using the Nepomuk query service.
@@ -102,7 +103,7 @@ namespace Nepomuk {
              *
              * \sa query(const QString&), close()
              */
-            bool blockingQuery( const QString& query, const QHash<QString, QString> &encodedRps = ( QHash<QString, QString>() ) );
+            bool blockingQuery( const QString& query, const hss &encodedRps = ( hss() ) );
 
             /**
              * Close the client, thus stop to monitor the query
