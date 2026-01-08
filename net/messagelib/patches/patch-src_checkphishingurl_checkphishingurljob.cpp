$NetBSD: patch-src_checkphishingurl_checkphishingurljob.cpp,v 1.1 2026/01/08 18:51:35 markd Exp $

Don't unconditionally ignore SSL errors from Google's phishing API
CVE-2025-69412
https://invent.kde.org/pim/messagelib/-/commit/df525dc91498423f3c45e143efab1c7102776652

--- webengineviewer/src/checkphishingurl/checkphishingurljob.cpp.orig	2025-10-27 12:55:28.000000000 +0000
+++ webengineviewer/src/checkphishingurl/checkphishingurljob.cpp
@@ -37,17 +37,10 @@ CheckPhishingUrlJob::CheckPhishingUrlJob
     d->mNetworkAccessManager->enableStrictTransportSecurityStore(true);
 
     connect(d->mNetworkAccessManager, &QNetworkAccessManager::finished, this, &CheckPhishingUrlJob::slotCheckUrlFinished);
-    connect(d->mNetworkAccessManager, &QNetworkAccessManager::sslErrors, this, &CheckPhishingUrlJob::slotSslErrors);
 }
 
 CheckPhishingUrlJob::~CheckPhishingUrlJob() = default;
 
-void CheckPhishingUrlJob::slotSslErrors(QNetworkReply *reply, const QList<QSslError> &error)
-{
-    qCDebug(WEBENGINEVIEWER_LOG) << " void CheckPhishingUrlJob::slotSslErrors(QNetworkReply *reply, const QList<QSslError> &error)" << error.count();
-    reply->ignoreSslErrors(error);
-}
-
 void CheckPhishingUrlJob::parse(const QByteArray &replyStr)
 {
     QJsonDocument document = QJsonDocument::fromJson(replyStr);
