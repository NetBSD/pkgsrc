$NetBSD: patch-common_autoconf_flags.m4,v 1.1 2026/09/03 17:12:42 jperkin Exp $

Reinstate correct flags on SunOS.

--- common/autoconf/flags.m4.orig	2026-09-03 15:39:26.252126621 +0000
+++ common/autoconf/flags.m4
@@ -672,6 +672,8 @@ AC_DEFUN_ONCE([FLAGS_SETUP_COMPILER_FLAG
     CCXXFLAGS_JDK="$CCXXFLAGS_JDK -DPPC64"
   elif test "x$OPENJDK_TARGET_OS" = xbsd; then
     CCXXFLAGS_JDK="$CCXXFLAGS_JDK -D_ALLBSD_SOURCE"
+  elif test "x$OPENJDK_TARGET_OS" = xsolaris; then
+    CCXXFLAGS_JDK="$CCXXFLAGS_JDK -D_REENTRANT -D_LARGEFILE64_SOURCE"
   elif test "x$OPENJDK_TARGET_OS" = xlinux; then
     CCXXFLAGS_JDK="$CCXXFLAGS_JDK -D_GNU_SOURCE -D_REENTRANT -D_LARGEFILE64_SOURCE"
   fi
