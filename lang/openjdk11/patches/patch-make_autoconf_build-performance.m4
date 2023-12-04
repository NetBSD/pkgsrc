$NetBSD: patch-make_autoconf_build-performance.m4,v 1.1 2023/12/04 01:08:16 tnn Exp $

try hw.physmem64 before hw.physmem

--- make/autoconf/build-performance.m4.orig	2023-12-04 00:31:51.317110114 +0000
+++ make/autoconf/build-performance.m4
@@ -83,7 +83,7 @@ AC_DEFUN([BPERF_CHECK_MEMORY_SIZE],
     FOUND_MEM=yes
   elif test -x /sbin/sysctl; then
     # Looks like a BSD system
-    MEMORY_SIZE=`/sbin/sysctl -n hw.physmem`
+    MEMORY_SIZE=`/sbin/sysctl -n hw.physmem64 || /sbin/sysctl -n hw.physmem`
     MEMORY_SIZE=`expr $MEMORY_SIZE / 1024 / 1024`
     FOUND_MEM=yes
     if test "x$OPENJDK_TARGET_OS_ENV" = xbsd.openbsd; then
