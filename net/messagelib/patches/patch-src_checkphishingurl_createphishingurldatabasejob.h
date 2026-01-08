$NetBSD: patch-src_checkphishingurl_createphishingurldatabasejob.h,v 1.1 2026/01/08 18:51:35 markd Exp $

Don't unconditionally ignore SSL errors from Google's phishing API
CVE-2025-69412
https://invent.kde.org/pim/messagelib/-/commit/df525dc91498423f3c45e143efab1c7102776652

--- webengineviewer/src/checkphishingurl/createphishingurldatabasejob.h.orig	2025-10-27 12:55:28.000000000 +0000
+++ webengineviewer/src/checkphishingurl/createphishingurldatabasejob.h
@@ -63,7 +63,6 @@ Q_SIGNALS:
 
 private:
     WEBENGINEVIEWER_NO_EXPORT void slotDownloadDataBaseFinished(QNetworkReply *reply);
-    WEBENGINEVIEWER_NO_EXPORT void slotSslErrors(QNetworkReply *reply, const QList<QSslError> &error);
     WEBENGINEVIEWER_NO_EXPORT void slotError(QNetworkReply::NetworkError error);
 
     std::unique_ptr<CreatePhishingUrlDataBaseJobPrivate> const d;
