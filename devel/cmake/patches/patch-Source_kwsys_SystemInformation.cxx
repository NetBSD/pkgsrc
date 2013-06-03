$NetBSD: patch-Source_kwsys_SystemInformation.cxx,v 1.1 2013/06/03 08:45:27 jperkin Exp $

Use correct cmake define.

--- Source/kwsys/SystemInformation.cxx.orig	2013-05-15 17:38:13.000000000 +0000
+++ Source/kwsys/SystemInformation.cxx
@@ -4300,7 +4300,7 @@ bool SystemInformationImplementation::Qu
   // a 32 bit process on a 64 bit host the returned memory will be
   // limited to 4GiB. So if this is a 32 bit process or if the sysconf
   // method fails use the kstat interface.
-#if SIZEOF_VOID_P == 8
+#if CMAKE_SIZEOF_VOID_P == 8
   if (this->QueryMemoryBySysconf())
     {
     return true;
