$NetBSD: patch-Source_kwsys_ProcessUNIX.c,v 1.1 2023/09/30 08:52:52 nros Exp $

* Use the correct ps command on NetBSD,
  this also makes cmake runnable on NetBSD Sparc, see pkg/57272

--- Source/kwsys/ProcessUNIX.c.orig	2023-09-27 13:10:16.942207869 +0000
+++ Source/kwsys/ProcessUNIX.c
@@ -2500,7 +2500,7 @@ static pid_t kwsysProcessFork(kwsysProce
    corresponding parsing format string.  The parsing format should
    have two integers to store: the pid and then the ppid.  */
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||       \
-  defined(__OpenBSD__) || defined(__GLIBC__) || defined(__GNU__)
+  defined(__OpenBSD__) || defined(__GLIBC__) || defined(__GNU__) || defined(__NetBSD__)
 #  define KWSYSPE_PS_COMMAND "ps axo pid,ppid"
 #  define KWSYSPE_PS_FORMAT "%d %d\n"
 #elif defined(__sun) && (defined(__SVR4) || defined(__svr4__)) /* Solaris */
