$NetBSD: patch-Source_kwsys_SystemInformation.cxx,v 1.9 2015/11/17 12:12:11 wiz Exp $

* Add more conditional handling for NetBSD, same as others.
* Treat FreeBSD and DragonFly the same way as NetBSD and OpenBSD.
* Treat Solaris same as Linux.
* Use correct cmake define.

--- Source/kwsys/SystemInformation.cxx.orig	2015-11-12 15:39:51.000000000 +0000
+++ Source/kwsys/SystemInformation.cxx
@@ -80,9 +80,9 @@ typedef int siginfo_t;
 # undef _WIN32
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+# include <sys/param.h>
 # include <sys/sysctl.h>
-# include <fenv.h>
 # include <sys/socket.h>
 # include <netdb.h>
 # include <netinet/in.h>
@@ -90,11 +90,15 @@ typedef int siginfo_t;
 #  include <ifaddrs.h>
 #  define KWSYS_SYSTEMINFORMATION_IMPLEMENT_FQDN
 # endif
-#endif
-
-#if defined(__OpenBSD__) || defined(__NetBSD__)
-# include <sys/param.h>
-# include <sys/sysctl.h>
+# if defined(KWSYS_SYSTEMINFORMATION_HAS_BACKTRACE)
+#  include <execinfo.h>
+#  if defined(KWSYS_SYSTEMINFORMATION_HAS_CPP_DEMANGLE)
+#    include <cxxabi.h>
+#  endif
+#  if defined(KWSYS_SYSTEMINFORMATION_HAS_SYMBOL_LOOKUP)
+#    include <dlfcn.h>
+#  endif
+# endif
 #endif
 
 #if defined(KWSYS_SYS_HAS_MACHINE_CPU_H)
@@ -124,7 +128,7 @@ typedef int siginfo_t;
 # endif
 #endif
 
-#ifdef __linux
+#if defined(__linux) || defined (__sun) || defined(_SCO_DS)
 # include <fenv.h>
 # include <sys/socket.h>
 # include <netdb.h>
@@ -4741,7 +4745,7 @@ bool SystemInformationImplementation::Qu
   // a 32 bit process on a 64 bit host the returned memory will be
   // limited to 4GiB. So if this is a 32 bit process or if the sysconf
   // method fails use the kstat interface.
-#if SIZEOF_VOID_P == 8
+#if CMAKE_SIZEOF_VOID_P == 8
   if (this->QueryMemoryBySysconf())
     {
     return true;
