$NetBSD: patch-src_qmmp_output.cpp,v 1.1 2025/03/31 16:50:45 nia Exp $

Default to oss instead of oss4 so this works on more systems.

--- src/qmmp/output.cpp.orig	2025-03-31 12:04:58.753946864 +0000
+++ src/qmmp/output.cpp
@@ -154,7 +154,7 @@ OutputFactory *Output::currentFactory()
 #elif defined Q_OS_MAC
     QString name = settings.value(u"Output/current_plugin"_s, u"qtmultimedia"_s).toString();
 #else
-    QString name = settings.value(u"Output/current_plugin"_s, u"oss4"_s).toString();
+    QString name = settings.value(u"Output/current_plugin"_s, u"oss"_s).toString();
 #endif
 #endif //QMMP_DEFAULT_OUTPUT
     for(QmmpPluginCache *item : std::as_const(*m_cache))
