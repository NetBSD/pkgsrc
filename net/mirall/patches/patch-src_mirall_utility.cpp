$NetBSD: patch-src_mirall_utility.cpp,v 1.1 2013/11/22 12:11:49 ryoon Exp $

* https://github.com/owncloud/mirall/issues/1060

--- src/mirall/utility.cpp.orig	2013-10-21 12:05:25.000000000 +0000
+++ src/mirall/utility.cpp
@@ -315,7 +315,7 @@ void Utility::setLaunchOnStartup(const Q
 
 qint64 Utility::freeDiskSpace(const QString &path, bool *ok)
 {
-#ifdef Q_OS_MAC
+#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     struct statvfs stat;
     statvfs(path.toUtf8().data(), &stat);
     return (qint64) stat.f_bavail * stat.f_frsize;
