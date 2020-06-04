$NetBSD: patch-make_autoconf_libraries.m4,v 1.1 2020/06/04 01:10:38 ryoon Exp $

* Enable ALSA audio support under NetBSD.

--- make/autoconf/libraries.m4.orig	2020-04-15 22:35:23.000000000 +0000
+++ make/autoconf/libraries.m4
@@ -73,7 +73,7 @@ AC_DEFUN_ONCE([LIB_DETERMINE_DEPENDENCIE
   fi
 
   # Check if alsa is needed
-  if test "x$OPENJDK_TARGET_OS" = xlinux -o "x$OPENJDK_TARGET_OS_ENV" = xbsd.freebsd; then
+  if test "x$OPENJDK_TARGET_OS" = xlinux -o "x$OPENJDK_TARGET_OS_ENV" = xbsd.freebsd -o "x$OPENJDK_TARGET_OS_ENV" = xbsd.netbsd; then
     NEEDS_LIB_ALSA=true
   else
     NEEDS_LIB_ALSA=false
