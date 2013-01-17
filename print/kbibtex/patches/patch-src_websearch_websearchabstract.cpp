$NetBSD: patch-src_websearch_websearchabstract.cpp,v 1.1 2013/01/17 16:02:17 joerg Exp $

--- src/websearch/websearchabstract.cpp.orig	2013-01-16 13:07:38.000000000 +0000
+++ src/websearch/websearchabstract.cpp
@@ -66,7 +66,7 @@ const int WebSearchAbstract::resultUnspe
 const char* WebSearchAbstract::httpUnsafeChars = "%:/=+$?&\0";
 
 
-HTTPEquivCookieJar::HTTPEquivCookieJar(QNetworkAccessManager *parent = NULL)
+HTTPEquivCookieJar::HTTPEquivCookieJar(QNetworkAccessManager *parent)
         : QNetworkCookieJar(parent), m_nam(parent)
 {
     // nothing
