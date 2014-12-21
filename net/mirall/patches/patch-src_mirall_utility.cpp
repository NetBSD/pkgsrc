$NetBSD: patch-src_mirall_utility.cpp,v 1.2 2014/12/21 13:46:24 ryoon Exp $

* https://github.com/owncloud/mirall/issues/1060

--- src/mirall/utility.cpp.orig	2014-12-18 11:45:49.000000000 +0000
+++ src/mirall/utility.cpp
@@ -172,7 +172,7 @@ void Utility::setLaunchOnStartup(const Q
 
 qint64 Utility::freeDiskSpace(const QString &path, bool *ok)
 {
-#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD) || defined(Q_OS_FREEBSD_KERNEL)
+#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD) || defined(Q_OS_FREEBSD_KERNEL) || defined(Q_OS_NETBSD)
     struct statvfs stat;
     statvfs(path.toUtf8().data(), &stat);
     return (qint64) stat.f_bavail * stat.f_frsize;
@@ -365,7 +365,7 @@ bool Utility::isUnix()
 
 bool Utility::isLinux()
 {
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD)
     return true;
 #else
     return false;
