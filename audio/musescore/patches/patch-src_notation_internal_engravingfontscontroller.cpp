$NetBSD: patch-src_notation_internal_engravingfontscontroller.cpp,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Treat FreeBSD and NetBSD like Linux for XDG cache support.

--- src/notation/internal/engravingfontscontroller.cpp.orig	2025-10-10 09:21:06.000000000 +0000
+++ src/notation/internal/engravingfontscontroller.cpp
@@ -57,7 +57,7 @@ void EngravingFontsController::scanAllDi
 #elif defined(Q_OS_MACOS)
     // MacOS is correctly handled by Qt
     QStringList globalFontsPaths = QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation).first(2);
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     // On Unix systems, we want $XDG_DATA_HOME (user-specific) and $XDG_DATA_DIRS (system-wide)
     QStringList globalFontsPaths { qgetenv("XDG_DATA_HOME") };
     globalFontsPaths.append(QString::fromLocal8Bit(qgetenv("XDG_DATA_DIRS")).split(':'));
