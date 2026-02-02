$NetBSD: patch-src_threadedjobmixin.cpp,v 1.1 2026/02/02 18:45:41 wiz Exp $

Fix Solaris build problem.
https://dev.gnupg.org/T8070

--- src/threadedjobmixin.cpp.orig	2025-06-03 15:55:22.000000000 +0000
+++ src/threadedjobmixin.cpp
@@ -119,17 +119,10 @@ static QList<QByteArray> from_sl(const QStringList &sl
     return result;
 }
 
-static QList<QByteArray> single(const QByteArray &ba)
-{
-    QList<QByteArray> result;
-    result.push_back(ba);
-    return result;
-}
-
 _detail::PatternConverter::PatternConverter(const QByteArray &ba)
-    : m_list(single(ba)), m_patterns(nullptr) {}
+    : m_list({ba}), m_patterns(nullptr) {}
 _detail::PatternConverter::PatternConverter(const QString &s)
-    : m_list(single(s.toUtf8())), m_patterns(nullptr) {}
+    : m_list({s.toUtf8()}), m_patterns(nullptr) {}
 _detail::PatternConverter::PatternConverter(const QList<QByteArray> &lba)
     : m_list(lba), m_patterns(nullptr) {}
 _detail::PatternConverter::PatternConverter(const QStringList &sl)
