$NetBSD: patch-server_src_nepomuk_queryserviceclient.cpp,v 1.1 2012/03/21 23:26:40 markd Exp $

Workaround for gcc4.[12]  https://bugs.kde.org/show_bug.cgi?id=295813

--- server/src/nepomuk/queryserviceclient.cpp.orig	2012-01-23 16:33:32.000000000 +0000
+++ server/src/nepomuk/queryserviceclient.cpp
@@ -150,7 +150,7 @@ Nepomuk::Query::QueryServiceClient::~Que
 }
 
 
-bool Nepomuk::Query::QueryServiceClient::query( const QString& query, const QHash<QString, QString> &encodedRps )
+bool Nepomuk::Query::QueryServiceClient::query( const QString& query, const hss &encodedRps )
 {
     close();
 
@@ -164,7 +164,7 @@ bool Nepomuk::Query::QueryServiceClient:
 }
 
 
-bool Nepomuk::Query::QueryServiceClient::blockingQuery( const QString& q, const QHash<QString, QString> &encodedRps )
+bool Nepomuk::Query::QueryServiceClient::blockingQuery( const QString& q, const hss &encodedRps )
 {
     if( query( q, encodedRps ) ) {
         QEventLoop loop;
