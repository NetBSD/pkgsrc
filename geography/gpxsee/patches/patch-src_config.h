$NetBSD: patch-src_config.h,v 1.1.1.1 2018/10/19 08:57:22 abs Exp $

Allow GLOBAL_DIR to be overridden by build system

--- src/config.h.orig	2018-10-11 16:19:35.000000000 +0000
+++ src/config.h
@@ -21,14 +21,19 @@
 
 #if defined(Q_OS_WIN32)
 #define USER_DIR        QDir::homePath() + QString("/GPXSee")
-#define GLOBAL_DIR      QApplication::applicationDirPath()
+#define DEFAULT_GLOBAL_DIR      QApplication::applicationDirPath()
 #elif defined(Q_OS_MAC)
 #define USER_DIR        QDir::homePath() + QString("/.gpxsee")
-#define GLOBAL_DIR      QApplication::applicationDirPath() \
+#define DEFAULT_GLOBAL_DIR      QApplication::applicationDirPath() \
                           + QString("/../Resources")
 #else
 #define USER_DIR        QDir::homePath() + QString("/.gpxsee")
-#define GLOBAL_DIR      QString("/usr/share/gpxsee")
+#define DEFAULT_GLOBAL_DIR      QString("/usr/share/gpxsee")
+#endif
+#ifdef GPXSEE_GLOBAL_DIR
+#define GLOBAL_DIR QString(GPXSEE_GLOBAL_DIR)
+#else
+#define GLOBAL_DIR DEFAULT_GLOBAL_DIR
 #endif
 
 #define USER_CSV_DIR           USER_DIR + QString("/") + CSV_DIR
