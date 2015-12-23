$NetBSD: patch-xbmc_linux_XFileUtils.cpp,v 1.2 2015/12/23 12:43:25 joerg Exp $

--- xbmc/linux/XFileUtils.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/linux/XFileUtils.cpp
@@ -24,12 +24,13 @@
 #include "XTimeUtils.h"
 #include "filesystem/SpecialProtocol.h"
 #include "utils/StringUtils.h"
+#include <cstdlib>
 
 #ifdef TARGET_POSIX
 #include "XHandle.h"
 #include <sys/types.h>
 #include <sys/stat.h>
-#if !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD) && !defined(TARGET_ANDROID)
+#if !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD) && !defined(TARGET_NETBSD) && !defined(TARGET_ANDROID)
 #include <sys/vfs.h>
 #else
 #include <sys/param.h>
@@ -68,7 +69,7 @@ HANDLE FindFirstFile(LPCSTR szPath,LPWIN
   StringUtils::Replace(strPath, '\\','/');
 
   // if the file name is a directory then we add a * to look for all files in this directory
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_ANDROID)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_ANDROID)
   DIR *testDir = opendir(strPath.c_str());
 #else
   DIR *testDir = opendir(szPath);
@@ -289,7 +290,7 @@ HANDLE CreateFile(LPCTSTR lpFileName, DW
   HANDLE result = new CXHandle(CXHandle::HND_FILE);
   result->fd = fd;
 
-#if (defined(TARGET_LINUX) || defined(TARGET_FREEBSD)) && defined(HAS_DVD_DRIVE) 
+#if (defined(TARGET_LINUX) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)) && defined(HAS_DVD_DRIVE) 
   // special case for opening the cdrom device
   if (strcmp(lpFileName, MEDIA_DETECT::CLibcdio::GetInstance()->GetDeviceFileName())==0)
     result->m_bCDROM = true;
@@ -575,7 +576,7 @@ DWORD  SetFilePointer(HANDLE hFile, int3
     nMode = SEEK_END;
 
   off64_t currOff;
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   currOff = lseek(hFile->fd, offset, nMode);
 #else
   currOff = lseek64(hFile->fd, offset, nMode);
@@ -645,7 +646,7 @@ BOOL SetEndOfFile(HANDLE hFile)
     return false;
 
   // get the current offset
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   off64_t currOff = lseek(hFile->fd, 0, SEEK_CUR);
 #else
   off64_t currOff = lseek64(hFile->fd, 0, SEEK_CUR);
@@ -676,7 +677,7 @@ BOOL SetFilePointerEx(  HANDLE hFile,
 
   off64_t toMove = liDistanceToMove.QuadPart;
 
-#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD)
+#if defined(TARGET_DARWIN) || defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   off64_t currOff = lseek(hFile->fd, toMove, nMode);
 #else
   off64_t currOff = lseek64(hFile->fd, toMove, nMode);
