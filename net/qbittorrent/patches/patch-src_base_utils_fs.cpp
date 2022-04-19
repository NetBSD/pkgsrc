$NetBSD: patch-src_base_utils_fs.cpp,v 1.2 2022/04/19 16:37:16 adam Exp $

Support NetBSD.

--- src/base/utils/fs.cpp.orig	2022-03-22 14:14:07.000000000 +0000
+++ src/base/utils/fs.cpp
@@ -40,7 +40,7 @@
 
 #if defined(Q_OS_WIN)
 #include <Windows.h>
-#elif defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#elif defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
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
 #include <QDebug>
 #include <QDir>
 #include <QDirIterator>
@@ -356,7 +360,7 @@ bool Utils::Fs::isNetworkFileSystem(cons
     if (statfs(file.toLocal8Bit().constData(), &buf) != 0)
         return false;
 
-#if defined(Q_OS_OPENBSD)
+#if defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD)
     return ((strncmp(buf.f_fstypename, "cifs", sizeof(buf.f_fstypename)) == 0)
         || (strncmp(buf.f_fstypename, "nfs", sizeof(buf.f_fstypename)) == 0)
         || (strncmp(buf.f_fstypename, "smbfs", sizeof(buf.f_fstypename)) == 0));
