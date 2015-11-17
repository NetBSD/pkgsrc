$NetBSD: patch-xbmc_storage_MediaManager.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/storage/MediaManager.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/storage/MediaManager.cpp
@@ -57,6 +57,8 @@
 #include "android/AndroidStorageProvider.h"
 #elif defined(TARGET_FREEBSD)
 #include "linux/LinuxStorageProvider.h"
+#elif defined(TARGET_NETBSD)
+#include "linux/LinuxStorageProvider.h"
 #elif defined(TARGET_POSIX)
 #include "linux/LinuxStorageProvider.h"
 #include <sys/ioctl.h>
@@ -614,7 +616,7 @@ void CMediaManager::CloseTray(const char
 #ifdef HAS_DVD_DRIVE
 #if defined(TARGET_DARWIN)
   // FIXME...
-#elif defined(TARGET_FREEBSD)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   // NYI
 #elif defined(TARGET_POSIX)
   char* dvdDevice = CLibcdio::GetInstance()->GetDeviceFileName();
