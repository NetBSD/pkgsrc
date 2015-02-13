$NetBSD: patch-src_lib_platform_posix_serialport.cpp,v 1.1 2015/02/13 11:12:23 jmcneill Exp $

--- src/lib/platform/posix/serialport.cpp.orig	2014-10-31 19:11:22.000000000 +0000
+++ src/lib/platform/posix/serialport.cpp
@@ -37,7 +37,7 @@
 #include "lib/platform/util/baudrate.h"
 #include "lib/platform/posix/os-socket.h"
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #ifndef XCASE
 #define XCASE	0
 #endif
@@ -58,7 +58,7 @@ using namespace PLATFORM;
 
 inline bool RemoveLock(const char *strDeviceName)
 {
-  #if !defined(__APPLE__) && !defined(__FreeBSD__) && defined(HAVE_LOCKDEV)
+  #if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && defined(HAVE_LOCKDEV)
   return dev_unlock(strDeviceName, 0) == 0;
   #else
   (void)strDeviceName; // silence unused warning
@@ -126,7 +126,7 @@ bool CSerialSocket::Open(uint64_t iTimeo
     return false;
   }
 
-  #if !defined(__APPLE__) && !defined(__FreeBSD__) && defined(HAVE_LOCKDEV)
+  #if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && defined(HAVE_LOCKDEV)
   if (dev_lock(m_strName.c_str()) != 0)
   {
     m_strError = "Couldn't lock the serial port";
