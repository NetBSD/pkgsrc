$NetBSD: patch-xbmc_cores_DllLoader_exports_emu__msvcrt.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/cores/DllLoader/exports/emu_msvcrt.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/cores/DllLoader/exports/emu_msvcrt.cpp
@@ -27,7 +27,7 @@
 #include <direct.h>
 #include <process.h>
 #else
-#if !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD)
+#if !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD) && !defined(TARGET_NETBSD)
 #include <mntent.h>
 #endif
 #endif
@@ -42,7 +42,7 @@
     #include <sys/ioctl.h>
     #if defined(TARGET_DARWIN)
       #include <IOKit/storage/IODVDMediaBSDClient.h>
-    #elif !defined(TARGET_FREEBSD)
+    #elif !defined(TARGET_FREEBSD) && !defined(TARGET_NETBSD)
       #include <linux/cdrom.h>
     #endif
   #endif
@@ -1343,7 +1343,7 @@ extern "C"
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_ANDROID)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_ANDROID)
       return fseek(stream, offset, origin);
 #else
       return fseeko64(stream, offset, origin);
@@ -1408,7 +1408,7 @@ extern "C"
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_ANDROID)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_ANDROID)
       return ftello(stream);
 #else
       return ftello64(stream);
@@ -1454,7 +1454,7 @@ extern "C"
       CLog::Log(LOGWARNING, "msvcrt.dll: dll_telli64 called, TODO: add 'int64 -> long' type checking");      //warning
 #ifndef TARGET_POSIX
       return (__int64)tell(fd);
-#elif defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_ANDROID)
+#elif defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_ANDROID)
       return lseek(fd, 0, SEEK_CUR);
 #else
       return lseek64(fd, 0, SEEK_CUR);
@@ -1632,7 +1632,7 @@ extern "C"
     int ret;
 
     ret = dll_fgetpos64(stream, &tmpPos);
-#if !defined(TARGET_POSIX) || defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_ANDROID)
+#if !defined(TARGET_POSIX) || defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_ANDROID)
     *pos = (fpos_t)tmpPos;
 #else
     pos->__pos = (off_t)tmpPos.__pos;
@@ -1647,6 +1647,8 @@ extern "C"
     {
 #if !defined(TARGET_POSIX) || defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_ANDROID)
       *pos = pFile->GetPosition();
+#elif defined(TARGET_NETBSD)
+      pos->_pos = pFile->GetPosition();
 #else
       pos->__pos = pFile->GetPosition();
 #endif
@@ -1669,6 +1671,8 @@ extern "C"
     {
 #if !defined(TARGET_POSIX) || defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_ANDROID)
       if (dll_lseeki64(fd, *pos, SEEK_SET) >= 0)
+#elif defined(TARGET_NETBSD)
+      if (dll_lseeki64(fd, (__off64_t)pos->_pos, SEEK_SET) >= 0)
 #else
       if (dll_lseeki64(fd, (__off64_t)pos->__pos, SEEK_SET) >= 0)
 #endif
@@ -1684,7 +1688,7 @@ extern "C"
     {
       // it might be something else than a file, or the file is not emulated
       // let the operating system handle it
-#if !defined(TARGET_POSIX) || defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_ANDROID)
+#if !defined(TARGET_POSIX) || defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_ANDROID)
       return fsetpos(stream, pos);
 #else
       return fsetpos64(stream, pos);
@@ -1700,7 +1704,7 @@ extern "C"
     if (fd >= 0)
     {
       fpos64_t tmpPos;
-#if !defined(TARGET_POSIX) || defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_ANDROID)
+#if !defined(TARGET_POSIX) || defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_ANDROID)
       tmpPos= *pos;
 #else
       tmpPos.__pos = (off64_t)(pos->__pos);
@@ -2173,7 +2177,7 @@ extern "C"
      if (!pFile)
        return -1;
 
-#if defined(HAS_DVD_DRIVE) && !defined(TARGET_FREEBSD)
+#if defined(HAS_DVD_DRIVE) && !defined(TARGET_FREEBSD) && !defined(TARGET_NETBSD)
 #if !defined(TARGET_DARWIN)
     if(request == DVD_READ_STRUCT || request == DVD_AUTH)
 #else
