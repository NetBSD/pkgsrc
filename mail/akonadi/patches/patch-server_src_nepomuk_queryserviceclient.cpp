$NetBSD: patch-server_src_nepomuk_queryserviceclient.cpp,v 1.2 2013/04/03 07:37:12 markd Exp $

Workaround for gcc4.[12]  https://bugs.kde.org/show_bug.cgi?id=295813

--- server/src/nepomuk/queryserviceclient.cpp.orig	2013-03-02 11:51:18.000000000 +0000
+++ server/src/nepomuk/queryserviceclient.cpp
@@ -159,7 +159,7 @@ Nepomuk::Query::QueryServiceClient::~Que
 }
 
 
-bool Nepomuk::Query::QueryServiceClient::query( const QString& query, const QHash<QString, QString> &encodedRps )
+bool Nepomuk::Query::QueryServiceClient::query( const QString& query, const hss &encodedRps )
 {
     close();
 
@@ -181,7 +181,7 @@ bool Nepomuk::Query::QueryServiceClient:
 
 
 
-bool Nepomuk::Query::QueryServiceClient::blockingQuery( const QString& q, const QHash<QString, QString> &encodedRps )
+bool Nepomuk::Query::QueryServiceClient::blockingQuery( const QString& q, const hss &encodedRps )
 {
     if( query( q, encodedRps ) ) {
         QEventLoop loop;
