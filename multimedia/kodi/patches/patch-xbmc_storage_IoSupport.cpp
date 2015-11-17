$NetBSD: patch-xbmc_storage_IoSupport.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/storage/IoSupport.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/storage/IoSupport.cpp
@@ -54,7 +54,7 @@
 #include <IOKit/storage/IOStorageDeviceCharacteristics.h>
 #endif
 #endif
-#ifdef TARGET_FREEBSD
+#if defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #include <sys/syslimits.h>
 #endif
 #include "cdioSupport.h"
@@ -204,7 +204,7 @@ INT CIoSupport::ReadSectorMode2(HANDLE h
     return -1;
   }
   return MODE2_DATA_SIZE;
-#elif defined(TARGET_FREEBSD)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   // NYI
 #elif defined(TARGET_POSIX)
   if (hDevice->m_bCDROM)
