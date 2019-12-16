$NetBSD: patch-src_base_utils_fs.cpp,v 1.1 2019/12/16 18:03:20 nia Exp $

Support NetBSD.

--- src/base/utils/fs.cpp.orig	2019-12-02 23:19:18.000000000 +0000
+++ src/base/utils/fs.cpp
@@ -39,7 +39,7 @@
 
 #if defined(Q_OS_WIN)
 #include <Windows.h>
-#elif defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD)
+#elif defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
 #include <sys/param.h>
 #include <sys/mount.h>
 #elif defined(Q_OS_HAIKU)
@@ -49,6 +49,10 @@
 #include <unistd.h>
 #endif
 
+#if defined(Q_OS_NETBSD)
+#define statfs statvfs
+#endif
+
 #include <QDebug>
 #include <QDir>
 #include <QDirIterator>
@@ -321,7 +325,7 @@ bool Utils::Fs::isNetworkFileSystem(cons
         return false;
 
     return (::GetDriveTypeW(volumePath.get()) == DRIVE_REMOTE);
-#elif defined(Q_OS_MACOS) || defined(Q_OS_OPENBSD)
+#elif defined(Q_OS_MACOS) || defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
     QString file = path;
     if (!file.endsWith('/'))
         file += '/';
