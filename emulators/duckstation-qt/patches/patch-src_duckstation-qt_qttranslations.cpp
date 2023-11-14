$NetBSD: patch-src_duckstation-qt_qttranslations.cpp,v 1.1 2023/11/14 17:57:41 nia Exp $

pkgsrc paths.

--- src/duckstation-qt/qttranslations.cpp.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/duckstation-qt/qttranslations.cpp
@@ -41,7 +41,7 @@ void QtHost::InstallTranslator()
   const QString language(QString::fromStdString(Host::GetBaseStringSettingValue("Main", "Language", "en")));
 
   // install the base qt translation first
-  const QString base_dir(QStringLiteral("%1/translations").arg(qApp->applicationDirPath()));
+  const QString base_dir(QStringLiteral("@PREFIX@/share/duckstation/translations"));
   QString base_path(QStringLiteral("%1/qtbase_%2.qm").arg(base_dir).arg(language));
   bool has_base_ts = QFile::exists(base_path);
   if (!has_base_ts)
