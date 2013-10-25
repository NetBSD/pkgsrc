$NetBSD: patch-Source_kwsys_SystemInformation.cxx,v 1.5 2013/10/25 10:49:23 obache Exp $

* Add more conditional handling for NetBSD, same as others.
* Treat Solaris same as Linux.
* Use correct cmake define.

--- Source/kwsys/SystemInformation.cxx.orig	2013-10-07 15:31:00.000000000 +0000
+++ Source/kwsys/SystemInformation.cxx
@@ -93,6 +93,22 @@ typedef int siginfo_t;
 #if defined(__OpenBSD__) || defined(__NetBSD__)
 # include <sys/param.h>
 # include <sys/sysctl.h>
+# include <sys/socket.h>
+# include <netdb.h>
+# include <netinet/in.h>
+# if defined(KWSYS_SYS_HAS_IFADDRS_H)
+#  include <ifaddrs.h>
+#  define KWSYS_SYSTEMINFORMATION_IMPLEMENT_FQDN
+# endif
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
@@ -130,7 +146,7 @@ typedef int siginfo_t;
 # endif
 #endif
 
-#ifdef __linux
+#if defined(__linux) || defined (__sun)
 # include <fenv.h>
 # include <sys/socket.h>
 # include <netdb.h>
@@ -4616,7 +4632,7 @@ bool SystemInformationImplementation::Qu
   // a 32 bit process on a 64 bit host the returned memory will be
   // limited to 4GiB. So if this is a 32 bit process or if the sysconf
   // method fails use the kstat interface.
-#if SIZEOF_VOID_P == 8
+#if CMAKE_SIZEOF_VOID_P == 8
   if (this->QueryMemoryBySysconf())
     {
     return true;
