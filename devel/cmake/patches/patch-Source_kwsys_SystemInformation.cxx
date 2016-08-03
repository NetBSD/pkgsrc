$NetBSD: patch-Source_kwsys_SystemInformation.cxx,v 1.10 2016/08/03 15:53:38 prlw1 Exp $

* Add more conditional handling for NetBSD, same as others.
* Treat FreeBSD and DragonFly the same way as NetBSD and OpenBSD.
* Treat Solaris same as Linux.

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
