$NetBSD: patch-libraries_base_src_System_CPUTime.hsc,v 1.1 2025/03/05 03:33:59 pho Exp $

Use clock_getres(CLOCK_PROCESS_CPUTIME_ID) only if it's confirmed to
work. See also patch-libraries_ghc-internal_configure.ac.

--- libraries/base/src/System/CPUTime.hsc.orig	2025-03-04 14:31:13.949097136 +0000
+++ libraries/base/src/System/CPUTime.hsc
@@ -38,7 +38,8 @@ import qualified System.CPUTime.Windows 
 #elif defined(javascript_HOST_ARCH)
 import qualified System.CPUTime.Javascript as I
 
-#elif _POSIX_TIMERS > 0 && defined(_POSIX_CPUTIME) && _POSIX_CPUTIME >= 0
+#elif _POSIX_TIMERS > 0 && defined(_POSIX_CPUTIME) && _POSIX_CPUTIME >= 0 \
+  && defined(CLOCK_GETRES_SUPPORTS_CLOCK_PROCESS_CPUTIME_ID)
 import qualified System.CPUTime.Posix.ClockGetTime as I
 
 #elif defined(HAVE_GETRUSAGE) && ! solaris2_HOST_OS
