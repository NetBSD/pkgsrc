$NetBSD: patch-Source_kwsys_SystemInformation.cxx,v 1.4 2013/10/24 04:50:57 obache Exp $

Use correct cmake define.

--- Source/kwsys/SystemInformation.cxx.orig	2013-10-07 15:31:00.000000000 +0000
+++ Source/kwsys/SystemInformation.cxx
@@ -130,7 +130,7 @@ typedef int siginfo_t;
 # endif
 #endif
 
-#ifdef __linux
+#if defined(__linux) || defined (__sun)
 # include <fenv.h>
 # include <sys/socket.h>
 # include <netdb.h>
@@ -4616,7 +4616,7 @@ bool SystemInformationImplementation::Qu
   // a 32 bit process on a 64 bit host the returned memory will be
   // limited to 4GiB. So if this is a 32 bit process or if the sysconf
   // method fails use the kstat interface.
-#if SIZEOF_VOID_P == 8
+#if CMAKE_SIZEOF_VOID_P == 8
   if (this->QueryMemoryBySysconf())
     {
     return true;
