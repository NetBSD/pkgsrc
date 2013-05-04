$NetBSD: patch-src_pronounce.cpp,v 1.1 2013/05/04 12:59:46 joerg Exp $

--- src/pronounce.cpp.orig	2013-05-04 00:31:26.000000000 +0000
+++ src/pronounce.cpp
@@ -29,6 +29,7 @@
 #include <QtNetwork/QNetworkAccessManager>
 #include <QtNetwork/QNetworkRequest>
 #include <QtNetwork/QNetworkReply>
+#include <ctime>
 
 Pronounce::Pronounce(QObject *parent) :
     QObject(parent),
