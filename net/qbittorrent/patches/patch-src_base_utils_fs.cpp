$NetBSD: patch-src_base_utils_fs.cpp,v 1.3 2022/11/29 16:37:59 adam Exp $

Support NetBSD.

--- src/base/utils/fs.cpp.orig	2022-11-26 21:16:23.000000000 +0000
+++ src/base/utils/fs.cpp
@@ -42,7 +42,7 @@
 
 #if defined(Q_OS_WIN)
 #include <Windows.h>
-#elif defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#elif defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 #include <sys/param.h>
 #include <sys/mount.h>
 #elif defined(Q_OS_HAIKU)
@@ -52,6 +52,10 @@
 #include <unistd.h>
 #endif
 
+#if defined(Q_OS_NETBSD)
+#define statfs statvfs
+#endif
+
 #include <QDateTime>
 #include <QDebug>
 #include <QDir>
@@ -243,7 +247,7 @@ bool Utils::Fs::isNetworkFileSystem(cons
     if (statfs(file.toLocal8Bit().constData(), &buf) != 0)
         return false;
 
-#if defined(Q_OS_OPENBSD)
+#if defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD)
     return ((strncmp(buf.f_fstypename, "cifs", sizeof(buf.f_fstypename)) == 0)
         || (strncmp(buf.f_fstypename, "nfs", sizeof(buf.f_fstypename)) == 0)
         || (strncmp(buf.f_fstypename, "smbfs", sizeof(buf.f_fstypename)) == 0));
