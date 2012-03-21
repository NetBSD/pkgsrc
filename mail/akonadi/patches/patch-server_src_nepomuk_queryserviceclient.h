$NetBSD: patch-server_src_nepomuk_queryserviceclient.h,v 1.1 2012/03/21 23:26:40 markd Exp $

Workaround for gcc4.[12]  https://bugs.kde.org/show_bug.cgi?id=295813

--- server/src/nepomuk/queryserviceclient.h.orig	2012-01-23 16:33:32.000000000 +0000
+++ server/src/nepomuk/queryserviceclient.h
@@ -21,6 +21,7 @@
 
 #include <QtCore/QObject>
 #include <QtCore/QHash>
+typedef QHash<QString, QString> hss;
 
 class QUrl;
 
@@ -78,7 +79,7 @@ namespace Nepomuk {
              *
              * \sa QueryParser
              */
-            bool query( const QString& query, const QHash<QString, QString> &encodedRps = QHash<QString, QString>() );
+            bool query( const QString& query, const hss &encodedRps = hss() );
 
             /**
              * Start a query using the Nepomuk user query language.
@@ -96,7 +97,7 @@ namespace Nepomuk {
              * 
              * \sa query(const QString&), close()
              */
-            bool blockingQuery( const QString& query, const QHash<QString, QString> &encodedRps = QHash<QString, QString>() );
+            bool blockingQuery( const QString& query, const hss &encodedRps = hss() );
 
             /**
              * Close the client, thus stop to monitor the query
