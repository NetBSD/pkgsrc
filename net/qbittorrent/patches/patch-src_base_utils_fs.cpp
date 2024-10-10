$NetBSD: patch-src_base_utils_fs.cpp,v 1.4 2024/10/10 13:22:35 adam Exp $

Support NetBSD.

--- src/base/utils/fs.cpp.orig	2024-09-29 17:53:45.000000000 +0000
+++ src/base/utils/fs.cpp
@@ -40,7 +40,7 @@
 
 #if defined(Q_OS_WIN)
 #include <windows.h>
-#elif defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#elif defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD)
 #include <sys/param.h>
 #include <sys/mount.h>
 #elif defined(Q_OS_HAIKU)
@@ -50,6 +50,10 @@
 #include <unistd.h>
 #endif
 
+#if defined(Q_OS_NETBSD)
+#define statfs statvfs
+#endif
+
 #include <QCoreApplication>
 #include <QDateTime>
 #include <QDebug>
@@ -242,7 +246,7 @@ bool Utils::Fs::isNetworkFileSystem(cons
     if (statfs(file.toLocal8Bit().constData(), &buf) != 0)
         return false;
 
-#if defined(Q_OS_OPENBSD)
+#if defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD)
     return ((strncmp(buf.f_fstypename, "cifs", sizeof(buf.f_fstypename)) == 0)
         || (strncmp(buf.f_fstypename, "nfs", sizeof(buf.f_fstypename)) == 0)
         || (strncmp(buf.f_fstypename, "smbfs", sizeof(buf.f_fstypename)) == 0));
